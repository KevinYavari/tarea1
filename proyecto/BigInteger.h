/*
 * Autor: Kevin Yavari Yoshioka
 * Fecha de creación: 05 de Mayo 2023
 * Fecha última modificación: 06 de Mayo 2023
 * Versión: 1.0
 * 
 * Archivo encabezado TAD BigInteger
 * Representación Estructuras De Numeros Grandes
 */
#ifndef __BIGINTEGER_H
#define __BIGINTEGER_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/************************
* ESTRUCTURAS DE DATOS *
************************/

class BigInteger{
	vector<int> vec;

	public:
		/************************
	    * OPERACIONES DEL TAD *
	    ************************/
	    //constructor
	    BigInteger(string numbero);
        BigInteger(BigInteger& other);

	    //operaciones
	    void add(BigInteger& other);
	    void product(BigInteger& other);
	    void substract(BigInteger& other);
	    void quotient(BigInteger& other);
	    void remainder(BigInteger& other);
	    void pow(const BigInteger& other);

	     // operadores
	    BigInteger operator+(BigInteger& other);
	    BigInteger operator-(BigInteger& other);
	    BigInteger operator*(BigInteger& other);
	    BigInteger operator/(BigInteger& other);
	    BigInteger operator%(BigInteger& other);
	    bool operator==(BigInteger& other);
	    bool operator<(BigInteger& other);
	    bool operator<=(BigInteger& other);

	    BigInteger sumarListaValores(vector<BigInteger> &vector);
	    BigInteger MultiplicarListaValores(vector<BigInteger> &vector);

};
#endif
