#include <stdio.h> // Librería estándar para manipular datos de entrada y salida
#include <string.h> // Librería de manejo de cadenas
#include<stdbool.h> // Librería del tipo booleano (estándar)
#include <stdlib.h> // Librería de rutinas de conversión estándar

#define longLinea 200
#define MAxUsuarios 50
#define MAxActividades 200
#define FicheroUsuarios "USUARIOS.txt"


typedef struct  zonas {
	int orden;
	char nombre[20];
};

typedef struct madrid {
	char sitio[50];
	char direccion[50];
	char nivel[20];
};
typedef struct datos {
	char nombre[30];
	char apellidos[100];
	int edad;
	char email[100];
	char contrasena[20];
	char lugar[30];
};
typedef struct usuarios {
	char nombre[100];
	char edad[4];
	char contrasenna[50];
	char correo[50];
	char zona[30];
} usuarios;
typedef struct actividades {
	char zona[20];
	char nombre[50];
	char precio[6];
};

void adios();
int lineasFichero();
void resenyas();
int Min_May(char palabra[50]);
void recomendacion();
void estrellas(int num, FILE* fichero);
void cargaFicheroActividades(struct actividades[], int*);
void cargaFicheroUsuarios(struct usuarios[], int*);
bool login();
bool nuevoRegistro();
bool comprobar(char[], char[], usuarios[], int*);
void novedades();
void pintarActividades();
void menuzonas();

int main() {
	bool registrado = false;
	int opcion;

	printf("\t********* Bienvenido a DOMINGUEROS *********\n");

	do {
		//system("cls");
		
		printf("\n MENU \n");
		if(registrado) {
		printf("-Usuario registrado-\n");
		}else {
			printf("\n (1)-Iniciar sesion \n");
			printf("\n (2)-Registrarse \n");
		}
		printf("\n (3)-Nuevos eventos de la semana\n");
		printf("\n (4)-Todas las actividades\n");
		printf("\n (5)-Actividades con filtro\n");
		printf("\n (6)-Resenyas\n");
		printf("\n (7)-Salir de la aplicacion\n");

		printf("\n Seleccinar opcion tecleando el numero asociado a la opcion a la que se desea acceder.\n");

		scanf("%d", &opcion);

		if (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 6 && opcion != 7 ) {
			printf("No se ha introducido un numero adecuado");
		}
		else {

			switch (opcion) {
			case 1:
				if (!registrado) {
					printf("-----------------------INICIAR SESION-----------------------\n");
					printf("\n");
					if (!registrado) registrado = login();
				}
				break;
			case 2:
				if (!registrado) {
					printf("-----------------------CREAR CUENTA NUEVA-----------------------\n");
					printf("\n");
					registrado = nuevoRegistro();
				}
				break;
			case 3:
				printf("----------------------------NOVEDADES---------------------------\n");
				printf("\n");
				if (registrado) novedades();
				else printf("\n Tiene que estar registrado para acceder a esta información \n");
				break;
			case 4:
				printf("------------------------TODAS LAS ACTIVIDADES----------------------\n");
				printf("\n");
				if (registrado) pintarActividades();
				else printf("\n Tiene que estar registrado para acceder a esta información \n");
				break;
			case 5:
				printf("------------------------ACTIVIDADES CON FILTRO----------------------\n");
				printf("\n");
				if (registrado) MenuZonasPrecio();
				else printf("\n Tiene que estar registrado para acceder a esta información \n");
				break;
			case 6:
				printf("-------------------------------RESENYAS----------------------------\n");
				printf("\n");
				printf("Estos son los ultimos comentarios de algunos domingueros\n");
				resenyas(); // Función que muestran por pantalla las reseñas que han sido introducidas anteriormente
				recomendacion(); // Función que permite introducir reseñas y mostrarlas todas de nuevo

				break;
			case 7:
				adios();
				return 0;
				break;
			}
		}

	} while (true);

}

void adios() {
	printf("Ha seleccionado la opcion de salir\n");
	printf("\n");
	printf("\t******** Hasta pronto DOMINGUERO ********");
}

int lineasFichero() {
	int cont = 0;
	int num_lineas = 0;
	FILE* ufichero;

	if ((ufichero = fopen("USUARIOS.txt", "r")) == NULL) {
		perror("USUARIOS.txt");
		printf("Error");
	}
	while ((cont = fgetc(ufichero)) != EOF) {
		if (cont == '\n') {
			num_lineas++;
		}
	}
	fclose(ufichero);

	return num_lineas;
}

void resenyas() {
	char cadena[100];
	FILE* pfichero;

	pfichero = fopen("RESEÑAS.txt", "r");

	if (pfichero != NULL) {
		while ((fgets(cadena, sizeof(cadena), pfichero)) != NULL) {
			printf("%s\n", cadena);
		}
	}
	else {
		printf("No se encuentra el fichero\n");
	}
	fclose(pfichero);
}

