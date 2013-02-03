#include <stdio.h>
#include <string.h>
#include "PresentECB.h"

unsigned char key80[10]  = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0x01, 0x23};
unsigned char key128[16] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF};
unsigned char plainText[24]      = "Bananas 12345678Bananas ";
unsigned char workingCopy80[24]  = "Bananas 12345678Bananas ";
unsigned char workingCopy128[24] = "Bananas 12345678Bananas ";
unsigned char cipherText80[24]  = {0x27, 0x8f, 0x14, 0x10, 0xa7, 0x38, 0x61, 0x83, 0x9a, 0xcc, 0x76, 0x89, 0x2b, 0xde, 0xe4, 0x7c, 0x27, 0x8f, 0x14, 0x10, 0xa7, 0x38, 0x61, 0x83};
unsigned char cipherText128[24] = {0x67, 0xa8, 0x05, 0xab, 0x0a, 0x9e, 0xea, 0x53, 0x9d, 0x0f, 0x40, 0x9a, 0x00, 0x21, 0x62, 0x30, 0x67, 0xa8, 0x05, 0xab, 0x0a, 0x9e, 0xea, 0x53};

void printMessage( const unsigned char *message ){
    printf( "Got: " );
    for( int i = 0; i < 24; i+=2 ){
        printf( "%02x%02x ", message[i], message[i+1] );
    }
    printf( "\n" );
}

int main(){
    int pass = 1;
    present80ECB_encrypt( workingCopy80, 24, key80 );
    present128ECB_encrypt( workingCopy128, 24, key128 );

    if( memcmp( workingCopy80, cipherText80, 24 ) != 0 ){
        pass = 0;
        printf( "Present80ECB encryption failed\n");
        printMessage( workingCopy80 );
    }
    if( memcmp( workingCopy128, cipherText128, 24 ) != 0 ){
        pass = 0;
        printf( "Present128ECB encryption failed\n");
        printMessage( workingCopy128 );
    }

    present80ECB_decrypt( workingCopy80, 24, key80 );
    present128ECB_decrypt( workingCopy128, 24, key128 );

    if( memcmp( workingCopy80, plainText, 24 ) != 0 ){
        pass = 0;
        printf( "Present80ECB decryption failed\n");
        printMessage( workingCopy80 );
    }
    if( memcmp( workingCopy128, plainText, 24 ) != 0 ){
        pass = 0;
        printf( "Present128ECB decryption failed\n");
        printMessage( workingCopy128 );
    }
    printf( "%s\n", (pass ? "PASS" : "FAIL") );
    return 0;
}
