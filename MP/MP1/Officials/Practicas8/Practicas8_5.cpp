#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//Base de datos de alumnos.

struct alumno{
			string dni="no hay datos";
			int edad=0;
			float nota=0;
};

int main(){
			int opcion_menu, n_alumno;
			alumno datos[10];

do{

			cout<<"Seleccione una opcion."<<endl;
			cout<<"1. Agregar un alumno."<<endl;
			cout<<"2. Imprimir datos de un alumno."<<endl;
			cout<<"3. Imprimir datos de todos los alumnos."<<endl;
			cout<<"4. Modificar los datos de un alumno."<<endl;
			cout<<"5. Eliminar datos de un alumno."<<endl;
			cout<<"6. Salir."<<endl;

			cin>>opcion_menu;
			switch(opcion_menu){

						case 1:{
									cout<<"Escriba los datos requeridos:"<<endl;
									cout<<"Escriba el numero de lista del alumno."<<endl;
									cin>>n_alumno;
									cout<<"Introduzca el DNI del alumno."<<endl;
									cin>>datos[n_alumno-1].dni;
									cout<<"Introduzca la edad del alumno."<<endl;
									cin>>datos[n_alumno-1].edad;
									cout<<"Introduzca la nota del alumno."<<endl;
									cin>>datos[n_alumno-1].nota;
									cout<<"Los datos del alumno han sido guardados."<<endl;
						}break;
									
						case 2:{
									cout<<"Introduzca el numero de lista del alumno."<<endl;
									cin>>n_alumno;
									cout<<"D.N.I.: "<<datos[n_alumno-1].dni<<endl;
									cout<<"Edad: "<<datos[n_alumno-1].edad<<endl;
									cout<<"Nota: "<<datos[n_alumno-1].nota<<endl;
						}break;

						case 3:{
									cout<<"Estos son los datos de todos los alumnos: "<<endl;
									for(int i=0; i<10; i++){
												if(datos[i].dni=="no hay datos"&&datos[i].edad==0&&datos[i].nota==0){
															cout<<"Alumno numero: "<<i+1<<endl;
															cout<<"No existen datos sobre este alumno. Introduzcalos para poder visualizarlos."<<endl;
												}
												else{
															cout<<"Alumno numero: "<<i+1<<endl;
															cout<<"D.N.I. : "<<datos[i].dni<<endl;
															cout<<"Edad: "<<datos[i].edad<<endl;
															cout<<"Nota: "<<datos[i].nota<<endl;
												}
									}
						}break;

						case 4:{
									cout<<"Escriba el numero de lista del alumno que desea modificar."<<endl;
									cin>>n_alumno;
									cout<<"Introduzca el DNI del alumno."<<endl;
									cin>>datos[n_alumno-1].dni;
									cout<<"Introduzca la edad del alumno."<<endl;
									cin>>datos[n_alumno-1].edad;
									cout<<"Introduzca la nota del alumno."<<endl;
									cin>>datos[n_alumno-1].nota;
									cout<<"Las modificaciones han sido guardadas."<<endl;
						}break;

						case 5:{
									cout<<"Introduzca el numero del aulmno que desea eliminar."<<endl;
									cin>>n_alumno;
									datos[n_alumno-1].dni=' ';
									datos[n_alumno-1].edad=0;
									datos[n_alumno-1].nota=0;
									if(opcion_menu==5){cout<<"Se han eliminado los datos del alumno."<<endl;}
						}break;

			};

}while(opcion_menu==1||opcion_menu==2||opcion_menu==3||opcion_menu==4||opcion_menu==5);

if(opcion_menu==6){cout<<"Hasta pronto."<<endl;}

system("pause");
}