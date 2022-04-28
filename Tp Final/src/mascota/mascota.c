#include "../../includes/includelib.h"
#include "../especie/especie.h"
#include "../localidad/localidad.h"
#include "../cliente/cliente.h"
#include "mascota.h"

THIS(obj_Mascota)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_MascotaImpl(void *self)
{
     obj_Mascota *obj=this(self);     
     
     printf("codigo: %d  - Nombre:%s, %s \n",
	 obj->getCodigo(obj),
	 obj->getFechaNac(obj),
	 obj->getNombre(obj)	 
	 );
}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getCodigoMascota_Impl(void *self)
{ return *((int *) getValue(self,POS_ID)); }
//----------------------------------------------------
static char *getNombreMascota_Impl(void *self)
{ return  (char *) getValue(self,POS_NOMBRE_MASC); }
//----------------------------------------------------
static char *getFechaNacMascota_Impl(void *self)
{ return  (char *) getValue(self,POS_F_NAC_MASC); }
//----------------------------------------------------
static int getDniClienteMascota_Impl(void *self)
{ return *( (int *) getValue(self,POS_DNI_CLI_MASC)); }
//----------------------------------------------------
static int getCodEspecieMascota_Impl(void *self)
{ return *( (int *) getValue(self,POS_COD_ESP_MASC)); }
//----------------------------------------------------
static int getVacunadoMascota_Impl(void *self)
{ return *( (int *) getValue(self,POS_VACUNADO_MASC)); }
//----------------------------------------------------
static char *getObservacionesMascota_Impl(void *self)
{ return  (char *) getValue(self,POS_OBS_MASC); }
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setCodigoMascota_Impl(void *self,int val)
{ setValue(self,POS_ID,&val); }
//----------------------------------------------------
static void setNombreMascota_Impl(void *self,char *nombres_Mascota)
{ setValue(self,POS_NOMBRE_MASC,nombres_Mascota); }
//----------------------------------------------------
static void setFechaNacMascota_Impl(void *self,char *apellido_Mascota)
{ setValue(self,POS_F_NAC_MASC,apellido_Mascota); }
//----------------------------------------------------
static void setDniClienteMascota_Impl(void *self,int val)
{ setValue(self,POS_DNI_CLI_MASC,&val); }
//----------------------------------------------------
static void setCodEspecieMascota_Impl(void *self,int val)
{ setValue(self,POS_COD_ESP_MASC,&val); }
//----------------------------------------------------
static void setVacunadoMascota_Impl(void *self,int val)
{ setValue(self,POS_VACUNADO_MASC,&val); }
//----------------------------------------------------
static void setObservacionesMascota_Impl(void *self,char *obs)
{ setValue(self,POS_OBS_MASC,obs); }
//----------------------------------------------------
static void destroyInternalMasc_Impl(void *self)
{
	obj_Mascota *obj = this(self);	

}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
obj_Especie *getEspecieMascotaObj_Impl(void *self)
{
	obj_Mascota *obj = this(self);		
	return NULL;
}
//----------------------------------------------------
obj_Cliente *getClienteMascotaObj_Impl(void *self)
{
	obj_Mascota *obj = this(self);		
	return NULL;
}
/// ....
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Mascota(void *self)
{
  obj_Mascota *obj     = this(self);  
  obj->ds  			    = &table_Mascota;
  obj->constructor 	    = Mascota_new;
  obj->sizeObj 		    = sizeof(obj_Mascota*);
  obj->especie 	    = NULL;  
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_MascotaImpl;
  // Inicializar handlers de getters y setters
  /// getters
  obj->getCodigo  	  		= getCodigoMascota_Impl;  
  obj->getNombre 		= getNombreMascota_Impl;
  obj->getFechaNac 		= getFechaNacMascota_Impl;
  obj->getDniCliente 	= getDniClienteMascota_Impl;
  obj->getCodEspecie 	= getCodEspecieMascota_Impl;  
  obj->getVacunado 		= getVacunadoMascota_Impl;  
  obj->getObservaciones	= getObservacionesMascota_Impl;  
  /// setters  
  obj->setCodigo     		= setCodigoMascota_Impl;    
  obj->setNombre 		= setNombreMascota_Impl;
  obj->setFechaNac 		= setFechaNacMascota_Impl;
  obj->setDniCliente 	= setDniClienteMascota_Impl;
  obj->setCodEspecie    = setCodEspecieMascota_Impl;  
  obj->setVacunado      = setVacunadoMascota_Impl;  
  obj->setObservaciones = setObservacionesMascota_Impl;
  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalMasc_Impl;
  //---- acceso a relaciones  
  obj->getEspecieObj 	= getEspecieMascotaObj_Impl;  
  obj->getClienteObj 	= getClienteMascotaObj_Impl;  
  return obj;
}
//----------------------------------------------------
//constructor de Mascota
obj_Mascota *Mascota_new()
{
  return (obj_Mascota *)init_obj(sizeof(obj_Mascota), init_Mascota);
}
//----------------------------------------------------
