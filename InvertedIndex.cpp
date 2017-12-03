#include "InvertedIndex.h"
#include <stdlib.h>

InvertedIndex::InvertedIndex(){
  this->word = NULL;
  this->frequency = NULL;
  this->id_doc =  NULL;
  this->max = this->filled = 0;
}

InvertedIndex::InvertedIndex(char* word, int max, int id){
  InvertedIndex();
  if(max>0 && id>0){
    this->word = word;
    this->max = max;
    this->frequency = new int[max];
    this->id_doc = new int[max];
    for(int i=0; i<max; i++)
      this->frequency[i] = this->id_doc[i] = 0;
    this->filled = 1;
    this->frequency[0] = 1;
    this->id_doc[0] = id;
  }
}

char* InvertedIndex::getWord(){
  return this->word;
}

void InvertedIndex::setWord(char* str){
  this->word = str;
}

int* InvertedIndex::getFrequency(){
  return this->frequency;
}

void InvertedIndex::setFrequency(int *f){
  this->frequency = f;
}

int* InvertedIndex::getIds(){
  return this->id_doc;
}

void InvertedIndex::setIds(int *ids){
  this->id_doc = ids;
}

int InvertedIndex::getFilled(){
  return this->filled;
}

void InvertedIndex::setFilled(int f){
  this->filled = f;
}

int InvertedIndex::getMax(){
  return this->max;
}

void InvertedIndex::setMax(int max){
  this->max = max;
}

int InvertedIndex::getFrequencyId(int id){
  if(id>0){
    for(int i=0; i<this->filled; i++){
      if(id == this->id_doc[i]){
	return this->frequency[i];
      }
    }
  }
  return -1;
}

void InvertedIndex::setFrequencyId(int f, int id){
  if(f>0 && id>0){
    for(int i=0; i<this->filled; i++){
      if(this->id_doc[i] == id){
	this->frequency[i] = f;
	return;
      }
    }
  }
}

void InvertedIndex::addFrequencyId(int id){
  if(id>0){
    for(int i=0; i<this->filled; i++){
      if(this->id_doc[i] == id){
	(this->frequency[i])++;
	return;
      }
    }
    this->id_doc[this->filled] = id;
    this->frequency[this->filled] = 1;
    (this->filled)++;
  }
}

void InvertedIndex::subFrequencyId(int id){
  if(id>0){
    for(int i=0; i<this->filled; i++){
      if(this->id_doc[i]==id){
	if(this->frequency[i]>0){
	  (this->frequency[i])--;
	  return;
	}
      }
    }
  }
}

void InvertedIndex::initDoc(int id){
  if(id>0){
    if(this->filled < this->max){
      for(int i=0; i<this->filled; i++){
	if(this->id_doc[i] == id)
	  return;
      }
      this->frequency[this->filled] = 1;
      this->id_doc[this->filled] = id;
      (this->filled)++;
    }
  }
}
