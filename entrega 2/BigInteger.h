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


#include <cmath>
#include <iostream>
#include <string>
#include <list>
using namespace std;

/************************
* ESTRUCTURAS DE DATOS *
************************/


class BigInteger{
    private:
    	list<int> lista;  
   		bool signo;
	public:
		/************************
	    * OPERACIONES DEL TAD *
	    ************************/
	    //constructor
	    BigInteger(); //hecho
	    BigInteger(const string& numero); //hecho
        BigInteger(const BigInteger& other); //hecho

	    //operaciones
	    void add(BigInteger& other);//hecho
	    void product(BigInteger& other);//hecho
	    void substract(BigInteger& other);//hecho
	    void quotient(BigInteger& other);
	    void remainder(BigInteger& other);
	    void pow(const int& other);//hecho
	    string toString();//hecho

	     // operadores

	    BigInteger operator+(BigInteger& other);//hecho
	    BigInteger operator-(BigInteger& other);//hecho
	    BigInteger operator*(BigInteger& other);//hecho
	    BigInteger operator/(BigInteger& other);
	    BigInteger operator%(BigInteger& other);
	    bool operator==(BigInteger& other);//hecho
	    bool operator<(BigInteger& other);//hecho
	    bool operator<=(BigInteger& other);//hecho

	    static BigInteger sumarListaValores(list<BigInteger> &lis);//hecho
	    static BigInteger multiplicarListaValores(list<BigInteger> &lis);//hecho

	    // funciones auxiliares

	    string sumar(BigInteger& other); //funcion para sumar //hecho
	    string restar(BigInteger& other); //funcion para restar //hecho
	    void borrarCeros(list<int> & other); //borrar ceros del principio //hecho
	    bool menor(BigInteger& other);

};

#endif
