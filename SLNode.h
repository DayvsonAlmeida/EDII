#ifndef SLNode_H
#define SLNode_H

class SLNode{
 private:
  void* data;
  SLNode *next;
 public:
  //Construtores
  SLNode();
  SLNode(void* data);
  //Métodos
  void setData(void* new_data);
  void* getData();
  void setNext(SLNode *new_next);
  SLNode* getNext();
  bool hasNext();  
};
#endif
