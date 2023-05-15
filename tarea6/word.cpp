/*
la complejidad es O(n*logn)

*/
#include <iostream>
#include <map>
#include <list>
#include <string>

using namespace std;

map<char, int> crearmapa(string& word) {
    map<char, int> ans;
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] != ' ') {
            if(ans.find(word[i]) != ans.end()) {
                ans[word[i]] += 1;
            } 
            else{
                ans.insert(pair<char, int>(word[i], 1));
            }
        }
    }
    return ans;
}

int main(){
    list<string> diccionario;
    string palabra;
    int flag = 0;
    while (flag == 0){
        getline(cin, palabra);
        if (palabra == "#") {
            flag = 1;
        }
        diccionario.push_back(palabra);
    }
    flag = 0;
    while (flag == 0){
        getline(cin, palabra);
        if (palabra == "#") {
            flag = 1;
        }
        map<char, int> mapa_palabra = crearmapa(palabra);
        int count = 0;
        for (auto it = diccionario.begin(); it != diccionario.end() ; ++it) {
            string palabra_dicc = *it;
            map<char, int> mapa_palabra_dicc = crearmapa(palabra_dicc);
            bool se_puede_formar = true;
            int flag2 = 0;
            for (auto iter = mapa_palabra_dicc.begin(); iter != mapa_palabra_dicc.end() && flag2 == 0; ++iter) {
                char caracter = iter->first;
                int frecuencia = iter->second;
                if (mapa_palabra.find(caracter) == mapa_palabra.end() || mapa_palabra[caracter] < frecuencia) {
                    se_puede_formar = false;
                    flag2 = 1;
                }
            }
            if (se_puede_formar) {
                count++;
            }
        }
        if(palabra != "#"){
            printf("%d\n",count);
        } 
    }

    return 0;
}
