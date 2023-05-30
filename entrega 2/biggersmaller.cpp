/*
 * Autor: Kevin Yavari Yoshioka
 * Fecha de creación: 05 de Mayo 2023
 * Fecha última modificación: 06 de Mayo 2023
 * Versión: 1.0
 * 
 * Archivo encabezado TAD BigInteger
 * Representación Estructuras De Numeros Grandes
 */


#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cmath>
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
	    void subtract(BigInteger& other);//hecho
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


};







/*********************************
 ********************************* 
    C O N S T R U C T O R E S
**********************************
**********************************/
BigInteger::BigInteger(){//hecho
}

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

BigInteger::BigInteger(const BigInteger& other) {//hecho
    lista = other.lista;
    signo = other.signo;
}



/******************************************************
 *****************************************************
                O P E R A C I O N E S
********************************************************
*******************************************************/
void BigInteger::add(BigInteger& other){//hecho
    string x;
    x = sumar(other);
    lista.clear();
    int i = 0;
    while(i != x.size()){
        lista.push_back(x[i] - '0');
    ++i;
    }
}

void BigInteger::product(BigInteger& other) {//hecho
    BigInteger x;
    x = *this * other;
    lista = x.lista;
    signo = x.signo;
}

void BigInteger::subtract(BigInteger& other){//hecho
    string x;
    x = restar(other);
    lista.clear();
    int i = 0;
    while(i != x.size()){
        lista.push_back(x[i] - '0');
    ++i;
    }
    borrarCeros(lista);
}
void quotient(BigInteger& other){//utilice para dividir el valor del objeto actual.

}
void remainder(BigInteger& other){//utilice para obtener el residuo de la división con el valor del objeto actual.

}

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
    /*
    bool flag = true;
    for (int i = 0; i < ans.size() && flag; ++i) {
        if (ans[i] == '0') {
            ans.erase(i);
        } else {
            flag = false;
        }
    }
    if (ans.empty()) {
        ans.push_back('0');
    }*/
    return ans;
}

/***************************************************
 ***************************************************
    S O B R E  C A R G A  D E  O P E R A D O R E S
****************************************************
****************************************************/
BigInteger BigInteger::operator-(BigInteger& other){//hecho
    string result;
    result = restar(other);
    BigInteger ans(result);
    if(signo == other.signo){
        if(lista < other.lista){
            ans.signo = signo;
        }
        else{
            ans.signo = false;
        }
    }
    else{
        ans.signo = signo;
    }
    return ans;
}


BigInteger BigInteger::operator+(BigInteger& other){//hecho
    string result;
    result = sumar(other);
    BigInteger ans(result);
    if(signo != other.signo){
        if(lista < other.lista){
            ans.signo = other.signo;
        }
        else{
            ans.signo = signo;
        }
    }
    else{
        ans.signo = signo;
    }
    return ans;
}

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
BigInteger BigInteger::operator/(BigInteger& other) {
    BigInteger quotient;
    quotient.signo = true;
    BigInteger dividend = *this;
    BigInteger divisor = other;
    if (dividend < divisor) {
        quotient.lista.push_back(0);
    }
    else if (dividend == divisor) {
        quotient.lista.push_back(1);
    }
    while (divisor < dividend){
        bool flag = true;
        auto it = dividend.lista.begin();
        BigInteger aux;
        aux.signo = true;
        aux.lista.push_back(*it);
        ++it;
        dividend.lista.pop_front();
        while(flag){
            if(divisor <= aux){
                flag = false;
            }
            else if(aux < divisor){
                aux.lista.push_back(*it);
                dividend.lista.pop_front();
                ++it;
            }          
        }
        int cont = 0;
        while(divisor <= aux){
            aux.subtract(divisor);
            cont += 1;
        }
        quotient.lista.push_back(cont);
        for(int i = 1; i < dividend.lista.size(); ++i){
            quotient.lista.push_back(0);
        }
    }
    if (signo != other.signo){
        quotient.signo = false;
    }

    return quotient;
}*/
/*

BigInteger operator%(BigInteger& other){}
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

bool BigInteger::operator<=(BigInteger& other){
    bool ans = false;
    if(((*this < other) == true) || ((*this == other) == true)){
        ans = true;
    }
    return ans;
}


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
        if (other < *this) {
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
        else if(*this <= other){
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
        if (other < *this) {
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
        else if(*this <= other){
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

void BigInteger::borrarCeros(list<int>& other) {//hecho
    auto it = other.begin();
    while (it != other.end() && *it == 0) {
        it = other.erase(it);
    }
}



void solution(BigInteger&a, string&b, BigInteger&c, string&d){
	int cont;
	if(a == c){
		if (b.size() < d.size()){
			bool flag = true;
			for (int i = 0; i < b.size() && flag; i++) {
	            int valor1 = b[i] - '0';
	            int valor2 = d[i] - '0';
	            if (valor1 > valor2){
	            	flag = false;
	            	printf("Bigger\n");
	            }else if (valor1 < valor2){
	            	printf("Smaller\n");
	            	flag = false;
	            }else{
	            	cont +=1;
	            }
        	}for (int i = d.size(); i < b.size() && flag; ++i){
        		int valor2 = d[i] - '0';
        		if (valor2 != 0){;
	            	printf("Smaller\n");
	            	flag = false;
        		}
        	}
        	if(flag == true){
        		printf("Same\n");
        	}
		}
		else if(b.size() > d.size()){
			bool flag = true;
			for (int i = 0; i < d.size() && flag; i++) {
	            int valor1 = b[i] - '0';
	            int valor2 = d[i] - '0';
	            if (valor1 > valor2){
	            	flag = false;
	            	printf("Bigger\n");
	            }else if (valor1 < valor2){
	            	printf("Smaller\n");
	            	flag = false;
	            }
        	}
        	for (int i = d.size(); i < b.size() && flag; ++i){
        		int valor1 = b[i] - '0';
        		if (valor1 != 0){
	            	printf("Bigger\n");
	            	flag = false;
        		}
        	}
        	if(flag == true){
        		printf("Same\n");
        	}
		}
		else{
			bool flag = true;
			for (int i = 0; i < d.size() && flag; i++) {
	            int valor1 = b[i] - '0';
	            int valor2 = d[i] - '0';
	            if (valor1 > valor2){
	            	flag = false;
	            	printf("Bigger\n");
	            }else if (valor1 < valor2){
	            	printf("Smaller\n");
	            	flag = false;
	            }
	        }if(flag == true){
        		printf("Same\n");
        	}
		}
		
	}
	else if(a < c){
		printf("Smaller\n");
	}else{
		printf("Bigger\n");
	}
}

int main(){
	string ans;
	int i = 0;
	while(getline(cin, ans)){
		i++;
		string num1;
		string b;
		string num3;
		string d;
		int flag = 1;
		for (int i = 0; i < ans.size(); ++i){
			if(ans[i] != '.' && ans[i] != ' '){
				if (flag == 1){
					num1.push_back(ans[i]);
				}
				else if (flag == 2){
					b.push_back(ans[i]);
				}
				else if (flag == 3){
					num3.push_back(ans[i]);
				}
				else{
					d.push_back(ans[i]);
				}
			}else{
				flag += 1;
			}
		}
		printf("Case %d: ", i);
		BigInteger a(num1);
		BigInteger c(num3);
		solution(a, b, c, d);
	}
	return 0;
} 	


