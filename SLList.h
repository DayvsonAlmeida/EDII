#ifndef SLLIST_H
#define SLLIST_H
#include "SLNode.h"
/*
  # Implementar as funções restantes
*/
class SLList{
 private:
  SLNode *first;
  int len;
 public:
  //Construtores
  SLList();
  //#Métodos#
  void setFirst(SLNode* new_first);
  SLNode* getFirst();
  int getLen();
  bool isEmpty();
  bool insertFirst(void* new_data);
  bool insertLast(void* new_data);
  bool insertInOrder(void* new_data, int(*cmp)(void*, void*));
  void* query(void* key, bool(*cmp)(void*, void*));
  void* remove(void* key, bool(*cmp)(void*, void*));
  void* removeFirst();
  //void* removeLast();  
};

#endif
