#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nombre[70];
	int Id;
	int Phone;
	int Puesto;
} DATOSPERSONA;

typedef struct {
	char nombreChofer[50];
	int puestos[3][3]; // Cambiado de char a int para indicar estado de puesto
	char placa[10]; 
	char horaExit[10];   
} BUS;

typedef struct {
	char destino[30];
	BUS Bus[3];
	int numBus;
	DATOSPERSONA DatosP;
} TIQUETE;

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
	TIQUETE tiquet[27];    
	int CodigoShear;
	int encontrado;
	char nombreNew[100];
	do {    
		system("cls");
		opcion = menuDestino();
		int NumBus = opcion - 1;
		switch (opcion) {
		case 1:
		case 2:
		case 3:
			mostrarPuestos(tiquet, NumBus);
			registro(tiquet, tam, NumBus);
			printf("Presione una tecla para continuar...");
			getchar();
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
			printf("Presione una tecla para continuar...");
			getchar(); getchar();
			break;     
		case 5:
			for (int i = 0; i < tam; i++) {
				mostrarLista(tiquet, i);
			}
			printf("Presione una tecla para continuar...");
			getchar(); getchar();
			break;
		case 6:
			printf("\nINGRESE LA IDENTIFICACION DE LA PERSONA QUE DESEA MODIFICAR: ");
			scanf("%d", &CodigoShear);
			encontrado = BuscarId(tiquet, tam, CodigoShear);
			if (encontrado != -1) {
				mostrarLista(tiquet, encontrado);
				printf("\nINGRESE EL NUEVO NOMBRE: ");
				getchar();
				gets(nombreNew);
				strcpy(tiquet[encontrado].DatosP.nombre, nombreNew);
				mostrarLista(tiquet, encontrado);
			} else {
				printf("\nNO HUBO COINCIDENCIA");
			}
			printf("Presione una tecla para continuar...");
			getchar(); getchar();
			break;      
		case 7:
			printf("\nINGRESE LA IDENTIFICACION DE LA PERSONA QUE DESEA MODIFICAR :  ");
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
			printf("Presione una tecla para continuar...");
			getchar(); getchar();
			break;
		case 8:
			printf("---------------------\n");
			printf("<<<<<<¡Bye-bye!>>>>>> \n");
			printf("---------------------\n");
			break;
		default:
			printf("\nESCRIBIO UN NUMERO FUERA DEL RANGO\n");
			printf("Presione una tecla para continuar...");
			getchar(); getchar();
			break;
		}
	} while (opcion != 8);
	
	return 0;
}

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

void mostrarPuestos(TIQUETE *t, int i) {
	int recorre = 0;
	printf("\nPUESTOS DEL BUS %d: \n", i);
	for (int k = 0; k < 3; k++) {
		for (int j = 0; j < 3; j++) {
			if (t->Bus[i].puestos[k][j] == 0) {
				printf("|%d : V|", recorre + 1);
			} else {
				printf("|%d : F|", recorre + 1);
			}
			recorre++;
		}
		printf("\n");
	}
}

void registro(TIQUETE *t, int i, int NumBus) {
	printf("\n\t\tINGRESE SUS DATOS");
	switch (NumBus) {
	case 0: 
		strcpy(t[i].destino, "NEW YORK - THE VEGA");
		strcpy(t[i].Bus[NumBus].horaExit, "5:00 PM");
		strcpy(t[i].Bus[NumBus].placa, "111 ALV");
		strcpy(t[i].Bus[NumBus].nombreChofer, "ALVARO ANDRES DELGADO OVIEDO");
		break;
	case 1: 
		strcpy(t[i].destino, "GUATEMALA - PARIS");
		strcpy(t[i].Bus[NumBus].horaExit, "7:00 PM");
		strcpy(t[i].Bus[NumBus].placa, "666 XXX");
		strcpy(t[i].Bus[NumBus].nombreChofer, "STELLA GIRALDO");
		break;
	case 2: 
		strcpy(t[i].destino, "CHAPINERO - PUERTO RICO");
		strcpy(t[i].Bus[NumBus].horaExit, "8:00 PM");
		strcpy(t[i].Bus[NumBus].placa, "369 QUK");
		strcpy(t[i].Bus[NumBus].nombreChofer, "WILLIAM PITERGO");
		break;
	}
	printf("\nDESTINO: %s", t[i].destino);
	printf("\nHORA EXIT: %s", t[i].Bus[NumBus].horaExit);
	printf("\nNOMBRE: ");
	getchar(); // Consumir el carácter de nueva línea pendiente
	gets(t[i].DatosP.nombre);
	printf("C.C o T.I: ");
	scanf("%d", &t[i].DatosP.Id);
	printf("CELULAR: ");
	scanf("%d", &t[i].DatosP.Phone);
	t[i].numBus = NumBus;
	int p;
	printf("PUESTO: ");
	scanf("%d", &p);
	if (p >= 1 && p <= 9) {
		int k = (p - 1) / 3;
		int j = (p - 1) % 3;
		t->Bus[NumBus].puestos[k][j] = 1; // Asignar puesto
		t[i].DatosP.Puesto = p;
	} else {
		printf("\n\tNO EXISTE ESE PUESTO");
	}
}

void mostrarLista(TIQUETE *t, int i) {
	printf("\n"); 
	printf("DESTINO: %s\n", t[i].destino);
	printf("NOMBRE: %s", t[i].DatosP.nombre);
	printf("\nC.C o T.I: %d\n", t[i].DatosP.Id);   
	printf("CELULAR: %d\n", t[i].DatosP.Phone); 
	printf("PUESTO: %d", t[i].DatosP.Puesto);
	printf("\nBUS: %d", t[i].numBus); 
	printf("\n"); 
}

int BuscarId(TIQUETE *t, int i, int dato) {
	for (int j = 0; j < i; j++) {
		if (t[j].DatosP.Id == dato) {
			return j;
		}
	}
	return -1;    
}

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

void limpiarPuesto(TIQUETE *t, int n, int NumBus) {
	if (n >= 1 && n <= 9) {
		int k = (n - 1) / 3;
		int j = (n - 1) % 3;
		t->Bus[NumBus].puestos[k][j] = 0; // Limpiar puesto
	}
}
