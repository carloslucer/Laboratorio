#include "../../includes/includelib.h"
#include "diagnostico.h"

THIS(obj_Diagnostico)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_DiagnosticoImpl(void *self)
{
     obj_Diagnostico *obj=this(self);
     printf("Cod Diagnostico: %d  Nom.Diagnostico:%s \n",
	 obj->getId(obj),
	 obj->getNombre(obj)
	 );
}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getIdDiagnostico_Impl(void *self)
{
  return *( (int *) getValue(self,POS_ID));
}
//----------------------------------------------------
static char *getNombreDiagnostico_Impl(void *self)
{
  return  (char *) getValue(self,POS_NOM_D);
}
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setIdDiagnostico_Impl(void *self,int val)
{ 
	setValue(self,POS_ID,&val);
}
//----------------------------------------------------
static void setNombreDiagnostico_Impl(void *self,char *descripcion_Diagnostico)
{ 
	setValue(self,POS_NOM_D,descripcion_Diagnostico);
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
/// ....
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Diagnostico(void *self)
{
  obj_Diagnostico *obj 	  = this(self);
  obj->ds  				  = &table_Diagnostico;
  obj->constructor 		  = Diagnostico_new;
  obj->sizeObj 			  = sizeof(obj_Diagnostico*);
  //incializacion de la interfaz de la entidad  
  obj->toString    		  = toString_DiagnosticoImpl;
  // Inicializar handlers de getters y setters
  /// getters
  obj->getId  	  		  = getIdDiagnostico_Impl;
  obj->getNombre		  = getNombreDiagnostico_Impl;  
  /// setters  
  obj->setId     		  = setIdDiagnostico_Impl;
  obj->setNombre   		  = setNombreDiagnostico_Impl;  
  return obj;
}
//----------------------------------------------------
//constructor de Diagnostico
obj_Diagnostico *Diagnostico_new()
{
  return (obj_Diagnostico *)init_obj(sizeof(obj_Diagnostico), init_Diagnostico);
}
//----------------------------------------------------
