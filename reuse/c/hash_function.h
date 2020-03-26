#include <string.h>


/********** standard hash function **********/
/* source links: https://www.partow.net/programming/hashfunctions */
/* author: Robert Sedgwicks */
unsigned int RS_hash(const char* str) {
  unsigned int b    = 378551;
  unsigned int a    = 63689;
  unsigned int hash = 0;
  unsigned int i    = 0;
  for (; i < strlen(str); ++i) {
    hash = hash * a + str[i];
    a = a* b;
  }
  return hash;
}

/* author: Justin Sobel*/
unsigned int JS_hash(const char* str) {
  unsigned int hash = 0;
  unsigned int i    = 0;
  for (; i < strlen(str); ++i) {
    hash ^= ((hash << 5) + str[i] + (hash >> 2));
  }
  return hash;
}

/* author: Peter J. Weinberger */
unsigned int PJW_hash(const char* str) {
  const unsigned int bits_in_unsigned_int = (unsigned int)(sizeof(unsigned int) * 8);
  const unsigned int three_quarters       = (unsigned int)((bits_in_unsigned_int * 3) / 4);
  const unsigned int one_eighth           = (unsigned int)(bits_in_unsigned_int / 8);
  const unsigned int high_bits            = (unsigned int)(0xFFFFFFFF) << (bits_in_unsigned_int - one_eighth);
  unsigned int hash = 0;
  unsigned int test = 0;
  unsigned int i    = 0;
  for (; i < strlen(str); ++i) {
    hash = (hash << one_eighth) + str[i];
    if ((test = hash & high_bits) != 0) {
      hash = ((hash ^ (test >> three_quarters)) & (~high_bits));
    }
  }
  return hash;
}

/* author: on UNIX system */
unsigned int ELF_hash(const char* str) {
  unsigned int hash = 0;
  unsigned int x    = 0;
  unsigned int i    = 0;
  for (; i < strlen(str); ++i) {
    hash = (hash << 4) + str[i];
    if ((x = hash & 0xF0000000L) != 0) {
      hash ^= (x >> 24);
    }
    hash &= ~x;
  }
  return hash;
}

/* author: Brian Kernighan and Dennis Ritchie */
unsigned int BKDR_hash(const char* str) {
  unsigned int seed = 131; /* 31 131 1313 13131 131313 etc.. */
  unsigned int hash = 0;
  unsigned int i    = 0;
  for (; i < strlen(str); ++i) {
    hash = hash * seed + str[i];
  }
  return hash;
}

/* author: open source SDBM project */
unsigned int SDBM_hash(const char* str) {
  unsigned int hash = 0;
  unsigned int i    = 0;
  for (; i < strlen(str); ++i) {
    hash = str[i] + (hash << 6) + (hash << 16) - hash;
  }
  return hash;
}

/* author: Daniel J. Bernstein */
unsigned int DJB_hash(const char* str) {
  unsigned int hash = 5381;
  unsigned int i    = 0;
  for (; i < strlen(str); ++i) {
    hash = ((hash << 5) + hash) + str[i];
  }
  return hash;
}

/* author: Donald E. Knuth */
unsigned int DEK_hash(const char* str) {
  unsigned int hash = strlen(str);
  unsigned int i    = 0;
  for (; i < strlen(str); ++i) {
    hash = ((hash << 5) ^ (hash >> 27)) ^ str[i];
  }
  return hash;
}

/* author: Arash Partow */
unsigned int AP_hash(const char* str) {
  unsigned int hash = 0xAAAAAAAA;
  unsigned int i    = 0;
  for (; i < strlen(str); ++i) {
    hash ^= ((i & 1) == 0) ? ((hash << 7) ^ (*str) * (hash >> 3)) :
                             (~((hash << 11) + ((*str) ^ (hash >> 5))));
  }
  return hash;
}

