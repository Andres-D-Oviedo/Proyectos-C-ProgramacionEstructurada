#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char nombre[50];
	int edad;
	char sex;
	int id;
	char dir[100];
	char enfermedad[20];
} BOY;

int menu();
int menuListar();
void registro(BOY *b, int tam);
int buscar(BOY *b, int tam, int Id);
void imprimirBoy(BOY *b, int i);

int main() {
	char nEnfermedadH[] = "HEPATITIS";
	char nEnfermedadS[] = "SARAMPION";
	char nEnfermedadO[] = "OTRA ENFERMEDAD";
	BOY boy[100];
	int opcion, EncontradoId, BuscarId, tam = 0;
	int contHombres, contMujeres;
	int E, S, O;
	int op3;
	int a, b;
	
	do {
		contMujeres = 0;
		contHombres = 0;
		opcion = menu();
		switch (opcion) {
		case 1: 
			system("cls");
			registro(boy, tam);
			tam++;
			break;
		case 2: 
			system("cls");
			printf("\n\t\tBUSCAR NIÑO O NIÑA\n");
			printf("\nDIGITE LA IDENTIFICACION: ");
			scanf("%d", &BuscarId);
			EncontradoId = buscar(boy, tam, BuscarId);
			if (EncontradoId == -1)
				printf("\nEL NIÑO NO FUE ENCONTRADO, POR TANTO NO EXISTE JAJA");
			else
				imprimirBoy(boy, EncontradoId);
			break;
		case 3: 
			op3 = menuListar();
			switch (op3) {
			case 1: 
				printf("\n\t\tLISTA DE NIÑOS\n");
				for (int i = 0; i < tam; i++)
					imprimirBoy(boy, i);
				break;
			case 2: 
				printf("\nDIGITE EL RANGO DE EDAD DE NIÑOS: ");
				scanf("%d", &a);
				printf(": ");
				scanf("%d", &b);
				for (int i = 0; i < tam; i++) {
					if (boy[i].sex == 'M') {
						int edad = boy[i].edad;
						if (a < edad && edad < b) {
							int op2;
							printf("\n|-------------------------|");
							printf("\n|    ENFERMEDAD A BUSCAR  ");
							printf("\n| 1. HEPATITIS            ");
							printf("\n| 2. SARAMPION            ");
							printf("\n| 3. OTRA ENFERMEDAD      ");
							printf("\nOPCION: ");
							scanf("%d", &op2);
							if (op2 == 1 && strcmp(nEnfermedadH, boy[i].enfermedad) == 0)
								imprimirBoy(boy, i);
							if (op2 == 2 && strcmp(nEnfermedadS, boy[i].enfermedad) == 0)
								imprimirBoy(boy, i);
							if (op2 == 3 && strcmp(nEnfermedadO, boy[i].enfermedad) == 0)
								imprimirBoy(boy, i);
						}
					}
				}
				break;
			case 3:
				printf("\nDIGITE EL RANGO DE EDAD DE NIÑAS: ");
				scanf("%d", &a);
				printf(": ");
				fflush(stdin);
				scanf("%d", &b);
				for (int i = 0; i < tam; i++) {
					if (boy[i].sex == 'F') {
						int edad = boy[i].edad;
						if (a < edad && edad < b) {
							int op2;
							printf("\n|-------------------------|");
							printf("\n|    ENFERMEDAD A BUSCAR  ");
							printf("\n| 1. HEPATITIS            ");
							printf("\n| 2. SARAMPION            ");
							printf("\n| 3. OTRA ENFERMEDAD      ");
							printf("\nOPCION: ");
							scanf("%d", &op2);
							if (op2 == 1 && strcmp(nEnfermedadH, boy[i].enfermedad) == 0)
								imprimirBoy(boy, i);
							if (op2 == 2 && strcmp(nEnfermedadS, boy[i].enfermedad) == 0)
								imprimirBoy(boy, i);
							if (op2 == 3 && strcmp(nEnfermedadO, boy[i].enfermedad) == 0)
								imprimirBoy(boy, i);
						}
					}
				}
				break;
			case 4: 
				printf("\nDIGITE EL RANGO DE EDAD DE NIÑOS Y NIÑAS: ");
				scanf("%d", &a);
				printf(": ");
				scanf("%d", &b);
				printf("\n|-------------------------|");
				printf("\n|    ENFERMEDAD A BUSCAR  ");
				printf("\n| 1. HEPATITIS            ");
				printf("\n| 2. SARAMPION            ");
				printf("\n| 3. OTRA ENFERMEDAD      ");
				printf("\nOPCION: ");
				int op2;
				scanf("%d", &op2);
				for (int i = 0; i < tam; i++) {
					int edad = boy[i].edad;
					if (a < edad && edad < b) {
						if (op2 == 1 && strcmp(nEnfermedadH, boy[i].enfermedad) == 0)
							imprimirBoy(boy, i);
						else if (op2 == 2 && strcmp(nEnfermedadS, boy[i].enfermedad) == 0)
							imprimirBoy(boy, i);
						else if (op2 == 3 && strcmp(nEnfermedadO, boy[i].enfermedad) == 0)
							imprimirBoy(boy, i);
					}
				}
				break;
			}
			break;
		case 4:
			E = 0;
			S = 0;
			O = 0;
			for (int i = 0; i < tam; i++) {
				if (boy[i].sex == 'M') {
					contHombres++;
					if (strcmp(boy[i].enfermedad, nEnfermedadH) == 0)
						E++;
					else if (strcmp(boy[i].enfermedad, nEnfermedadS) == 0)
						S++;
					else if (strcmp(boy[i].enfermedad, nEnfermedadO) == 0)
						O++;
				}
			}
			printf("\n|----------------------------------------------------------------------|");
			printf("\n|         PORCENTAJES DE NIÑOS AFECTADOS POR ENFERMEDAD                |");
			printf("\n| 1. HEPATITIS: %d%%", (E * 100) / contHombres);
			printf("\n| 2. SARAMPION: %d%%", (S * 100) / contHombres);
			printf("\n| 3. OTRAS ENFERMEDADES: %d%%", (O * 100) / contHombres);
			printf("\n|----------------------------------------------------------------------|");
			getch();
			break;
		case 5:
			E = 0;
			S = 0;
			O = 0;
			for (int i = 0; i < tam; i++) {
				if (boy[i].sex == 'F') {
					contMujeres++;
					if (strcmp(boy[i].enfermedad, nEnfermedadH) == 0)
						E++;
					else if (strcmp(boy[i].enfermedad, nEnfermedadS) == 0)
						S++;
					else if (strcmp(boy[i].enfermedad, nEnfermedadO) == 0)
						O++;
				}
			}
			printf("\n|----------------------------------------------------------------------|");
			printf("\n|         PORCENTAJES DE NIÑAS AFECTADAS POR ENFERMEDAD                |");
			printf("\n| 1. HEPATITIS: %d%%", (E * 100) / contMujeres);
			printf("\n| 2. SARAMPION: %d%%", (S * 100) / contMujeres);
			printf("\n| 3. OTRAS ENFERMEDADES: %d%%", (O * 100) / contMujeres);
			printf("\n|----------------------------------------------------------------------|");
			getch();
			break;
		case 6:
			system("cls");
			printf("      ---------------------\n");
			printf("      <<<<<<¡Bye-bye!>>>>>> \n");
			printf("      ---------------------\n");
			break;
		default:
			printf("Opción inválida. Por favor, intente de nuevo.\n");
		}
	} while (opcion != 6);
	
	getch();
	return 0;
}

