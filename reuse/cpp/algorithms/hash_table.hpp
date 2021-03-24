// TODO

// https://en.wikipedia.org/wiki/Hash_table


// open hashing
// array + linked_list
class OpenHashingHashTable {
 public:
  OpenHashingHashTable();
  ~OpenHashingHashTable();

  bool add(const KeyType&, const ValueType&);
  void del(const KeyType&);
  void change(const KeyType&, const ValueType&);
  ValueType get(const KeyType&);

 privete:
  //
};


// closed hashing / open addressing
// only array
class OpenAddressingHashTable {};

