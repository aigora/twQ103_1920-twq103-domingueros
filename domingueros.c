#include <stdio.h>

int main () {
	int a;
	
	printf(" Bienvenido a DOMINGUEROS\n");
	
	do{
	printf("\n MENU \n");
	printf("\n (1)-Iniciar sesion \n");
	printf("\n (2)-Registrarse \n");
	printf("\n (3)-Novedades de la semana\n");
	printf("\n (4)-Informacion sobre la aplicacion\n");
	printf("\n (5)-Salir de la aplicacion\n");
	
	printf("\n Seleccinar opcion tecleandola en el ordenador el número asociado a la opcion a la que se desea acceder.\n");
	
	scanf("%d", &a);
	
	}while( a != 1 || a != 2 || a != 3 || a != 4 || a != 5 );
	
	switch(a) {
		case 1:
			printf("Ha seleccionado la opcion de INICIAR SESION\n");
			break;
		case 2:
			printf("Ha seleccionado la opcion de REGISTRARSE\n");
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
		default:
			printf("Se ha introducido mal el numero\n");
	}
}
