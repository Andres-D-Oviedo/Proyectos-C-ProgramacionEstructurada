#include <iostream>
#include <conio.h>
#include <stdio.h>

typedef struct Nodo
{
	int info;
	Nodo *der;
	Nodo *izq;
}node; 
 
node*crearnodo(int n);//nodo raíz
void insertar(node *&arbol,int n);
void mostrar_arbol(node*,int);
void menu();
node*arbol=NULL;


int main()				// main
{
	int i;
	for (i=0;i<3;i++)
	{
		menu();
	}
	
	return 0;

}
//funcion del menu
void menu()
{
	int opcion;
	do
	{
		int dato,opcion,contador=0;
		printf ("\t:MENU:\n");
		printf("1. insertar un nuevo nodo\n");
		printf("2. mostrar el arbol completo\n");
		printf("Opcion:\t");
		scanf("%d",&opcion);
	
		switch(opcion)
			{
			case 1:
				printf("digite un numero: ");
				scanf("%d",&dato);
				insertar(arbol,dato); //inserta el dato en el arbol, un nodo
				system ("pause");
				break;
			case 2:
				printf("\n mostrando el arbol completo \n\n");
				mostrar_arbol(arbol,contador);
				printf("\n");
				system("pause");
				break;
			
			default:
				opcion!=2;
				break;
			}	
		system ("cls");
	}while (opcion !=3 );
}

//funcion crear nodo
node*crearnodo(int n)
{
	node *nuevo_nodo= new node();
	nuevo_nodo->info=n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;
	return nuevo_nodo;
}
	
//funcion para insertar nodos en el arbol
void insertar(node *&arbol,int n)
{
	if (arbol==NULL)//si el arbol está vacio
	{
		node*nuevo_nodo=crearnodo(n);//crea un nodo
		arbol=nuevo_nodo;//alamceno en la raiz
	}
	else//si el arbol ya tiene nodo
	{
		int valorraiz=arbol->info; //obtenemos el valor de la raiz 
		if (n<valorraiz) // si el elemento es menor a la raiz insertamos nodo en la izq
		{
			insertar(arbol->izq,n);
		}
		else //si el elemento es mayor a la raiz insteramos nodo en la derecha  
		{
			insertar(arbol->der,n);
		}	
	}
}

//funcion imprimir arbol
void mostrar_arbol(node *arbol,int contador)	//ontador ayudará a separar cada nodo 
{
	if(arbol==NULL)		//si arbol vacio
	{
		return;
	}
	else 
	{
		mostrar_arbol(arbol->der,contador+1); //imprime los nodos de la derecha 
		for (int i=0;i<contador;i++)
		{ 
			printf("  ");
		}
		printf("%d\n",arbol->info);//________-imprimir derecho 
		mostrar_arbol(arbol->izq,contador+1);
		
	}
}
