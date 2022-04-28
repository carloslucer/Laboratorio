#include "../../includes/includelib.h"
#include "../localidad/localidad.h"
#include "../especie/especie.h"
#include "tratamiento.h"

THIS(obj_Tratamiento)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_TratamientoImpl(void *self)
{
     obj_Tratamiento *obj=this(self);
     printf("objTratamiento\n");
    //implementar con la mayor cantidad de datos
}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getIdTratamiento_Impl(void *self)
{ return *( (int *) getValue(self,POS_ID)); }
//----------------------------------------------------
static char *getDescripcion_M_Impl(void *self)
{ return  (char *) getValue(self,POS_DESCRIPCION_M); }
//----------------------------------------------------
static int getCodEspecie_M_Impl(void *self)
{ return *( (int *) getValue(self,POS_COD_ESPECIE_M)); }
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setIdTratamiento_Impl(void *self,int val)
{ setValue(self,POS_ID,&val); }
//----------------------------------------------------
static void setDescripcion_M_Impl(void *self,char *obs)
{ setValue(self,POS_DESCRIPCION_M,obs); }
//----------------------------------------------------
static void setCodEspecie_M_Impl(void *self,int val)
{ setValue(self,POS_COD_ESPECIE_M,&val); }
//----------------------------------------------------
static void destroyInternalTratamiento_Impl(void *self)
{
	obj_Tratamiento *obj = this(self);	
	// implementar
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

obj_Especie *getEspecieTratamientoObj_Impl(void *self)
{
	/// implementar
	return NULL;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Tratamiento(void *self)
{
  obj_Tratamiento *obj  = this(self);
  obj->ds                     = &table_Tratamiento;
  obj->constructor            = Tratamiento_new;
  obj->sizeObj                = sizeof(obj_Tratamiento*);
  //incializacion de la interfaz de la entidad
  obj->toString               = toString_TratamientoImpl;
  obj->especie			  	  = NULL;
  
    // Inicializar handlers de getters y setters
  /// getters
  obj->getId 				  = getIdTratamiento_Impl;
  obj->getDescripcion   	  = getDescripcion_M_Impl;
  obj->getCodEspecie          = getCodEspecie_M_Impl;  
    /// setters  
  obj->setId 				  = setIdTratamiento_Impl;  
  obj->setDescripcion         = setDescripcion_M_Impl;
  obj->setCodEspecie  	      = setCodEspecie_M_Impl;
  
  // implementar detroy internal para liberar recursos
  obj->destroyInternal        = destroyInternalTratamiento_Impl;
  //---- acceso a relaciones    
  obj->getEspecieObj		  = getEspecieTratamientoObj_Impl;
  return obj;
}
//----------------------------------------------------
//constructor de Tratamiento
obj_Tratamiento *Tratamiento_new()
{
  return (obj_Tratamiento *)init_obj(sizeof(obj_Tratamiento), init_Tratamiento);
}
//----------------------------------------------------
