#include<iostream>
#include<fstream>
#include "imagen.h"
#include "lista.h"
#include <cstring>
#include "pgm.h"
using namespace std;


Imagen::Imagen(){
	datos=0;
	nfilas=0;
	ncolumnas=0;
	}

Imagen::Imagen(int filas, int columnas){
	nfilas=filas;
	ncolumnas=columnas;
	datos=0;
	crear(filas,columnas);}

Imagen::Imagen(const Imagen &copia){
	nfilas=copia.nfilas;
	ncolumnas=copia.ncolumnas;

	datos=new byte [nfilas*ncolumnas];

	for(int i=0;i<nfilas*ncolumnas;i++){
	datos[i]=copia.datos[i];}}

Imagen::~Imagen(){
	destruir();}

Imagen Imagen::operator+(const Imagen &B) const{
	int nr,nc;
	nr=this->nfilas;
	nc=this->ncolumnas + B.ncolumnas;
	
	Imagen resultado(nr,nc);
	
	for(int i=0;i<nr;i++){
		for(int j=0;j<nc;j++){
			if(j<this->ncolumnas){
					resultado.set(i,j,get(i,j));
			}
			else{  
				if(B.nfilas>i){
						resultado.set(i,j,B.get(i,j-this->ncolumnas));
				}
			}
		}
	}
		
			
				

	return resultado;
}

Imagen & Imagen::operator=(const Imagen &C){
	if(this!=&C){
		crear(C.nfilas,C.ncolumnas);
		nfilas=C.nfilas;
		ncolumnas=C.ncolumnas;
		for(int i=0;i<nfilas*ncolumnas;i++){
			datos[i]=C.datos[i];
		}
	}
	return *this;
}

void Imagen::crear(int nfilas, int ncolumnas){
		
		if(datos!=0){
		destruir();}                

		datos=new byte [nfilas*ncolumnas];

		for(int i=0;i<nfilas*ncolumnas;i++){
		datos[i]=0;}
	}	

int Imagen::filas(){
		
		return(nfilas);
	}

int Imagen::columnas(){
		
		return(ncolumnas);
	}

	   
void Imagen::set(int y, int x, byte v){
		datos[y*ncolumnas+x]=v;
	}

byte Imagen::get(int y, int x) const{
		byte aux;
		aux=datos[y*ncolumnas+x];
		return(aux);
	}

void Imagen::setPos(int i, byte v){
		datos[i]=v;

	}

byte Imagen::getPos(int i){
		byte aux;
		aux=datos[i];
		return aux;

	}

bool Imagen::leerImagen(const char nombreFichero[]){
		int filas;
		int columnas;

   if (infoPGM(nombreFichero,filas,columnas)==IMG_PGM_BINARIO){ 
       datos=new byte[filas*columnas];
       if(leerPGMBinario(nombreFichero,datos,filas,columnas)){
        nfilas=filas;
	ncolumnas=columnas;
	return true;
      	}
       else
        return false;
    }

    if (infoPGM(nombreFichero,filas,columnas)==IMG_PGM_TEXTO){
	datos=new byte[filas*columnas];
      if(leerPGMTexto(nombreFichero,datos,filas,columnas)){
  	   nfilas=filas;
	   ncolumnas=columnas;
	return true;
       }
       else
        return false;
      }
      else{return false;}
}
	   
bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario){

	if(esBinario){
		return escribirPGMBinario(nombreFichero,datos,nfilas,ncolumnas);}
	else
		return escribirPGMTexto(nombreFichero,datos,nfilas,ncolumnas) ;
	} 

Imagen Imagen::plano(int k){ 
		Imagen pla(nfilas, ncolumnas); 
		for(int i=0;i<filas()*columnas();i++){ 
			if(getbit(getPos(i),k)){ 
			pla.setPos(i,255); 
			} 
			else{pla.setPos(i,0);}} 
		return pla; }

bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong){
		int cardinal =strlen(grises);
		int contador_char=0;
		int k;
		if(filas()*(columnas()+1)>maxlong){return false;}
		else{
		for(int i=0;i<filas();i++){
			for(int j=0;j<columnas();j++){
				k=get(i,j)*cardinal/256;
				arteASCII[contador_char]=grises[k];
				contador_char++;
				}
			arteASCII[contador_char]='\n';
			contador_char++;
			}
		arteASCII[contador_char]='\0';
		return true;
}}

void Imagen::destruir(){
	nfilas=ncolumnas=0;

	if(datos!=0){
	delete []datos;}
}

bool Imagen::listaAArteASCII(const Lista celdas){
	bool b=false;
	int maxlong=1000000;
	char nombrefinal[256];
	ofstream salida;
	const int total=celdas.longitud();
	bool exito;    
    
 	for(int i=0;i<total;i++){
 		
	char arteASCII[1000001];
		
 	const string grises=celdas.getCelda(i);
 		
	exito=aArteASCII( grises.c_str(),arteASCII, maxlong);

		
	if(exito){
	sprintf(nombrefinal,"arteascii%d.txt",i+1);
	salida.open(nombrefinal);
	salida<<arteASCII<<endl;
	salida.close();
	b=true;}
		
	else{
	cout<<"No ha funcionado";
	b=false;}
}
	return b;}
