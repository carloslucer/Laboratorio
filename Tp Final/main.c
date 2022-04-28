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

int main(int argc, char *argv[])
{
  obj_Mascota *masc;
  obj_Cliente *cliente;
  
  cliente = Cliente_new();
  void *list,*itm;
  int i=0,size=0, sizeEnf=0;
  if(!init_config(argv[POS_CONFIG]))
  	 exit(-1);  	
      
  size = cliente->findAll(cliente,&list,NULL);
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    ((Object *)itm)->toString(itm);
  }
  destroyObjList(list,size);
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
