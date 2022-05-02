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


/*
 altaCliente(){
	int dni, codPostal;
	dni=0; codPostal=0;
    char nombre[MAXNOMBRE], apellido[MAXAPELLIDO],telefono[MAXTELEFONO], domicilio[MAXDOMICILIO], observacion[MAXOBSERVACION];
	obj_Cliente *cliente;
    cliente = Cliente_new();
    
	printf("ALTA CLIENTE \n");
	printf("ingrese dni: \n");
	scanf("%d", &dni);
	fflush(stdin);
	  cliente->setDni(cliente,dni);
	  printf("ingrese nombre: \n");
	  fgets(nombre,MAXNOMBRE-1,stdin);
	  fflush(stdin);
	  cliente->setNombres(cliente,nombre);
	  printf("ingrese apellido: \n");
	  fgets(apellido,MAXAPELLIDO-1,stdin);
	  cliente->setApellido(cliente,apellido);
	  fflush(stdin);
	  printf("ingrese donicilio \n");
	  fgets(domicilio,MAXDOMICILIO-1,stdin);
	  cliente->setDomicilio(cliente,domicilio);
      fflush(stdin);
	  printf("ingrese telefono: \n");
	  fgets(telefono,MAXTELEFONO-1,stdin);
	  cliente->setTelefono(cliente,telefono);
      
	  printf("ingrese codigo postal: \n");
	  scanf("%d",&codPostal);
	  cliente->setCodPostal(cliente,codPostal);	  
	  
      printf("ingrese observaciones: \n");
	  fgets(observacion,MAXOBSERVACION-1,stdin);
	  cliente->setObservaciones(cliente,observacion);
	  
	  cliente->saveObj(cliente);
   
     
     destroyObj(cliente);
  
   }*/




int main(int argc, char *argv[])
{
  /*j_Mascota *masc;
  obj_Cliente *cliente;
  
  cliente = Cliente_new();
  void *list,*itm;
  int i=0,size=0, sizeEnf=0;
  */
 	
      
/*  size = cliente->findAll(cliente,&list,NULL);
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    ((Object *)itm)->toString(itm);
  }
 */ 
 //ltaCliente();
  
  
  	int dni, codPostal;
	dni=0; codPostal=0;
	obj_Cliente *cliente;
    cliente = Cliente_new();
     if(!init_config(argv[POS_CONFIG]))
  	 exit(-1);  
	printf("ALTA CLIENTE \n");
	/*intf("ingrese dni: \n");
	scanf("%d", &dni);
	fflush(stdin);*/
	 /* cliente->setDni(cliente,87345854);
	  printf("ingrese nombre: \n");
	  fgets(nombre,MAXNOMBRE-1,stdin);
	  fflush(stdin);
	  cliente->setNombres(cliente,nombre);
	  printf("ingrese apellido: \n");
	  fgets(apellido,MAXAPELLIDO-1,stdin);
	  cliente->setApellido(cliente,apellido);
	  fflush(stdin);
	  printf("ingrese donicilio \n");
	  fgets(domicilio,MAXDOMICILIO-1,stdin);
	  cliente->setDomicilio(cliente,domicilio);
      fflush(stdin);
	  printf("ingrese telefono: \n");
	  fgets(telefono,MAXTELEFONO-1,stdin);
	  cliente->setTelefono(cliente,telefono);
      
	  printf("ingrese codigo postal: \n");
	  scanf("%d",&codPostal);
	  cliente->setCodPostal(cliente,codPostal);	  
	  
      printf("ingrese observaciones: \n");
      fflush(stdin);
	  fgets(observacion,MAXOBSERVACION-1,stdin);
	  cliente->setObservaciones(cliente,observacion);
	  */
	 if(cliente->findbykey(cliente,94844537) != NOT_FOUND){
   	  cliente->setDomicilio(cliente,"gas");
   	  cliente->saveObj(cliente);
   }
   
   //destroyObj(list);
    
   destroyObj(cliente);
  
  
  


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
