#ifndef _NodoABP
#define _NodoABP

class NodoABP{
  public:
    int info;
    int nivel;
    int FB; // Fator de Balanceamento
    NodoABP *pai;
    NodoABP *esq;
    NodoABP *dir;
    int hesq;
    int hdir;
    
    NodoABP(int dado);
    void imprime();
};
#endif