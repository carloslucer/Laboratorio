#include "../../includes/includelib.h"
#include "localidad.h"
#define MAXNOMBRELOCALIDAD 80

THIS(obj_Localidad)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_LocalidadImpl(void *self)
{
     obj_Localidad *obj=this(self);
     printf("Cod Localidad: %d  Nom.Localidad:%s \n",
	 obj->getId(obj),
	 obj->getNombre(obj)
	 );
}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getIdLocalidad_Impl(void *self)
{
  return *( (int *) getValue(self,POS_ID));
}
//----------------------------------------------------
static char *getNombreLocalidad_Impl(void *self)
{
  return  (char *) getValue(self,POS_DESCRIPCION);
}
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setIdLocalidad_Impl(void *self,int val)
{ 
	setValue(self,POS_ID,&val);
}
//----------------------------------------------------
static void setNombreLocalidad_Impl(void *self,char *descripcion_Localidad)
{ 
	setValue(self,POS_DESCRIPCION,descripcion_Localidad);
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
/// ....
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Localidad(void *self)
{
  obj_Localidad *obj 	  = this(self);
  obj->ds  				  = &table_Localidad;
  obj->constructor 		  = Localidad_new;
  obj->sizeObj 			  = sizeof(obj_Localidad*);
  //incializacion de la interfaz de la entidad  
  obj->toString    		  = toString_LocalidadImpl;
  // Inicializar handlers de getters y setters
  /// getters
  obj->getId  	  		  = getIdLocalidad_Impl;
  obj->getNombre		  = getNombreLocalidad_Impl;  
  /// setters  
  obj->setId     		  = setIdLocalidad_Impl;
  obj->setNombre   		  = setNombreLocalidad_Impl;  
  return obj;
}
//----------------------------------------------------
//constructor de Localidad
obj_Localidad *Localidad_new()
{
  return (obj_Localidad *)init_obj(sizeof(obj_Localidad), init_Localidad);
}
//----------------------------------------------------
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
//-------------ALTA---------------
altaLocalidad(){
	int idcodigoPostal;
	char nombre[MAXNOMBRELOCALIDAD];
	obj_Localidad *localidad;
    localidad = Localidad_new();

	printf("ALTA LOCALIDAD \n");
	validadCodigoPostal(idcodigoPostal);
	system("PAUSE");
	
  printf("ingrese nombre de la localidad: \n");
  fgets(nombre,MAXNOMBRELOCALIDAD-1,stdin);
  localidad->setNombre(localidad, MAXNOMBRELOCALIDAD);
  
  if(!localidad->saveObj(localidad))
{
	printf("Ocurrio un error al agregar la Localidad:\n%s\n",getsLastError());
}
destroyObj(localidad);

}

  

