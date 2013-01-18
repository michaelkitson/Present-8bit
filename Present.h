#ifndef PRESENT_H
#define PRESENT_H

#define PRESENT_80_KEY_SIZE_BYTES 10
#define PRESENT_128_KEY_SIZE_BYTES 16
#define PRESENT_BLOCK_SIZE_BYTES 8

void present80_encryptBlock( unsigned char *block, const unsigned char *key );
void present80_decryptBlock( unsigned char *block, const unsigned char *key );

void present128_encryptBlock( unsigned char *block, const unsigned char *key );
void present128_decryptBlock( unsigned char *block, const unsigned char *key );

#endif
