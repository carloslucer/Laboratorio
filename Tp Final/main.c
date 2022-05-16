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

int verificarCadena (char *cadena)
{
	int i=0;
	int longitud = strlen(cadena);
	while(i <= longitud){
		if (!isdigit(cadena[i]))
			i++;
		else {
			printf("\nERROR: El dato ingresado es incorrecto.\n\n");
			system("pause\n\n");
			return 0;
		}
	}
	return 1;
}

void particionarFecha(char *fecha, int *date){

	int i = 0;
	
    char *palabra = strtok(fecha, "-");
        
    while(palabra != NULL) {		
		
		date[i] = atoi(palabra);
        palabra = strtok(NULL, "-");
        ++i;
    }
}

bool verificarFecha(char* fecha){
	
    int date[2];  
	
	char fechaAux[MAXFECHA];

	strcpy(fechaAux,fecha);

	if ((fechaAux[4] == '-') && (fechaAux[7] == '-') && (fechaAux[9] >=0)){
    
	    particionarFecha(fecha, date); 
	    
	    if ((date[2]>0) && (date[2]<=31)){
	    	
			if (date[1] >= 1 && date[1] <= 12 ){
		        switch (date[1] ){
					case  1 :
		            case  3 :
		            case  5 :
		            case  7 :
		            case  8 :
		            case 10 :
					case 12 :
						if ( date[2] < 1 && date[2] > 31 )
		                	return 0;
		                break;
		            case  4 :
		            case  6 :
		            case  9 :				
					case 11 :
						if ( date[2] < 1 && date[2] > 30 )
		            		return 0;
		               	break;				
					
					case  2 :
						if( date[0] % 4 != 0 && date[0] % 100 == 0 || date[0] % 400 != 0 )
		                	if ( date[2] < 1 && date[2] > 29 )
								return 0;
		                else
		                    if ( date[2] < 1 && date[2] > 28 )
		                    	return 0;
		                
		               	break;
		        }
		    }else 
				return 0;
	    }else
	    	return 0;
	}else
		return 0;
			    
    return 1; 
}


void ingresarNumero(char *pregunta, char *cadena){
	int bandera=0;
	int size;
	
	do{
		fflush( stdin ); // limpia el buffer
		printf("%s", pregunta);
		scanf("%s",cadena);
		size = strlen(cadena)-1;
		bandera = verificarNum(cadena,size);
	}while(!bandera);
}

void ingresarCadena(char *texto, char *cadena){
	int maxCadena = 50;
	int bandera;
	do{
		fflush( stdin ); // limpia el buffer
		printf("%s", texto);
		fgets(cadena,maxCadena,stdin);	
		bandera = verificarCadena(cadena);;
	}while(bandera == 0);
}


void ingresarFecha(char *pregunta, char *cadena){
	char fecha[MAXFECHA];
	int bandera;
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
{   int bandera;
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

//------------------MENUS------------------------------------------------

void menuAltas(){
  int opcion = 0;
  while(opcion!=6){
  
  
  printf("SELECCIONE LA INFORMACION QUE DESEA DAR DE ALTA:\n");
  printf("[ 1 - Cliente       ]\n");
  printf("[ 2 - Mascota       ]\n");
  printf("[ 3 - Especie       ]\n");
  printf("[ 4 - Profesional   ]\n");
  printf("[ 5 - Medicamamento ]\n");
  printf("[ 6 - Localidad     ]\n");
  printf("[ 7 - consulta      ]\n");  
  
  
  scanf("%d",&opcion);
  
    switch (opcion){
    case 1: altaCliente();
    case 2: altaMascota();
    case 3: altaEspecie();
    case 4: altaProfesional();
    case 5: altaMedicamento();
    case 6: altaLocalidad();
    case 7: altaConsulta();
    break;  
  
     }   
  
}


}
void menuActulizaciones(){
	
	 int opcion = 0;
    while(opcion!=7)
    {
    
      printf("SELECCIONE LA INFORMACION QUE DESEA ACTUALIZAR:\n");
      printf("[ 1 - Clientes                     ]\n");
      printf("[ 2 - Mascotas                     ]\n");
      printf("[ 3 - Profesionales                ]\n");
      printf("[ 4 - Turnos                       ]\n");
      printf("[ 5 - Tratamientos de Mascota      ]\n");
      printf("[ 6 - Medicamentos de Mascota      ]\n");
      printf("[ 7 - Salir                        ]\n");
       
       
    /*    scanf("%d",&opcion);
      
        switch (opcion)
        { 
          case 1: actualizarClientes();
          case 2: actualizarMascotas();
          case 3: actualizarProfesionales();
          case 4: actualizarTurnos();
          case 5: actualizarTratamientosMascota();
          case 6: actualizarMedicamentosMascota();
          break;  
             }   */
       }    
}
  
void menulistados(){
  
    int opcion = 0;
    while(opcion!=7)
    {
    
      printf("SELECCIONE LA INFORMACION QUE DESEA LISTAR:\n");
      printf("[ 1 - Clientes                     ]\n");
      printf("[ 2 - Mascotas                     ]\n");
      printf("[ 3 - Profesionales                ]\n");
      printf("[ 4 - Turnos-consuta               ]\n");
      printf("[ 5 - Tratamientos de Mascota      ]\n");
      printf("[ 6 - Medicamentos de Mascota      ]\n");
      printf("[ 7 - Salir                        ]\n");
       
       
        scanf("%d",&opcion);
      
        switch (opcion)
        { 
          case 1: listarClientes();
          case 2: listarMascotas();
          case 3: listarProfesionales();
          case 4: listarConsultas();
          case 5: listarTratamientosMascota();
          case 6: listarMedicamentosMascota();
          break;  
             }   
       }    
}


void menuEstadisticas(){

	int opcion = 0;

    while(opcion!=7)
    {
    
      printf("SELECCIONE LA INFORMACION QUE DESEA CONOCER LA ESTADISTICA:\n");
      printf("[ 1 - Clientes                     ]\n");
      printf("[ 2 - Mascotas                     ]\n");
      printf("[ 3 - Profesionales                ]\n");
      printf("[ 4 - Turnos                       ]\n");
      printf("[ 5 - Tratamientos de Mascota      ]\n");
      printf("[ 6 - Medicamentos de Mascota      ]\n");
      printf("[ 7 - Salir                        ]\n");
       
    
        scanf("%d",&opcion);
     /* 
        switch (opcion)
        { 
          case 1: estadisticaClientes();
          case 2: estadisticaMascotas();
          case 3: estadisticaProfesionales();
          case 4: estadisticaTurnos();
          case 5: estadisticaTratamientosMascota();
          case 6: estadisticaMedicamentosMascota();
          break;  
             }   
       }   
	*/
  
}
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
  fflush(stdin);
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
