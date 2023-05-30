#include "BigInteger.h"
#include <iostream>
#include <string>
#include <list>
#include <cmath>
#include <algorithm>
#include <sstream>
using namespace std;



/*********************************
 ********************************* 
    C O N S T R U C T O R E S
**********************************
**********************************/
/*
constructor BigInteger
Entrada: nada.
Descripción: este constructor no recibe nada y crear un BigInteger
*/
BigInteger::BigInteger(){//hecho
}

/*
constructor BigInteger
Entrada: un string que hace referencia a un BigInteger.
Descripción: este constructor recibe un string y crear un BigInteger
*/
BigInteger::BigInteger(const string& numero){//hecho
    if (numero.front() == '-') {
        signo = false;
        for (int i = 1; i < numero.size(); i++) {
            int valor = numero[i] - '0';
            lista.push_back(valor);
        }borrarCeros(lista);
    }
    else {
        signo = true;
        for (int i = 0; i < numero.size(); i++) {
            int valor = numero[i] - '0';
            lista.push_back(valor);
        }borrarCeros(lista);
    }
    if(lista.empty()){
          lista.push_back(0);
      }  
}

/*
constructor BigInteger
Entrada: un BigInteger.
Descripción: este constructor recibe un BigInteger, lo copia y lo almacena en otro 
BigInteger
*/
BigInteger::BigInteger(const BigInteger& other) {//hecho
    lista = other.lista;
    signo = other.signo;
}



/******************************************************
 *****************************************************
                O P E R A C I O N E S
********************************************************
*******************************************************/

/*
funcion add
Entrada: un BigInteger.
Descripción: suma dos BigInteger y la respuesta la guarda en el primer BigInteger
*/
void BigInteger::add(BigInteger& other){//hecho
    BigInteger x;
    x = *this + other;
    lista = x.lista;
    signo = x.signo;
}

/*
funcion product
Entrada: un BigInteger.
Descripción: multiplica dos BigInteger y la respuesta la guarda en el primer BigInteger
*/
void BigInteger::product(BigInteger& other) {//hecho
    BigInteger x;
    x = *this * other;
    lista = x.lista;
    signo = x.signo;
}

/*
funcion substract
Entrada: un BigInteger.
Descripción: resta dos BigInteger y la respuesta la guarda en el primer BigInteger
*/
void BigInteger::substract(BigInteger& other){//hecho
    BigInteger x;
    x = *this - other;
    lista = x.lista;
    signo = x.signo;
    borrarCeros(lista);
}

/*
funcion quotient
Entrada: un BigInteger.
Descripción: utilice para dividir el valor del objeto actual.
*/
void BigInteger::quotient(BigInteger& other){
    BigInteger x;
    x = *this / other;
    lista = x.lista;
    signo = x.signo;
}

/*
funcion remainder
Entrada: un BigInteger.
Descripción: utilice para obtener el residuo de la división con el valor del objeto actual.
*/
void BigInteger::remainder(BigInteger& other){
    BigInteger x;
    x = *this % other;
    lista = x.lista;
    signo = x.signo;
    borrarCeros(lista);
}

/*
funcion pow
Entrada: un BigInteger.
Descripción: eleva un BigInteger al numero dado
*/
void BigInteger::pow(const int& other){
    BigInteger ans(*this);
    int i = 0;
    if(other != 0){
        while (i < other-1){
                product(ans);
            ++i;
        }
    }else{
        lista.clear();
        lista.push_back(1);
    }
    if (signo == false){
        if ((other % 2) == 0){
            signo = true;
        }
    }
}

/*
funcion toString
Entrada: un BigInteger.
salida: un string que seria el BigInteger
Descripción: convierte un BigInteger a string 
*/
string BigInteger::toString() {
    int tam_lista = lista.size();
    string ans;
    if (signo == false) {
        ans.push_back('-');
    }
    for (list<int>::iterator it = lista.begin(); it != lista.end(); ++it) {
        char caracter = '0' + (*it);
        ans.push_back(caracter);
    }
    if (lista.empty()){
        lista.push_back(0);
        ans = "0";
    }
    return ans;
}

/***************************************************
 ***************************************************
    S O B R E  C A R G A  D E  O P E R A D O R E S
****************************************************
****************************************************/