void estrellas(int num, FILE* fichero) {
	int i;
	char asteriscos[4];
	for (i = 0; i < num; i++) {
		asteriscos[i] = '*';
	}

	fprintf(fichero, "PUNTUACION: %s\n", asteriscos);
	fclose(fichero);
}

int Min_May(char palabra[50]) {
	int i = 0;
	for (i = 0; palabra[i] != '\0'; ++i) {
		if (palabra[i] >= 'a' && palabra[i] <= 'z') {
			palabra[i] = palabra[i] - 32;
		}
	}
}

void recomendacion() {
	int recomendar, i, muy_recomendado = 4, esta_bien = 3, mejorable = 2, no_recomendado = 1;
	char nombre[50], apellidos[50], cadena[100];
	struct madrid viajero;
	FILE* pfichero;

	printf("Para ESCRIBIR RECOMENDACION introduzca '1'. Despues debera escribir su nombre y apellidos\n");
	printf("En caso contrario pulse 0 para  SALIR\n");
	scanf("%d", &recomendar);
	if (recomendar == 1) {
		printf("Nombre:\n");
		fflush(stdin);
		gets(nombre);
		printf("Apellidos:\n");
		gets(apellidos);
		strcat(nombre, " ");
		strcat(nombre, apellidos);

		pfichero = fopen("RESEÑAS.txt", "a+");

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
			for (i = 0; i <= 2; i++) {
				gets(cadena);
				fprintf(pfichero, "%s\n", cadena);
			}

			if (strcmp(viajero.nivel, "MUY RECOMENDADO") == 0) {
				estrellas(muy_recomendado, pfichero);
			} if (strcmp(viajero.nivel, "ESTA BIEN") == 0) {
				estrellas(esta_bien, pfichero);
			} if (strcmp(viajero.nivel, "MEJORABLE") == 0) {
				estrellas(mejorable, pfichero);
			} if (strcmp(viajero.nivel, "NO RECOMENDADO") == 0) {
				estrellas(no_recomendado, pfichero);
			} if ((strcmp(viajero.nivel, "MUY RECOMENDADO") != 0) && (strcmp(viajero.nivel, "ESTA BIEN") != 0) && (strcmp(viajero.nivel, "MEJORABLE") != 0) && (strcmp(viajero.nivel, "NO RECOMENDADO") != 0)) {
				fprintf(pfichero, "SIN PUNTUACION\n");
			}

		}
		else {
			printf("No se encuentra el fichero\n");
		}
		printf("\n");
		fclose(pfichero);

		resenyas();
	}
	else if (recomendar == 0) {
		adios();
	}
}

bool login() {
	struct usuarios usuario[MAxUsuarios];
	int numUsuarios;
	cargaFicheroUsuarios(usuario, &numUsuarios);
	char correo[50], contrasenna[50];
	bool registrado;
	do {
		printf("\n Introduzca correo electrnico: ");
		scanf("%s", &correo);
		printf("\n Introduzca contrasenna: ");
		scanf("%s", &contrasenna);
		registrado = comprobar(correo, contrasenna, usuario, &numUsuarios);
		if (registrado != true) printf("\n Usuario o contrasenna incorrecto, introducir de nuevo");
	} while (registrado != true);
	printf("\n correo y contrasena correctos, bienvenido \n");
	return true;
}

bool comprobar(char correo[50], char contrasenna[50], struct usuarios usuario[], int* num) {
	int i;
	for (i = 0; i < (*num); i++) {
		if (strcmp(correo, usuario[i].correo) == 0) {
			if (strcmp(contrasenna, usuario[i].contrasenna) == 0) return true;
		}
	}
	return false;

}

void cargaFicheroUsuarios(struct usuarios usuario[], int* num) {
	int numLineas = 0, i, j = 0, k = 0;
	char linea[MAxUsuarios][longLinea];
	FILE* fich;
	char delim[] = "-";

	fich = fopen(FicheroUsuarios, "r");
	while (fgets(linea[numLineas], longLinea, (FILE*)fich)) {
		//printf("LINEA: %s \n", linea[numLineas]);
		numLineas++;
	}
	fclose(fich);
	for (i = 0; i < numLineas; i++) {
		do {
			usuario[i].nombre[j++] = linea[i][k++];
		} while (linea[i][k] != '-' && linea[i][k] != '\n');
		usuario[i].nombre[--j] = '\0';
		k += 2;
		j = 0;
		do {
			usuario[i].edad[j++] = linea[i][k++];
		} while (linea[i][k] != '-' && linea[i][k] != '\n');
		usuario[i].edad[--j] = '\0';
		k += 2;
		j = 0;
		do {
			usuario[i].contrasenna[j++] = linea[i][k++];
		} while (linea[i][k] != '-' && linea[i][k] != '\n');
		usuario[i].contrasenna[--j] = '\0';
		k += 2;
		j = 0;
		do {
			usuario[i].correo[j++] = linea[i][k++];
		} while (linea[i][k] != '-' && linea[i][k] != '\n');
		usuario[i].correo[--j] = '\0';
		k += 2;
		j = 0;
		do {
			usuario[i].zona[j++] = linea[i][k++];
		} while (linea[i][k] != '-' && linea[i][k] != '\n');
		usuario[i].zona[--j] = '\0';
		k = 0;
		j = 0;
	}
	*num = numLineas;
}

