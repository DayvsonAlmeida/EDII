#include "HashTable.h"
#include <math.h>
#include <stdlib.h>

HashTable::HashTable(){
  vet = NULL;
  len = 0;
}

HashTable::HashTable(int size){
  HashTable();
  if(size>0){
    this->len = size;
    this->vet = new SLList[len];
    for(int i=0; i<len; i++)
      vet[i] = SLList();
  }
}

int HashTable::mapping(int key){//Melhorar o mapeamento posteriormente
  return (abs(key) % len);
}

bool HashTable::insert(void* data, int(*getValue)(void*), int(*cmp)(void*, void*)){
  int key, h;
  bool status = false;
  
  key = getValue(data);
  h = this->mapping(key);
  if(h>=0 && h<this->len){
    status = this->vet[h].insertInOrder(data, cmp);
  }
  return status;
}

void* HashTable::remove(void* key, int(*getValue)(void*), bool(*cmp)(void*, void*)){
  int h, hKey;

  hKey = getValue(key);
  h = this->mapping(hKey);
  if(h>=0 && h<this->len){
    void* out;
    out = this->vet[h].remove(key, cmp);
    return out;
  }
  return NULL;
}

void* HashTable::query(void* key, int(*getValue)(void*), bool(*cmp)(void*, void*)){
  int h, hKey;

  hKey = getValue(key);
  h = this->mapping(hKey);
  if(h>=0 && h<this->len){
    void* out;
    out = this->vet[h].query(key, cmp);
    return out;
  }
  return NULL;
}
