#include <unistd.h>
#include "ABP.h"
#include <string.h>
NodoABP *auxiliar;
int contador=0;
ABP::ABP ()
{
  cont =0;
  Raiz = NULL;
}
NodoABP* ABP::getRaiz()
{
  return Raiz;
}

int CalculaQtdDeFolhas();
int ABP::CalculaGrauNodo(NodoABP *n)
{
  int grau = 0;
  if (n->esq != NULL)
    grau ++;
  if (n->dir != NULL)
    grau ++;
return grau;
}
// ***********
int ABP::max(int a, int b)
{
  if (a>b)
    return a;
  else return b;    
}
// ************************************
void ABP::insere(int n)
{
  Raiz = insere(Raiz,n);
}
// ************************************
NodoABP* ABP::insere(NodoABP *nodo, int n)
{
  if(Raiz == NULL){
    NodoABP *aux;
    aux = new NodoABP(n);
    return aux;
  }
  if (nodo == NULL) { // encontrou o local para inserir
    NodoABP *aux;
    //cout<<"inseri o = "<<n<<endl;
    aux = new NodoABP(n);
    //cout<<"auxiliar= "<<auxiliar->info<<endl;
    aux->pai = auxiliar;
    AchaNivel(aux);
    return aux;
  }
  else {
    
          if (n <= nodo->info){
            auxiliar = nodo;
            nodo->esq =  insere(nodo->esq, n);
          }
          else{ 
            auxiliar= nodo;
            nodo->dir = insere(nodo->dir, n);
          }
    }
    return nodo;
}
// ************************************
void ABP::AchaNivel(NodoABP *nodo){
  NodoABP *aux = nodo;
  int contador=0;
  while(nodo != Raiz){
    nodo = nodo->pai;
    contador++;
    aux->nivel = contador;
  }
}
// ************************************
int ABP::ABP::CalculaProfundidadeDaArvore()
{
  return CalculaProfundidade(Raiz); 
}
// ************************************
int ABP::CalculaProfundidade(NodoABP *n)
{ 
  int alturaEsq, alturaDir;
  if (n != NULL)
  {
    alturaEsq = CalculaProfundidade(n->esq);
    alturaDir = CalculaProfundidade(n->dir);
    return 1 + max (alturaEsq, alturaDir);
  }
  else return 0;
}
// ************************************
int ABP::EncontraMenor() {
  NodoABP *aux = Raiz;
    // loop down to find the leftmost leaf
    while (aux->esq != NULL) 
    {
      aux = aux->esq;
    }
  return(aux->info);
}
// ************************************
NodoABP* ABP::UltimoEsq() {
  NodoABP *aux = Raiz;
    while (aux->esq != NULL) 
    {
      aux = aux->esq;
    }
  return(aux);
}
// ************************************
NodoABP* ABP::UltimoDir() {
  NodoABP *aux = Raiz;
    while (aux->dir != NULL) 
    {
      aux = aux->dir;
    }
  return(aux);
}
// ************************************
NodoABP* ABP::busca (int n) 
{
  return busca(Raiz, n);
}
// ************************************
void ABP::Busca_ImprimeNodo(int n)
{
  NodoABP* aux;
  aux = busca(n);
  if (aux == NULL)
    cout << "Nao achou" << endl;
  else
  {
    cout << "Achou aqui:" << endl;
    aux->imprime();
  }
}
// ************************************
NodoABP* ABP::busca(NodoABP *nodo, int n) 
{
  if (nodo == NULL || nodo->info == n)
      return nodo;
  if (nodo->info > n)
      return busca (nodo->esq, n);
  else
      return busca (nodo->dir, n);
}
// ************************************
void ABP::CaminhaCENTRAL()
{
  cout << "Caminhamento Central: ";
  
  CaminhaCENTRAL(Raiz);
  cout << endl;
}
// ************************************
void ABP::CaminhaCENTRAL(NodoABP *nodo)
{
  if(nodo == NULL) return;
  CaminhaCENTRAL(nodo->esq);
  cout << nodo->info << " ";
  CaminhaCENTRAL(nodo->dir);

}
// ************************************
void ABP::GeraConexoesDOT(NodoABP *nodo)
{
    if(nodo == NULL) return;
    GeraConexoesDOT(nodo->esq);
    //   "nodeA":dir -> "nodeB";
    if (nodo->esq)
        cout << "\"node" << nodo->info << "\":esq -> \"node" << nodo->esq->info << "\"" <<endl;
    GeraConexoesDOT(nodo->dir);
    if (nodo->dir)
        cout << "\"node" << nodo->info << "\":dir -> \"node" << nodo->dir->info << "\""<<endl;
}

