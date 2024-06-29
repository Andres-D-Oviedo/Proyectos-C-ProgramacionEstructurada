#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

// Definición de estructuras
typedef struct {
	char nombre[70];
	int Id;
	int Phone;
	int Puesto;
} DATOSPERSONA;

typedef struct {
	char nombreChofer[50];
	char puestos[3][3]; // Puestos del bus
	char placa[10];
	char horaExit[10];
} BUS;

typedef struct {
	char destino[30];
	BUS Bus[3];
	int numBus;
	DATOSPERSONA DatosP;
} TIQUETE;

// Prototipos de funciones
int menuDestino();
void mostrarPuestos(TIQUETE *t, int i);
void registro(TIQUETE *t, int i, int NumBus);
void mostrarLista(TIQUETE *t, int i);
void imprimirTiquet(TIQUETE *t, int i);
int BuscarId(TIQUETE *t, int i, int dato);
void limpiarPuesto(TIQUETE *t, int n, int NumBus);

int main() {
	int tam = 0;
	int opcion;
	int NumBus;
	TIQUETE tiquet[27];
	int CodigoShear;
	int encontrado;
	char nombreNew[100];
	
	do {
		system("cls");
		opcion = menuDestino();
		NumBus = opcion;
		
		switch (opcion) {
		case 1:
		case 2:
		case 3:
			mostrarPuestos(tiquet, NumBus);
			registro(tiquet, tam, NumBus);
			getch();
			tam++;
			break;
		case 4:
			printf("\nINGRESE LA IDENTIFICACION DE LA PERSONA QUE DESEA BUSCAR: ");
			scanf("%d", &CodigoShear);
			encontrado = BuscarId(tiquet, tam, CodigoShear);
			if (encontrado != -1) {
				imprimirTiquet(tiquet, encontrado);
			} else {
				printf("\nNO HUBO COINCIDENCIA");
			}
			getch();
			break;
		case 5:
			for (int i = 0; i < tam; i++) {
				mostrarLista(tiquet, i);
			}
			getch();
			break;
		case 6:
			printf("\nINGRESE LA IDENTIFICACION DE LA PERSONA QUE DESEA MODIFICAR: ");
			scanf("%d", &CodigoShear);
			encontrado = BuscarId(tiquet, tam, CodigoShear);
			if (encontrado != -1) {
				mostrarLista(tiquet, encontrado);
				printf("\nINGRESE EL NUEVO NOMBRE: ");
				fflush(stdin);
				gets(nombreNew);
				strcpy(tiquet[encontrado].DatosP.nombre, nombreNew);
				mostrarLista(tiquet, encontrado);
			} else {
				printf("\nNO HUBO COINCIDENCIA");
			}
			getch();
			break;
		case 7:
			printf("\nINGRESE LA IDENTIFICACION DE LA PERSONA QUE DESEA MODIFICAR: ");
			scanf("%d", &CodigoShear);
			encontrado = BuscarId(tiquet, tam, CodigoShear);
			if (encontrado != -1) {
				mostrarLista(tiquet, encontrado);
				mostrarPuestos(tiquet, tiquet[encontrado].numBus);
				limpiarPuesto(tiquet, tiquet[encontrado].DatosP.Puesto, tiquet[encontrado].numBus);
				registro(tiquet, encontrado, tiquet[encontrado].numBus);
				mostrarLista(tiquet, encontrado);
			} else {
				printf("\nNO HUBO COINCIDENCIA");
			}
			break;
		case 8:
			printf("---------------------\n");
			printf("<<<<<<¡Bye-bye!>>>>>>\n");
			printf("---------------------\n");
			break;
		default:
			printf("\nESCRIBIO UN NUMERO FUERA DEL RANGO\n");
			break;
		}
	} while (opcion != 8);
	
	getch();
	return 0;
}

