#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

// Definición de estructuras para manejar la información de pasajeros y asientos
typedef struct {
	char nombre[30];
	char phone[15];
	long int id;
} PASAJERO;

typedef struct {
	int NumBolt;
	int disponibilidad; 
} ASIENTO;

typedef struct {
	ASIENTO create;
	PASAJERO datos;
	char origen[50];
	char destino[50];
	char num[2];
	int hora;
} BOLETO;

// Variables globales para iteraciones
int i, j, k;

// Declaración de funciones
int menu();
void asignar(BOLETO cliente[80], int numP[20][4]);
void disponibles(BOLETO cliente[80], int numP[20][4]);
int vender(BOLETO cliente[80], int numP[20][4], int k);
void buscar(BOLETO cliente[80], int numP[20][4]);
void imprimirPasajeros(BOLETO cliente[80]);

int main() {
	BOLETO bolet[80];
	int opcion, k = 1;
	int num_a[20][4];
	
	// Asignar disponibilidad inicial de los asientos
	asignar(bolet, num_a);
	
	// Bucle principal del menú
	do {
		opcion = menu();
		system("cls");
		switch (opcion) {
		case 1:
			k = vender(bolet, num_a, k);
			break;
		case 2:
			disponibles(bolet, num_a);
			break;
		case 3:
			buscar(bolet, num_a);
			break;
		case 4:
			disponibles(bolet, num_a);
			break;
		case 5:
			imprimirPasajeros(bolet);
			break;
		case 6:
			printf("      ---------------------\n");
			printf("      <<<<<<¡Bye-bye!>>>>>> \n");
			printf("      ---------------------\n");
			break;
		}
	} while (opcion != 6);
	
	getch();
	return 0;
}

// Función para mostrar el menú y leer la opción seleccionada
int menu() {
	printf("\n|-------------------------------------|");
	printf("\n|      BIENVENIDO A AEROLINEAS IF     |");
	printf("\n| DESTINOS:                           |");
	printf("\n| 1. VENDER TIQUETE                   |");
	printf("\n| 2. IMPRIMIR TIQUETE                 |");
	printf("\n| 3. CONSULTAR PASAJERO               |");
	printf("\n| 4. CONSULTAR DISPONIBILIDAD         |");
	printf("\n| 5. IMPRIMIR PASAJEROS               |");
	printf("\n| 6. TERMINAR                         |");
	printf("\n|-------------------------------------|");
	printf("\nOPCION: ");
	int opc;
	scanf("%d", &opc);
	return opc;
}

// Función para asignar disponibilidad inicial de los asientos
void asignar(BOLETO cliente[80], int numP[20][4]) {
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 4; j++) {
			numP[i][j] = 1;
		}
	}
}

// Función para mostrar asientos disponibles
void disponibles(BOLETO cliente[80], int numP[20][4]) {
	printf("LOS ASIENTOS DISPONIBLES SON LOS QUE TIENEN EL NUMERO (1) Y LOS QUE NO LO ESTAN TIENEN EL NUMERO (0)\n");
	printf("\nNo\tA\tB\tC\tD\n\n");
	for (i = 0; i < 20; i++) {
		printf("%d", i + 1);
		for (j = 0; j < 4; j++) {
			printf("\t%d", numP[i][j]);
		}
		printf("\n");
	}
	getch();
}