void ABP::GeraNodosDOT(NodoABP *nodo)
{
    if(nodo == NULL) return;
    GeraNodosDOT(nodo->esq);
    //node10[label = "<esq> | 10 | <dir> "];
    cout << "node" << nodo->info << "[label = \"<esq> | " << nodo->hesq << " | " <<nodo->info <<" | " << nodo->hdir << " | <dir> \"]" <<endl;
    GeraNodosDOT(nodo->dir);
}


void ABP::GeraNodosDOT()
{
    GeraNodosDOT(Raiz);
}
void ABP::GeraConexoesDOT()
{
    GeraConexoesDOT(Raiz);
}
void ABP::GeraDOT()
{
  if(cont== 0)return;
    cout << "digraph g { \nnode [shape = record,height=.1];\n" << endl;
    GeraNodosDOT();
    cout << endl;
    GeraConexoesDOT();
    cout << "}" << endl;
}
// ************************************
void ABP::CaminhaPRE()
{
  cout << "Caminhamento Pré Fixado: ";
  CaminhaPRE(Raiz);
  cout << endl;
}
// ************************************
void ABP::CaminhaPRE(NodoABP *nodo)
{
  if(nodo == NULL) return;
  cout << nodo->info << " ";
  CaminhaPRE(nodo->esq);
  CaminhaPRE(nodo->dir);  
}
// ************************************
void ABP::CaminhaPOS(NodoABP *nodo)
{
  if(nodo == NULL) return;
  CaminhaPOS(nodo->esq);
  CaminhaPOS(nodo->dir);  
  cout << nodo->info << " ";
}

void ABP::BalancaDD(NodoABP *nodo){
  NodoABP *no = nodo->dir,*auxiliar = nodo->dir->esq;
  nodo->dir == NULL ? (no = nodo->esq,auxiliar = nodo->esq->esq): no;
  if(nodo->info == Raiz->info){// é raiz?
    no->esq = nodo;
    nodo->pai = no;
    no->pai = NULL;
   auxiliar==NULL ? nodo->dir = NULL : nodo->dir = auxiliar;
    Raiz = no;
  }
  else{ //não é raiz
    no->pai = nodo->pai;
    if(nodo->pai->dir == NULL)nodo->pai->esq = no;
    else{
      nodo->info == nodo->pai->dir->info ?nodo->pai->dir = no :nodo->pai->esq = no;
    }
    nodo->pai = no;
    no->esq = nodo;
    auxiliar==NULL ? nodo->dir = NULL : nodo->dir = auxiliar;
  }
}

void ABP::BalancaEE(NodoABP *nodo){
  NodoABP *no = nodo->esq,*auxiliar = nodo->esq->dir;
  nodo->esq == NULL ? (no = nodo->dir,auxiliar = nodo->dir->dir): no;
  if(nodo->info == Raiz->info){// é raiz?
    no->dir = nodo;
    nodo->pai = no;
    no->pai = NULL;
    auxiliar==NULL ? nodo->esq = NULL : nodo->esq = auxiliar; 
    Raiz = no;
  }
  else{ //não é raiz
    no->pai = nodo->pai;
    if(nodo->pai->esq == NULL)nodo->pai->dir = no;
    else{
      nodo->info == nodo->pai->esq->info ?nodo->pai->esq = no :nodo->pai->dir = no;
    }
    nodo->pai = no;
    no->dir = nodo;
    auxiliar==NULL ? nodo->esq = NULL : nodo->esq = auxiliar; 
  }
}

void ABP::AchaFB(){
  AchaFB(Raiz);  // começa sempre pela raiz
}

void ABP::AchaFB(NodoABP *nodo){
  if(nodo == NULL) return;
  achaaltura(nodo); // vai atualizar as alturas
  nodo->FB = nodo->hesq - nodo->hdir;  // calculo do fator de balanceamento, pega a altura da esquerda e diminui da direita
  //cout<<"Nodo = "<<nodo->info << " FB= "<<nodo->FB<<endl;
  AchaFB(nodo->esq); // recursao
  AchaFB(nodo->dir); // recursao
}

NodoABP *ABP::achaaltura(NodoABP *nodo){
  nodo->hesq = CalculaProfundidade(nodo->esq);
  nodo->hdir = CalculaProfundidade(nodo->dir);
  return nodo;
}

