#include "rng.h"

//https://rosettacode.org/wiki/The_ISAAC_cipher

// making these global variables static means that these variables are only accessible by functions within this file

// External results
static uint32_t randRsl[256]; // this is the key
static uint32_t randCnt;

// Internal state
static uint32_t mm[256]; 
static uint32_t aa = 0, bb = 0, cc = 0;

void isaac() {   
    ++cc;  // cc just gets incremented once per 256 results
    bb += cc; // then combined with bb
   
    for (uint32_t i = 0; i < 256; ++i)
    {
        uint32_t x, y;

        x = mm[i];
        switch (i % 4)
        {
            case 0: 
                aa = aa ^ (aa << 13); 
                break;
            case 1:
                aa = aa ^ (aa >> 6); 
                break;
            case 2:
                aa = aa ^ (aa << 2);
                break;
            case 3:
                aa = aa ^ (aa >> 16);
                break;
        }
        aa = mm[(i + 128) % 256] + aa;
        y = mm[(x >> 2) % 256] + aa + bb;
        mm[i] = y;
        bb = mm[(y >> 10) % 256] + x;
        randRsl[i] = bb; 
    }
    randCnt = 0; // Prepare to use the first set of results. 
}

void mix(uint32_t a[])
{  
    a[0] = a[0] ^ a[1] << 11; a[3] += a[0]; a[1] += a[2];
    a[1] = a[1] ^ a[2] >>  2; a[4] += a[1]; a[2] += a[3];
    a[2] = a[2] ^ a[3] <<  8; a[5] += a[2]; a[3] += a[4];
    a[3] = a[3] ^ a[4] >> 16; a[6] += a[3]; a[4] += a[5];
    a[4] = a[4] ^ a[5] << 10; a[7] += a[4]; a[5] += a[6];
    a[5] = a[5] ^ a[6] >>  4; a[0] += a[5]; a[6] += a[7];
    a[6] = a[6] ^ a[7] <<  8; a[1] += a[6]; a[7] += a[0];
    a[7] = a[7] ^ a[0] >>  9; a[2] += a[7]; a[0] += a[1];  
}

void randInit(bool flag)
{
    uint32_t a[8];
    aa = bb = cc = 0;
   
    a[0] = 2654435769UL; // 0x9e3779b9: the golden ratio 
    for (uint32_t j = 1; j < 8; ++j) a[j] = a[0]; // set all elements within array a to the golden ratio
    for (uint32_t i = 0; i < 4; ++i) mix(a); // mix all elements of a
    for (uint32_t i = 0; i < 256; i += 8) // Fill in mm[] with messy stuff from the key and the mixed a
    {
        if (flag) // Use all the information in the seed.
            for (uint32_t j = 0; j < 8; ++j)
                a[j] += randRsl[i + j];
        mix(a);
        for (uint32_t j = 0; j < 8; ++j)
            mm[i + j] = a[j];
    }  
    if (flag)  // Do a second pass to make all of the seed affect all of mm.
    {   
        for (uint32_t i = 0; i < 256; i += 8)
        {
            for (uint32_t j = 0; j < 8; ++j)
                a[j] += mm[i + j];
            mix(a);
            for (uint32_t j = 0; j < 8; ++j)
                mm[i + j] = a[j];
        }
    }   
    
    isaac(); // Fill in the first set of results.
    randCnt = 0; // Prepare to use the first set of results.
}

// Seed ISAAC with a given string.
// The string can be any size. The first 256 values will be used.
void seedIsaac(std::string seed, bool flag)
{
    uint32_t seedLength = seed.length();
    for (uint32_t i = 0; i < 256; i++) //setting array mm to 0
        mm[i] = 0;
    for (uint32_t i = 0; i < 256; i++)
        randRsl[i] = i > seedLength ? 0 : seed[i]; // In case seed has less than 256 elements
    // Initialize ISAAC with seed
    randInit(flag);
}

// Get a random 32-bit value 0..MAXINT
uint32_t getRandom32Bit()
{
    uint32_t result = randRsl[randCnt];
    ++randCnt;
    if (randCnt > 255)
    {
        isaac();
        randCnt = 0;
    }
    return result;
}