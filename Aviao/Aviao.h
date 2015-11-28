#ifndef AVIAO_H
#define AVIAO_H

#include <string>
using std::string;

class Aviao
{
private:
	const static  int MAX_MENSAGEM = 3;
	float altitude;
	float velocidade;
	string modelo;
	bool estado; //voando ou nao-voando.
	bool estadoAlerta;
	
public:
	Aviao( float altitude = 0.0, float velocidade = 0.0 , const string &modelo = "Desconhecido", bool estado = false , bool estadoAlerta =  false );
	Aviao( const string &modelo );
	
	void setVelocidade( float );
	float getVelocidade() const;
	
	void setAltitude( float );
	float getAltitude() const;
	
	void setModelo( const string & );
	string getModelo() const;
	
	void setEstado( bool );
	bool getEstado() const;
	
	void setEstadoAlerta( bool );
	bool getEstadoAlerta() const;
	
	int mensagem() const;
	void imprimirAtributo() const;
	void sairEstadoAlerta();
	void mensagemAlerta( const string[] );
	inline void voar() { estado = true; velocidade = 500.0; altitude = 1000.0; };

};

#endif // AVIAO_H
