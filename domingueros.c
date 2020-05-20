#include <stdio.h> // Librería estándar para manipular datos de entrada y salida
#include <string.h> // Librería de manejo de cadenas
#include<stdbool.h> // Librería del tipo booleano (estándar)
#include <stdlib.h> // Librería de rutinas de conversión estándar

int lineasFichero();
void resenyas();
int Min_May(char palabra[50]);
void recomendacion();
void estrellas(int num, FILE*fichero);

struct madrid{
	char sitio[50];
	char direccion[50];
	char nivel[20];
};
struct datos{
	char nombre[30];
	char apellidos[100];
	int edad;
	char email[100];
	char contrasena[20];
	char lugar[30];
};
struct TActividad{
	char zona[100];
	char actividad[100];
};
	
int main () {
	struct datos usuarios[100]; // Registrarse - Iniciar sesión
	struct TActividad actividad[100];
	int opcion, j; //Registrarse
	int no_cuenta = 0, no_email = 0, ayuda, i;
	bool punto = false, arroba = false; // Registrarse
	bool es_cuenta = false, diferente = false;
	int cuentas = 0, longitud_con = 0; // Registrarse
	char contrasena[20], email[100]; // Registrase
	int nActividad=0;
	int cont=1, num; // Novedades
	char cadena[80]; // Novedades
	srand (time(NULL)); //Novedades
	FILE *pfichero;
	FILE *nfichero; // Novedades
	FILE *ufichero; // Registrarse - Iniciar sesion
	
	printf("\t********* Bienvenido a DOMINGUEROS *********\n");
	
	do{
		printf("\n MENU \n");
		printf("\n (1)-Iniciar sesion \n");
		printf("\n (2)-Registrarse \n");
		printf("\n (3)-Nuevos eventos de la semana\n");
		printf("\n (4)-Todas las actividades\n");
		printf("\n (5)-Resenyas\n");
		printf("\n (6)-Informacion sobre la aplicacion\n");
		printf("\n (7)-Salir de la aplicacion\n");
	
		printf("\n Seleccinar opcion tecleando el numero asociado a la opcion a la que se desea acceder.\n");
	
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
				gets (usuarios[0].nombre);
				printf ("\nApellidos:\t");
				gets (usuarios[0].apellidos);

				if (usuarios[0].nombre[0] == '\0' || usuarios[0].apellidos[0] == '\0'){
					printf ("ERROR. Debe completar adecuadamente con sus datos todos los campos\n");
				}
	
			} while (usuarios[0].nombre[0] == '\0' || usuarios[0].apellidos[0] == '\0');
			
			strcat(usuarios[0].nombre, " ");
			strcat(usuarios[0].nombre, usuarios[0].apellidos);
			
			printf ("\nEdad:\t");
			scanf ("%d", &usuarios[0].edad);
			
			do {
				printf("\nCorreo:\t");
				scanf("%s", usuarios[0].email);
					
				for (j=0; usuarios[0].email[j]!= '\0';j++){
						
					if (usuarios[0].email[j] == '@'){
						arroba = true;
					}
					if (usuarios[0].email[j] == '.'){
						punto = true;
					}
				}
					
				if (arroba == false || punto == false){
						printf ("El correo introducido no es valido\n");
						arroba = false;
						punto = false;
				}
					
			} while (arroba == false || punto == false);
			
			do{
				printf ("\nContrasena:\t");
				scanf ("%s", usuarios[0].contrasena);
				longitud_con = strlen(usuarios[0].contrasena);
				
				if (usuarios[0].contrasena[0] == '\0'){ /////////////////////////////////////////////////////////NO SALE
					printf ("\nERROR. Debe completar adecuadamente con sus datos todos los campos\n");
				}
				if (longitud_con < 8){
					printf ("\nTu contrasena es demasiado corta. Minimo 8 caracteres\n");
				}
			} while (longitud_con < 8 || usuarios[0].contrasena[0] == '\0');
			
			printf ("\nLugar de residencia en la Comunidad de Madrid (o provincia):\t");
			scanf ("%s", usuarios[0].lugar);	
			
			ufichero = fopen("USUARIOS.txt", "a+");
			
			if (ufichero == NULL) {
				printf("No se encuentra el fichero\n");
			}
			
			fprintf(ufichero, "%s - %d - %s - %s - %s\n", usuarios[0].nombre, usuarios[0].edad, usuarios[0].contrasena, usuarios[0].email, usuarios[0].lugar);
			fclose(ufichero);
			
			cuentas = lineasFichero();
			
			printf("Cuenta creada con exito\n");
			printf("Gracias %s por unirte a esta gran familia de viajeros\n", usuarios[0].nombre);
			printf("Ya somos %d domingueros!\n", cuentas);	

			break;
		case 3:
			printf("-----------------------NOVEDADES DE LA SEMANA-----------------------\n");
			printf("\n");
			printf("Hemos encontrado algunos CHOLLOS que puede que te interesen\n");
			printf("Encontraras mas informacion de dichos eventos en las paginas oficiales correspondientes \n");
			printf("\n");
			
			nfichero = fopen ("NOVEDADES_DELA_SEMANA.txt", "r");
	
			if (nfichero == NULL) {
				printf("No se encuentra el fichero\n");
				return 0;
			}
	
			num=rand()% 16+1; // Numero de linea aleatorio entre 1 y 16 = rand () % (N-M+1) + M
			
			// Recorremos el fichero línea a línea hasta el final del mismo, comparando si el contador de lineas, 'cont', es igual a un número aleatorio
			// que obtenemos mediante la función rand(). [incluímos la librería stdlib.h]
			while (((fgets(cadena, sizeof (cadena), nfichero))!= EOF)){ 
				if(cont==num){
					printf ("%s\n", cadena);
					break;
				} else{
					cont++;
				}
			}
			
			fclose(nfichero);
			
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
			printf("Estos son los ultimos comentarios de algunos domingueros\n");
			resenyas(); // Función que muestran por pantalla las reseñas que han sido introducidas anteriormente
			recomendacion(); // Función que permite introducir reseñas y mostrarlas todas de nuevo
			break;
		case 6:
			printf("-----------------------INFORMACION SOBRE LA APLICACION-----------------------\n");
			printf("\n");
			break;
		case 7:
			adios();
			break;		
	}
}
void adios(){
	printf("Ha seleccionado la opcion de salir\n");
	printf("\n");
	printf("\t******** Hasta pronto DOMINGUERO ********");
}
			       