// Función para vender boletos
int vender(BOLETO cliente[80], int numP[20][4], int k) {
	char opc;
	int opc2 = 0, aux;
	int y = 0, m = 0;
	
	if (k < 81) {
		do {
			printf("PASAJERO NUMERO [%d]\n", k);
			printf("\nDIGITE SU DESTINO : ");
			fflush(stdin);
			gets(cliente[k].destino);
			
			do {
				if (strcmp(cliente[k].destino, cliente[1].destino) == 0) {
					m = 1;
				} else {
					printf("\nEL UNICO DESTINO QUE ESTA DISPONIBLE POR EL MOMENTO ES: %s\n", cliente[k-1].destino);
					m = 0;
					getch();
					system("cls");
					printf("POR FAVOR DIGITE UN DESTINO QUE ESTE DISPONIBLE: ");
					gets(cliente[k].destino);
				}
			} while (m == 0);
			
			printf("\nDIGITE SU LUGAR DE ORIGEN: ");
			fflush(stdin);
			gets(cliente[k].origen);
			printf("\nDIGITE SU NOMBRE: ");
			gets(cliente[k].datos.nombre);
			printf("\nDIGITE SU IDENTIFICACION: ");
			scanf("%ld", &cliente[k].datos.id);
			printf("\nDIGITE SU NUMERO DE TELEFONO: ");
			fflush(stdin);
			gets(cliente[k].datos.phone);
			system("cls");
			
			do {
				disponibles(cliente, numP);
				printf("EN QUE LUGAR DESEA SENTARSE?.SI UN PUESTO TIENE EL NUMERO 0 NO ESTA DISPONIBLE");
				printf("\nLAS COLUMNAS A Y D SON VENTANILLAS Y LAS COLUMNAS B Y C PASILLO");
				printf("\n\nQUE COLUMNA DESEA?: ");
				fflush(stdin);
				scanf("%c", &opc);
				printf("QUE FILA DESEA? ");
				scanf("%d", &opc2);
				opc2 -= 1;
				
				if (opc == 'A' && numP[opc2][0] == 1) {
					y = 1;
					numP[opc2][0] = 0;
				} else if (opc == 'B' && numP[opc2][1] == 1) {
					y = 1;
					numP[opc2][1] = 0;
				} else if (opc == 'C' && numP[opc2][2] == 1) {
					y = 1;
					numP[opc2][2] = 0;
				} else if (opc == 'D' && numP[opc2][3] == 1) {
					y = 1;
					numP[opc2][3] = 0;
				} else {
					printf("\nEL PUESTO ESTA OCUPADO, POR FAVOR SELECCIONE OTRO\n");
					system("pause");
					system("cls");
					y = 0;
				}
			} while (y == 0);
			
			Sleep(1000);
			system("cls");
			
			cliente[k].num[0] = opc;
			cliente[k].num[1] = opc2 + 1;
			cliente[k].create.NumBolt = k;
			
			printf("\nNo\tA\tB\tC\tD\n\n");
			for (i = 0; i < 20; i++) {
				printf("%d", i + 1);
				for (j = 0; j < 4; j++) {
					printf("\t%d", numP[i][j]);
				}
				printf("\n");
			}
			k++;
			printf("USTED A REALIZADO LA COMPRA EXITOSAMENTE, ¡GRACIAS POR SU COMPRA!");
			printf("\n\nDESEA COMPRAR OTRO TIQUETE? RESPONDA SI(1) O NO(2): ");
			scanf("%d", &aux);
			y = 0;
			system("cls");
		} while (aux != 2);
	}
	
	getch();
	system("cls");
	return k;
}

// Función para buscar un pasajero por su identificación
void buscar(BOLETO cliente[80], int numP[20][4]) {
	long int a;
	int x = 0;
	printf("\nDIGITE EL NUMERO DE CEDULA DEL PASAJERO QUE DESEA BUSCAR: ");
	scanf("%ld", &a);
	
	for (k = 0; k < 80; k++) {
		if (cliente[k].datos.id == a) {
			printf("\nEL PASAJERO ENCONTRADO ES:\n");
			printf("\n-NOMBRE: %s", cliente[k].datos.nombre);
			printf("\n-NUMERO DE IDENTIFICACION: %ld", cliente[k].datos.id);
			printf("\n-NUMERO DE TELEFONO: %s", cliente[k].datos.phone);
			printf("\n-CODIGO DE ASIENTO: %c-%d", cliente[k].num[0], cliente[k].num[1]);
			printf("\n-NUMERO DE BOLETO: %d", cliente[k].create.NumBolt);
			printf("\n-LUEGAR DE ORIGEN: %s", cliente[k].origen);
			printf("\n-DESTINO: %s", cliente[k].destino);
			x = 1;
		}
	}
	
	if (x != 1) {
		printf("\nEL PASAJERO NO SE ENCONTRO\n");
	}
	
	getch();
	system("cls");
}

// Función para imprimir la lista de pasajeros
void imprimirPasajeros(BOLETO cliente[80]) {
	printf("\nLISTA DE PASAJEROS:\n");
	for (k = 1; k < 80; k++) {
		if (cliente[k].datos.id != 0) {
			printf("\nPASAJERO %d\n", k);
			printf("NOMBRE: %s\n", cliente[k].datos.nombre);
			printf("IDENTIFICACION: %ld\n", cliente[k].datos.id);
			printf("TELEFONO: %s\n", cliente[k].datos.phone);
			printf("ORIGEN: %s\n", cliente[k].origen);
			printf("DESTINO: %s\n", cliente[k].destino);
			printf("ASIENTO: %c-%d\n", cliente[k].num[0], cliente[k].num[1]);
		}
	}
	getch();
}