/*
sobre carga del operador '-'
Entrada: un BigInteger
salida: un BigInteger
Descripción: resta dos BigInteger
*/
BigInteger BigInteger::operator-(BigInteger& other){//hecho
    string result;
    result = restar(other);
    BigInteger ans(result);
    if(signo == other.signo){
        if(lista.size() < other.lista.size()){
            if (other.signo == true){
                ans.signo = false;
            }else{
                ans.signo = true;
            }
            
        }
        else if(lista.size() > other.lista.size()){
            ans.signo = other.signo;
        }
        else{
            bool flag = true;
            list<int>::iterator it1 = lista.begin();
            list<int>::iterator it2 = other.lista.begin();
            for(it1; it1 != lista.end() && flag; ++it1){
                if (*it1 > *it2){
                    flag = false;
                    ans.signo = signo;
                }
                else if (*it1 < *it2){
                    flag = false;
                    if (other.signo == true){
                        ans.signo = false;
                    }else{
                        ans.signo = true;
                    }
                }else{
                    ++it1;
                    ++it2;
                }
            }if(*it1 - 1 > *it2 - 1){
                ans.signo = signo;
            }else if (*it1 - 1 > *it2 - 1){
                if (other.signo == true){
                    ans.signo = false;
                }else{
                    ans.signo = true;
                }
            }
            else if (flag == true){
                printf("ho");
                ans.signo = false;    
            }
        }
    }
    else{
        ans.signo = signo;
    }
    return ans;
}

/*
sobre carga del operador '+'
Entrada: un BigInteger
salida: un BigInteger
Descripción: suma dos BigInteger
*/
BigInteger BigInteger::operator+(BigInteger& other){//hecho
    string result;
    result = sumar(other);
    BigInteger ans(result);
    if(signo != other.signo){
        if(lista.size() < other.lista.size()){
            ans.signo = other.signo;
        }
        else if(lista.size() > other.lista.size()){
            ans.signo = signo;
        }
        else{
            bool flag = true;
            list<int>::iterator it1 = lista.begin();
            list<int>::iterator it2 = other.lista.begin();
            for(it1; it1 != lista.end() && flag; ++it1){
                if (*it1 > *it2){
                    flag = false;
                    ans.signo = signo;
                }
                else if (*it1 < *it2){
                    flag = false;
                    ans.signo = other.signo;
                }
                ++it1;
                ++it2;
            }
            if (flag == true){
                ans.signo = true;    
            }
        }
    }
    else{
        ans.signo = signo;
    }
    return ans;
}

/*
sobre carga del operador '*'
Entrada: un BigInteger
salida: un BigInteger
Descripción: multiplica dos BigInteger
*/
BigInteger BigInteger::operator*(BigInteger& other) {//hecho
    BigInteger ans("0");
    ans.signo = true;
    auto it2 = other.lista.rbegin();
    int carry = 0;
    int ceros = 0;
    while (it2 != other.lista.rend()) {
        auto it1 = lista.rbegin();
        string temp;
        for (int i = 0; i < ceros; ++i) {
            temp.push_back('0');
        }
        carry = 0;
        while (it1 != lista.rend()) {
            int prod = (*it1) * (*it2) + carry;
            carry = prod / 10;
            prod %= 10;
            temp.push_back(prod + '0');
            ++it1;
        }
        if (carry > 0) {
            temp.push_back(carry + '0');
        }
        reverse(temp.begin(), temp.end());
        BigInteger tempBigInt(temp);// 
        ans.add(tempBigInt);
        ++it2;
        ceros += 1;
    }
    if (signo != other.signo) {
        ans.signo = false;
    }
    return ans;
}

/*
sobre carga del operador '/'
Entrada: un BigInteger
salida: un BigInteger
Descripción: divide dos BigInteger
*/
BigInteger BigInteger::operator/(BigInteger& other) {
    BigInteger quotient;
    quotient.signo = true;
    BigInteger dividend = *this;
    dividend.signo = true;
    BigInteger divisor = other;
    divisor.signo = true;
    int ans = 0;
    if (dividend < divisor) {
        quotient.lista.push_back(0);
        if (signo != other.signo){
            quotient.signo = false;
        }
    }
    else if (dividend == divisor) {
        quotient.lista.push_back(1);
        if (signo != other.signo){
            quotient.signo = false;
        }
    }
    else{
        BigInteger aux;
        aux.signo = true;
        auto it = dividend.lista.begin();
        bool flag = true;
        int cont = 1;
        while(dividend.lista.size() > divisor.lista.size()){
            divisor.lista.push_back(0);
            cont *= 10;
        }
        if(dividend < divisor){
            divisor.lista.pop_back();
            cont /= 10;
        }
        while(cont != 0){
            if(divisor < dividend){
                dividend.substract(divisor);
                ans += cont;
            }
            else {
                divisor.lista.pop_back();
                cont /= 10;            
            }
        }
        stringstream ss;
        ss << ans;
        string cadena = ss.str();
        quotient = cadena;
        if (signo != other.signo){
            quotient.signo = false;
        }
    }
    return quotient;
}