void imprimirBoy(BOY *b, int i) {
	printf("\n|---------------------------------------------------------------------------|");
	printf("\n| NOMBRE: %s", b[i].nombre);
	printf("\n| EDAD: %d", b[i].edad);
	printf("\n| IDENTIFICACION: %d", b[i].id);
	printf("\n| DIRECCION: %s", b[i].dir);
	printf("\n| SEXO: %c", b[i].sex);
	printf("\n| ENFERMEDAD: %s", b[i].enfermedad);
	printf("\n|---------------------------------------------------------------------------|\n");
}

int buscar(BOY *b, int tam, int Id) {
	for (int i = 0; i < tam; i++) {
		if (b[i].id == Id)
			return i;
	}
	return -1;
}

void registro(BOY *b, int tam) {
	int i = tam;
	int opc;
	printf("\n|--------------------------------------------------------------|");
	printf("\nDIGITE LOS DATOS DEL NIÑO A REGISTRAR: \n");
	printf("\nNOMBRE: ");
	fflush(stdin);
	gets(b[i].nombre);
	printf("\nEDAD: ");
	scanf("%d", &b[i].edad);
	printf("\nIDENTIFICACION: ");
	scanf("%d", &b[i].id);
	printf("\n|-------------------------|");
	printf("\n|         SEXO            ");
	printf("\n| 1. MASCULINO            ");
	printf("\n| 2. FEMENINO             ");
	do {
		printf("\nOPCION: ");
		scanf("%d", &opc);
		if (opc == 1)
			b[i].sex = 'M';
		if (opc == 2)
			b[i].sex = 'F';
	} while (opc < 1 || opc > 2);
	printf("\nDIRECCION: ");
	fflush(stdin);
	gets(b[i].dir);
	printf("\n|-------------------------|");
	printf("\n|         ENFERMEDAD      ");
	printf("\n| 1. HEPATITIS            ");
	printf("\n| 2. SARAMPION            ");
	printf("\n| 3. OTRA ENFERMEDAD      ");
	printf("\nOPCION: ");
	scanf("%d", &opc);
	if (opc == 1)
		strcpy(b[i].enfermedad, "HEPATITIS");
	if (opc == 2)
		strcpy(b[i].enfermedad, "SARAMPION");
	if (opc == 3)
		strcpy(b[i].enfermedad, "OTRA ENFERMEDAD");
	printf("\nEL NIÑO SE HA REGISTRADO CON EXITO");
	getch();
}

