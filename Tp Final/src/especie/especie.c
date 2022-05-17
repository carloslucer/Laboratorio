#include "../../includes/includelib.h"
#include "especie.h"
#define MAXNOMBRE 5

THIS(obj_Especie)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_EspecieImpl(void *self)
{
     obj_Especie *obj=this(self);
     printf("Cod Especie: %d  Nom.Especie:%s \n",
	 obj->getId(obj),
	 obj->getNombre(obj)
	 );
}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getIdEspecie_Impl(void *self)
{
  return *( (int *) getValue(self,POS_ID));
}
//----------------------------------------------------
static char *getNombreEspecie_Impl(void *self)
{
  return  (char *) getValue(self,POS_NOM_E);
}
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setIdEspecie_Impl(void *self,int val)
{ 
	setValue(self,POS_ID,&val);
}
//----------------------------------------------------
static void setNombreEspecie_Impl(void *self,char *descripcion_Especie)
{ 
	setValue(self,POS_NOM_E,descripcion_Especie);
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
/// ....
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Especie(void *self)
{
  obj_Especie *obj 	  = this(self);
  obj->ds  				  = &table_Especie;
  obj->constructor 		  = Especie_new;
  obj->sizeObj 			  = sizeof(obj_Especie*);
  //incializacion de la interfaz de la entidad  
  obj->toString    		  = toString_EspecieImpl;
  // Inicializar handlers de getters y setters
  /// getters
  obj->getId  	  		  = getIdEspecie_Impl;
  obj->getNombre		  = getNombreEspecie_Impl;  
  /// setters  
  obj->setId     		  = setIdEspecie_Impl;
  obj->setNombre   		  = setNombreEspecie_Impl;  
  return obj;
}
//----------------------------------------------------
//constructor de Especie
obj_Especie *Especie_new()
{
  return (obj_Especie *)init_obj(sizeof(obj_Especie), init_Especie);
}

//------------------Validaciones--------------------------

int validarEspecie(){
	obj_Especie *especie;
	especie = Especie_new();
	int codEspecie=0;
    int especieValida=0;
    do{
	    printf("\n\t ingrese el codigo de la especie los siguientes son los validos \n");
	    listarEspecie();
	    fflush(stdin);
	    scanf("%d", &codEspecie);
	    if(especie->findbykey(especie,codEspecie) == NOT_FOUND)
		{ 
            printf("codigo no existe \n");
	 	}
	 	else especieValida = 1;
    }
	while(!especieValida); 
    destroyObj(especie);
    return codEspecie; 	
}
//---------------Listado-----------------------
listarEspecie(){
	  int size,i;
	  void *list,*itm;
	  obj_Especie *especie;
	  especie = Especie_new();
  
      size = especie->findAll(especie,&list,NULL);
  
	  for(i=0;i<size;++i)
	  {
	    itm = ((Object **)list)[i];    
	    ((Object *)itm)->toString(itm);
	    printf("\n");
	    fflush(stdin);
	
	  }
	printf("\n");	  
  destroyObjList(list,size);
  destroyObj(especie);
  
}
//------------------Alta----------------------------------
altaEspecie(){
	char nombre[MAXNOMBRE];
	int idEspecie;
	 obj_Especie *especie;
  	especie = Especie_new();
  
  printf("ALTA ESPECIE \n");
  printf("Ingrese nombre de la especie: \n");
   fflush(stdin);
   fgets(nombre,MAXNOMBRE-1,stdin);

    especie->setNombre(especie,nombre);
    
    
  if(especie->saveObj(especie)){ 
    printf("especie guardado correctamente \n");
      }
    else{
     printf("error al guardar la especie \n");
    }
   
   destroyObj(especie);
}



  
