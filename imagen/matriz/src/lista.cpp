#include <string>
#include <fstream>
#include "lista.h"
#include <iostream>

using namespace std;

Lista::Lista(){
	cabecera=0;
}
   
Lista::Lista(string valor){
	cabecera=new Celda;
	cabecera->datos=valor;
	cabecera->siguiente=0;

}
	
Lista::~Lista(){
	destruir();}

Lista::Lista(const Lista &copyA){

	
	cabecera = 0;
	Celda *aux=copyA.cabecera;
 
 	while(aux!=0){
 	
  		insertar(aux->datos);
  		aux=aux->siguiente;}
}

Lista Lista::operator+(const string &cadena){
	
	Lista resultado(*this);
	resultado.insertar(cadena);

	return(resultado);}

Lista & Lista::operator=(const Lista &listC){
	
	if(this != &listC){
		destruir();
		
		cabecera = 0;
		Celda *aux = listC.cabecera;

		while (aux != 0){

			insertar(aux->datos);
			aux = aux->siguiente;
		}
	}
	return *this;
}

void Lista::destruir(){	

       Celda * actual = cabecera;
	while (actual !=0){
		Celda *aux=actual;
		actual=actual->siguiente;
		delete aux;
	}
        cabecera=0;
}  

void Lista::insertar(string valor){
	if(cabecera==0){
	  cabecera=new Celda;
	  cabecera->datos=valor;
	  cabecera->siguiente=0;
	}
	else{
		Celda * actual=cabecera;
		while(actual->siguiente !=0){
			
			actual= actual->siguiente;
		}
		actual->siguiente=new Celda; //OTRO FALLO QUE HABIA
		actual->siguiente->datos=valor;
		actual->siguiente->siguiente =0;
				
		}
}
string Lista::getCelda(int pos) const{
		int i=0;
		Celda *actual=cabecera;
		while(actual !=0 && i!=pos){
			actual  = actual->siguiente;
			i++;
		}
		if (i!=pos){
		  cout<<"esa posicion no existe";
		  return "";
		}
		else {return (actual->datos);}
		
		
		
}
 int Lista::longitud() const{
	int numero=0;
	Celda * actual = cabecera;

	while(actual !=0){
		actual = actual -> siguiente;
		numero++;
	}
        return(numero);
}


/**
 * @brief Construye una lista de celdas enlazadas a partir de la informacion 
 * contenida en un fichero.
 * @param nombreFichero ruta del fichero de texto con el contenido de las datoss
 * a insertar en la lista
 * @retval true si ha tenido éxito en la lectura y el formato es el correcto
 * @retval false si se ha producido algún error en la lectura 
 * 
 * Lee desde disco los elementos almacenados en @a nombreFichero y los guarda 
 * en la lista. La función debe asegurarse de que la estructura sigue un patron 
 * determinado, y se ha de crear la lista con el numero de elementos que contenga. 
 */
bool Lista::leerLista(const char nombrefichero[]){
	ifstream fin;
	fin.open(nombrefichero);
	if(!fin){
		return false;
	}else{
		string grises;
		int lineas;
		getline(fin,grises); //la primera linea se ignora
		fin >> lineas; //leo el numero de datos de grises
		getline(fin,grises); //leer salto de linea
		if (!fin){
			return false;
		}else {
			int i = 0;
			getline(fin,grises); //leer cadena de caracteres
			while ((i < lineas)&&(fin)){
				if (grises != ""){
					insertar(grises);
					i++;
				}
				getline(fin,grises); //leer cadena de caracteres
			}
		}
		fin.close();
	}
	return true;
}
