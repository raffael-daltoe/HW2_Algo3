
#ifndef _ARVBIN
#define _ARVBIN
#include <iostream>
using namespace std;

#include "NodoABP.h"

class ABP 
{
  int cont;
  NodoABP *Raiz;

  int max(int a, int b);
  NodoABP *insere(NodoABP *nodo, int n);
  int CalculaProfundidade(NodoABP *n);
  NodoABP *busca(NodoABP *nodo, int n); 
  void CaminhaCENTRAL(NodoABP *nodo);
  void CaminhaPRE(NodoABP *nodo);
  void CaminhaPOS(NodoABP *nodo);
  void GeraConexoesDOT(NodoABP *nodo);
  void GeraNodosDOT(NodoABP *nodo);
  void AchaNivel(NodoABP *nodo);
  void AchaFB(NodoABP *nodo);
  int Profundidade(NodoABP *nodo,int x);
  NodoABP * achaaltura(NodoABP *nodo);
  NodoABP *acha_desbalanceamento(NodoABP *nodo);
  NodoABP* qtdenodo(NodoABP *nodo);  
  NodoABP* Destroi_Nodos(NodoABP *nodo);
  void BalancaDD(NodoABP *aux);
  void BalancaEE(NodoABP *aux);
  NodoABP* UltimoEsq();
  NodoABP* UltimoDir();
  //NodoABP* VerificaBalanceamento(NodoABP *nodo);
public:
  ABP ();
  NodoABP* getRaiz();
  int Diferenca(NodoABP *n);
  int CalculaQtdDeFolhas();
  int CalculaGrauNodo(NodoABP *n);
  void insere(int n);
  int CalculaProfundidadeDaArvore();
  int EncontraMenor();
  NodoABP* busca (int n);
  void Busca_ImprimeNodo(int n);
  void CaminhaCENTRAL();
  void CaminhaPRE();
  void GeraConexoesDOT();
  void GeraNodosDOT();
  void GeraDOT();
  void AplicaBalancemento();
  void AchaFB();
  void Destroi_Nodos();
  int qtdenodo();
  void Remove(NodoABP *aux);
};
#endif 
