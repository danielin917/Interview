#include <iostream>
#include <string>

using namespace std;

enum Color{R,Y,G,B};





void Hits(Color Answer[], Color Guess[]){
	int hit = 0, phit = 0;	
	for(int i = 0; i < 4; i++){
		if(Answer[i] == Guess[i])
			hit++;
		else{
			for(int g = 0; g < 3; g++){
				if(Guess[i] == Answer[(i + g)% 4]){
					phit++;
					break;
				}
			
			}
		
		}
	
	
	}

	cout << "HITS: " << hit << "\tPSEUDO HITS: " << phit;

}


int main(){
Color answer[] ={R,R,Y,G};
Color guess[] = {B,G,Y,R};

Hits(answer, guess);

}

