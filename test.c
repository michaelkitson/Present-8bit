#include <stdio.h>
#include "Present.h"

typedef struct testCase{
    unsigned char *workingCopy;
    unsigned char *plainText;
    unsigned char *key;
    unsigned char *cipherText;
} testCase_t;

#define TESTCASE_COUNT_80 2
testCase_t testCases80[TESTCASE_COUNT_80] = {
    {
        (unsigned char[8])  {0, 0, 0, 0, 0, 0, 0, 0 },
        (unsigned char[8])  {0, 0, 0, 0, 0, 0, 0, 0 },
        (unsigned char[10]) {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        (unsigned char[8])  {0x55, 0x79, 0xC1, 0x38, 0x7B, 0x22, 0x84, 0x45}
    },
    {
        (unsigned char[8])  {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
        (unsigned char[8])  {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
        (unsigned char[10]) {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
        (unsigned char[8])  {0x33, 0x33, 0xDC, 0xD3, 0x21, 0x32, 0x10, 0xD2}
    }
};

#define TESTCASE_COUNT_128 2
testCase_t testCases128[TESTCASE_COUNT_128] = {
    {
        (unsigned char[8])  {0, 0, 0, 0, 0, 0, 0, 0 },
        (unsigned char[8])  {0, 0, 0, 0, 0, 0, 0, 0 },
        (unsigned char[16]) {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        (unsigned char[8])  {0x96, 0xDB, 0x70, 0x2A, 0x2E, 0x69, 0x00, 0xAF}
    },
    {
        (unsigned char[8])  {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
        (unsigned char[8])  {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
        (unsigned char[16]) {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
        (unsigned char[8])  {0x62, 0x8D, 0x9F, 0xBD, 0x42, 0x18, 0xE5, 0xB4}
    }
};

int test( const unsigned char *a, const unsigned char *b, const int length ){
    int i;
    for( i = 0; i < length; i++ ){
        if( a[i] != b[i] ){
            return 1;
        }
    }
    return 0;
}

int main( int argc, char *argv[] ){
    int i, pass = 0;
    for( i = 0; i < TESTCASE_COUNT_80; i++ ){
        testCase_t tc = testCases80[i];
        pass |= test( tc.workingCopy, tc.plainText, 8 );
        present80_encryptBlock( tc.workingCopy, tc.key );
        pass |= test( tc.workingCopy, tc.cipherText, 8 );
        present80_decryptBlock( tc.workingCopy, tc.key );
        pass |= test( tc.workingCopy, tc.plainText, 8 );
    }
    printf( "Present-80  %s\n", (pass == 0) ? "PASS" : "FAIL");
    pass = 0;

    for( i = 0; i < TESTCASE_COUNT_128; i++ ){
        testCase_t tc = testCases128[i];
        pass |= test( tc.workingCopy, tc.plainText, 8 );
        present128_encryptBlock( tc.workingCopy, tc.key );
        pass |= test( tc.workingCopy, tc.cipherText, 8 );
        present128_decryptBlock( tc.workingCopy, tc.key );
        pass |= test( tc.workingCopy, tc.plainText, 8 );
    }
    printf( "Present-128 %s\n", (pass == 0) ? "PASS" : "FAIL");
    return 0;
}
