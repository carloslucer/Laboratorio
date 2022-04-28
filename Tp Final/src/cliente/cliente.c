#include "../../includes/includelib.h"
#include "../localidad/localidad.h"
#include "cliente.h"

THIS(obj_Cliente)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_ClienteImpl(void *self)
{
     obj_Cliente *obj=this(self);     
     obj_Localidad *loc = obj->getLocalidadObj(obj);
     printf("DNI: %d  - ApyNom:%s, %s - \tLocalidad: %s\n",
	 obj->getDni(obj),
	 obj->getApellido(obj),
	 obj->getNombres(obj),	 	 
	 loc->getNombre(loc)
	 );
}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getDniCliente_Impl(void *self)
{ return *((int *) getValue(self,POS_ID)); }
//----------------------------------------------------
static char *getNombresCliente_Impl(void *self)
{ return  (char *) getValue(self,POS_NOMBRES_CLI); }
//----------------------------------------------------
static char *getApellidoCliente_Impl(void *self)
{ return  (char *) getValue(self,POS_APELLIDO_CLI); }
//----------------------------------------------------
static char *getDomicilioCliente_Impl(void *self)
{ return  (char *) getValue(self,POS_DOMICILIO_CLI); }
//----------------------------------------------------
static char *getTelefonoCliente_Impl(void *self)
{ return  (char *) getValue(self,POS_TELEFONO_CLI); }
//----------------------------------------------------
static int getCodPostalCliente_Impl(void *self)
{ return *( (int *) getValue(self,POS_COD_POSTAL_CLI)); }
//----------------------------------------------------
static char *getObservacionesCliente_Impl(void *self)
{ return  (char *) getValue(self,POS_OBS_CLI); }
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setDniCliente_Impl(void *self,int val)
{ setValue(self,POS_ID,&val); }
//----------------------------------------------------
static void setNombresCliente_Impl(void *self,char *nombres_Cliente)
{ setValue(self,POS_NOMBRES_CLI,nombres_Cliente); }
//----------------------------------------------------
static void setApellidoCliente_Impl(void *self,char *apellido_Cliente)
{ setValue(self,POS_APELLIDO_CLI,apellido_Cliente); }
//----------------------------------------------------
static void setDomicilioCliente_Impl(void *self,char *domicilio_Cliente)
{ setValue(self,POS_DOMICILIO_CLI,domicilio_Cliente); }
//----------------------------------------------------
static void setTelefonoCliente_Impl(void *self,char *telefono_Cliente)
{ setValue(self,POS_TELEFONO_CLI,telefono_Cliente); }
//----------------------------------------------------
static void setCodPostalCliente_Impl(void *self,int val)
{ setValue(self,POS_COD_POSTAL_CLI,&val); }
//----------------------------------------------------
static void setObservacionesCliente_Impl(void *self,char *obs)
{ setValue(self,POS_OBS_CLI,obs); }
//----------------------------------------------------
static void destroyInternalCli_Impl(void *self)
{
	obj_Cliente *obj = this(self);	
	if(obj->localidad!=NULL)
	{	
	  destroyObj(obj->localidad);
	  obj->localidad = NULL;
	}
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
/// ....
obj_Localidad *getLocalidadClienteObj_Impl(void *self)
{
	obj_Cliente *obj = this(self);	
	obj->localidad = Localidad_new();
	if(obj->localidad->findbykey(obj->localidad,obj->getCodPostal(obj))!=NOT_FOUND)
	  {
	  	return obj->localidad;
	  }
	return NULL;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Cliente(void *self)
{
  obj_Cliente *obj     = this(self);  
  obj->ds  			    = &table_Cliente;
  obj->constructor 	    = Cliente_new;
  obj->sizeObj 		    = sizeof(obj_Cliente*);
  obj->localidad 	    = NULL;  
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_ClienteImpl;
  // Inicializar handlers de getters y setters
  /// getters
  obj->getDni  	  		= getDniCliente_Impl;  
  obj->getNombres 		= getNombresCliente_Impl;
  obj->getApellido 		= getApellidoCliente_Impl;
  obj->getDomicilio 	= getDomicilioCliente_Impl;
  obj->getTelefono 		= getTelefonoCliente_Impl;    
  obj->getCodPostal 	= getCodPostalCliente_Impl;  
  obj->getObservaciones	= getObservacionesCliente_Impl;  
  /// setters  
  obj->setDni     		= setDniCliente_Impl;    
  obj->setNombres 		= setNombresCliente_Impl;
  obj->setApellido 		= setApellidoCliente_Impl;
  obj->setDomicilio 	= setDomicilioCliente_Impl;
  obj->setTelefono 		= setTelefonoCliente_Impl;  
  obj->setCodPostal     = setCodPostalCliente_Impl;  
  obj->setObservaciones = setObservacionesCliente_Impl;
  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalCli_Impl;
  //---- acceso a relaciones  
  obj->getLocalidadObj 	= getLocalidadClienteObj_Impl;  
  return obj;
}
//----------------------------------------------------
//constructor de Cliente
obj_Cliente *Cliente_new()
{
  return (obj_Cliente *)init_obj(sizeof(obj_Cliente), init_Cliente);
}
//----------------------------------------------------
