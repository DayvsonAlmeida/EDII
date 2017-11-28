#include <iostream>
#include "HashTable.h"

using namespace std;

int getValue(void* a){
  return (*(int*)a);
}
int cmp(void* a, void* b){
  int *pa, *pb;
  pa = (int*)a;
  pb = (int*)b;
  if(*pa < *pb)
    return -1;
  else if(*pa > *pb)
    return 1;
  else
    return 0;
}
bool cmpb(void* a, void* b){
  int *pa, *pb;
  pa = (int*)a;
  pb = (int*)b;
  if(*pa == *pb)
    return true;
  return false;
}

int main(){
  HashTable tabela;
  int a=10, b=7, c=5;
  
  tabela = HashTable(10);
  tabela.insert((void*)&a, getValue, cmp);
  tabela.insert((void*)&b, getValue, cmp);
  int *p;
  p = (int*)tabela.query((void*)&c, getValue, cmpb);
  if(p!=NULL)
    cout << *p << endl;
  else
    cout << "Azedou!\n";
  return 0;
}
