


// http://origin.redisbook.com/internal-datastruct/dict.html
// TODO

/**
 * dict
 */
typedef struct dict {
  dictType* type;

  void* priv_data;

  dict_hash_tab hash_tab[2];
} dict;
