#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "SLList.h"

class HashTable{
 private:
  SLList *vet;
  int len;
 public:
  //Construtores
  HashTable();
  HashTable(int size);
  //Métodos
  int mapping(int key);
  bool insert(void* data, int(*getValue)(void*), int(*cmp)(void*, void*));
  void* remove(void* key, int(*getValue)(void*), bool(*cmp)(void*, void*));
  void* query(void* key, int(*getValue)(void*), bool(*cmp)(void*, void*));
};
#endif 
