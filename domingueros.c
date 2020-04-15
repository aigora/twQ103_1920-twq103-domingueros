#include <stdio.h>

#define INTRO '\r'

struct datos{
	char nombre[30];
	char apellidos[100];
	char apodo[30];
	int edad;
	char email[100];
	char lugar[30];
};
	
int main () {
	struct datos usuarios[100];
	int opcion, i;
	int cuentas=0, longitud_ap = 0;
	
	printf(" Bienvenido a DOMINGUEROS\n");
	
	do{
		printf("\n MENU \n");
		printf("\n (1)-Iniciar sesion \n");
		printf("\n (2)-Registrarse \n");
		printf("\n (3)-Novedades de la semana\n");
		printf("\n (4)-Informacion sobre la aplicacion\n");
		printf("\n (5)-Salir de la aplicacion\n");
	
		printf("\n Seleccinar opcion tecleandola en el ordenador el número asociado a la opcion a la que se desea acceder.\n");
	
		scanf("%d", &opcion);
	
		if ( opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5){
			printf ("No se ha introducido un numero adecuado");
		}

	} while ( opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 );
	
	switch (opcion) {
		case 1:
			printf ("Ha seleccionado la opcion de INICIAR SESION\n");
			break;
		case 2:
			printf ("Ha seleccionado la opcion de REGISTRARSE\n");
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
			
			do{
				printf ("\nNombre de usuario o apodo: ");
				scanf ("%s", usuarios[cuentas].apodo);
				
				longitud_ap = strlen(usuarios[cuentas].apodo);
	
				if (usuarios[cuentas].apodo[0] == '\0'){ // ESTE CONDICIONAL NO ME LO LEE 
					printf ("\nERROR. Debe completar adecuadamente con sus datos todos los campos\n");
					
				} else if (longitud_ap >8){
					printf("Tu apodo es demasiado largo. Maximo 8 caracteres\n");
					
				} else { // HABRÁ QUE COMPROBARLO MÁS ADELANTE
					for (i=0; i<cuentas; i++){      	
						if (usuarios[i].apodo == usuarios[cuentas].apodo){
							printf ("Este nombre ya ha sido escogido. Intentelo de nuevo\n");
						}
					}	
				} //AQUI DEBERIAMOS COMPROBAMOS SI EL APODO INTRODUCIDO COINCIDE CON ALGUNO YA REGISTRADO
				
			} while ( usuarios[cuentas].apodo[0] == '\0' || longitud_ap >8);		
					
			printf ("Edad:\t");
			scanf ("%d", &usuarios[cuentas].edad);
			
			if (usuarios[cuentas].edad <18){	
			}
			
				printf ("Correo:\t");
				fflush (stdin);
				scanf ("%s", usuarios[cuentas].email);
				
				printf ("Lugar de residencia:\t");
				fflush (stdin);
				gets (usuarios[cuentas].lugar);
		
			printf("Cuenta creada con exito");
			printf("Ya somos %d domingueros!", cuentas+1);
			cuentas++;	
			
			break;
		case 3:
			printf("Ha seleccionado la opcion de NOVEDADES DE LA SEMANA\n");
			break;
		case 4:
			printf("Ha seleccionado la opcion de INFORMACION SOBRE LA APLICACION\n");
			break;
		case 5:
			printf("Ha seleccionado la opcion de SALIR\n");
			printf("Hasta pronto");
			break;
					
	}
}
