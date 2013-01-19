#include <stdio.h>
#include <string.h>
#include "PresentCBC.h"

unsigned char iv[8]      = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01};
unsigned char key80[10]  = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0x01, 0x23};
unsigned char key128[16] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF};
unsigned char plainText[24]      = "Bananas 12345678Bananas ";
unsigned char workingCopy80[24]  = "Bananas 12345678Bananas ";
unsigned char workingCopy128[24] = "Bananas 12345678Bananas ";
unsigned char cipherText80[24]  = {0x89, 0x3c, 0x69, 0xf4, 0xdb, 0x27, 0x34, 0x69, 0xde, 0x65, 0xe4, 0x5a, 0xda, 0x20, 0xe7, 0xd0, 0x4a, 0xbc, 0x7b, 0x2a, 0xae, 0x77, 0x5e, 0x61};
unsigned char cipherText128[24] = {0xf9, 0x3a, 0xdf, 0x2d, 0x59, 0x89, 0x72, 0xb8, 0x6d, 0xac, 0xce, 0x19, 0xfb, 0xce, 0x73, 0x8e, 0x40, 0xed, 0x52, 0x7e, 0x90, 0x1b, 0x33, 0x5a};

void printMessage( const unsigned char *message ){
    printf( "Got: " );
    for( int i = 0; i < 24; i+=2 ){
        printf( "%02x%02x ", message[i], message[i+1] );
    }
    printf( "\n" );
}

int main(){
    int pass = 1;
    present80CBC_encrypt( workingCopy80, 24, key80, iv );
    present128CBC_encrypt( workingCopy128, 24, key128, iv );

    if( memcmp( workingCopy80, cipherText80, 24 ) != 0 ){
        pass = 0;
        printf( "Present80CBC encryption failed\n");
        printMessage( workingCopy80 );
    }
    if( memcmp( workingCopy128, cipherText128, 24 ) != 0 ){
        pass = 0;
        printf( "Present128CBC encryption failed\n");
        printMessage( workingCopy128 );
    }

    present80CBC_decrypt( workingCopy80, 24, key80, iv );
    present128CBC_decrypt( workingCopy128, 24, key128, iv );

    if( memcmp( workingCopy80, plainText, 24 ) != 0 ){
        pass = 0;
        printf( "Present80CBC decryption failed\n");
        printMessage( workingCopy80 );
    }
    if( memcmp( workingCopy128, plainText, 24 ) != 0 ){
        pass = 0;
        printf( "Present128CBC decryption failed\n");
        printMessage( workingCopy128 );
    }
    printf( "%s\n", (pass ? "PASS" : "FAIL") );
}
