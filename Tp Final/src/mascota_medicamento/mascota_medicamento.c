#include "../../includes/includelib.h"
#include "../localidad/localidad.h"
#include "../especie/especie.h"
#include "../tratamiento/tratamiento.h"
#include "../medicamento/medicamento.h"
#include "mascota_medicamento.h"

THIS(obj_MascotaMedicamento)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_MascotaMedicamentoImpl(void *self)
{
     obj_MascotaMedicamento *obj=this(self);
     printf("objMascotaMedicamento\n");
    //implementar con la mayor cantidad de datos
}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getIdMascotaMedicamento_Impl(void *self)
{ return *( (int *) getValue(self,POS_ID)); }
//----------------------------------------------------
static int getCodTratamiento_MM_Impl(void *self)
{ return *( (int *) getValue(self,POS_COD_TRAT_MM)); }
//----------------------------------------------------
static int getCodMedicamento_MM_Impl(void *self)
{ return *( (int *) getValue(self,POS_COD_MED_MM)); }
//----------------------------------------------------
static int getCantidad_MM_Impl(void *self)
{ return *( (int *) getValue(self,POS_CANTIDAD_MM)); }
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setIdMascotaMedicamento_Impl(void *self,int val)
{ setValue(self,POS_ID,&val); }
//----------------------------------------------------
static void setCodTratamiento_MM_Impl(void *self,int val)
{ setValue(self,POS_COD_TRAT_MM,&val); }
//----------------------------------------------------
static void setCodMedicamento_MM_Impl(void *self,int val)
{ setValue(self,POS_COD_MED_MM,&val); }
//----------------------------------------------------
static void setCantidad_MM_Impl(void *self,int val)
{ setValue(self,POS_CANTIDAD_MM,&val); }
//----------------------------------------------------
static void destroyInternalMascotaMedicamento_Impl(void *self)
{
	obj_MascotaMedicamento *obj = this(self);	
	// implementar
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

obj_Tratamiento *getTratamientoMascotaMedicamentoObj_Impl(void *self)
{
	/// implementar
	return NULL;
}
//----------------------------------------------------
obj_Medicamento *getMedicamentoMascotaMedicamentoObj_Impl(void *self)
{
	/// implementar
	return NULL;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_MascotaMedicamento(void *self)
{
  obj_MascotaMedicamento *obj  = this(self);
  obj->ds                     = &table_MascotaMedicamento;
  obj->constructor            = MascotaMedicamento_new;
  obj->sizeObj                = sizeof(obj_MascotaMedicamento*);
  //incializacion de la interfaz de la entidad
  obj->toString               = toString_MascotaMedicamentoImpl;
  obj->tratamiento		  	  = NULL;
  obj->medicamento		  	  = NULL;
  
    // Inicializar handlers de getters y setters
  /// getters
  obj->getId 				  = getIdMascotaMedicamento_Impl;  
  obj->getCodTratamiento      = getCodTratamiento_MM_Impl;  
  obj->getCodMedicamento      = getCodMedicamento_MM_Impl;  
  obj->getCantidad	          = getCantidad_MM_Impl;  
    /// setters  
  obj->setId 				  = setIdMascotaMedicamento_Impl;  
  obj->setCodTratamiento  	  = setCodTratamiento_MM_Impl;
  obj->setCodMedicamento  	  = setCodMedicamento_MM_Impl;
  obj->setCantidad			  = setCantidad_MM_Impl;	
  // implementar detroy internal para liberar recursos
  obj->destroyInternal        = destroyInternalMascotaMedicamento_Impl;
  //---- acceso a relaciones    
  obj->getTratamientoObj	  = getTratamientoMascotaMedicamentoObj_Impl;
  obj->getMedicamentoObj	  = getMedicamentoMascotaMedicamentoObj_Impl;
  return obj;
}
//----------------------------------------------------
//constructor de MascotaMedicamento
obj_MascotaMedicamento *MascotaMedicamento_new()
{
  return (obj_MascotaMedicamento *)init_obj(sizeof(obj_MascotaMedicamento), init_MascotaMedicamento);
}
//----------------------------------------------------
