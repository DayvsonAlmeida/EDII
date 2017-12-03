#ifndef AVLTREE_H
#define AVLTREE_H

//Estrutura do Nó
typedef struct _avlnode_{
  void* data;
  struct _avlnode_ *left;
  struct _avlnode_ *right;
}AVLNode;

//Declaração da Classe
class AVLTree{
 public:
  AVLNode *root;  
  int height(AVLNode *t);
  int diff(AVLNode *t);
  AVLNode *rr_rotation(AVLNode *parent);
  AVLNode *ll_rotation(AVLNode *parent);
  AVLNode *lr_rotation(AVLNode *parent);
  AVLNode *rl_rotation(AVLNode *parent);
  AVLNode* balance(AVLNode *t);
  AVLNode* insert(AVLNode *root, void* value, int (*cmp)(void*, void*));
  void inorder(AVLNode *t, void (*visit)(void*));
  void preorder(AVLNode *t, void (*visit)(void*));
  void postorder(AVLNode *t, void (*visit)(void*));
  void* query(AVLNode *t, void* key, int (*cmp)(void*, void*));
  AVLTree();
};

#endif
