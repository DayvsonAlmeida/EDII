#ifndef BSTREE_H
#define BSTREE_H

typedef struct _bstnode_{
  struct _bstnode_ *left, *right;
  void* data;
}BSNode;

class BSTree{
 public:
  BSNode *root;
  BSTree();
  bool isEmpty();
  void inorder(BSNode *t, void (*visit)(void*));
  void preorder(BSNode *t, void (*visit)(void*));
  void posorder(BSNode *t, void (*visit)(void*));
  void insert(void* data, int (*cmp)(void*, void*));
  void* query(void* key, int (*cmp)(void*, void*));
};

#endif
