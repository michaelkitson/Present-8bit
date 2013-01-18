#ifndef PRESENTECB_H
#define PRESENTECB_H

// DISCLAIMER: Unless you really know what you're doing, go use CBC mode
// ECB mode may seem simpler with no IV, but it has important security implications
// See: https://en.wikipedia.org/wiki/Block_cipher_modes_of_operation

/**
 * Encrypts the message data in place using electronic codebook mode.
 * The message 
 *
 * @param message       The message data to be encrypted
 * @param messageLength The length of the message in bytes must be a multiple
 *                      of the block size as no padding is performed
 * @param key           The 80-bit key to use in the encryption
 */
void present80ECB_encrypt( unsigned char *message, const unsigned int messageLength,  const unsigned char *key );

/**
 * Decrypts the message data in place using electronic codebook mode. 
 *
 * @param message       The message data to be decrypted
 * @param messageLength The length of the message in bytes must be a multiple
 *                      of the block size as no padding is performed
 * @param key           The 80-bit key used in the encryption
 */
void present80ECB_decrypt( unsigned char *message, const unsigned int messageLength, const unsigned char *key );

/**
 * Encrypts the message data in place using electronic codebook mode.
 *
 * @param message       The message data to be encrypted
 * @param messageLength The length of the message in bytes must be a multiple
 *                      of the block size as no padding is performed
 * @param key           The 128-bit key to use in the encryption
 */
void present128ECB_encrypt( unsigned char *message, const unsigned int messageLength, const unsigned char *key );

/**
 * Decrypts the message data in place using electronic codebook mode. 
 *
 * @param message       The message data to be decrypted
 * @param messageLength The length of the message in bytes must be a multiple
 *                      of the block size as no padding is performed
 * @param key           The 128-bit key used in the encryption
 */
void present128ECB_decrypt( unsigned char *message, const unsigned int messageLength, const unsigned char *key );

#endif
