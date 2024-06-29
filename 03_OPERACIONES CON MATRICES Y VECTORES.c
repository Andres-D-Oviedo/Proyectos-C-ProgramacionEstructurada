#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu();

int main() {    
	srand(time(NULL));
	int suma = 0, resta = 0, traza = 0;
	int n, a, i, j, escalar, Q, v;
	
	printf("DIGITE ORDEN DE LA MATRIZ: \t");
	scanf("%d", &n);
	printf("\n");
	int A[n][n];
	int B[n][n];
	
	printf("\nDIGITE EL TAMAÑO DEL VECTOR: ");
	scanf("%d", &a);
	
	// Inicializo dos vectores para el producto punto 
	int y[a], t[a], r[a];
	for (j = 0; j < a; j++)
		y[j] = rand() % 5;
	for (j = 0; j < a; j++)
		t[j] = rand() % 5;
	
	// Matriz generada inicializada
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			A[i][j] = rand() % 5;
			
			// Segunda matriz inicializada para suma y resta
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					B[i][j] = rand() % 5;
					
					do {
						system("cls");
						int opc = menu(); 
						switch (opc) { 
						case 1: 
							printf("\n\t\tMATRIZ GENERADA\n");
							for (i = 0; i < n; i++) {
								for (j = 0; j < n; j++)
									printf("%d  ", A[i][j]);
								printf("\n");
							}
							break;
						case 2: 
							printf("\n\t\tMATRIZ TRANSPUESTA\n");
							for (i = 0; i < n; i++) {
								for (j = 0; j < n; j++)
									printf("%d  ", A[j][i]);
								printf("\n");
							}
							getchar();        
							break;
						case 3: 
							printf("\n\t\tMATRIZ SUMA\n");
							for (i = 0; i < n; i++) {
								for (j = 0; j < n; j++) {
									suma = A[i][j] + B[i][j];
									printf("%d  ", suma);
								}
								printf("\n");
							}
							break; 
						case 4: 
							printf("\n\t\tMATRIZ RESTA\n");
							for (i = 0; i < n; i++) {
								for (j = 0; j < n; j++) {
									resta = A[i][j] - B[i][j];
									printf("%d  ", resta);
								}
								printf("\n");
							}
							break; 
						case 5: 
							for (i = 0; i < n; i++)
								for (j = 0; j < n; j++)
									if (i == j)
										traza += A[i][j];
										printf("\nLA TRAZA DE LA MATRIZ ES: %d", traza);
										break; 
						case 6: 
							printf("\nDIGITE EL ESCALAR: ");
							scanf("%d", &escalar);
							printf("\n\t\tMATRIZ GENERADA POR ESCALAR\n");
							for (i = 0; i < n; i++) {
								for (j = 0; j < n; j++) {
									Q = escalar * A[i][j];
									printf("%d  ", Q);
								}       
								printf("\n"); 
							}
							break;
						case 7:
						case 8:
						case 9: 
						{
							int orden = (opc == 7) ? 2 : (opc == 8) ? 3 : 4;
							int UNO[orden][orden], DOS[orden][orden], TRES[orden][orden];
							for (i = 0; i < orden; i++)
								for (j = 0; j < orden; j++) {
									UNO[i][j] = rand() % 10;
									DOS[i][j] = rand() % 10;
							}
								printf("\n\t\tMATRIZ UNO\n");
								for (i = 0; i < orden; i++) {
									for (j = 0; j < orden; j++)
										printf("%d  ", UNO[i][j]);
									printf("\n");
								}
								printf("\n\t\tMATRIZ DOS\n");
								for (i = 0; i < orden; i++) {
									for (j = 0; j < orden; j++)
										printf("%d  ", DOS[i][j]);
									printf("\n");
								}
								for (i = 0; i < orden; i++)
									for (j = 0; j < orden; j++) {
										TRES[i][j] = 0;
										for (int k = 0; k < orden; k++)
											TRES[i][j] += UNO[i][k] * DOS[k][j];
								}
									printf("\n\t\tMATRIZ PRODUCTO\n");
									for (i = 0; i < orden; i++) {
										for (j = 0; j < orden; j++)
											printf("%d  ", TRES[i][j]);
										printf("\n");
									}
						}
						break;
						case 10: 
							printf("\nVECTOR 1: \n\n");
							for (i = 0; i < a; i++)
								printf("%d  ", y[i]);
							printf("\nVECTOR 2: \n\n");
							for (i = 0; i < a; i++)
								printf("%d  ", t[i]);
							printf("\nVECTOR PRODUCTO PUNTO: \n\n");
							for (j = 0; j < a; j++) {
								r[j] = y[j] * t[j];
								printf("%d  ", r[j]);
							}
							break;
						case 11: 
							printf("\nVECTOR 1: \n\n");
							for (i = 0; i < a; i++)
								printf("%d  ", y[i]);
							printf("\nVECTOR 2: \n\n");
							for (i = 0; i < a; i++)
								printf("%d  ", t[i]);
							printf("\nVECTOR SUMA: \n\n");
							for (i = 0; i < a; i++) {
								r[i] = y[i] + t[i];
								printf("%d  ", r[i]);
							}
							break;        
						case 12: 
							printf("\nVECTOR 1: \n\n");
							for (i = 0; i < a; i++)
								printf("%d  ", y[i]);
							printf("\nVECTOR 2: \n\n");
							for (i = 0; i < a; i++)
								printf("%d  ", t[i]);
							printf("\nVECTOR RESTA: \n\n");
							for (i = 0; i < a; i++) {
								r[i] = y[i] - t[i];
								printf("%d  ", r[i]);
							}
							break;
						default:  
							printf("\nEL NUMERO QUE INGRESO NO SE ENCUENTRA EN EL MENU!");
							break;
						}
						printf("\n|---------------------|");
						printf("\n|     MENU ALTERNO    |");
						printf("\n|---------------------|");
						printf("\n|1. MENU PRINCIPAL    |");
						printf("\n|2. SALIR             |"); 
						printf("\n|---------------------|");
						printf("\nOPCION: ");
						scanf("%d", &v);
					} while (v == 1);
					printf("      ---------------------\n");
					printf("      <<<<<<¡Bye-bye!>>>>>> \n");
					printf("      ---------------------\n");
					getchar();
					return 0;
}

