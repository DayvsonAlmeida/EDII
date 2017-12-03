#include "BSTree.h"
#include <stdlib.h>

BSTree::BSTree(){
  root = NULL;
}

bool BSTree::isEmpty(){
  if(root == NULL)
    return true;
  return false;
}

void BSTree::inorder(BSNode *t, void (*visit)(void*)){
  if(t==NULL) return;
  inorder(t->left, visit);
  visit(t->data);
  inorder(t->right, visit);
}

void BSTree::preorder(BSNode *t, void (*visit)(void*)){
  if(t==NULL) return;
  visit(t->data);
  inorder(t->left, visit);
  inorder(t->right, visit);
}

void BSTree::posorder(BSNode *t, void (*visit)(void*)){
  if(t==NULL) return;
  inorder(t->left, visit);
  inorder(t->right, visit);
  visit(t->data);
}

void BSTree::insert(void* data, int (*cmp)(void*, void*)){
  BSNode *newNode, *cur, *parent;
  newNode = new BSNode[1];
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  
  if(isEmpty()){
    this->root = newNode;
  }else{
    cur = root;
    while(cur!=NULL){
      parent = cur;
      if(cmp(cur->data, data) <= 0){ //Dado maior que o elemento, descer à direita
	cur = cur->right;
      }else{
	cur = cur->left;
      }
    }
    if(cmp(parent->data, data) <= 0){ //Inserir à direita
      parent->right = newNode;
    }else{
      parent->left = newNode;
    }
  }
}

void* BSTree::query(void* key, int (*cmp)(void*, void*)){
  BSNode *t;
  void* out = NULL;

  t = root;
  while(t!=NULL){
    if(cmp(t->data, key) == 0){
      out = t->data;
      break;
    }
    if(cmp(t->data, key) < 0) //Buscar na direita
      t = t->right;
    else
      t = t->left;
  }
  return out;
}
