/*
 este código es O(n), donde n es la longitud de 
 la cadena de entrada 'p'. El código recorre cada 
 carácter de la cadena una sola vez y realiza una 
 cantidad constante de operaciones para cada carácter, 
 por lo que la complejidad no depende del tamaño de ningún otro parámetro.
 el codigo se resuelve en este ciclo "for(int f = 0; f < p.size(); f++)"
*/
#include <iostream>
#include <string>

using namespace std;

int main(){

	char arr1[100] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X',
	'Y','Z','0','1','2','3','4','5','6','7','8','9','.',',','?','\'','!','/','(',')','&',':',';','=','+','-','_','"','@'};

	string arr2[100] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.",
	"--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....",
	"--...","---..","----.",".-.-.-","--..--","..--..",".----.","-.-.--","-..-.","-.--.","-.--.-",".-...","---...","-.-.-.",
	"-...-",".-.-.","-....-","..--.-",".-..-.",".--.-."};
	int x;
	scanf("%d\n",&x);
	for(int i = 1; i < x+1 ; i++){
		string p;
		getline(cin,p);
		string ans;
		string aux = "";
		int cont = 0;
		for(int f = 0; f < p.size(); f++){
			if (p[f] != ' '){
				aux += p[f];
				cont = 0;
			}

			else if (p[f] == ' '){
				cont += 1;
				if(cont == 2){
					ans += ' ';
				}
				if (aux != ""){
					for(int y = 0; y < 100; y++){
						if (arr2[y] == aux){
							ans += arr1[y];
						}
					}
					aux = "";
				}
			}
		}
		if (aux != ""){
			for(int y = 0; y < 100; y++){
				if (arr2[y] == aux){
					ans += arr1[y];
				}
			}
		}
		cout << "Message #" << i << endl;
		cout << ans << endl;
		if(i != x){
			cout << endl;
		}
	}
	return 0;
}