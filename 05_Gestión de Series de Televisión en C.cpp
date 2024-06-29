#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX_SERIES 30
#define MAX_TEMPORADAS 5

typedef struct {
	int dia;
	int mes;
	int ano;
} FECHA;

typedef struct {
	char nombre[50];
	int hora;
	int minutos;
	int segundos;
	int numCap;
} CAPITULO;

typedef struct {
	CAPITULO capitulo[MAX_SERIES];
	int NumCap;
	FECHA fecha;
} TEMPORADA;

typedef struct {
	char nombre[50];
	int codigo;
	int Numtemp;
	TEMPORADA temporada[MAX_TEMPORADAS];
	char categoria[20];
	char nombreDir[100];
} SERIE;

// Prototipos de funciones
int menu();
void insertarSerie(SERIE *s, int *tam);
void EscogerCategoria(SERIE *s, int tam, int dato);
void categorias();
void mostrarLista(SERIE *s, int tam);
void mostrarUnaSerie(SERIE *s, int x);
int buscarSeriePorNombre(SERIE *s, int tam, char NameSerie[50]);
int buscarSeriePorCategoria(SERIE *s, int tam, char NameCategoria[20]);
int buscarPorId(SERIE *s, int tam, int dato);
void eliminarSerie(SERIE *s, int *tam, int dato);
void guardarSerie(SERIE *s, int tam);

int main() {
	int opcion, encontrado, buscarId, eliminarId;
	char nombreserie[50], nombreCategoria[20];
	int tam = 0;
	SERIE series[MAX_SERIES];
	
	do {
		system("cls");
		opcion = menu();
		
		switch (opcion) {
		case 1:
			system("cls");
			insertarSerie(series, &tam);
			break;
		case 2:
			system("cls");
			mostrarLista(series, tam);
			break;
		case 3:
			system("cls");
			printf("\nDIGITE EL NOMBRE QUE DESEA BUSCAR: ");
			fflush(stdin);
			gets(nombreserie);
			encontrado = buscarSeriePorNombre(series, tam, nombreserie);
			if (encontrado != -1) {
				printf("\nLA SERIE QUE ESTA BUSCANDO ES: \t");
				mostrarUnaSerie(series, encontrado);
			} else {
				printf("\nNO HUBO COINCIDENCIA\n");
			}
			getch();
			break;
		case 4:
			system("cls");
			printf("\nDIGITE LA CATEGORIA QUE DESEA BUSCAR: ");
			fflush(stdin);
			gets(nombreCategoria);
			encontrado = buscarSeriePorCategoria(series, tam, nombreCategoria);
			if (encontrado != -1) {
				printf("\nSERIES DE CATEGORIA : %s", nombreCategoria);
				mostrarUnaSerie(series, encontrado);
			} else {
				printf("\nNO HUBO COINCIDENCIA\n");
			}
			getch();
			break;
		case 5:
			system("cls");
			printf("\nDIGITE EL NOMBRE DE LA SERIE QUE DESEA MODIFICAR: ");
			fflush(stdin);
			gets(nombreserie);
			encontrado = buscarSeriePorNombre(series, tam, nombreserie);
			if (encontrado != -1) {
				printf("\nSERIE: \t");
				mostrarUnaSerie(series, encontrado);
				insertarSerie(series, &encontrado);
				mostrarUnaSerie(series, encontrado);
			} else {
				printf("\nNO HUBO COINCIDENCIA");
			}
			getch();
			break;
		case 6:
			system("cls");
			printf("\nDIGITE LA ID QUE DESEA ELIMINAR: \t  ");
			scanf("%d", &buscarId);
			eliminarId = buscarPorId(series, tam, buscarId);
			if (eliminarId != -1) {
				eliminarSerie(series, &tam, eliminarId);
			} else {
				printf("\nNO HAY COINCIDENCIA\n");
			}
			getch();
			break;
		case 7:
			system("cls");
			printf("\nDIGITE EL NOMBRE DE LA SERIE QUE DESEA GUARDAR: ");
			fflush(stdin);
			gets(nombreserie);
			encontrado = buscarSeriePorNombre(series, tam, nombreserie);
			if (encontrado != -1) {
				guardarSerie(series, encontrado);
			} else {
				printf("\nNO HUBO COINCIDENCIA");
			}
			getch();
			break;
		case 8:
			printf("      ---------------------\n");
			printf("      <<<<<<¡Bye-bye!>>>>>> \n");
			printf("      ---------------------\n");
			break;
		default:
			printf("Opcion incorrecta. Digite nuevamente una opcion:");
			break;
		}
		
	} while (opcion != 8);
	
	return 0;
}

