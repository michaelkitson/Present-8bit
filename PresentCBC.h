#ifndef PRESENTCBC_H
#define PRESENTCBC_H

/**
 * Encrypts the message data in place using cipher block chaining mode.
 *
 * @param message       The message data to be encrypted
 * @param messageLength The length of the message in bytes. Must be a multiple
 *                      of the block size as no padding is performed
 * @param key           The 80-bit key to use in the encryption
 * @param iv            The 64-bit initialization vector for the first block
 */
void present80CBC_encrypt( unsigned char *message, const unsigned int messageLength, const unsigned char *key, const unsigned char *iv );

/**
 * Decrypts the message data in place using cipher block chaining mode.
 *
 * @param message       The message data to be decrypted
 * @param messageLength The length of the message in bytes. Must be a multiple
 *                      of the block size as no padding is performed
 * @param key           The 80-bit key used in the encryption
 * @param iv            The 64-bit initialization vector for the first block
 */
void present80CBC_decrypt( unsigned char *message, const unsigned int messageLength, const unsigned char *key, const unsigned char *iv );

/**
 * Encrypts the message data in place using cipher block chaining mode.
 *
 * @param message       The message data to be encrypted
 * @param messageLength The length of the message in bytes. Must be a multiple
 *                      of the block size as no padding is performed
 * @param key           The 128-bit key to use in the encryption
 * @param iv            The 64-bit initialization vector for the first block
 */
void present128CBC_encrypt( unsigned char *message, const unsigned int messageLength, const unsigned char *key, const unsigned char *iv );

/**
 * Decrypts the message data in place using cipher block chaining mode.
 *
 * @param message       The message data to be decrypted
 * @param messageLength The length of the message in bytes. Must be a multiple
 *                      of the block size as no padding is performed
 * @param key           The 128-bit key used in the encryption
 * @param iv            The 64-bit initialization vector for the first block
 */
void present128CBC_decrypt( unsigned char *message, const unsigned int messageLength, const unsigned char *key, const unsigned char *iv );

#endif
