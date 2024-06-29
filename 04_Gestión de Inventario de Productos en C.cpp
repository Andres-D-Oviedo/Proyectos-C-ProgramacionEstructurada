#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define MAX 1000
#define MES 12

// Estructura para almacenar la información de un producto
typedef struct {
	int codigo;
	char nombre[50];
	char marca[50];
	float precio;
	int cantidad;
} tipoproducto;

// Prototipos de funciones
void menu();
int llenar(tipoproducto *producto, int i);
void Buscarprod(tipoproducto *produc, char *prod, int cont);
void imprimirproducto(tipoproducto *docent, int posicion);
void listarproductos(tipoproducto *docent, int cont);
void insertarproducto(tipoproducto *vector, tipoproducto producto, int cont, int c);

int main() {
	int opcion, contador = 0, c;
	char prod[50];
	tipoproducto productos[MAX];
	tipoproducto producto;
	float TOTAL = 0;
	
	do {
		system("cls");
		menu();
		printf("\nDigite la opcion a la cual desea ingresar: ");
		scanf("%d", &opcion);
		printf("\n_______________________\n");
		
		switch (opcion) {
		case 1:
			system("cls");
			if (contador < MAX) {
				printf("\nInsertar informacion del producto: %d  ", contador + 1);
				c = llenar(&producto, contador);
				insertarproducto(productos, producto, contador, c);
				contador++;
			}
			break;
			
		case 2:
			system("cls");
			printf("\nInserte producto a buscar: ");
			fflush(stdin);
			gets(prod);
			Buscarprod(productos, prod, contador);
			break;
			
		case 3:
			system("cls");
			printf("\nLista de productos: ");
			listarproductos(productos, contador);
			break;
			
		case 4:
			system("cls");
			printf("GRACIAS POR USAR NUESTROS SERVICIOS ");
			break;
			
		default:
			printf("Opcion incorrecta. Digite nuevamente una opcion:");
			break;
		}
	} while (opcion != 4);
	
	return 0;
}

// Función para mostrar el menú principal
void menu() {
	printf("\n_______________________\n");
	printf("             Menu de opciones\n");
	printf("1. Añadir un producto \n");
	printf("2. Buscar producto\n");
	printf("3. Listar productos \n");
	printf("4. Salir\n");
	printf("_______________________\n");
}

// Función para llenar los datos de un producto
int llenar(tipoproducto *producto, int i) {
	int c;
	printf("\nDigite el codigo:\t");
	fflush(stdin);
	scanf("%d", &(producto[i].codigo));
	
	printf("\nDigite nombre del producto:\t");
	fflush(stdin);
	gets(producto[i].nombre);
	
	printf("\nDigite la marca del producto:\t");
	fflush(stdin);
	gets(producto[i].marca);
	
	printf("\nDigite el precio:\t");
	fflush(stdin);
	scanf("%f", &producto[i].precio);
	
	printf("¿Cuantos desea añadir?");
	fflush(stdin);
	scanf("%d", &c);
	
	producto[i].cantidad = c;  // Corregido para inicializar la cantidad
	
	return 0;
}

// Función para insertar un producto en el vector
void insertarproducto(tipoproducto *vector, tipoproducto producto, int cont, int c) {
	vector[cont] = producto;
}

// Función para buscar un producto por nombre
void Buscarprod(tipoproducto *produc, char *prod, int cont) {
	int i, esta = 0, pos = -1;
	for (i = 0; i < cont; i++) {
		if (strcmp(produc[i].nombre, prod) == 0) {
			pos = i;
			esta = 1;
			break;
		}
	}
	if (esta == 1) {
		imprimirproducto(produc, pos);
	} else {
		printf(" No se encontro el producto. \n");
	}
	getch();
}

// Función para imprimir los detalles de un producto
void imprimirproducto(tipoproducto *produc, int posicion) {
	printf("\nCodigo: %d", produc[posicion].codigo);
	printf("\nProducto: %s", produc[posicion].nombre);
	printf("\nEs de la marca: %s", produc[posicion].marca);
	printf("\nEl precio es: %.2f", produc[posicion].precio);
	printf("\nHay %d disponibles.", produc[posicion].cantidad);
}

// Función para listar todos los productos
void listarproductos(tipoproducto *produc, int cont) {
	int i;
	for (i = 0; i < cont; i++) {
		printf("\n%d. ", i + 1);
		imprimirproducto(produc, i);
	}
	printf("\n\n");
	getch();
}

