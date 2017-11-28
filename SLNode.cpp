#include "SLNode.h"
#include <stdlib.h>
#include <iostream>

SLNode::SLNode(){
  this->data = NULL;
  this->next = NULL;
}

SLNode::SLNode(void* new_data){
  this->data = new_data;
  this->next = NULL;
}

void SLNode::setData(void* new_data){
  this->data = new_data;
}

void* SLNode::getData(){
  return this->data;
}

void SLNode::setNext(SLNode *new_next){
  this->next = new_next;
}

SLNode* SLNode::getNext(){
  if(this->next!=NULL)
    return this->next;
  else
    return NULL;
}

bool SLNode::hasNext(){
  if(this->next != NULL)
    return true;
  else
    return false;
}
