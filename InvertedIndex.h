#ifndef INVERTED_INDEX_H
#define INVERTED_INDEX_H
#include <string.h>

class InvertedIndex{
 private:
  char *word;
  int *frequency, *id_doc;
  int max, filled;
 public:
  //Construtores
  InvertedIndex();
  InvertedIndex(std::string, int max, int id_doc);
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

  
};

#endif
