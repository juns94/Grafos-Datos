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
		cout << "		(0) Salir" << endl;

		cout << endl;
		cout << endl;

		cin >> opc;




		if (opc != 0) {


			switch (opc){
			
			case 1:{

			//	add();
				break;
			}

			case 2:{

			//	add(ls);

				break; }

			case 3:{
			//	addDesc(ls);

				int opcA;

				cout << "Que operacion de vertice quiere hacer?" << endl;
				cout << "(1) agregarArista(tObjeto *fuente, tObjeto *destino);" << endl;
				cout << "(2) agregarArista(tObjeto *nodo, int peso);" << endl;
				cout << "(3) agregarArista(tObjeto *fuente, tObjeto *destino, int peso);" << endl;
				cout << "(0) regresar al menu principal" << endl;
				cin >> opcA;

				switch (opcA){


				case 1:{


					

					//	add();
					break;
				}

				case 2:{

					//	add(ls);

					break; }

				case 3:{

					//	add(ls);

					break; }
				}


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

