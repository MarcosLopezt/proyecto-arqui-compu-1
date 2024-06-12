#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>


void set_input_mode() {
    struct termios tattr;
    
    // Obtén los atributos del terminal
    tcgetattr(STDIN_FILENO, &tattr);
    
    // Desactiva el modo de entrada en buffer y desactiva la impresión automática de caracteres
    tattr.c_lflag &= ~(ICANON | ECHO);
    
    // Establece los nuevos atributos del terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &tattr);
}

void reset_input_mode() {
    struct termios tattr;
    
    // Obtén los atributos del terminal
    tcgetattr(STDIN_FILENO, &tattr);
    
    // Activa el modo de entrada en buffer y la impresión automática de caracteres
    tattr.c_lflag |= (ICANON | ECHO);
    
    // Establece los nuevos atributos del terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &tattr);
}

void ingresar_contrasena(char contrasena[], int *i){
	char caracter;
	set_input_mode();
    
	printf("Ingrese la contrasena de 5 caracteres: ");
	
	*i=0;
    
	while (*i < 5) {
    	caracter = getchar();
    	
        if (caracter == '\n') {
            printf("\n");
        	return;
    	}
        contrasena[*i] = caracter;
        printf("*");
    	fflush(stdout);
    	(*i)++;
	}
	contrasena[5] = '\0';
	
	
    
    while ((caracter = getchar()) != '\n' && caracter != EOF);
    /*
	printf("\nLa contrasena ingresada es: %s\n", contrasena);
	*/
	printf("\n");
	reset_input_mode();
	
	
}

void validar_contrasena(char contrasena[], char password[], bool *contrasena_correcta){

	for (int i = 0; contrasena[i] != '\0' && password[i] != '\0'; i++) {
  	  if (contrasena[i] != password[i]) {
  		  *contrasena_correcta = false;
  		  return;
  	  }
	}
    
	*contrasena_correcta = true;
	return;
    
}

int main()
{
	char contrasena[6] = "";
	char password[6] = "arqui";
	int i = 0;
	int intentos = 0;
	bool contrasena_correcta = false;
	int opcion;
    
	while (!contrasena_correcta && intentos < 3){
  	  ingresar_contrasena(contrasena, &i);
  	  validar_contrasena(contrasena, password, &contrasena_correcta);
  	  intentos++;
	}
	if (!contrasena_correcta){
    	return 0;
	}
    
	do {
  	  printf("\nMenu de opciones:\n");
  	  printf("1. opcion 1\n");
  	  printf("2. opcion 2\n");
  	  printf("3. opcion 3\n");
  	  printf("4. opcion 4\n");
  	  printf("5. salir\n");
  	  printf("Seleccione una opcion: ");
  	  scanf("%d", &opcion);
  	  getchar();

  	  switch (opcion) {
  		  case 1:
  			  printf("elegiste la opcion 1");
  			  break;
  		  case 2:
  			  printf("elegiste la opcion 2");
  			  break;
  		  case 3:
  			  printf("elegiste la opcion 3");
  			  break;
  		  case 4:
  			  printf("elegiste la opcion 4");
  			  break;
   		 case 5:
  			  printf("saliendo");
  			  break;
  		  default:
  			  printf("Opcion no valida. Intente de nuevo.\n");
  			  break;
  	  }
	} while (opcion != 5);

	return 0;
}