void filtrarZona(char nombreZona[20]) {
	struct actividades actividad[MAxActividades];
	int numActividades, i;
	cargaFicheroActividades(actividad, &numActividades);
	for (i = 0; i < numActividades; i++) {
		if (strcmp(actividad[i].zona, nombreZona) == 0) printf("Actividad: %s , Precio: %s \n", actividad[i].nombre, actividad[i].precio);
	}
}

void filtrarPrecio(int nPrecio) {
	char precio[6];
	sprintf(precio, "%d", nPrecio);
	struct actividades actividad[MAxActividades];
	int numActividades, i;
	cargaFicheroActividades(actividad, &numActividades);
	for (i = 0; i < numActividades; i++) {
		if (strcmp(actividad[i].precio, precio) == 0) printf("Actividad: %s , Precio: %s \n", actividad[i].nombre, actividad[i].precio);
	}
}

void cargaFicheroActividades(struct actividades actividad[], int* num) {
	int numLineas = 0, i, j = 0, k = 0;
	char linea[MAxActividades][longLinea];
	FILE* fich;
	char delim = 32;

	fich = fopen("actividadesprecio.txt", "r");
	while (fgets(linea[numLineas], longLinea, (FILE*)fich)) {
		//printf("LINEA: %s \n", linea[numLineas]);
		numLineas++;
	}
	fclose(fich);
	for (i = 0; i < numLineas; i++) {
		do {
			actividad[i].zona[j++] = linea[i][k++];
		} while (linea[i][k] != delim && linea[i][k] != '\n');
		actividad[i].zona[j] = '\0';
		k++;
		j = 0;
		do {
			actividad[i].nombre[j++] = linea[i][k++];
		} while (linea[i][k] != delim && linea[i][k] != '\n');
		actividad[i].nombre[j] = '\0';
		k++;
		j = 0;
		do {
			actividad[i].precio[j++] = linea[i][k++];
		} while (linea[i][k] != delim && linea[i][k] != '\n');
		actividad[i].precio[j] = '\0';
		k = 0;
		j = 0;
	}
	*num = numLineas;
}

int MenuZonasPrecio() {

	char eleccion[50];
	int precio;
	do {
		printf("\n Menu \n");
		printf("1 - Filtro de Zona\n");
		printf("2 - Filtro de precio \n");
		printf("3 - Volver al menu anterior \n");
		scanf(" %s", &eleccion);
		if (eleccion[0] == '1' && strlen(eleccion) == 1) {
			menuzonas();
		}
		if (eleccion[0] == '2' && strlen(eleccion) == 1) {
			printf("\n Introduzca precio de referencia: \n");
			scanf("%d", &precio);
			filtrarPrecio(precio);
		}
		if (eleccion[0] == '3' && strlen(eleccion) == 1) {
			return 0;
		}
	} while (!(eleccion[0] > 0 && eleccion[0] < 3 && strlen(eleccion) == 1));
	return 0;
}

void menuzonas() {
	char eleccion[50];
	int i, numero;
	struct zonas zona[5] = { {1,"Noreste"},{2,"Noroeste"},{3,"Madridcentro"},{4,"Madridsur"} };

	printf("\n Elija zona \n");
	for (i = 0; i < 4; i++) {
		printf("%i %s \n", zona[i].orden, zona[i].nombre);
	}
	do {
		scanf(" %s", &eleccion);
		if (eleccion[0] > '0' && eleccion[0] < '5' && strlen(eleccion) == 1) {
			numero = (int)eleccion[0] - (int)48;
			filtrarZona(zona[numero].nombre);
		}
		else {
			printf("\n Seleccione una zona valida (1..4) \n");
		}
	} while (!(eleccion[0] > '0' && eleccion[0] < '5' && strlen(eleccion) == 1));
}

