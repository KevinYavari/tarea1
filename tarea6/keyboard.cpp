/*
la comeplejidad de este programa es 
O(n) ya que solo se recorre una vez la variable
donde esta contenida la oraciòn
*/
#include <iostream>
#include <list>
#include <string>
using namespace std;


int main(){
    string aux;
    while(getline(cin, aux)){;
        list<char> x;
        auto it = x.begin();

        for(int i = 0; i < aux.size() ; ++i){
            if(aux[i] == '['){
                it = x.begin();
            }
            else if(aux[i] == ']'){
                it = x.end();
            }
            else{
                x.insert(it, aux[i]);
            }
        }
        for(auto it = x.begin(); it != x.end(); ++it){
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}
