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
#define MAXNOMBRE 80
#define MAXAPELLIDO 90
#define MAXDOMICILIO 120
#define MAXOBSERVACION 250
#define MAXTELEFONO 20

//-----------------LISTAR---------------------------------------
listarClientes(){
  
  int size,i;
  void *list,*itm;
  obj_Cliente *cliente;
  cliente = Cliente_new();
  
  size = cliente->findAll(cliente,&list,NULL);
  
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    ((Object *)itm)->toString(itm);
    printf("\n");
    fflush(stdin);

  }
  
  destroyObjList(list,size);
  destroyObj(cliente);
  
}
listarMascotas(){
	  int size,i;
  void *list,*itm;
  obj_Mascota *mascota;
  mascota = Mascota_new();
  
  size = mascota->findAll(mascota,&list,NULL);
  
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    ((Object *)itm)->toString(itm);
    printf("\n");
    fflush(stdin);

  }
  
  destroyObjList(list,size);
  destroyObj(mascota);
	
  
}
listarProfesionales(){
}
listarTurnos(){
  
}
listarTratamientosMascota(){
}
listarMedicamentosMascota(){
}


//-----------------VALIDAR--------------------------------------

int validarCodigoPostal(){
    int codPostal;
    obj_Localidad *localidad;
    localidad = Localidad_new();
    int codigoCorrecto =0;
    printf("ingrese codigo postal: \n");
    while (!codigoCorrecto){
    scanf("%d",&codPostal);
    if(localidad->findbykey(localidad,codPostal) != NOT_FOUND){
         codigoCorrecto=1;
    }else printf("ingrese codigo postal invalido, ingrese uno correcto: \n");
    fflush(stdin);
}
destroyObj(localidad);
return codPostal;
}

//-------------------ALTAS---------------------------------------------

altaCliente(){
  int dni, codPostal;
    char nombre[MAXNOMBRE], apellido[MAXAPELLIDO], domicilio[MAXDOMICILIO], observacion[MAXOBSERVACION], telefono[MAXTELEFONO];
  obj_Cliente *cliente;
    cliente = Cliente_new();
    
  printf("ALTA CLIENTE \n");
  printf("ingrese dni: \n");
  scanf("%d", &dni);
  fflush(stdin);
  if(cliente->findbykey(cliente,dni) == NOT_FOUND){
    cliente->setDni(cliente,dni);
     
    printf("ingrese nombre: \n");
    fgets(nombre,MAXNOMBRE-1,stdin);
    cliente->setNombres(cliente,nombre);
    
    printf("ingrese apellido: \n");
    fgets(apellido,MAXAPELLIDO-1,stdin);
    cliente->setApellido(cliente,apellido);
    
    printf("ingrese donicilio \n");
    fgets(domicilio,MAXDOMICILIO-1,stdin);
    cliente->setDomicilio(cliente,domicilio);

    printf("ingrese telefono: \n");
    fgets(telefono,MAXTELEFONO-1,stdin);
    cliente->setTelefono(cliente,telefono);
      
    codPostal = validarCodigoPostal();
    cliente->setCodPostal(cliente,codPostal);   
    
      printf("ingrese observaciones: \n");
    fgets(observacion,MAXOBSERVACION-1,stdin);
    cliente->setObservaciones(cliente,observacion);
    
    if(cliente->saveObj(cliente)){ 
    printf("cliente guardado correctamente \n");
      }
    else{
     printf("error al guardar cliente \n");
    }
   }
   else{
    printf("cliente ya existe \n");
   }
  destroyObj(cliente);
}
   
altaMascota(){

}

altaEspecie(){

}

altaProfesionl(){

}

altaMedicamento(){

}

altaLocalidad(){

}


//------------------MENUS------------------------------------------------

void menuAltas(){
  int opcion = 0;
  while(opcion!=7){
  
  
  printf("SELECCIONE LA INGORMACION QUE DESEA DAR DE ALTA:\n");
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
    case 4: altaProfesionl();
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
    
      printf("SELECCIONE LA INGORMACION QUE DESEA LISTAR:\n");
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
  
 /* size = cliente->findAll(cliente,&list,NULL);
  
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    ((Object *)itm)->toString(itm);

  }
  
  destroyObjList(list,size);
  destroyObj(cliente);
  
  
  
*/

  // ejemplo para agregar Localidad nueva.
  /*
  loc =  Localidad_new();
  loc->setId(loc,9000);
  loc->setNombre(loc,"Comodoro Rivadavia");
  if(!loc->saveObj(loc))
  {
    printf("Ocurrio un error al agregar Localidad:\n%s\n",getLastError());
  }
  destroyObj(loc);*/
  // codigo para buscar por codigo y actualizar informacion
  /*
  loc =  Localidad_new();
  if(loc->findbykey(loc,9120) != NOT_FOUND)
  {
    loc->setNombre(loc,"Puerto Madryn"); // Puerto Madryn
    if(!loc->saveObj(loc))
    {
      printf("Ocurrio un error al agregar Localidad:\n%s\n",getLastError());
    }
}
  destroyObj(loc);
  */
  // ejemplo para listar todas las localidades en el sistema
  /*
  loc =  Localidad_new();
  
  size = loc->findAll(loc,&list,NULL);
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    ((Object *)itm)->toString(itm);
  }
  destroyObjList(list,size);
  destroyObj(loc);
  */
    /*
 masc =  Mascota_new();  
  size = masc->findAll(masc,&list,NULL);
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    ((Object *)itm)->toString(itm);
  }
  destroyObjList(list,size);
  destroyObj(masc);
  */
  system("PAUSE");
  return 0;
}
