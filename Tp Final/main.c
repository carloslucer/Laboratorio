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
       
       
        scanf("%d",&opcion);
      
        switch (opcion)
        { 
          case 1: actualizarClientes();
          case 2: actualizarMascotas();
          case 3: actualizarProfesionales();
          case 4: actualizarTurnos();
          case 5: actualizarTratamientosMascota();
          case 6: actualizarMedicamentosMascota();
          break;  
             }   
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
