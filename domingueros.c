#include <stdio.h>
#include <string.h>
#include<stdbool.h>

void resenyas();
char Min_May(char palabra[50]);
void recomendacion();
void estrellas(int num, FILE*fichero);

struct madrid{
	char sitio[50];
	char direccion[50];
	char nivel[10];
};
struct datos{
	char nombre[30];
	char apellidos[100];
	int edad;
	char apodo[20];
	char contrasena[20];
	char email[100];
	char lugar[30];
};
struct TActividad{
	char zona[100];
	char actividad[100];
};
	
int main () {
	struct datos usuarios[100];
	struct TActividad actividad[100];
	int opcion, i, j;
	int no_cuenta = 0, no_email = 0, ayuda;
	bool punto = false, arroba = false, es_cuenta = false, diferente = false;
	int cuentas = 0, longitud_ap = 0, longitud_con = 0;
	char contrasena[20], apodo[20], email[100];
	int nActividad=0;
	FILE *pfichero;
	
	printf(" Bienvenido a DOMINGUEROS\n");
	
	do{
		printf("\n MENU \n");
		printf("\n (1)-Iniciar sesion \n");
		printf("\n (2)-Registrarse \n");
		printf("\n (3)-Nuevos eventos de la semana\n");
		printf("\n (4)-Todas las actividades\n");
		printf("\n (5)-Resenyas\n");
		printf("\n (6)-Informacion sobre la aplicacion\n");
		printf("\n (7)-Salir de la aplicacion\n");
	
		printf("\n Seleccinar opcion tecleandola en el ordenador el número asociado a la opcion a la que se desea acceder.\n");
	
		scanf("%d", &opcion);
	
		if ( opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 6){
			printf ("No se ha introducido un numero adecuado");
		}

	} while ( opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 6);
	
	switch (opcion) {
		case 1:
			printf("-----------------------INICIAR SESION-----------------------\n");
			printf ("\n");
			// HABRÁ QUE COMPROBARLO MÁS ADELANTE
			do{
				printf ("Apodo:\n");
				scanf ("%s", apodo);
				printf ("Contraseña:\n");
				scanf ("%s", contrasena);
				
				for (i=0; i<cuentas; i++){
					if (usuarios[i].apodo != apodo || usuarios[i].contrasena != contrasena){
						es_cuenta = false;
						no_cuenta++;
						printf ("No coincide con ninguna cuenta ya creada");
					}else{
						es_cuenta = true;
					}
				}
				
				if (no_cuenta == 3){
					printf ("Necesita ayuda?");
					printf ("\n");
							
					printf ("(1)-Volver a iniciar sesion. Teclee 1 para iniciar sesion\n");
					printf ("(2)-No recuerda su contraseña. Teclee 2 si quiere recuperarla\n");
					
					scanf ("%d", &ayuda);
							
					switch (ayuda) {
						case 1:
							printf ("Ha escogido VOLVER A INICAR SESION\n");
							printf ("\n");
							break;
						case 2:
							printf ("Ha escogido RECUPERAR CONTRASEÑA\n");
							printf ("\n");
							
							do {
								printf("\nCorreo:\t");
								scanf("%s", usuarios[cuentas].email);
								
								for (i=0; i<cuentas; i++){
									if (usuarios[i].email == email){
										printf ("Tu apodo es: %s\t", usuarios[i].apodo);
										printf ("Tu contrasena es: %s\t", usuarios[i].contrasena);	
									} else{
										printf ("No coincide con ninguna cuenta ya creada\n");
										no_email++;
									}
								}
							} while (no_email<=5);
							break;
					}
				}
			} while (es_cuenta == false && no_cuenta<3 || no_email==5 || ayuda == 1);
			
			no_email = 0;
			no_cuenta = 0;
			
			printf("\nBienvenido de nuevo\n");
			break;
		case 2:
			printf("-----------------------CREAR CUENTA NUEVA-----------------------\n");
			printf ("\n");
			printf ("Complete con sus datos\n");
			printf ("\n");
			
			do {
				printf ("Nombre:\t");
				fflush (stdin);
				gets (usuarios[cuentas].nombre);
				
				printf ("\nApellidos:\t");
				gets (usuarios[cuentas].apellidos);

				if (usuarios[cuentas].nombre[0] == '\0' || usuarios[cuentas].apellidos[0] == '\0'){
					printf ("ERROR. Debe completar adecuadamente con sus datos todos los campos\n");
				}
	
			} while (usuarios[cuentas].nombre[0] == '\0' || usuarios[cuentas].apellidos[0] == '\0');
			
			printf ("\nEdad:\t");
			scanf ("%d", &usuarios[cuentas].edad);
			
			if (usuarios[cuentas].edad <18){
				printf("El contenido estara adaptado a su edad\n");
			}
			
			do{
				printf ("\nNombre de usuario o apodo:\t");
				scanf ("%s", usuarios[cuentas].apodo);
				
				longitud_ap = strlen(usuarios[cuentas].apodo);
	
				if (usuarios[cuentas].apodo[0] == '\0'){ // ESTE CONDICIONAL NO ME LO LEE 
					printf ("\nERROR. Debe completar adecuadamente con sus datos todos los campos\n");
					
				}
				if (longitud_ap >8){
					printf("Tu apodo es demasiado largo. Maximo 8 caracteres\n");
					
				} // else { // AQUI COMPROBAMOS SI EL APODO INTRODUCIDO COINCIDE CON ALGUNO YA REGISTRADO
					//for (i=0; i<cuentas; i++){      	
						//if (usuarios[i].apodo == usuarios[cuentas].apodo){
							//diferente = false;
							//printf ("Este nombre ya ha sido escogido. Intentelo de nuevo\n");
						//} else{
							//diferente = true;
						//}
					//} // HABRÁ QUE COMPROBARLO MÁS A DELANTE	
				//} || diferente == false
			} while ( usuarios[cuentas].apodo[0] == '\0' || longitud_ap >8);
			
			do{
				printf ("\nContrasena:\n");
				scanf ("%s", usuarios[cuentas].contrasena);
				longitud_con = strlen(usuarios[cuentas].contrasena);
				
				if (usuarios[cuentas].contrasena[0] == '\0'){
					printf ("\nERROR. Debe completar adecuadamente con sus datos todos los campos\n");
					
				}else if (longitud_con < 8 || usuarios[cuentas].contrasena[0] == '\0'){
					printf ("Tu contrasena es demasiado corta. Minimo 8 caracteres\n");
				}
			} while (longitud_con < 8);
			
			do {
				printf("\nCorreo:\t");
				scanf("%s", usuarios[cuentas].email);
					
				for (j=0; usuarios[cuentas].email[j]!= '\0';j++){
						
					if (usuarios[cuentas].email[j] == '@'){
						arroba = true;
					}
					if (usuarios[cuentas].email[j] == '.'){
						punto = true;
					}
				}
					
				if (arroba == false || punto == false){
					printf ("El correo introducido no es valido\n");
					arroba = false;
					punto = false;
				}
					
			} while (arroba == false || punto == false);
			
				
			printf ("\nLugar de residencia en la Comunidad de Madrid:\t");
			scanf ("%s", usuarios[cuentas].lugar);
		
			printf("Cuenta creada con exito");
			printf("Ya somos %d domingueros!", cuentas+1);
			cuentas++;	
			
			break;
		case 3:
			printf("-----------------------NOVEDADES DE LA SEMANA-----------------------\n");
			printf("\n");
			break;
		case 4:
			printf("-----------------------TODAS LAS ACTIVIDADES-----------------------\n");
			printf("\n");
			printf("Esta son todas las actividades disponibles:\n");
			pfichero=fopen("actividades.txt","r");
	
			if(pfichero== NULL){
				printf("No se encuentra el fichero\n");
				return 0;
			}
		
			while (fscanf(pfichero, "%s %s ",actividad[nActividad].zona,
			actividad[nActividad].actividad != EOF){
				printf("%s %s\n",actividad[nActividad].zona, actividad[nActividad].actividad);
				nActividad++;
			}
			fclose(pfichero);
			break;
		case 5:
			printf("-----------------------RESENYAS-----------------------\n");
			printf("\n");
			resenyas();
			recomendacion();
			break;
		case 6:
			printf("-----------------------INFORMACION SOBRE LA APLICACION-----------------------\n");
			printf("\n");
			break;
		case 7:
			printf("Ha seleccionado la opcion de SALIR\n");
			printf("Hasta pronto");
			break;
					
	}
}

void resenyas(){
	char cadena[100];
	FILE*pfichero;
	
		pfichero = fopen ("RESEÑAS.txt", "r");
								
		if (pfichero != NULL) {
			while ((fgets(cadena,sizeof (cadena), pfichero))!= NULL){
				printf ("%s\n", cadena);
			}
		} else{
			printf("No se encuentra el fichero\n");
		}
	fclose(pfichero);
}

void estrellas(int num, FILE*fichero){
	int i;
	char asteriscos[4];
	for (i=0; i<=num; i++) {
		asteriscos[i]='*';
	}

	fprintf(fichero,"PUNTUACION: %s", asteriscos);
	fclose(fichero);
}
char Min_May(char palabra[50]){
	int i=0;
	for (i=0;palabra[i]!='\0';++i){
		if(palabra[i]>='a' && palabra[i]<='z'){
			palabra[i]=palabra[i]-32;
		}
	}
	return palabra;
}	
void recomendacion(){
	int recomendar, i, muy_recomendado=4, esta_bien=3, mejorable=2, no_recomendado=1;
	char nombre[50],apellidos[50],cadena[100];
	struct madrid viajero;
	FILE*pfichero;
	
	printf("Para ESCRIBIR RECOMENDACION introduzca '1'. Despues debera escribir su nombre y apellidos\n");
	printf("En caso contrario pulse 0\n");
	scanf("%d", &recomendar);
	if(recomendar == 1){
		printf("Nombre:\n");
		fflush(stdin);
		gets(nombre);
		printf("Apellidos:\n");
		gets(apellidos);
		strcat(nombre, " ");
		strcat(nombre ,apellidos);
		
		pfichero = fopen ("RESEÑAS.txt", "a+");
	
		if (pfichero != NULL) {
			fprintf(pfichero, "- %s\n", nombre);
		
			printf("Introduzca SITIO DE MADRID visitado:");
			gets(viajero.sitio);
			Min_May(viajero.sitio);
			printf("DIRECCION:");
			gets(viajero.direccion);
			Min_May(viajero.direccion);
			printf("MUY RECOMENDADO/ESTA BIEN/'MEJORABLE/NO RECOMENDADO:");
			gets(viajero.nivel);
			Min_May(viajero.nivel);
			printf("Describa su experiencia en 3 lineas de 100 caracteres cada una como maximo\n");
			
			fprintf(pfichero, "%s-%s-%s\n", viajero.sitio, viajero.direccion, viajero.nivel);
			for (i=0; i <= 2; i++){
				gets(cadena);
				fprintf(pfichero, "%s\n", cadena);
			}
			
			if(strcmp(viajero.nivel,"MUY RECOMENDADO")== 0){
				estrellas(muy_recomendado, pfichero);
			} if(strcmp(viajero.nivel,"ESTA BIEN")== 0){
				estrellas(esta_bien, pfichero);
			} if(strcmp(viajero.nivel,"MEJORABLE")== 0){
				estrellas(mejorable, pfichero);
			} if(strcmp(viajero.nivel,"NO RECOMENDADO")== 0){
				estrellas(no_recomendado, pfichero);
			} if((strcmp(viajero.nivel,"MUY RECOMENDADO")!= 0) && (strcmp(viajero.nivel,"ESTA BIEN")!= 0) && (strcmp(viajero.nivel,"MEJORABLE")!=0) && (strcmp(viajero.nivel,"NO RECOMENDADO")!= 0)){
				fprintf(pfichero, "SIN PUNTUACION\n");
			}
			
		} else{
			printf("No se encuentra el fichero\n");
		}
		printf("\n");
		fclose(pfichero);
		
		resenyas();
	} else if(recomendar == 0){
		printf("Hasta luego");
	}
}