int menu() {
	printf("\n|-------------------------------------------------|");
	printf("\n|                      MENU                       |");
	printf("\n|-------------------------------------------------|");
	printf("\n|       OPERACIONES CON LA MATRIZ GENERADA        |");
	printf("\n|                                                 |");
	printf("\n| 1. MOSTRAR MATRIZ GENERADA                      |");
	printf("\n| 2. MOSTRAR TRANSPUESTA DE LA MATRIZ GENERADA    |");
	printf("\n| 3. SUMA DE MATRICES                             |");
	printf("\n| 4. RESTA DE MATRICES                            |");
	printf("\n| 5. MOSTRAR TRAZA DE LA MATRIZ GENERADA          |");
	printf("\n| 6. MULTIPLICACION ESCALAR POR MATRIZ GENERADA   |");
	printf("\n|-------------------------------------------------|");
	printf("\n|   OPERACION PRODUCTO MATRICIAL PARA MATRICES    |");
	printf("\n|-------------------------------------------------|");
	printf("\n| 7. PRODUCTO 2X2                                 |");
	printf("\n| 8. PRODUCTO 3X3                                 |");
	printf("\n| 9. PRODUCTO 4X4                                 |");
	printf("\n|-------------------------------------------------|");
	printf("\n|        OPERACIONES CON VECTORES                 |");
	printf("\n|-------------------------------------------------|");
	printf("\n| 10. PRODUCTO PUNTO                              |");
	printf("\n| 11. SUMA DE VECTORES                            |");
	printf("\n| 12. RESTA DE VECTORES                           |");
	printf("\n|-------------------------------------------------|");
	printf("\n|    DIGITE EL NUMERO DE LA OPERACION A REALIZAR  |");
	printf("\n|-------------------------------------------------|");
	int opc;
	scanf("%d", &opc);
	return opc;
}
