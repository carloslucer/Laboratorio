#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h> 
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "includes/includes.h"
#define MSJ_REINTENTAR "Desea reintentar la operacion? s/n"
#define MAX_CARACTERES 50
#define fgets(cadena) fgets(cadena,MAX_CARACTERES,stdin)

char *nombre_archivo = NULL;
bool descendente = false;

int bandera = 0;
int opc = 0;



//------------------MENUS------------------------------------------------

void menuAltas(){
  int opcion = 0;
  while(opcion!=7){
  
  
  printf("SELECCIONE LA INFORMACION QUE DESEA DAR DE ALTA:\n");
  printf("[ 1 - cliente       ]\n");
  printf("[ 2 - Mascota       ]\n");
  printf("[ 3 - Especie       ]\n");
  printf("[ 4 - Profesional   ]\n");
  printf("[ 5 - Medicamamento ]\n");
  printf("[ 6 - Localidad     ]\n");
  
  scanf("%d",&opcion);
  
    switch (opcion){
    case 1: altaCliente();
    case 2: altaMascota();
    case 3: altaEspecie();
    case 4: altaProfesional();
    case 5: altaMedicamento();
    case 6: altaLocalidad();
    break;  
  
     }   
  
}


}
void menuActulizaciones(){
  
}

void menulistados(){
  
    int opcion = 0;
    while(opcion!=7)
    {
    
      printf("SELECCIONE LA INFORMACION QUE DESEA LISTAR:\n");
      printf("[ 1 - clientes                     ]\n");
      printf("[ 2 - Mascotas                     ]\n");
      printf("[ 3 - Profesionales                ]\n");
      printf("[ 4 - Turnos                       ]\n");
      printf("[ 5 - Tratamientos de Mascota      ]\n");
      printf("[ 6 - Medicamentos de Mascota      ]\n");
      printf("[ 7 - Salir                        ]\n");
       
       
        scanf("%d",&opcion);
      
        switch (opcion)
        { 
          case 1: listarClientes();
          case 2: listarMascotas();
          case 3: listarProfesionales();
          case 4: listarTurnos();
          case 5: listarTratamientosMascota();
          case 6: listarMedicamentosMascota();
          break;  
             }   
       }    
}
void menuEstadisticas(){
  
}

void modificarCliente(){
}



void menuDesplegable(){
int opcion=0; 

while(opcion != 5) {


  printf("[ 1 - Ingresos       ]\n");
  printf("[ 2 - Actualizaciones]\n");
  printf("[ 3 - Listados       ]\n");
  printf("[ 4 - Estadisticas   ]\n");
  printf("[ 5 - Salir          ]\n");
  
  scanf("%d",&opcion);
  
  switch (opcion){
    case 1:menuAltas();
    case 2:menuActulizaciones();
    case 3:menulistados();
    case 4:menuEstadisticas();
    break;
  }
}
    
  
}

int main(int argc, char *argv[])
{
  if(!init_config(argv[POS_CONFIG]))
     exit(-1);  
  menuDesplegable();
  
  system("PAUSE");
  return 0;
}

void ingresarNumero(char *pregunta, char *cadena){
	
	int size;
	
	do{
		fflush( stdin ); // limpia el buffer
		printf("%s", pregunta);
		scanf("%s",cadena);
		size = strlen(cadena)-1;
		bandera = verificarNum(cadena,size);
	}while(bandera == 0);
}

void ingresarCadena(char *texto, char *cadena){
	
	do{
		fflush( stdin ); // limpia el buffer
		printf("%s", texto);
		fgets(cadena);	
		bandera = verificarCadena(cadena);
	}while(bandera == 0);
}


void ingresarFecha(char *pregunta, char *cadena){

	char fecha[MAXFECHA];
	
	do{
		ingresarCadena(pregunta, cadena);
		strcpy(fecha, cadena);
		bandera = verificarFecha(fecha);
		if(bandera == 0){
			printf("\nERROR: Formato de fecha incorrecto.\n");
			printf("Reintente la operacion. Ejemplo de fecha: 1994-05-01\n\n");
			system("pause");
		}
	}while(bandera == 0);			
}

bool continuar (char *pregunta)
{
	char respuesta[4]="";
	int size;	
	
	do{
		bandera = 0;
		printf("%s",pregunta);
		scanf("%s",respuesta);//(cadena);
		size = strlen(respuesta)-1;
		
		if (size == 0)
		{
			if ((respuesta[size] == 's') || (respuesta[size] == 'S') || (respuesta[size]== 'n') || (respuesta[size] == 'N'))
			{
				if ((respuesta[size] == 's') || (respuesta[size] == 'S'))
					return true;
				else
					return false;
			}else{
				printf("\n\nERROR: El dato ingresado es incorrecto\n\n");
				system("pause");
			}
		}else
			printf("ERROR: longitud invalida\n\n");
	}while(bandera == 0);
}

int verificarNum (char *numero, int longitud)
{
	int i=0;
	
	while(i <= longitud){
		if (isdigit(numero[i]))
			i++;
		else {
			printf("\nERROR: El dato ingresado es incorrecto.\n\n");
			system("pause\n\n");
			return 0;
		}
	}
	return 1;
}
