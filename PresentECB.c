#import "PresentECB.h"
#import "Present.h"

void performBlockFunction( void (*blockFunction)(unsigned char *, const unsigned char *), unsigned char *message, const unsigned int messageLength,  const unsigned char *key ){
    unsigned int offset = 0;
    while( offset < messageLength ){
        blockFunction( &message[offset], key );
        offset += PRESENT_BLOCK_SIZE_BYTES;
    }    
}

void present80ECB_encrypt( unsigned char *message, const unsigned int messageLength,  const unsigned char *key ){
    performBlockFunction( present80_encryptBlock, message, messageLength, key );
}

void present80ECB_decrypt( unsigned char *message, const unsigned int messageLength,  const unsigned char *key ){
    performBlockFunction( present80_decryptBlock, message, messageLength, key );
}

void present128ECB_encrypt( unsigned char *message, const unsigned int messageLength,  const unsigned char *key ){
    performBlockFunction( present128_encryptBlock, message, messageLength, key );
}

void present128ECB_decrypt( unsigned char *message, const unsigned int messageLength,  const unsigned char *key ){
    performBlockFunction( present128_decryptBlock, message, messageLength, key );
}
