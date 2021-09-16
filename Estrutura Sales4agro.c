
#include <stdio.h>
#include <string.h>
#define MAX 5
#define ERRO -1
#define true 1
#define false 0


typedef int bool;

typedef int ANUNCIOID;
typedef int TIPO;
typedef char TITULO[15];
typedef char USUARIO[15];

typedef struct{
ANUNCIOID identificador;
TIPO tipo;
TITULO titulo;
USUARIO usuario;
} ANUNCIO;

typedef struct {
  ANUNCIO A[MAX+1];
  int nroElem;
} LISTA;



void inicializarLista(LISTA *l){
  l->nroElem = 0;
} 


void exibirLista(LISTA *l){
  int i;
  printf("Anuncios: \n\n");
  for (i=0; i < l->nroElem; i++){
    printf("ID: %d\n", l->A[i].identificador);
	printf("Tipo: %d\n", l->A[i].tipo);
	printf("Titulo: %s\n", l->A[i].titulo);
	printf("Usuario: %s", l->A[i].usuario);
	printf("\n\n\n"); 
  }
} 



int tamanho(LISTA *l) {
  return(l->nroElem);
} 



int tamanhoEmBytes(LISTA *l) {
  return(sizeof(LISTA));
} 




void destruirLista(LISTA *l) {
  l->nroElem = 0;
} 



bool inserirElemLista(ANUNCIO anu, int i, LISTA *l){
  int j;
  if ((l->nroElem >= MAX) || (i < 1) || (i > (l->nroElem+1))) {
    return(false); 
  }
  if((l->nroElem > 0) && (i < l->nroElem+1)){
    for (j = l->nroElem; j >= i; j--) {
       l->A[j] = l->A[j-1];
       }
  }   
  l->A[i-1] = anu;
  l->nroElem++;
  return(true);
}




int buscaSeq(ANUNCIOID id, LISTA *l) {
  int i = 0;
  while (i < l->nroElem){
    if(id == l->A[i].identificador) {
          return(i); 
    }
    else {
         i++;
    }
  }
  return(ERRO);
} 



bool inserirElemListaOrd(ANUNCIO anu, LISTA *l) {
  int i = 0;
  ANUNCIOID id = anu.identificador;
  if(l->nroElem >= MAX) {
    return(false);
  }
  l->A[l->nroElem].identificador = id;
  
  while(l->A[i].identificador < id) {
    i++;
  } 
  
  if((l->A[i].identificador == id) && (i < l->nroElem)) {
    return(false); 
  }
  else {
    return(inserirElemLista(anu, i+1, l));
  }
} 


bool excluirElemLista(ANUNCIOID id, LISTA *l) { 
  int pos, j;
  pos = buscaSeq(id, l);
  if(pos == ERRO) {
    return(false);
  }
  for(j = pos; j < l->nroElem-1; j++) {
    l->A[j] = l->A[j+1];
  }
  l->nroElem--;
  return(true);
} 
