#ifndef INVERTED_INDEX_H
#define INVERTED_INDEX_H
#include <string.h>

/*
 * NÃO EXISTE ID 0
 */
class InvertedIndex{
 private:
  char *word;
  int *frequency, *id_doc; //Id = 0 representa uma posição vazia, id>0
  int max; //Max indica a quantidade de arquivos da coleção
  int filled; //Filled indica quantos documentos já foram inseridos
 public:
  //Construtores
  InvertedIndex();
  InvertedIndex(char* word, int max, int id);
  //Métodos
  char* getWord();
  void setWord(char* str);
  int* getFrequency();
  void setFrequency(int *f);
  int* getIds();
  void setIds(int *ids);
  int getFilled();
  void setFilled(int f);
  int getMax();
  void setMax(int max);

  int getFrequencyId(int id);
  void setFrequencyId(int f, int id);
  void addFrequencyId(int id);
  void subFrequencyId(int id);
  void initDoc(int id);
};

#endif
