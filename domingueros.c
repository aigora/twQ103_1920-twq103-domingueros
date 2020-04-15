#include <stdio.h>

struct datos{
	char nombre[30];
	char apellidos[100];
	int edad;
	char email[100];
	char lugar[30];
};
	
int main () {
	struct datos usuarios[100];
	int opcion;
	int cuentas=0;
	
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
			
			do {
				
			while(cuentas<=100){
				printf ("Nombre del usuario:\t");
				       gets (usuario[cuentas].nombre);
					
				printf ("Apellidos:\t");
				       gets (usuario[cuentas].apellidos);
					
				printf ("Edad:\t");
				       scanf ("%d", &usuario[cuentas].edad);
					
				printf ("Correo:\t");
				       scanf ("%s", usuario[cuentas].email);
				
				printf ("Lugar de residencia:\t");
				       gets (usuario[cuentas].lugar);
			}	
					
			if (){
				printf ("Debes completar con tus datos todos los campos");
			} else {
				printf("Cuenta creada con exito");
				printf("Ya somos %d domingueros!", cuentas+1);
				cuentas++;
			}
					
			} while ()
					
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
