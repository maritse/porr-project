#include "des.h"
#include "permutations.h"

//#pragma GCC optimize ("unroll-loops")

DES::DES(ui64 key)
{
    keygen(key);
}

ui64 DES::encrypt(ui64 block)
{
    return des(block, false);
}

ui64 DES::decrypt(ui64 block)
{
    return des(block, true);
}

ui64 DES::encrypt(ui64 block, ui64 key)
{
    DES des(key);
    return des.des(block, false);
}

ui64 DES::decrypt(ui64 block, ui64 key)
{
    DES des(key);
    return des.des(block, true);
}

void DES::keygen(ui64 key)
{
    // przygotowanie klucza - usuniecie bitow parzystosci
    ui64 permuted_choice_1 = 0; // 56 bity
    for (ui8 i = 0; i < 56; i++)
    {
        permuted_choice_1 <<= 1;
        permuted_choice_1 |= (key >> (64-PC1[i])) & LB64_MASK;
    }

    // przytgotowanie 28 bitowych polowek klucza
    ui32 C = (ui32) ((permuted_choice_1 >> 28) & 0x000000000fffffff);
    ui32 D = (ui32)  (permuted_choice_1 & 0x000000000fffffff);

    // obliczanie 16 kluczy dla kazdej rundy
    for (ui8 i = 0; i < 16; i++)
    {
        // przesuniecia bitowe polowek w kazdej rundzie
        for (ui8 j = 0; j < ITERATION_SHIFT[i]; j++)
        {
            C = (0x0fffffff & (C << 1)) | (0x00000001 & (C >> 27));
            D = (0x0fffffff & (D << 1)) | (0x00000001 & (D >> 27));
        }

        ui64 permuted_choice_2 = (((ui64) C) << 28) | (ui64) D;

        // przygotowanie 48 bitowego klucza poprzez permutacje kompresujaca
        sub_key[i] = 0; // 48 bits (2*24)
        for (ui8 j = 0; j < 48; j++)
        {
            sub_key[i] <<= 1;
            sub_key[i] |= (permuted_choice_2 >> (56-PC2[j])) & LB64_MASK;
        }
    }
}

ui64 DES::des(ui64 block, bool decrypt)
{
    // permutacja poczatkowa
    block = ip(block);

    // podzial bloku wejsciowego na lewa i prawa czesc po 32 bity
    ui32 L = (ui32) (block >> 32) & L64_MASK;
    ui32 R = (ui32) (block & L64_MASK);

    // 16 cykli feistela
    for (ui8 i = 0; i < 16; i++)
    {
        ui32 F = decrypt ? f(R, sub_key[15-i]) : f(R, sub_key[i]);
        feistel(L, R, F);
    }

    // zamiana prawej i lewej strony miejscami
    block = (((ui64) R) << 32) | (ui64) L;

    // permutacja koncowa
    return fp(block);
}

ui64 DES::ip(ui64 block)
{
    ui64 result = 0;
    for (ui8 i = 0; i < 64; i++)
    {
        result <<= 1;
        result |= (block >> (64-IP[i])) & LB64_MASK;
    }
    return result;
}

ui64 DES::fp(ui64 block)
{
    ui64 result = 0;
    for (ui8 i = 0; i < 64; i++)
    {
        result <<= 1;
        result |= (block >> (64-FP[i])) & LB64_MASK;
    }
    return result;
}

void DES::feistel(ui32 &L, ui32 &R, ui32 F)
{
    ui32 temp = R;
    R = L ^ F;
    L = temp;
}

// funkcja f w sieci feistela
ui32 DES::f(ui32 R, ui64 k)
{
    // permutacja rozszerzajca 32 bity na 48 bitow
    ui64 s_input = 0;
    for (ui8 i = 0; i < 48; i++)
    {
        s_input <<= 1;
        s_input |= (ui64) ((R >> (32-EXPANSION[i])) & LB32_MASK);
    }

    // operacja XOR prawej czesci z kluczem
    s_input = s_input ^ k;

    // operacje S-blokow i wyscie 32 bitowe
    ui32 s_output = 0;
    for (ui8 i = 0; i < 8; i++)
    {
        // Outer bits
        char row = (char) ((s_input & (0x0000840000000000 >> 6*i)) >> (42-6*i));
        row = (row >> 4) | (row & 0x01);

        // Middle 4 bits of input
        char column = (char) ((s_input & (0x0000780000000000 >> 6*i)) >> (43-6*i));

        s_output <<= 4;
        s_output |= (ui32) (SBOX[i][16*row + column] & 0x0f);
    }

    // permutacje P-blokow 32 bitowe
    ui32 f_result = 0;
    for (ui8 i = 0; i < 32; i++)
    {
        f_result <<= 1;
        f_result |= (s_output >> (32 - PBOX[i])) & LB32_MASK;
    }

    return f_result;
}