// Menú principal
int menuDestino() {
	printf("\n|-------------------------------------|");
	printf("\n|       BIENVENIDO A BOBAIRCRAFF      |");
	printf("\n| DESTINOS:                           |");
	printf("\n| 1. NEW YORK - THE VEGA     (5:00 PM)|");
	printf("\n| 2. GUATEMALA - PARIS       (7:00 PM)|");
	printf("\n| 3. CHAPINERO - PUERTO RICO (8:00 PM)|");
	printf("\n|                                     |");
	printf("\n| 4. IMPRIMIR TIQUETE                 |");
	printf("\n| 5. MOSTRAR LISTA (PASAJEROS)        |");
	printf("\n| 6. MODIFICAR NOMBRE                 |");
	printf("\n| 7. MODIFICAR PUESTO                 |");
	printf("\n| 8. SALIR                            |");
	printf("\n|-------------------------------------|");
	printf("\nOPCION: ");
	int opc;
	scanf("%d", &opc);
	return opc;
}

// Muestra los puestos del bus
void mostrarPuestos(TIQUETE *t, int i) {
	printf("\nLAS (F) INDICAN QUE EL PUESTO ESTA VACIO Y LAS (V) QUE ESTA OCUPADO\n");
	int recorre = 0;
	printf("\nPUESTOS DEL BUS %d: \n", i);
	for (int k = 0; k < 3; k++) {
		for (int j = 0; j < 3; j++) {
			if (t->Bus[i].puestos[k][j] == 0) {
				printf("|%d : F|", recorre + 1);
			} else {
				printf("|%d : V|", recorre + 1);
			}
			recorre++;
		}
		printf("\n");
	}
}

// Registra un nuevo tiquete
void registro(TIQUETE *t, int i, int NumBus) {
	printf("\n\t\tINGRESE SUS DATOS");
	switch (NumBus) {
	case 1:
		strcpy(t[i].destino, "NEW YORK - THE VEGA");
		strcpy(t[i].Bus[NumBus].horaExit, "5:00 PM");
		strcpy(t[i].Bus[NumBus].placa, "111 ALV");
		strcpy(t[i].Bus[NumBus].nombreChofer, "ALVARO X");
		break;
	case 2:
		strcpy(t[i].destino, "GUATEMALA - PARIS");
		strcpy(t[i].Bus[NumBus].horaExit, "7:00 PM");
		strcpy(t[i].Bus[NumBus].placa, "666 XXX");
		strcpy(t[i].Bus[NumBus].nombreChofer, "STELLA GIRALDO");
		break;
	case 3:
		strcpy(t[i].destino, "CHAPINERO - PUERTO RICO");
		strcpy(t[i].Bus[NumBus].horaExit, "8:00 PM");
		strcpy(t[i].Bus[NumBus].placa, "369 QUK");
		strcpy(t[i].Bus[NumBus].nombreChofer, "WILLIAM PITERGO");
		break;
	}
	
	// Abre archivo para escribir datos del tiquete
	FILE *archivo = fopen("mi_archivo.txt", "a");
	if (archivo == NULL) {
		printf("Error al abrir el archivo\n");
		return;
	}
	
	// Solicita y guarda los datos del pasajero
	printf("\nDESTINO: %s", t[i].destino);
	printf("\nHORA EXIT: %s", t[i].Bus[NumBus].horaExit);
	printf("\nNOMBRE: ");
	fflush(stdin);
	gets(t[i].DatosP.nombre);
	printf("C.C o T.I: ");
	scanf("%d", &t[i].DatosP.Id);
	printf("CELULAR: ");
	scanf("%d", &t[i].DatosP.Phone);
	printf("BUS: ");
	scanf("%d", &t[i].numBus);
	int p;
	printf("PUESTO: ");
	scanf("%d", &p);
	
	// Guarda los datos en el archivo
	fprintf(archivo, "\n\n\tDESTINO: %s\n", t[i].destino);
	fprintf(archivo, "NOMBRE: %s", t[i].DatosP.nombre);
	fprintf(archivo, "\nC.C o T.I: %d\n", t[i].DatosP.Id);
	fprintf(archivo, "CELULAR: %d\n", t[i].DatosP.Phone);
	fprintf(archivo, "PUESTO: %d", p);
	fprintf(archivo, "\nBUS: %d", t[i].numBus);
	fclose(archivo);
	
	// Asigna el puesto en el bus
	if (p >= 1 && p <= 9) {
		switch (p) {
		case 1: t->Bus[NumBus].puestos[0][0] = 1; break;
		case 2: t->Bus[NumBus].puestos[0][1] = 1; break;
		case 3: t->Bus[NumBus].puestos[0][2] = 1; break;
		case 4: t->Bus[NumBus].puestos[1][0] = 1; break;
		case 5: t->Bus[NumBus].puestos[1][1] = 1; break;
		case 6: t->Bus[NumBus].puestos[1][2] = 1; break;
		case 7: t->Bus[NumBus].puestos[2][0] = 1; break;
		case 8: t->Bus[NumBus].puestos[2][1] = 1; break;
		case 9: t->Bus[NumBus].puestos[2][2] = 1; break;
		}
		t[i].DatosP.Puesto = p;
	} else {
		printf("\n\tNO EXISTE ESE PUESTO");
	}
}