// Función para mostrar el menú principal
int menu() {
	int opc;
	printf("\n|-------------------------------------|");
	printf("\n|                MENU                 |");
	printf("\n|-------------------------------------|");
	printf("\n| 1. INSERTAR SERIE                   |");
	printf("\n| 2. IMPRIMIR LISTA                   |");
	printf("\n| 3. BUSCAR SERIE POR NOMBRE          |");
	printf("\n| 4. BUSCAR SERIE POR CATEGORIA       |");
	printf("\n| 5. MODIFICAR SERIE COMPLETAMENTE    |");
	printf("\n| 6. ELIMINAR SERIE                   |");
	printf("\n| 7. GUARDAR SERIE                    |");
	printf("\n| 8. SALIR                            |");
	printf("\n|-------------------------------------|");
	printf("\nOPCION: \t");
	scanf("%d", &opc);
	return opc;
}

// Función para insertar una nueva serie
void insertarSerie(SERIE *s, int *tam) {
	int i = *tam;
	int categ, numCap, tempo;
	printf("\n\tDIGITE ACONTINUACION LOS DATOS DE LA SERIE %d: ", i + 1);
	printf("\nNOMBRE: \t");
	fflush(stdin);
	gets(s[i].nombre);
	printf("CODIGO: \t");
	scanf("%d", &s[i].codigo);
	printf("DIGITE EL NUMERO DE TEMPORADAS: ");
	scanf("%d", &tempo);
	s[i].Numtemp = tempo;
	
	for (int h = 0; h < tempo; h++) {
		printf("\nDIGITE DATOS DE LA TEMPORADA %d:\n", h + 1);
		printf("FECHA DE ESTRENO: \n");
		printf("DIA: ");
		scanf("%d", &s[i].temporada[h].fecha.dia);
		printf("MES: ");
		scanf("%d", &s[i].temporada[h].fecha.mes);
		printf("AÑO: ");
		scanf("%d", &s[i].temporada[h].fecha.ano);
		printf("DIGITE LA CANTIDAD DE CAPITULOS: \n");
		scanf("%d", &numCap);
		s[i].temporada[h].NumCap = numCap;
		
		for (int k = 0; k < numCap; k++) {
			printf("INGRESE EL NOMBRE DEL CAPITULO %d: ", k + 1);
			fflush(stdin);
			gets(s[i].temporada[h].capitulo[k].nombre);
			printf("INGRESE LA DURACION: \n");
			printf("HORA: ");
			scanf("%d", &s[i].temporada[h].capitulo[k].hora);
			printf("MINUTOS: ");
			scanf("%d", &s[i].temporada[h].capitulo[k].minutos);
			printf("SEGUNDOS: ");
			scanf("%d", &s[i].temporada[h].capitulo[k].segundos);
			printf("\n");
		}
	}
	printf("DIGITE EL NOMBRE DEL DIRECTOR: ");
	fflush(stdin);
	gets(s[i].nombreDir);
	printf("\nDIGITE LA CATEGORIA:\n");
	categorias();
	
	do {
		printf("\nOPCION: \t");
		scanf("%d", &categ);
		if (categ < 1 || categ > 9)
			printf("\nEL NUMERO QUE INGRESO NO HACE PARTE DE NINGUNA CATEGORIA");
	} while (categ < 1 || categ > 9);
	
	EscogerCategoria(s, i, categ);
	(*tam)++;
	system("cls");
}

// Función para asignar la categoría a una serie
void EscogerCategoria(SERIE *s, int tam, int dato) {
	switch (dato) {
	case 1:
		strcpy(s[tam].categoria, "DRAMA");
		break;
	case 2:
		strcpy(s[tam].categoria, "COMEDIA");
		break;
	case 3:
		strcpy(s[tam].categoria, "ACCION");
		break;
	case 4:
		strcpy(s[tam].categoria, "CIENCIA FICCION");
		break;
	case 5:
		strcpy(s[tam].categoria, "TERROR");
		break;
	case 6:
		strcpy(s[tam].categoria, "FANTASIA");
		break;
	case 7:
		strcpy(s[tam].categoria, "SUSPENSO");
		break;
	case 8:
		strcpy(s[tam].categoria, "MUSICAL");
		break;
	case 9:
		strcpy(s[tam].categoria, "ANIMACION");
		break;
	}
}

// Función para mostrar las categorías disponibles
void categorias() {
	printf("\n|----------------------|");
	printf("\n|    CATEGORIAS        |");
	printf("\n|----------------------|");
	printf("\n| 1. DRAMA             |");
	printf("\n| 2. COMEDIA           |");
	printf("\n| 3. ACCION            |");
	printf("\n| 4. CIENCIA FICCION   |");
	printf("\n| 5. TERROR            |");
	printf("\n| 6. FANTASIA          |");
	printf("\n| 7. SUSPENSO          |");
	printf("\n| 8. MUSICAL           |");
	printf("\n| 9. ANIMACION         |");
	printf("\n|----------------------|");
}

