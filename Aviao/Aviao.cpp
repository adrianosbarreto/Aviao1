#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Aviao.h"

using namespace std;

Aviao::Aviao( float altitude, float velocidade , const string &modelo, bool estado, bool estadoAlerta )
{
	setEstado( estado );
	setModelo( modelo );
	setAltitude( altitude );
	setVelocidade( velocidade );
	setEstadoAlerta( estadoAlerta );
}
Aviao::Aviao( const string &modelo )
{
	setModelo( modelo );
	this->altitude = 0.0;
	this->velocidade = 0.0;
	this->modelo = "DESCONHECIDO";
	this->estado = false;
	this->estadoAlerta = false;
}

void Aviao::imprimirAtributo() const
{
	cout << "Modelo: " << this->modelo << endl;
	cout << "Estado de Voo(1 = Voando, 0 = Nao voando): " << this->getEstado() << endl;
	cout << "Velocidade: " << this->getVelocidade() << "Km/h"<< endl;
	cout << "Altitude: " << this->getAltitude() << "m" << endl;
}
int Aviao::mensagem() const
{
	int opcao;
	cout << "O que você deseja Fazer:"<< endl;
	
	cout << "\t1-Voar" << endl;
	cout << "\t2-Modificar Velocidade" << endl;
	cout << "\t3-Modificar Altitude" << endl;
	cout << "\t4-Enviar Mensagem Alerta aos Passageiros" << endl;
	cout << "\t5-Sair estado de Alerta" << endl;
	cout << "\t6-Exibir Atributos do Aviao" << endl;
	cout << "\t7-Sair" << endl;
	
	cout << "Digite a Opção desejada: ";
	cin >> opcao;
	system("cls");
	return opcao;
}

void Aviao::mensagemAlerta( const string []mensagemAlerta )
{
	int i;
	setEstadoAlerta( true );
	for( i = 0; i < n; i++){
		cout << mensagemAlerta[i];
	}
}
void Aviao::sairEstadoAlerta()
{
	setEstadoAlerta( false );
}

void Aviao::setAltitude( float altitude )
{
	if( this->estado == true )
	{
		if( altitude <= 5000 && altitude >= 0 )
		{
			this->altitude = altitude;
		}
		else
		{
			do
			{
				cout << "Digite Altitude Valida(entre 0 e 5000): ";
				cin >> altitude;
				this->altitude = altitude;
			}while( ( this->altitude < 0 ) || ( this->altitude > 5000 ) );
		}
	}
	else
	{
		this->altitude = 0.0;
		cout << "Aviao Nao Voando";
	}
}

float Aviao::getAltitude() const
{
		return this->altitude;
}

//set velocidade entre 0 e 600km/h
void Aviao::setVelocidade( float velocidade )
{
	if( this->estado == true )
	{
		if( ( velocidade <= 600 ) && ( velocidade >= 0 ))
		{
			this->velocidade = velocidade;
		}
		else
		{
			do
			{
				cout << "Digite Velocidade Valida(entre 0 e 600): ";
				cin >> velocidade;
				this->velocidade = velocidade;
			}while( ( this->velocidade < 0 ) || ( this->velocidade > 600 ) );
		}
	}
	else
	{
		this->velocidade = 0.0;
		cout << "Aviao Nao Voando";
	}
}

float Aviao::getVelocidade() const
{
	return this->velocidade;	
}

void Aviao::setModelo( const string &modelo )
{
	string aux = modelo;
	
	modelo.size() <= 6 ? this->modelo = modelo : this->modelo = aux.substr(0, 5);
	
}

string Aviao::getModelo() const
{
	return this->modelo;
}

void Aviao::setEstado( bool estado )
{
	this->estado = estado;
}

bool Aviao::getEstado() const
{
	return this->estado;
}

void Aviao::setEstadoAlerta( bool estadoAlerta )
{
	this->estadoAlerta = estadoAlerta;
}

bool Aviao::getEstadoAlerta() const
{
	return this->estadoAlerta;
}