// Muestra la lista de pasajeros
void mostrarLista(TIQUETE *t, int i) {
	printf("\n");
	printf("DESTINO: %s\n", t[i].destino);
	printf("NOMBRE: %s", t[i].DatosP.nombre);
	printf("\nC.C o T.I: %d\n", t[i].DatosP.Id);
	printf("CELULAR: %d\n", t[i].DatosP.Phone);
	printf("PUESTO: %d", t[i].DatosP.Puesto);
	printf("BUS: %d", t[i].numBus);
	printf("\n");
}

// Busca un pasajero por su identificación
int BuscarId(TIQUETE *t, int i, int dato) {
	for (int j = 0; j < i; j++) {
		if (t[j].DatosP.Id == dato) {
			return j;
		}
	}
	return -1;
}

// Imprime el tiquete de un pasajero
void imprimirTiquet(TIQUETE *t, int i) {
	printf("\n|-------------------------------------|");
	printf("\n|              BOBTIQUET              ");
	printf("\n|DESTINO: %s", t[i].destino);
	printf("\n|NOMBRE: %s", t[i].DatosP.nombre);
	printf("\n|C.C o T.I: %d", t[i].DatosP.Id);
	printf("\n|CELULAR: %d", t[i].DatosP.Phone);
	printf("\n|BUS: %d", t[i].numBus);
	printf("\n|PUESTO: %d", t[i].DatosP.Puesto);
	printf("\n|PLACA DEL BUS: %s", t[i].Bus[t[i].numBus].placa);
	printf("\n|CONDUCTOR: %s", t[i].Bus[t[i].numBus].nombreChofer);
	printf("\n|HORA DE SALIDA: %s", t[i].Bus[t[i].numBus].horaExit);
	printf("\n|-------------------------------------|");
}

// Limpia el puesto de un pasajero
void limpiarPuesto(TIQUETE *t, int n, int NumBus) {
	switch (n) {
	case 1: t->Bus[NumBus].puestos[0][0] = 0; break;
	case 2: t->Bus[NumBus].puestos[0][1] = 0; break;
	case 3: t->Bus[NumBus].puestos[0][2] = 0; break;
	case 4: t->Bus[NumBus].puestos[1][0] = 0; break;
	case 5: t->Bus[NumBus].puestos[1][1] = 0; break;
	case 6: t->Bus[NumBus].puestos[1][2] = 0; break;
	case 7: t->Bus[NumBus].puestos[2][0] = 0; break;
	case 8: t->Bus[NumBus].puestos[2][1] = 0; break;
	case 9: t->Bus[NumBus].puestos[2][2] = 0; break;
	}
}
