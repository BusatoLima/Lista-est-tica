
#include <stdio.h>
#include <string.h>
#include "Estrutura Sales4agro.c"


void inserir(LISTA *l){
  ANUNCIOID id;
  TIPO tp;
  TITULO titu;
  USUARIO usua;
  
  printf("Anuncio ID: ");scanf("%d",&id);
  printf("Tipo: ");scanf("%d",&tp);
  printf("Titulo: ");scanf("%s",&titu);
  printf("Usuario: ");scanf("%s",&usua);
  printf("\n");
  ANUNCIO anu;
  anu.identificador = id;
  anu.tipo = tp;
  strcpy(anu.titulo,titu);
  strcpy(anu.usuario,usua);
  
  if (inserirElemListaOrd(anu,l)) {
    printf("%s inserido corretamente.\n",titu);
  }
  else {
    printf("Nao foi possivel inserir.\n");
  }
  
  
}

void excluir(LISTA *l){
  ANUNCIOID id;
  scanf("%d",&id);
  if (excluirElemLista(id,l)) {
    printf("Anuncio %d excluido corretamente.\n",id);
  }
  else {
    printf("Nao foi possivel excluir anuncio %d.\n",id);
  }  
}

void imprimir_elementos(LISTA *l){
  exibirLista(l);
}

void exibir_detalhes_lista(LISTA *l){
  printf("Numero de anuncios na lista: %d.\n",tamanho(l));
  printf("Tamanho da lista (em bytes): %d.\n",tamanhoEmBytes(l));
}


void destruir(LISTA *l){
     destruirLista(l);
     printf("Lista zerada.\n");
}


int main(){
  LISTA lista;
  inicializarLista(&lista);
  int opcao;
  while (opcao != 6) {
  system("cls");
  printf("SALES4AGRO\n\n");
  printf("MENU\n");
  printf("1 : Inserir anuncio \n");
  printf("2 : Excluir um anuncio \n");
  printf("3 : Imprimir valores da lista\n");
  printf("4 : Destruir (zerar) lista\n");
  printf("5 : Exibir log de utilizacao da lista\n");
  printf("6 : SAIR \n");
  printf("Digite a opcao desejada: ");
  scanf("%d",&opcao);
  switch (opcao) {
      case 1 : inserir(&lista); break;
      case 2 : excluir(&lista); break;
      case 3 : imprimir_elementos(&lista); break;
      case 4 : destruir(&lista); break;
      case 5 : exibir_detalhes_lista(&lista); break;
    }  
  printf("Pressione qualquer tecla para continuar....\n");
  getch();
  } 
 
  return 0;
}
