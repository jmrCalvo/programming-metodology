/**
 * lee cualquier imagen indicada por el usuario y un fichero con cadenas 
 * de caracteres y crea ficheros de imagen transformadas, una por cadena
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include "imagen.h"
#include "lista.h"

using namespace std;

int main(int argc,char *argv[]){
    if (argc !=3 ){
   	 cout<<"los parametros son "<<endl;
   	 cout<<"1 fichero imagen"<<endl;
   	 cout<<"2 fichero de grise"<<endl;
	return 0;
     }

    char *ficheroGrises=argv[2];
    char *ficheroImagen=argv[1];
    Imagen origen;
    Lista celdas;


    // Leer la imagen desde fichero
    if (!origen.leerImagen(ficheroImagen)){
		cerr << "Error leyendo imagen " << ficheroImagen << endl;
		return 1;
    }
	
	
	// Leer cadenas desde fichero
	if (celdas.leerLista(ficheroGrises)){	
		// realizar las conversiones
		if (origen.listaAArteASCII(celdas)){
			cout << "Exito en la conversion." << endl;
			cout << "Chequee los ficheros asciiX.txt" << endl;
			cout << endl;
		}else{
			cerr << "La conversion no ha sido posible" << endl;
			cerr << endl;
		}
		//~celdas; // liberar memoria listas
	}else{
		cerr << "Error lista de grises " << ficheroGrises << endl;
	}

}