/*
sobre carga del operador '%'
Entrada: un BigInteger
salida: un BigInteger
Descripción: obtiene el residuo de un BigInteger
*/
BigInteger BigInteger::operator%(BigInteger& other){
    BigInteger quotient;
    quotient.signo = true;
    BigInteger dividend = *this;
    dividend.signo = true;
    BigInteger divisor = other;
    divisor.signo = true;
    int ans = 0;
    if (dividend < divisor) {
        quotient.lista.push_back(0);
        if (signo != other.signo){
            quotient.signo = false;
        }
    }
    else if (dividend == divisor) {
        quotient.lista.push_back(1);
        if (signo != other.signo){
            quotient.signo = false;
        }
    }
    else{
        BigInteger aux;
        aux.signo = true;
        auto it = dividend.lista.begin();
        bool flag = true;
        int cont = 1;
        while(dividend.lista.size() > divisor.lista.size()){
            divisor.lista.push_back(0);
            cont *= 10;
        }
        if(dividend < divisor){
            divisor.lista.pop_back();
            cont /= 10;
        }
        while(cont != 0){
            if(divisor < dividend){
                dividend.substract(divisor);
                ans += cont;
            }
            else {
                divisor.lista.pop_back();
                cont /= 10;            
            }

        }

        if (signo == true && other.signo == false){
            dividend.add(other);
        }
        else if (signo == false && other.signo == true){
            dividend.substract(other);
        }
        if(*this < other){
            dividend.signo = false;
        } 
    }
    borrarCeros(dividend.lista);
    return dividend;
}


/*
sobre carga del operador '=='
Entrada: un BigInteger
salida: un bool
Descripción: compara dos BigInteger para saber si son iguales
*/
bool BigInteger::operator==(BigInteger& other){//hecho
    bool ans = true;
    if (lista.size() != other.lista.size()){
        ans = false;
    }
    else if(signo != other.signo){
        ans = false;
    }
    else{
        auto it1 = lista.begin();
        auto it2 = other.lista.begin();
        bool flag = false;
        while(flag == false && it1 != lista.end()){
            if(*it1 != *it2){
                flag = true;
                ans = false;
            }
            ++it1;
            ++it2;
        }
    }
    return ans;
}

/*
sobre carga del operador '<'
Entrada: un BigInteger
salida: un bool
Descripción: compara dos BigInteger para saber si el primer BigInteger es menor
*/
bool BigInteger::operator<(BigInteger& other){//hecho
    bool ans = true;
    if(signo == other.signo){
        if(signo == true){
            if(lista.size() > other.lista.size()){
                ans = false;
            }
            else if(lista.size() == other.lista.size()){
                auto it1 = lista.begin();
                auto it2 = other.lista.begin();
                bool flag = false;
                while(flag == false && it1 != lista.end()){
                    if(*it1 > *it2){
                        flag = true;
                        ans = false;
                    }
                    else if(*it1 < *it2){
                        flag = true;
                    }
                    ++it1;
                    ++it2;
                }
            }
        }
        else{
            if(lista.size() < other.lista.size()){
                ans = false;
            }
            else if(lista.size() == other.lista.size()){
                auto it1 = lista.begin();
                auto it2 = other.lista.begin();
                bool flag = false;
                while(flag == false && it1 != lista.end()){
                    if(*it1 < *it2){
                        flag = true;
                        ans = false;
                    }
                    else if(*it1 > *it2){
                        flag = true;
                    }
                    ++it1;
                    ++it2;
                }
            }
        }
    }
    else if (signo == true && other.signo == false){
        ans = false;
    }
    return ans;
}

/*
sobre carga del operador '<='
Entrada: un BigInteger
salida: un bool
Descripción: compara dos BigInteger para saber si el primer BigInteger es menor o igual al segundo
*/
bool BigInteger::operator<=(BigInteger& other){
    bool ans = false;
    if(((*this < other) == true) || ((*this == other) == true)){
        ans = true;
    }
    return ans;
}

