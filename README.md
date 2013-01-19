Present-8bit
============

An 8-bit Implementation of the PRESENT block cipher in C

Supports ECB and CBC encryption modes with 80 or 128 bit keys

Usage:
```c
unsigned char iv[8]       = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01};
unsigned char key[10]     = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0x01, 0x23};
unsigned char message[56] = "An 8-bit Implementation of the PRESENT block cipher in C";

present80CBC_encrypt( message, 56, key, iv );
// hex: 8792ccad4f2e3331899c7c25fd4b36dda5e70689f2ccb84c57b799433b3194391f4b6aa6b7cd683a765858c3a4a56020626d46aded962cdd

present80CBC_decrypt( message, 56, key, iv );
```
