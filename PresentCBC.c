#import "PresentCBC.h"
#import "Present.h"

void performBlockFunctionForward( void (*blockFunction)(unsigned char *, const unsigned char *), unsigned char *message, const unsigned int messageLength,  const unsigned char *key, const unsigned char *iv ){
    unsigned char *nonce = (unsigned char *) iv;
    unsigned int offset = 0;
    int i;
    while( offset < messageLength ){
        for( i = 0; i < PRESENT_BLOCK_SIZE_BYTES; i++ ){
            message[offset + i] ^= nonce[i];
        }
        blockFunction( &message[offset], key );
        nonce = &message[offset];
        offset += PRESENT_BLOCK_SIZE_BYTES;
    }
}

/**
 * This will perform the given decryption function backward to perform the cbc
 * functionality in-place
 */
void performBlockFunctionBackward( void (*blockFunction)(unsigned char *, const unsigned char *), unsigned char *message, const unsigned int messageLength,  const unsigned char *key, const unsigned char *iv ){
    unsigned int offset = PRESENT_BLOCK_SIZE_BYTES;
    int i;
    while( offset < messageLength ){
        blockFunction( &message[messageLength - offset], key );
        for( i = 0; i < PRESENT_BLOCK_SIZE_BYTES; i++ ){
            message[(messageLength - offset) + i] ^= message[((messageLength - offset) - PRESENT_BLOCK_SIZE_BYTES) + i];
        }
        offset += PRESENT_BLOCK_SIZE_BYTES;
    }
    // Decrypt last block using the iv
    blockFunction( &message[0], key );
    for( i = 0; i < PRESENT_BLOCK_SIZE_BYTES; i++ ){
        message[i] ^= iv[i];
    }
}

void present80CBC_encrypt( unsigned char *message, const unsigned int messageLength,  const unsigned char *key, const unsigned char *iv ){
    performBlockFunctionForward( present80_encryptBlock, message, messageLength, key, iv );
}

void present80CBC_decrypt( unsigned char *message, const unsigned int messageLength,  const unsigned char *key, const unsigned char *iv ){
    performBlockFunctionBackward( present80_decryptBlock, message, messageLength, key, iv );
}

void present128CBC_encrypt( unsigned char *message, const unsigned int messageLength,  const unsigned char *key, const unsigned char *iv ){
    performBlockFunctionForward( present128_encryptBlock, message, messageLength, key, iv );
}

void present128CBC_decrypt( unsigned char *message, const unsigned int messageLength,  const unsigned char *key, const unsigned char *iv ){
    performBlockFunctionBackward( present128_decryptBlock, message, messageLength, key, iv );
}
