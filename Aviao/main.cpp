#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Aviao.h"

using namespace std;

//Criar o set e o get de tripulação e passar por referencia o ponteiro de tripulação.


int main(int argc, char **argv)
{
	string mensagem = "Apertem os Cintos";
	float m;
	int fim = 1;
	Aviao a( 0.0, 0.0, "QWE975", false, false );
	
	//Aviao a;
	system("cls");
	do{
		switch(a.mensagem()){
			
			case 1:
				a.voar();
				system("pause");
				break;
			case 2:
				cout << "Digite Velocidade: ";
				cin >> m;
				a.setVelocidade(m);
				system("pause");
				break;
			case 3:
				cout << "Digite a Altitude: ";
				cin >> m;
				a.setAltitude(m);
				system("pause");
				break;
			case 4:
				a.mensagemAlerta( mensagem );
				system("pause");
				break;
			case 5:
				a.sairEstadoAlerta();
				break;	
			case 6:
				a.imprimirAtributo();
				system("pause");
				break;
			default:
				fim = 0;
				cout << "Fechando...";
				break;
		}
		system("cls");
	}while(fim != 0 );
	return 0;
}
