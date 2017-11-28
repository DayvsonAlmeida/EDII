#include "SLList.h"
#include <stdlib.h>

SLList::SLList(){
  this->first = NULL;
  this->len = 0;
}

void SLList::setFirst(SLNode* new_first){
  this->first = new_first;
}

SLNode* SLList::getFirst(){
  return this->first;
}

bool SLList::isEmpty(){
  if(this->first!=NULL)
    return false;
  else
    return true;
}

bool SLList::insertFirst(void* new_data){
  SLNode *newNode;
  newNode = new SLNode[1];
  *newNode = SLNode(new_data);
  if(newNode->getData()!=NULL){
    newNode->setNext(this->first);
    this->setFirst(newNode);
    (this->len)++;
    return true;  
  }
  return false;
}

bool SLList::insertLast(void* new_data){
  SLNode *newNode;
  newNode = new SLNode[1];
  *newNode = SLNode(new_data);
  if(newNode->getData()!=NULL){
    SLNode *aux;
    aux = this->first;
    while(aux->hasNext()){
      aux = aux->getNext();
    }
    aux->setNext(newNode);
    (this->len)++;
    return true;
  }
  return false;
}

bool SLList::insertInOrder(void* new_data, int(*cmp)(void*, void*)){
  SLNode *newNode, *cur, *prev;
  int status;
  
  newNode = new SLNode[1];
  *newNode = SLNode(new_data);
  if(this->isEmpty()){
    this->setFirst(newNode);
    (this->len)++;
    return true;
  }else{
    cur = this->getFirst();
    prev = NULL;
    status = cmp(cur->getData(), new_data);
    while(cur->hasNext() && status<=0){
      prev = cur;
      cur = cur->getNext();
      status = cmp(cur->getData(), new_data);
    }
    if(status>0){//Encontrou um elemento maior que o dado (inserir dado antes do elemento)
      if(prev == NULL){//Dado menor que o primeiro elemento
	newNode->setNext(this->first);
	this->setFirst(newNode);
	(this->len)++;
	return true;
      }else{//Inserção no meio da lista
	newNode->setNext(cur);
	prev->setNext(newNode);
	(this->len)++;
	return true;
      }
    }else{//Dados maior que todos os elementos
      if(!cur->hasNext()){//checando se está no último elemento
	cur->setNext(newNode);
	(this->len)++;
	return true;
      }
    }
  }
  return false;
}

void* SLList::removeFirst(){
  SLNode *removed;
  void* out;
  if(!this->isEmpty()){
    out = this->first->getData();
    removed = this->first;
    this->first = this->first->getNext();
    delete []removed;
    (this->len)--;
    return out;
  }
  return NULL;
}

void* SLList::query(void* key, bool(*cmp)(void*, void*)){
  SLNode *cur;
  bool found;
  
  if(!(this->isEmpty())){
    cur = this->first;
    found = cmp(cur->getData(), key);
    while(cur->hasNext() && !found){
      cur = cur->getNext();
      found = cmp(cur->getData(), key);
    }
    if(found){
      return (cur->getData());
    }
  }
  return NULL;
}

int SLList::getLen(){
  return (this->len);
}

void* SLList::remove(void* key, bool(*cmp)(void*, void*)){
  SLNode *cur, *prev;
  bool found;
  void* out;
  
  if(!(this->isEmpty())){
    prev = NULL;
    cur = this->first;
    found = cmp(cur->getData(), key);
    while(cur->hasNext() && !found){
      prev = cur;
      cur = cur->getNext();
      found = cmp(cur->getData(), key);
    }
    if(found){
      out = cur->getData();
      if(prev == NULL){
	this->first = this->first->getNext();
      }else{
	prev->setNext(cur->getNext());
      }
      delete []cur;
      (this->len)--;
      return out;
    }
  }
  return NULL;
}