/*
funcion sumarListaValores
Entrada: una lista de tipo BigInteger
salida: un BigInteger
Descripción: suma todos los BigIntegerque hay en una lista
*/
BigInteger BigInteger::sumarListaValores(list<BigInteger> &lis){
    BigInteger ans("0");
    auto it = lis.begin();
    while(it != lis.end()){
        BigInteger s(*it);
        ans.add(s);
        ++it;
    }
    return ans;
}

/*
funcion multiplicarListaValores
Entrada: una lista de tipo BigInteger
salida: un BigInteger
Descripción: multiplica todos los BigIntegerque hay en una lista
*/
BigInteger BigInteger::multiplicarListaValores(list<BigInteger> &lis){
    BigInteger ans("1");
    auto it = lis.begin();
    while(it != lis.end()){
        BigInteger s(*it);
        ans.product(s);
        ++it;
    }
    return ans;

}

/*******************************************
 *******************************************
    F U N C I O N E S  A U X I L I A R E S
********************************************
********************************************/

/*
funcion sumar
Entrada: un BigInteger
salida: un string que representa un numero
Descripción: funcion auxiliar para sumar dos BigInteger
*/
string BigInteger::sumar(BigInteger& other) {//hecho
    int tam_lista = lista.size();
    int tam_other = other.lista.size();
    int x = tam_lista;
    int bandera;
    string ans;
    int aux2 = 0;
    int p = 0;
    if ((signo == false && other.signo == false) || (signo == true && other.signo == true)) {
        if (tam_lista > tam_other) {
            for (int i = tam_other; i < tam_lista; ++i) {
                other.lista.push_front(0);
            }
            bandera = 1;
            }
            else if (tam_lista < tam_other) {
                for (int i = tam_lista; i < tam_other; ++i) {
                    lista.push_front(0);
                }
                bandera = 2;
            }
            auto it1 = lista.rbegin();
            auto it2 = other.lista.rbegin();
            while (it1 != lista.rend()) {
            aux2 = *it1 + *it2 + p;
            p = aux2 / 10;
            aux2 %= 10;
            ans.push_back('0' + aux2);
            ++it1;
            ++it2;
        }
    }
    if (p > 0){
        ans.push_back('0' + p);
    }
    else if ((signo == false && other.signo == true) || (signo == true && other.signo == false)) {
        if (other.lista.size() < lista.size()) {
            for (int i = tam_other; i < tam_lista; ++i) {
                other.lista.push_front(0);
            }
            bandera = 1;
            auto it1 = lista.rbegin();
            auto it2 = other.lista.rbegin();
            while (it1 != lista.rend()) {
                aux2 = (*it1 - *it2) - p;
                if (aux2 < 0) {
                    aux2 += 10;
                    p = 1; 
                }      
                else {
                    p = 0;
                }
                ans.push_back('0' + aux2);
                ++it1;
                ++it2;
            }
        }
        else if(other.lista.size() > lista.size()){
            for (int i = tam_lista; i < tam_other; ++i) {
                lista.push_front(0);
            }
            auto it2 = lista.rbegin();  
            auto it1 = other.lista.rbegin();
            while (it2 != lista.rend()) {
            aux2 = (*it1 - *it2) - p;
                if (aux2 < 0) {
                    aux2 += 10;
                    p = 1; 
                }      
                else {
                    p = 0;
                }
                ans.push_back('0' + aux2);
                ++it1;
                ++it2;
            }
        }else{
            if (menor(other)){
                bandera = 1;
                auto it2 = lista.rbegin();
                auto it1 = other.lista.rbegin();
                while (it2 != lista.rend()) {
                    aux2 = (*it1 - *it2) - p;
                    if (aux2 < 0) {
                        aux2 += 10;
                        p = 1; 
                    }      
                    else {
                        p = 0;
                    }
                    ans.push_back('0' + aux2);
                    ++it1;
                    ++it2;
                }
            }
            else{
                auto it1 = lista.rbegin();  
                auto it2 = other.lista.rbegin();
                while (it1 != lista.rend()) {
                aux2 = (*it1 - *it2) - p;
                    if (aux2 < 0) {
                        aux2 += 10;
                        p = 1; 
                    }      
                    else {
                        p = 0;
                    }
                    ans.push_back('0' + aux2);
                    ++it1;
                    ++it2;
                }
            }
        } 
    }

    // Invertir la cadena resultante
    reverse(ans.begin(), ans.end());

    if (bandera == 1) {
        borrarCeros(other.lista);
    }
    else {
        borrarCeros(lista);
    }
    return ans;
}

