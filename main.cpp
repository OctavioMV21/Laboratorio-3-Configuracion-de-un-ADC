 /**********************************************************************************************************************
 // FileName:        Lab_3_Config_ADC.cpp
 // Program version: Dev-C++ 6.3
 // Company:         TECNM - ITCH
 // Description:     Lab_3 POO conf ADC
 // Authors:         Luis Octavio Mendez Valles
 // Professor:       Alfredo Chacon
 // Subject:         Arquitectura de Prog. Para Hardware
 // Updated:         09/10/2022
 ************************************************************************************************************************/
 
#include <iostream>
#include <stdlib.h>

using namespace std;

//Clase
class ADC{
	
	//Atributos
	private:
		static int res1;
		static float frec;
		int canal;
		float volts;
		double res2;
	
	public:
		ADC(){}; //Constructor
		//Metodos
		void canales();
		void leerVolts();
		void muestraDatos();
		static void capturaDatos();
		
};

//Inicializa las variables estaticas
float ADC::frec=0;
int ADC::res1=0;

void ADC::canales(){ //Definicion del metodo canales

	//Lee los canales
	do{
    	cout<<"\nIntroducir canal AN a usar (1-32): ";
    	cin>>canal;
    	if(canal<1 || canal>32){ //Verifica el canal
    		cout<<"Entrada invalida"<<endl;
    	}
	}while(canal<1 || canal>32); //Repite si la entrada es incorrecta

}

void ADC::leerVolts(){ //Definicion del metodo leerVolts

	//Lee el voltaje
	do{
    	cout<<"\nIntroducir voltaje (0-3.3v) del canal "<<canal<<": ";
    	cin>>volts;
    	if(volts<0 || volts>3.3){ //Verifica el voltaje
    		cout<<"Entrada invalida"<<endl;
    	}
	}while(volts<0 || volts>3.3); //Repite si la entrada es incorrecta

	//Conversion a 8 bits
	if(res1 == 8){
		res2 = (volts*255)/3.3;
	}
	
	//Conversion a 10 bits
	if(res1 == 10){
		res2 = (volts*1023)/3.3;
	}
	
	//Conversion a 12 bits
	if(res1 == 12){
		res2= (volts*4095)/3.3;
	}

}

void ADC::muestraDatos(){ //Definicion del metodo muestraDatos

	cout<<"\nCanal AN"<<canal<<"\nConversion: "<<res2<<endl;

}

void ADC::capturaDatos(){ //Definicion del metodo capturaDatos
	
	//Lee la resolucion
	do{
		cout<<"\nIntroducir resolucion de bits (8, 10, 12): ";
		cin>>res1;
		if(res1!=8 && res1!=10 && res1!=12){ //Verifica la resolucion
			cout<<"Entrada invalida"<<endl;
		}
	}while(res1!=8 && res1!=10 && res1!=12); //Repite si la entrada es incorrecta

	//Lee la frecuencia
	cout<<"\nIntroducir frecuencia de muestreo (Hz): ";
	cin>>frec;

}

void portada(); //Prototipo de funcion 

//main
int main(){
	
	int can;
	portada(); //Llama a portada
	ADC::capturaDatos(); //Llama al metodo capturaDatos
    cout<<"\nIntroducir la cantidad de canales a leer: ";
    cin>>can;
	ADC canal[can]; //Se crea un objeto
	  
    //Ciclos para los metodos
	for(int i=0;i<can;i++){
		canal[i].canales();
	}
	for(int i=0;i<can;i++){
		canal[i].leerVolts();
	}
	for(int i=0;i<can;i++){
		canal[i].muestraDatos();
	}
	
	return 0;
}

//Se imprime la portada
void portada() {
	
	printf("---------------------------------------------------------\n");
	printf("|| Instituto Tecnologico de Chihuahua                  ||\n");
	printf("|| Autor: Luis Octavio Mendez Valles 19060757          ||\n");
	printf("|| Programa: Lab_3 Configuracion ADC                   ||\n");
	printf("|| Catedratico: Alfredo Chacon                         ||\n");
	printf("|| Materia: Arquitectura de Prog. para Hardware        ||\n");
	printf("---------------------------------------------------------\n\n");
	printf("-------------------------------------------------------------\n");
	printf("|| Instrucciones de uso: Introduzca la resolucion de bits  ||\n");
	printf("|| deseada, asi como la frecuencia de muestreo, cantidad y ||\n");
    printf("|| canales a leer.                                         ||\n");
    printf("-------------------------------------------------------------\n\n");
    
}
