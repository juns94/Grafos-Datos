// EjemploGrafos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Grafo.h"

Grafo *grafo; 

void inicio(){
	int primero;
	int segundo;
	
	int opc;
	do{

		system("cls");
		cout << endl;
		cout <<	 "	  -----	Pruebas de Grafos Dinamicos -----" << endl;

		cout << endl;
		cout << endl;
		cout << endl;
		/*
		agregarVertice(Tobjeto *nodo);
		borrarVertice(tObjeto *nodo);
		agregarArista(tObjeto *nodo);
		agregarArista(tObjeto *fuente, tObjeto *destino);
		agregarArista(tObjeto *nodo, int peso);
		agregarArista(tObjeto *fuente, tObjeto *destino, int peso);
		eliminarArista(tObjeto *nodo);
		eliminarArista(tObjeto *fuente, tObjeto *destino);
		*/

		cout << "		Que operacion desea hacer?" << endl;
		cout << endl;
		cout << endl;
		cout << "		(1) Agregar Vertice" << endl;
		cout << "		(2) Borrar Vertice" << endl;
		cout << "		(3) Agregar Arista" << endl;
		cout << "		(4) Eliminar Arista" << endl;
		cout << "		(5) Desplegar Arista" << endl;
		cout << "		(6) Desplegar Vertice" << endl;
		cout << "		(0) Salir" << endl;

		cout << endl;
		cout << endl;

		cin >> opc;




		if (opc != 0) {


			switch (opc){
			
			case 1:{ //agregar vertice, arista es raya
				cout << "Ingrese el dato del nuevo vertice." << endl;
				int dato;
				cin >> dato;
				
				
				if(grafo->agregarVertice(dato))
					cout << "Dato ingresado correctamente" << endl;
				else

					cout << "Dato ya existente" << endl;
				break;
			}

			case 2:{
				cout << "Ingrese el  valor del dato para eliminar." << endl;
				int dato;
				cin >> dato;

				if (grafo->borrarVertice(dato))
					cout << "Dato eliminado correctamente" << endl;
				else

					cout << "El dato no se encuentra." << endl;

				break; }

			case 3:{

				int dato, dato2, dato3;

				cout << "Favor ingresar el dato fuente" << endl;
				cin >> dato;
				cout << "Favor ingresar el dato destino" << endl;
				cin >> dato2;
				cout << "Favor ingresar el peso de la arista" << endl;
				cin >> dato3;

				if (grafo->unirVertices(dato, dato2, dato3))
					cout << "Dato ingresado correctamente" << endl;
				else

					cout << "No se pudo realizar esta operacion debido a errores con los valores numericos" << endl;


			//	addDesc(ls);
				/*
				int opcA;

				cout << "Que operacion de vertice quiere hacer?" << endl;
				cout << "(1) agregarArista(tObjeto *fuente, tObjeto *destino);" << endl;
				cout << "(2) agregarArista(tObjeto *nodo, int peso);" << endl;
				cout << "(3) agregarArista(tObjeto *fuente, tObjeto *destino, int peso);" << endl;
				cout << "(0) regresar al menu principal" << endl;
				cin >> opcA;

				switch (opcA){


				case 1:{

					int dato, dato2;

					cout << "Favor ingresar el dato nodo" << endl;
					cin >> dato;	
					cout << "Favor ingresar el dato peso" << endl;
					cin >> dato2;

					if (grafo->unirVertices(dato, dato2))
						cout << "Dato ingresado correctamente" << endl;
					else

						cout << "No se pudo realizar esta operacion debido a errores con los valores numericos" << endl;
					

					//	add();
					break;
				}

				case 2:{
					int dato, dato2, dato3;

					cout << "Favor ingresar el dato fuente" << endl;
					cin >> dato;
					cout << "Favor ingresar el dato destino" << endl;
					cin >> dato2;
					cout << "Favor ingresar el peso de la arista" << endl;
					cin >> dato3;

					if (grafo->borrarArista(dato, dato2,dato3))
						cout << "Dato ingresado correctamente" << endl;
					else

						cout << "No se pudo realizar esta operacion debido a errores con los valores numericos" << endl;


					break; }

				case 3:{

					int dato, dato2;

					cout << "Favor ingresar el dato fuente" << endl;
					cin >> dato;
					cout << "Favor ingresar el dato destino" << endl;
					cin >> dato2;

					if (grafo->borrarArista(dato, dato2))
						cout << "Dato ingresado correctamente" << endl;
					else

						cout << "No se pudo realizar esta operacion debido a errores con los valores numericos" << endl;



					break; }
				}
*/

				break; }

			case 4:{

				//	add(ls);

				break; }


			case 5:{


				cout << " Desplegando todas los aristas: " << endl;


				//	add(ls);

				break; }


			case 6:{

				cout << " Desplegando todas los vertices: " << endl;
				


				//	add(ls);

				break; }


	


			default:{ cout << "OPCION INVALIDA" << endl;
				break; }
			}
		}
		else{
			cout << "Fin del programa" << endl;
		}
		cout << endl;
		system("pause");

	} while (opc != 0);



}
int _tmain(int argc, _TCHAR* argv[])
{

	grafo = new Grafo();

	inicio();

	return 0;
}