/*
funcion restar
Entrada: un BigInteger
salida: un string que representa un numero
Descripción: funcion auxiliar para restar dos BigInteger
*/
string BigInteger::restar(BigInteger& other) {//hecho
    int tam_lista = lista.size();
    int tam_other = other.lista.size();
    int x = tam_lista;
    int bandera;
    string ans;
    int aux2 = 0;
    int p = 0;
    if ((signo == false && other.signo == true) || (signo == true && other.signo == false)) {
            if (tam_lista > tam_other) {
            for (int i = tam_other; i < tam_lista; ++i) {
                other.lista.push_front(0);
            }
            bandera = 1;
            }
            else if (tam_lista < tam_other) {
                for (int i = tam_lista; i < tam_other; ++i) {
                    lista.push_front(0);
                }
                bandera = 2;
            }
            auto it1 = lista.rbegin();
            auto it2 = other.lista.rbegin();
            while (it1 != lista.rend()) {
            aux2 = *it1 + *it2 + p;
            p = aux2 / 10;
            aux2 %= 10;
            ans.push_back('0' + aux2);
            ++it1;
            ++it2;
        }
    }
    if (p > 0){
        ans.push_back('0' + p);
    }
    else if ((signo == false && other.signo == false) || (signo == true && other.signo == true)) {
        if (other.lista.size() < lista.size()) {
            for (int i = tam_other; i < tam_lista; ++i) {
                other.lista.push_front(0);
            }
            bandera = 1;
            auto it1 = lista.rbegin();
            auto it2 = other.lista.rbegin();
            while (it1 != lista.rend()) {
                aux2 = (*it1 - *it2) - p;
                if (aux2 < 0) {
                    aux2 += 10;
                    p = 1; 
                }      
                else {
                    p = 0;
                }
                ans.push_back('0' + aux2);
                ++it1;
                ++it2;
            }
        }
        else if(other.lista.size() > lista.size()){
            for (int i = tam_lista; i < tam_other; ++i) {
                lista.push_front(0);
            }
            auto it2 = lista.rbegin();  
            auto it1 = other.lista.rbegin();
            while (it2 != lista.rend()) {
            aux2 = (*it1 - *it2) - p;
                if (aux2 < 0) {
                    aux2 += 10;
                    p = 1; 
                }      
                else {
                    p = 0;
                }
                ans.push_back('0' + aux2);
                ++it1;
                ++it2;
            }
        }else{
            if (menor(other)){
                bandera = 1;
                auto it1 = lista.rbegin();
                auto it2 = other.lista.rbegin();
                while (it1 != lista.rend()) {
                    aux2 = (*it1 - *it2) - p;
                    if (aux2 < 0) {
                        aux2 += 10;
                        p = 1; 
                    }      
                    else {
                        p = 0;
                    }
                    ans.push_back('0' + aux2);
                    ++it1;
                    ++it2;
                }
            }
            else{
                auto it2 = lista.rbegin();  
                auto it1 = other.lista.rbegin();
                while (it2 != lista.rend()) {
                aux2 = (*it1 - *it2) - p;
                    if (aux2 < 0) {
                        aux2 += 10;
                        p = 1; 
                    }      
                    else {
                        p = 0;
                    }
                    ans.push_back('0' + aux2);
                    ++it1;
                    ++it2;
                }
            }
        }
    }
    
    // Invertir la cadena resultante
    reverse(ans.begin(), ans.end());

    if (bandera == 1) {
        borrarCeros(other.lista);
    }
    else {
        borrarCeros(lista);
    }
    return ans;
}

/*
funcion borrarCeros
Entrada: una lista 
Descripción: funcion auxiliar para quitar los 0 que estan al inicio de una lista
*/
void BigInteger::borrarCeros(list<int>& other) {//hecho
    auto it = other.begin();
    while (it != other.end() && *it == 0) {
        it = other.erase(it);
    }
}


bool BigInteger::menor(BigInteger& other){
    bool ans = true;
        if(lista.size() > other.lista.size()){
            ans = false;
        }
        else if(lista.size() < other.lista.size()){
            ans = true;
        }
        else{
            bool flag = true;
            list<int>::iterator it1 = lista.begin();
            list<int>::iterator it2 = other.lista.begin();
            for(it1; it1 != lista.end() && flag; ++it1){
                if (*it1 > *it2){
                    flag = false;
                    ans = false;
                }
                else if (*it1 < *it2){
                    flag = false;
                    ans = true;
                }
                ++it1;
                ++it2;
            }
            if (flag == true){
                ans = true;    
            }
        }
    return ans;
}