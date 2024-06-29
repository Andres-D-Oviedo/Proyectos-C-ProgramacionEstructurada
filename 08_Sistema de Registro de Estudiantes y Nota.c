#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura para las materias
struct mat {
	char materia[50];
	int codmat;
	float notas[20];
};

// Definición de la estructura para los datos del estudiante
struct datos {
	char nombre[50];
	char carrera[20];
	long long codigo;
	struct mat materias;
};

// Declaración global de la variable estudiante
struct datos estudiante;

FILE* registros;

// Prototipos de funciones
void registro();
void agregar();
void ver();
int menu();

// Función para registrar nuevos estudiantes
void registro() {
	int num, i;
	char rpt, *nombre;
	char regis[] = "D:\\regis.txt";
	registros = fopen(regis, "wt");
	if (registros == NULL) {
		printf("\n Error en la apertura");
		return;
	}
	fprintf(registros, "Registro de estudiantes\n");
	fflush(stdout);
	fflush(stdin);
	nombre = (char*)malloc(50);
	do {
		fflush(stdin);
		printf("\nIngrese el codigo: ");
		scanf("%lli", &estudiante.codigo);
		printf("\nIngrese el nombre: ");
		fflush(stdin);
		fflush(stdout);
		fgets(nombre, 50, stdin);
		strcpy(estudiante.nombre, nombre);
		printf("\nIngrese la carrera: ");
		gets(estudiante.carrera);
		printf("Cuantas materias ve el estudiante?: ");
		scanf("%d", &num);
		for (i = 0; i < num; i++) {
			fflush(stdin);
			printf("Ingrese la materia %d: ", i + 1);
			gets(estudiante.materias.materia);
		}
		fprintf(registros, "\nNombre: %s", estudiante.nombre);
		fprintf(registros, "Codigo: %lli", estudiante.codigo);
		fprintf(registros, "\nCarrera: %s", estudiante.carrera);
		fprintf(registros, "\nMaterias: %s", estudiante.materias.materia);
		fprintf(registros, "\n");
		printf("Desea agregar mas usuarios?(presione s para si y n para no): ");
		scanf(" %c", &rpt);
		system("cls");
	} while (rpt == 's' || rpt == 'S');
	fclose(registros);
	free(nombre);
}

// Función para agregar más estudiantes al archivo
void agregar() {
	int num, i;
	char rpt, *nombre;
	char regis[] = "D:\\regis.txt";
	registros = fopen(regis, "at");
	if (registros == NULL) {
		printf("\n Error en la apertura");
		return;
	}
	fflush(stdout);
	fflush(stdin);
	nombre = (char*)malloc(50);
	do {
		fflush(stdin);
		printf("\nIngrese el codigo: ");
		scanf("%lli", &estudiante.codigo);
		printf("\nIngrese el nombre: ");
		fflush(stdin);
		fflush(stdout);
		fgets(nombre, 50, stdin);
		strcpy(estudiante.nombre, nombre);
		printf("\nIngrese la carrera: ");
		gets(estudiante.carrera);
		printf("Cuantas materias ve el estudiante?: ");
		scanf("%d", &num);
		for (i = 0; i < num; i++) {
			fflush(stdin);
			printf("Ingrese la materia %d: ", i + 1);
			gets(estudiante.materias.materia);
		}
		fprintf(registros, "\nUsuario agregado");
		fprintf(registros, "\nNombre: %s", estudiante.nombre);
		fprintf(registros, "Codigo: %lli", estudiante.codigo);
		fprintf(registros, "\nCarrera: %s", estudiante.carrera);
		fprintf(registros, "\nMaterias: %s", estudiante.materias.materia);
		fprintf(registros, "\n");
		printf("Desea agregar mas usuarios?(presione s para si y n para no): ");
		scanf(" %c", &rpt);
		system("cls");
	} while (rpt == 's' || rpt == 'S');
	fclose(registros);
	free(nombre);
}

// Función para ver todos los estudiantes registrados
void ver() {
	int a;
	char regis[] = "D:\\regis.txt";
	registros = fopen(regis, "r");
	if (registros == NULL) {
		printf("\n Error en la apertura");
		return;
	}
	while ((a = fgetc(registros)) != EOF) {
		if (a == '\n') {
			printf("\n");
		} else {
			putchar(a);
		}
	}
	fclose(registros);
}

// Función para mostrar el menú y gestionar las opciones
int menu() {
	int opc;
	char a, b;
	printf("\nSeleccione una opción");
	printf("\n1. Registrar estudiante(s).\t2. Añadir estudiante.\t3. Ver estudiantes.\t4. Salir\nOPCION: ");
	scanf("%d", &opc);
	switch (opc) {
	case 1:
		system("cls");
		fflush(stdout);
		printf("Al seleccionar esta opción se borran todos los datos de estudiantes previos. Presione s para continuar y n para regresar al menú: ");
		fflush(stdin);
		scanf(" %c", &a);
		if (a != 's' && a != 'n') {
			printf("Por favor ingrese una de las opciones anteriores: ");
			scanf(" %c", &a);
		} else if (a == 's') {
			registro();
		} else if (a == 'n') {
			system("cls");
			menu();
		}
		printf("_____________________________________________________________________________\n");
		break;
	case 2:
		system("cls");
		fflush(stdout);
		agregar();
		printf("_____________________________________________________________________________\n");
		system("cls");
		break;
	case 3:
		system("cls");
		fflush(stdout);
		ver();
		system("pause");
		system("cls");
		printf("_____________________________________________________________________________\n");
		break;
	case 4:
		printf("Está seguro que desea salir? s/n: ");
		fflush(stdin);
		scanf(" %c", &a);
		if (a == 's')
			break;
		else {
			opc = 0;
			printf("_____________________________________________________________________________\n");
			system("cls");
			break;
		}
	}
	return opc;
}

// Función principal que muestra el menú principal y gestiona las opciones
int main() {
	int opc = 0;
	while (opc != 4) {
		printf("Bienvenido al sistema de notas\n");
		opc = menu();
	}
	return 0;
}
