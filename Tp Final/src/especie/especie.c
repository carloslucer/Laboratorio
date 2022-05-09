#include "../../includes/includelib.h"
#include "especie.h"
#define MAXNOMBRE 5;

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
//------------------ALTA----------------------------------
altaEspecie(){
	char nombre[MAXNOMBRE];
	int idEspecie;
	 obj_Especie *especie;
  especie = Especie_new();
  
  printf("ingrese el codigo de la especie  \n");
     scanf("%d", &idEspecie);
  fflush(stdin);
  if(mascota->findbykey(mascota,idEspecie) == NOT_FOUND){
    mascota->setId (mascota,idEspecie);
  
  printf("ALTA ESPECIE \n");
  printf("Ingrese nombre de la especie: \n");
   fgets(nombre,MAXNOMBRE-1,stdin);
    mascota->setNombre(mascota,nombre);
    
  
  if(especie->saveObj(especie)){ 
    printf("especie guardado correctamente \n");
      }
    else{
     printf("error al guardar la especie \n");
    }
   }
   else{
    printf("especie ya existe \n");
   }
  
}
