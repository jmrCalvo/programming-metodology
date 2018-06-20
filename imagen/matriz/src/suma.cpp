#include<iostream>
#include<cstring>
#include "imagen.h"
#include<string>

using namespace std;

int main(int argc, char *argv[]){
	bool Binario=false;
	Imagen A,B,C;
	
	//Comprobamos que son 5 argumentos
	if(argc != 5){
	cerr<<"Error: El número de argumentos no corresponde.";}
	
	else{
		if(!A.leerImagen(argv[1])){
				cerr<<"Hay un error al leer la primera imagen";}
		
		if(!B.leerImagen(argv[2])){
				cerr<<"Hay un error al leer la segunda imagen";}
				
				C=A+B;
		
		if(strcmp(argv[4],"t") == 0){
				C.escribirImagen(argv[3],Binario);
				cout<<"Éxito en la ejecución. Compruebe su fichero "<<argv[3]<<endl;
		}
		if(strcmp(argv[4],"b") == 0){
				Binario=true;
				C.escribirImagen(argv[3],Binario);
				cout<<"Éxito en la ejecución. Compruebe su fichero "<<argv[3]<<endl;
		}
		
}

	return 0;
}