int lineasFichero(){
	int cont=0;
	int num_lineas = 0;
	FILE *ufichero;
	
	if ((ufichero = fopen("USUARIOS.txt", "r")) == NULL){
    	perror("USUARIOS.txt");
      	printf("Error");
   }	
   while ((cont = fgetc(ufichero)) != EOF){
   		if (cont == '\n'){
   			num_lineas++;
		}	
   }
   fclose(ufichero);
   
	return num_lineas;
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
	for (i=0; i<num; i++) {
		asteriscos[i]='*';
	}

	fprintf(fichero,"PUNTUACION: %s\n", asteriscos);
	fclose(fichero);
}
			       
int Min_May(char palabra[50]){
	int i=0;
	for (i=0;palabra[i]!='\0';++i){
		if(palabra[i]>='a' && palabra[i]<='z'){
			palabra[i]=palabra[i]-32;
		}
	}
}
			       
void recomendacion(){
	int recomendar, i, muy_recomendado=4, esta_bien=3, mejorable=2, no_recomendado=1;
	char nombre[50],apellidos[50],cadena[100];
	struct madrid viajero;
	FILE*pfichero;
	
	printf("Para ESCRIBIR RECOMENDACION introduzca '1'. Despues debera escribir su nombre y apellidos\n");
	printf("En caso contrario pulse 0 para  SALIR\n");
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
		adios();
	}
}
			