bool nuevoRegistro() {
	struct usuarios usuario[MAxUsuarios];//Iniciar sesión
	int numUsuarios;//Iniciar sesión//Iniciar sesión
	FILE* ufichero; // Registrarse - Iniciar sesion
	bool punto = false, arroba = false; // Registrarse
	bool es_cuenta = false, diferente = false;
	int cuentas = 0, longitud_con = 0, edad = 0; // Registrarse
	char apellidos[30];
	int  j; //Registrarse 

	printf("Complete con sus datos\n");
	printf("\n");

	do {
		printf("Nombre:\t");
		fflush(stdin);
		gets(usuario[0].nombre);
		printf("\nApellidos:\t");
		gets(apellidos);

		if (usuario[0].nombre[0] == '\0' || apellidos[0] == '\0') {
			printf("ERROR. Debe completar adecuadamente con sus datos todos los campos\n");
		}

	} while (usuario[0].nombre[0] == '\0' || apellidos[0] == '\0');

	strcat(usuario[0].nombre, " ");
	strcat(usuario[0].nombre, apellidos);

	printf("\nEdad:\t");
	scanf("%d", &edad);
	sprintf(usuario[0].edad, "%d", edad);

	do {
		printf("\nCorreo:\t");
		scanf("%s", usuario[0].correo);

		for (j = 0; usuario[0].correo[j] != '\0'; j++) {

			if (usuario[0].correo[j] == '@') {
				arroba = true;
			}
			if (usuario[0].correo[j] == '.') {
				punto = true;
			}
		}

		if (arroba == false || punto == false) {
			printf("El correo introducido no es valido\n");
			arroba = false;
			punto = false;
		}

	} while (arroba == false || punto == false);

	do {
		printf("\nContrasena:\t");
		scanf("%s", usuario[0].contrasenna);
		longitud_con = strlen(usuario[0].contrasenna);

		if (usuario[0].contrasenna[0] == '\0') { /////////////////////////////////////////////////////////NO SALE
			printf("\nERROR. Debe completar adecuadamente con sus datos todos los campos\n");
		}
		if (longitud_con < 8) {
			printf("\nTu contrasena es demasiado corta. Minimo 8 caracteres\n");
		}
	} while (longitud_con < 8 || usuario[0].contrasenna[0] == '\0');

	printf("\nLugar de residencia en la Comunidad de Madrid (o provincia):\t");
	scanf("%s", usuario[0].zona);

	ufichero = fopen(FicheroUsuarios, "a+");

	if (ufichero == NULL) {
		printf("No se encuentra el fichero\n");
	}

	fprintf(ufichero, "%s - %d - %s - %s - %s\n", usuario[0].nombre, usuario[0].edad, usuario[0].contrasenna, usuario[0].correo, usuario[0].zona);
	fclose(ufichero);

	cuentas = lineasFichero();

	printf("Cuenta creada con exito\n");
	printf("Gracias %s por unirte a esta gran familia de viajeros\n", usuario[0].nombre);
	printf("Ya somos %d domingueros!\n", cuentas);
	return true;
}

void novedades() {
	FILE* nfichero; // Novedades
	int cont = 1, num, maseventos, eventos = 0; // Novedades
	char cadena[80]; // Novedades
	srand(time(NULL)); //Novedades


	printf("Hemos encontrado algunos CHOLLOS que puede que te interesen\n");
	printf("Encontraras mas informacion de dichos eventos en las paginas oficiales correspondientes \n");
	printf("\n");
	printf("\nSi quieres continuar pulsa ENTER\n");
	getch();
	printf("\n");

	do {
		nfichero = fopen("NOVEDADES_DELA_SEMANA.txt", "r");

		if (nfichero == NULL) {
			printf("No se encuentra el fichero\n");
			return 0;
		}

		num = rand() % 16 + 1; // Numero de linea aleatorio entre 1 y 16 = rand () % (N-M+1) + M

		// Recorremos el fichero línea a línea hasta el final del mismo, comparando si el contador de lineas, 'cont', es igual a un número aleatorio
		// que obtenemos mediante la función rand(). [incluímos la librería stdlib.h]
		while (((fgets(cadena, sizeof(cadena), nfichero)) != EOF)) {
			if (cont == num) {
				printf("%s\n", cadena);
				break;
			}
			else {
				cont++;
			}
		}
		fclose(nfichero);

		maseventos = 0;
		eventos++;
		
		printf("\n Si quiere ver otro evento pulse '1'. En caso contrario saldra de la pagina\n");
		fflush(stdin);
		scanf("%d", &maseventos);
		printf("\n");
		
		if(maseventos == 1 && eventos==2){
			printf("Hoy no hemos encontrado mas eventos para ti\n");
			printf("\n");
		}
	
	}while (eventos<2 && maseventos==1);
	
	adios();
}

void pintarActividades() {
	struct actividades actividad[MAxActividades];
	int numActividades, i;
	cargaFicheroActividades(actividad, &numActividades);
	for (i = 0; i < numActividades; i++) {
		printf("Actividad: %s , Zona: %s \n", actividad[i].nombre, actividad[i].zona);
	}

}
