#include "BigInteger.h"

BigInteger::BigInteger(string numero){
    for(int i = 0; i < numero.size(); i++){
        int valor = numero[i] - '0'; 
        vec.push_back(valor);
    }
}





