#include "avlTree.h"
#include <stdlib.h>

AVLTree::AVLTree(){
  root = NULL;
}

int max(int a, int b){
  if(a>b)
    return a;
  else
    return b;
}

//Altura
int AVLTree::height(AVLNode *t){
  int h = 0;
  if (t != NULL){
    int hl = height(t->left);
    int hr = height(t->right);
    int hmax = max(hl, hr);
    h = hmax + 1;
  }
  return h;
}
 
//Fator de balanceamento 
int AVLTree::diff(AVLNode *t){
  int hl = height(t->left);
  int hr = height(t->right);
  int bfactor= hl - hr;
  return bfactor;
}
 

//Right- Right Rotation (Simples à Esquerda)
AVLNode *AVLTree::rr_rotation(AVLNode *parent){
  AVLNode *temp;

  temp = parent->right;
  parent->right = temp->left;
  temp->left = parent;
  return temp;
}

//Left- Left Rotation (Simples à Direita)
AVLNode *AVLTree::ll_rotation(AVLNode *parent){
  AVLNode *temp;

  temp = parent->left;
  parent->left = temp->right;
  temp->right = parent;
  return temp;
}
 
//Left - Right Rotation (Dupla à Direita)
AVLNode *AVLTree::lr_rotation(AVLNode *parent){
  AVLNode *temp;
  temp = parent->left;
  parent->left = rr_rotation(temp);
  return ll_rotation(parent);
}
 
//Right- Left Rotation (Dupla à Esquerda)
AVLNode *AVLTree::rl_rotation(AVLNode *parent){
  AVLNode *temp;
    
  temp = parent->right;
  parent->right = ll_rotation(temp);
  return rr_rotation(parent);
}
 

//Balanceamento
AVLNode *AVLTree::balance(AVLNode *t){
  int bfactor = diff (t);
    
  if(bfactor > 1){ //Esquerda mais pesada
    if(diff(t->left) > 0) //Rotação Simples à Direita
      t = ll_rotation(t);
    else //Rotação Dupla à Direita
      t = lr_rotation(t);
  }else if(bfactor < -1){ //Direita mais pesada
    if(diff(t->right) > 0) //Rotação Dupla à Esquerda
      t = rl_rotation(t);
    else //Rotação Simples à Esquerda
      t = rr_rotation(t);
  }
  return t;
}
 
//Inserir elemento
AVLNode *AVLTree::insert(AVLNode *root, void* value, int (*cmp)(void*, void*)){
 
  if(root == NULL){ //Se árvore vazia
    root = new AVLNode[1];
    root->data = value;
    root->left = NULL;
    root->right = NULL;
    return root;
  }else if(cmp(root->data, value) > 0){ //Value menor que o elemento do nó
    root->left = insert(root->left, value, cmp);
    root = balance(root);
  }else if (cmp(root->data, value) <= 0){ //Value maior ou igual ao elemento do nó
    root->right = insert(root->right, value, cmp);
    root = balance(root);
  }
  return root;
}
 
//Simétrico
void AVLTree::inorder(AVLNode *t, void (*visit)(void*)){
  if(t == NULL)
    return;
  inorder(t->left, visit);
  visit(t->data);
  inorder(t->right, visit);
}

//Pré Ordem
void AVLTree::preorder(AVLNode *t, void (*visit)(void*)){
  if (t == NULL)
    return;
  visit(t->data);
  preorder(t->left, visit);
  preorder(t->right, visit);
}
 
//Pós Ordem
void AVLTree::postorder(AVLNode *t, void (*visit)(void*)){
  if (t == NULL)
    return;
  postorder( t->left, visit);
  postorder( t->right, visit);
  visit(t->data);
}

void* AVLTree::query(AVLNode *t, void* key, int (*cmp)(void*, void*)){
  if(t == NULL)
    return NULL;
  if(cmp(t->data, key) == 0)
    return t->data;
  if(cmp(t->data, key)>0) //key menor que o nó
    return (query(t->left, key, cmp));
  else //key maior que o nó
    return (query(t->right, key, cmp));
}