// Función para mostrar la lista de series
void mostrarLista(SERIE *s, int tam) {
	for (int i = 0; i < tam; i++) {
		mostrarUnaSerie(s, i);
	}
	getch();
}

// Función para mostrar una serie específica
void mostrarUnaSerie(SERIE *s, int x) {
	printf("\nNOMBRE: %s\n", s[x].nombre);
	printf("CODIGO: %d\n", s[x].codigo);
	printf("NUMERO DE TEMPORADAS: %d\n", s[x].Numtemp);
	
	for (int i = 0; i < s[x].Numtemp; i++) {
		printf("TEMPORADA %d:\n", i + 1);
		printf("FECHA DE ESTRENO: %d/%d/%d\n", s[x].temporada[i].fecha.dia, s[x].temporada[i].fecha.mes, s[x].temporada[i].fecha.ano);
		printf("NUMERO DE CAPITULOS: %d\n", s[x].temporada[i].NumCap);
		
		for (int j = 0; j < s[x].temporada[i].NumCap; j++) {
			printf("CAPITULO %d: %s\n", j + 1, s[x].temporada[i].capitulo[j].nombre);
			printf("DURACION: %d:%d:%d\n", s[x].temporada[i].capitulo[j].hora, s[x].temporada[i].capitulo[j].minutos, s[x].temporada[i].capitulo[j].segundos);
		}
	}
	printf("NOMBRE DEL DIRECTOR: %s\n", s[x].nombreDir);
	printf("CATEGORIA: %s\n", s[x].categoria);
}

// Función para buscar una serie por su nombre
int buscarSeriePorNombre(SERIE *s, int tam, char NameSerie[50]) {
	for (int i = 0; i < tam; i++) {
		if (strcmp(s[i].nombre, NameSerie) == 0) {
			return i;
		}
	}
	return -1;
}

// Función para buscar una serie por su categoría
int buscarSeriePorCategoria(SERIE *s, int tam, char NameCategoria[20]) {
	for (int i = 0; i < tam; i++) {
		if (strcmp(s[i].categoria, NameCategoria) == 0) {
			return i;
		}
	}
	return -1;
}

// Función para buscar una serie por su ID
int buscarPorId(SERIE *s, int tam, int dato) {
	for (int i = 0; i < tam; i++) {
		if (s[i].codigo == dato) {
			return i;
		}
	}
	return -1;
}

// Función para eliminar una serie
void eliminarSerie(SERIE *s, int *tam, int dato) {
	for (int i = dato; i < *tam - 1; i++) {
		s[i] = s[i + 1];
	}
	(*tam)--;
	printf("\nLA SERIE HA SIDO ELIMINADA EXITOSAMENTE\n");
}

// Función para guardar una serie en un archivo
void guardarSerie(SERIE *s, int tam) {
	FILE *archivo = fopen("Series.txt", "a");
	if (archivo == NULL) {
		printf("\nError al abrir el archivo\n");
		return;
	}
	fprintf(archivo, "NOMBRE: %s\n", s[tam].nombre);
	fprintf(archivo, "CODIGO: %d\n", s[tam].codigo);
	fprintf(archivo, "NUMERO DE TEMPORADAS: %d\n", s[tam].Numtemp);
	
	for (int i = 0; i < s[tam].Numtemp; i++) {
		fprintf(archivo, "TEMPORADA %d:\n", i + 1);
		fprintf(archivo, "FECHA DE ESTRENO: %d/%d/%d\n", s[tam].temporada[i].fecha.dia, s[tam].temporada[i].fecha.mes, s[tam].temporada[i].fecha.ano);
		fprintf(archivo, "NUMERO DE CAPITULOS: %d\n", s[tam].temporada[i].NumCap);
		
		for (int j = 0; j < s[tam].temporada[i].NumCap; j++) {
			fprintf(archivo, "CAPITULO %d: %s\n", j + 1, s[tam].temporada[i].capitulo[j].nombre);
			fprintf(archivo, "DURACION: %d:%d:%d\n", s[tam].temporada[i].capitulo[j].hora, s[tam].temporada[i].capitulo[j].minutos, s[tam].temporada[i].capitulo[j].segundos);
		}
	}
	fprintf(archivo, "NOMBRE DEL DIRECTOR: %s\n", s[tam].nombreDir);
	fprintf(archivo, "CATEGORIA: %s\n", s[tam].categoria);
	fprintf(archivo, "--------------------------------------\n");
	fclose(archivo);
	printf("\nLA SERIE HA SIDO GUARDADA EXITOSAMENTE\n");
}