NodoABP *ABP::acha_desbalanceamento(NodoABP *nodo){
  //GeraDOT();
  if(nodo == NULL){
    return nodo;
  }
  if(nodo->esq != NULL && nodo->FB >= 2 && nodo->esq->FB == -1){//balanc. esq/dir
		return nodo;
  }
  else if(nodo->dir != NULL && nodo->FB <= -2 && nodo->dir->FB == 1){//balanc. dir/esq
		return nodo;
	}
  else if(nodo->FB >= 2){//balan. esq/esq
		return nodo;
	}
  else if(nodo->FB <= -2){//balan. dir/dir
		return nodo;
	}
  else{
      if(nodo->esq == NULL && nodo->dir !=NULL){//se o nodo esquerdo for nulo e o do direito não, a varivavel nodo vai pegar o nodo direito e retornar
        nodo = acha_desbalanceamento(nodo->dir);
        return nodo;
      }
      else if(nodo->esq != NULL && nodo->dir == NULL){//se o nodo direito for nulo e o do esquerdo não, a varivavel nodo vai pegar o nodo esquerdo e retornar
        nodo = acha_desbalanceamento(nodo->esq);
        return nodo;
      }
      else{ // se nenhuma das situações acima forem concluidas
        if(nodo != Raiz){ // se o nodo for diferente da raiz ele pega o pai dele
          nodo = nodo->pai;
          return nodo;
        }
         else{ // se for a raiz, ele vai ver se na direita é nulo, se for ele retorna         
          if(nodo->esq != NULL)nodo = acha_desbalanceamento(nodo->esq);
          if(nodo->dir != NULL)nodo = acha_desbalanceamento(nodo->dir);
      }
     return nodo;
      }
  }
}


void ABP::AplicaBalancemento(){  
  while(1){
    AchaFB();
    GeraDOT();
    NodoABP *aux = acha_desbalanceamento(Raiz);
    if(aux->FB >= 2 && aux->esq->FB == -1){//balanc. esq/dir
      BalancaDD(aux->esq);
      BalancaEE(aux);
      AplicaBalancemento();
    }
    else if(aux->FB <= -2 && aux->dir->FB == 1){//balanc. dir/esq
      BalancaEE(aux->dir);
      BalancaDD(aux);
      AplicaBalancemento();
    }
    else if(aux->FB <= -2 ){//balan. dir/dir
      BalancaDD(aux);
      AplicaBalancemento();
    }
    else if(aux->FB >= 2 ){//balan. esq/esq
      BalancaEE(aux);
      AplicaBalancemento();
    }
    return;
  }
}

void ABP::Destroi_Nodos(){
  Destroi_Nodos(Raiz);
}

NodoABP* ABP::Destroi_Nodos(NodoABP *n)
{
    if(n == NULL){
      Raiz= NULL;
      return n;
    }
    Destroi_Nodos(n->esq);
    Destroi_Nodos(n->dir);
    n->pai = NULL;
    n->esq = NULL;
    n->dir= NULL;
    delete n;
  return n;
}

int ABP::qtdenodo(){
  cont =0;
  qtdenodo(Raiz);
  return cont;
}

NodoABP *ABP::qtdenodo(NodoABP *n){
  if (n == NULL) return n;
      qtdenodo(n->esq);
      qtdenodo(n->dir);
      cont++;
  return n;    
}

void ABP::Remove(NodoABP *aux){
  NodoABP *pai = aux->pai;
  NodoABP *nodo = aux;
  if(aux->esq == NULL && aux->dir == NULL ){
    pai->esq == aux?(pai->esq=NULL, delete aux) : (pai->dir=NULL,delete aux);
    return;
  }
  else{
    if(nodo->esq!=NULL ){ //trocar pelo maior nodo a esq da arvore
      nodo = nodo->esq;
      while(nodo->dir!=NULL)nodo=nodo->dir;
    }

    else{ // trocar pelo menor nodo a direita da arvore
      nodo = nodo->dir;
      while(nodo->esq!=NULL)nodo=nodo->esq;
    }
    
    if( aux == Raiz){
      pai = nodo->pai;
       pai->esq == nodo? pai->esq=NULL : pai->dir=NULL;
       nodo->pai = NULL;
       pai = Raiz->esq;
       pai->pai = nodo;
       pai = Raiz->dir;
       pai->pai = nodo;
       nodo->esq = Raiz->esq;
       nodo->dir = Raiz->dir;
       Raiz = nodo;
       delete aux;
      return;  
    } 
    else{
      nodo->pai = aux->pai;
      if(aux->dir != nodo && aux->dir !=NULL){
        nodo->dir = aux->dir;
        nodo->dir = NULL;
        pai = aux->pai;
        pai->esq == aux ? pai->esq = nodo : pai->dir = nodo; 
        delete aux;
        return;
      }
      nodo->esq = aux->esq;
      nodo->esq = NULL;
      pai = aux->pai;
      pai->esq == aux ? pai->esq = nodo : pai->dir = nodo; 
    }
  }
  delete aux; 
}