int menu() {
	printf("\n|---------------------------------------------------------------------------|");
	printf("\n|                                MENU                                      |");
	printf("\n| 1. REGISTRAR UN NIÑO                                                     |");
	printf("\n| 2. BUSCAR E IMPRIMIR NIÑO POR ID                                         |");
	printf("\n| 3. LISTAR LOS NIÑOS AFECTADOS                                            |");
	printf("\n| 4. PORCENTAJE DE NIÑOS AFECTADOS POR ENFERMEDAD                          |");
	printf("\n| 5. PORCENTAJE DE NIÑAS AFECTADAS POR ENFERMEDAD                          |");
	printf("\n| 6. SALIR                                                                 |");
	printf("\n|---------------------------------------------------------------------------|");
	int opc;
	printf("\nOPCION: ");
	scanf("%d", &opc);
	return opc;
}

int menuListar() {
	printf("\n|----------------------------------------------------------------------|");
	printf("\n|                           MENU LISTAR                                |");
	printf("\n| 1. TODOS                                                            |");
	printf("\n| 2. NIÑOS ENTRE W AÑOS Y Z AÑOS AFECTADOS POR X ENFERMEDAD            |");
	printf("\n| 3. NIÑAS ENTRE W AÑOS Y Z AÑOS AFECTADAS POR X ENFERMEDAD            |");
	printf("\n| 4. TODOS AFECTADOS ENTRE W AÑOS Y Z AÑOS AFECTADOS POR X ENFERMEDAD  |");
	printf("\n|----------------------------------------------------------------------|");
	int opc;
	printf("\nOPCION: ");
	scanf("%d", &opc);
	return opc;
}
