#include <iostream>
#include "SLList.h"
#include "InvertedIndex.h"
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

char** alocar(int tamCol);
SLList* indexListCreate(char** arquivos, int tamCol, int C);

int main(){
  char** arquivos;
  SLList *indexList;
  int tamCol, c;

  //Inicialização dos caminhos
  cout << "Informe a quantidade de arquivos: ";
  cin >> tamCol;
  arquivos = alocar(tamCol);
  cout << "Informe os caminhos:\n";
  for(int i=0; i<tamCol; i++){
    cout << i+1 << ": ";
    cin >> arquivos[i];
  }
  cout << "Valor para C: ";
  cin >> c;
  indexList = indexListCreate(arquivos, tamCol, c); //Recebendo lista de indices invertidos
  //Fim da Aquisição dos indíces

  //
  InvertedIndex *aux;
  cout << "\n\n\n\n";
  while(!indexList->isEmpty()){
    int* id_doc, *frequency;
    aux = (InvertedIndex*)indexList->removeFirst();
    if(aux!=NULL){
      cout << aux->getWord() << endl;
      id_doc = aux->getIds();
      frequency = aux->getFrequency();
      for(int i=0; i<aux->getFilled(); i++){
	cout << "doc <" << arquivos[id_doc[i]-1] << "> count: "<< frequency[i] << endl;
      }
    }
  }
  return 0;
}

char** alocar(int tamCol){
  char** tmp;
  tmp = new char*[tamCol];
  for(int i=0; i<tamCol; i++)
    tmp[i] = new char[100];
  return tmp;
}

bool cmpString(void* elm, void* key){
  InvertedIndex *indice = (InvertedIndex*)elm;
  char* palavra = (char*)key;
  if(strcmp(indice->getWord(), palavra) == 0)
    return true;
  return false;
}

SLList* indexListCreate(char** arquivos, int tamCol, int C){
  InvertedIndex *newIndex, *aux_index;
  SLList *indexList;
  ifstream in;
  string auxstr;
  char *linha, *palavra, *newPalavra;
  int qtd;

  //Incialização da lista
  indexList = new SLList[1];
  *indexList = SLList();
  for(int i=0; i<tamCol; i++){
    in.open(arquivos[i]);
    //Extração das linhas
    while(!in.eof()){
      getline(in, auxstr); //Extração da primeira linha
      linha = (char*)auxstr.c_str();
      if(in.eof()) break;
      //Quebra em palavras
      palavra = strtok(linha, " ,.()[]!?");
      while(palavra!=NULL){
	//Checagem se já existe um indice com a palavra
	if(strlen(palavra)>=C){
	  aux_index = (InvertedIndex*)indexList->query((void*)palavra, cmpString);
	  if(aux_index!=NULL){ //Existe um indice com essa palavra
	    aux_index->addFrequencyId(i+1); //Conta +1 para o doc
	  }else{ //Não existe um indice com essa palavra
	    newIndex = new InvertedIndex[1];
	    newPalavra = new char[strlen(palavra)];
	    strcpy(newPalavra, palavra);
	    *newIndex = InvertedIndex(newPalavra, tamCol, i+1);
	    indexList->insertFirst((void*)newIndex);
	  }
	}
	palavra = strtok(NULL, " ,.()[]!?"); //Próxima palavra
      }
    }
    in.close();
  }
  return indexList;
}
