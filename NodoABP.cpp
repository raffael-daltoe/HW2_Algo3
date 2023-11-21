#include <iostream>
using namespace std;

#include "NodoABP.h"

NodoABP::NodoABP(int dado)
{
  esq = NULL;
  dir = NULL;
  pai = NULL;
  hesq= 0;
  hdir= 0;
  info = dado; 
}  
void NodoABP::imprime()
{
  cout << "Nodo: " << info << endl;
  cout << "\tEsq: ";
  if (esq != NULL)
    cout << esq->info;
  else cout << "NULL";
  cout << endl;

  cout << "\tDir: ";
  if (dir != NULL)
    cout << dir->info;
  else cout << "NULL";
  cout << endl;
}