// Site = https://dreampuf.github.io/GraphvizOnline/

#include <fstream>
#include <iostream>
using namespace std;

#include "ABP.h"
void imprime() {
	cout << endl;
	cout << "[0]. Para sair." << endl;
	cout << "[1]. Para inserir um nodo a arvore." << endl;
	cout << "[2]. Para inserir uma sequencia de nodos a arvore." << endl;
	cout << "[3]. Para gerar o DOT da arvore." << endl;
	cout << "[4]. Para realizar o balanceamento da arvore." << endl;
	cout << "[5]. Para importar nodos de um arquivo .txt." << endl;
	cout << "[6]. Para destruir todos os nodos." << endl;
	cout << "[7]. Para informar os nodos alocados." << endl;
	cout << "[8]. Para fazer o caminhamentoPos." << endl;
	cout << "Escolha: ";
}

int main() {
	ABP B;
	int tmp;
	while (1) {
		imprime();
		cin >> tmp;
		cout << endl;
		system("clear");
		switch (tmp) {
		case 1: {
			int umNodo;
			cout << "Digite a informacao do nodo a ser inserido: ";
			cin >> umNodo;
			B.insere(umNodo);
		} break;

		case 2: {
			int seq1, seq2, i = 1;
			cout << "Digite quantos nodos serão!" << endl;
			cin >> seq2;
			cout << "Digite os nodos seguintes:" << endl;
			while (i <= seq2) {
				cout << "Nodo " << i << ") ";
				cin >> seq1;
				B.insere(seq1);
				i++;
			}
		} break;

		case 3: {
			if (B.qtdenodo() < 3) {
				cout << "Quantidade de nodos insuficientes, tente novamente."
					 << endl;
				continue;
			}
			B.AchaFB();
			B.GeraDOT();
		} break;

		case 4: {
			if (B.qtdenodo() < 3) {
				cout << "Quantidade de nodos insuficientes, tente novamente."
					 << endl;
				continue;
			}
			cout << "/**********/ Arvore Balanceada /**********/" << endl
				 << endl;
			B.AchaFB();
			B.AplicaBalancemento();
			B.GeraDOT();
		} break;

		case 5: {
			B.Destroi_Nodos();
			cout << "Digite qual arquivo.txt você quer que o programa leia."
				 << endl;
			fstream fp;
			string nome, aux;
			cin >> nome;
			int valor;
			fp.open(nome, ios::in);
			if (!fp.is_open()) {
				cout << "Não foi possivel abrir o arquivo, tente novamente!"
					 << endl;
				continue;
			} else {
				while (!fp.eof()) {
					getline(fp, aux);
					valor = stoi(aux);
					B.insere(valor);
				}
			}
			fp.close();
		} break;
		case 6: {
			if (B.qtdenodo() == 0) {
				cout << "Nenhum Nodo encontrado." << endl;
				continue;
			}
			cout << "Destruindo todos os nodos..." << endl;
			B.Destroi_Nodos();
		} break;
		case 7: {
			cout << "Quantidade de nodos alocados= " << B.qtdenodo() << endl;
			continue;
		}
		case 8: {
			B.CaminhaCENTRAL();
		}
		case 9: {
			cout << "Insira o dado" << endl;
			int dado;
			cin >> dado;
			NodoABP *aux = B.busca(dado);
			B.Remove(aux);
			continue;
		} break;
		case 0: {
			exit(0);
		} break;
		}
	}
	return 0;
}
