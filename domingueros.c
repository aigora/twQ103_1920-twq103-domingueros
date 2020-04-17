#include <stdio.h>
#include <string.h>
#include<stdbool.h>

struct datos{
	char nombre[30];
	char apellidos[100];
	int edad;
	char apodo[20];
	char contrasena[20];
	char email[100];
	char lugar[30];
};
	
int main () {
	struct datos usuarios[100];
	int opcion, i, j;
	int no_cuenta = 0, no_email = 0, ayuda;
	bool punto = false, arroba = false, es_ cuenta = false, diferente = false;
	int cuentas = 0, longitud_ap = 0, longitud_con = 0;
	char contrasena[20], apodo[20], email[100];
	
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
			} while (es_cuenta = false && no_cuenta<3 || no_email=5 || ayuda = 1);
			
			no_email = 0;
			no_cuenta = 0;
			
			printf("\nBienvenido de nuevo\n");
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
					
				} else if (longitud_ap >8){
					printf("Tu apodo es demasiado largo. Maximo 8 caracteres\n");
					
				} else { // AQUI COMPROBAMOS SI EL APODO INTRODUCIDO COINCIDE CON ALGUNO YA REGISTRADO
					for (i=0; i<cuentas; i++){      	
						if (usuarios[i].apodo == usuarios[cuentas].apodo){
							diferente = false;
							printf ("Este nombre ya ha sido escogido. Intentelo de nuevo\n");
						} else{
							diferente = true;
						}
					} // HABRÁ QUE COMPROBARLO MÁS A DELANTE	
				}
			} while ( usuarios[cuentas].apodo[0] == '\0' || longitud_ap >8 || diferente = false);
			
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
