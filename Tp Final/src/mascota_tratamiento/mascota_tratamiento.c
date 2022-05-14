#include "../../includes/includelib.h"
#include "../localidad/localidad.h"
#include "../especie/especie.h"
#include "../cliente/cliente.h"
#include "../profesional/profesional.h"
#include "../mascota/mascota.h"
#include "../diagnostico/diagnostico.h"
#include "../consulta/consulta.h"
#include "../tratamiento/tratamiento.h"
#include "../medicamento/medicamento.h"
#include "mascota_tratamiento.h"

THIS(obj_MascotaTratamiento)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_MascotaTratamientoImpl(void *self)
{
     obj_MascotaTratamiento *obj=this(self);
     printf("objMascotaTratamiento\n");
    //implementar con la mayor cantidad de datos
}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getIdMascotaTratamiento_Impl(void *self)
{ return *( (int *) getValue(self,POS_ID)); }
//----------------------------------------------------
static int getCodConsulta_MT_Impl(void *self)
{ return *( (int *) getValue(self,POS_COD_COSULTA_MT)); }
//----------------------------------------------------
static int getCodTratamiento_MT_Impl(void *self)
{ return *( (int *) getValue(self,POS_COD_TRAT_MT)); }
//----------------------------------------------------
static char *getFechaDesde_MT_Impl(void *self)
{ return  (char *) getValue(self,POS_FECHA_D_MT); }
//----------------------------------------------------
static char *getFechaHasta_MT_Impl(void *self)
{ return  (char *) getValue(self,POS_FECHA_H_MT); }
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setIdMascotaTratamiento_Impl(void *self,int val)
{ setValue(self,POS_ID,&val); }
//----------------------------------------------------
static void setCodTratamiento_MT_Impl(void *self,int val)
{ setValue(self,POS_COD_TRAT_MT,&val); }
//----------------------------------------------------
static void setCodConsulta_MT_Impl(void *self,int val)
{ setValue(self,POS_COD_COSULTA_MT,&val); }
//----------------------------------------------------
static void setFechaDesde_MT_Impl(void *self,char *fdesde)
{ setValue(self,POS_FECHA_D_MT,fdesde); }
//----------------------------------------------------
static void setFechaHasta_MT_Impl(void *self,char *fhasta)
{ setValue(self,POS_FECHA_H_MT,fhasta); }
//----------------------------------------------------
static void destroyInternalMascotaTratamiento_Impl(void *self)
{
	// implementado
	obj_MascotaTratamiento *obj = this(self);	
	if(obj->tratamiento!=NULL)
	{	
	  destroyObj(obj->tratamiento);
	  obj->tratamiento = NULL;
	}
	
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

obj_Tratamiento *getTratamientoMascotaTratamientoObj_Impl(void *self)
{
	/// implementado
	obj_TratamientoMascotaMedicamento *obj = this(self);
    obj->mascotaTratamiento = Tratamiento_new();

    if(obj->mascotaTratamiento->findbykey(obj->mascotaTratamiento, obj->getidTratamiento(obj))!= NOT_FOUND)
    	return obj->mascotaTratamiento
	return NULL;
}
//----------------------------------------------------
obj_Consulta *getConsultaMascotaTratamientoObj_Impl(void *self)
{
	/// implementado
	obj_ConsultaMascotaTratamiento *obj = this(self);
    obj->consultaTratamiento = ConsultaTratamiento_new();

    if(obj->consultaTratamiento->findbykey(obj->consultaTratamiento, obj->getidTratamiento(obj))!= NOT_FOUND)
    	return obj->consultaTratamiento
	return NULL;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_MascotaTratamiento(void *self)
{
  obj_MascotaTratamiento *obj  = this(self);
  obj->ds                     = &table_MascotaTratamiento;
  obj->constructor            = MascotaTratamiento_new;
  obj->sizeObj                = sizeof(obj_MascotaTratamiento*);
  //incializacion de la interfaz de la entidad
  obj->toString               = toString_MascotaTratamientoImpl;
  obj->consulta		  	  	  = NULL;
  obj->tratamiento		  	  = NULL;  
  
    // Inicializar handlers de getters y setters
  /// getters
  obj->getId 				  = getIdMascotaTratamiento_Impl;  
  obj->getCodConsulta      	  = getCodConsulta_MT_Impl;  
  obj->getCodTratamiento      = getCodTratamiento_MT_Impl;      
  obj->getFechaDesde	      = getFechaDesde_MT_Impl;  
  obj->getFechaHasta	      = getFechaHasta_MT_Impl;  
    /// setters  
  obj->setId 				  = setIdMascotaTratamiento_Impl;  
  obj->setCodTratamiento  	  = setCodTratamiento_MT_Impl;
  obj->setCodConsulta  	  	  = setCodConsulta_MT_Impl;
  obj->setFechaDesde	      = setFechaDesde_MT_Impl;  
  obj->setFechaHasta	      = setFechaHasta_MT_Impl;  
  // implementar detroy internal para liberar recursos
  obj->destroyInternal        = destroyInternalMascotaTratamiento_Impl;
  //---- acceso a relaciones    
  obj->getConsultaObj	  	  = getConsultaMascotaTratamientoObj_Impl; 
  obj->getTratamientoObj	  = getTratamientoMascotaTratamientoObj_Impl;  
  return obj;
}
//----------------------------------------------------
//constructor de MascotaTratamiento
obj_MascotaTratamiento *MascotaTratamiento_new()
{
  return (obj_MascotaTratamiento *)init_obj(sizeof(obj_MascotaTratamiento), init_MascotaTratamiento);
}
//-------------Altas---------------------------------------

void altaMascotaTratamiento(){
	int idMascotaTratamiento, codConsulta, codTratamiento;
	fechaDesde[MAXFECHA], fechaHasta[MAXFECHA];
	
	obj_Consulta *consulta;
	consulta = Consulta_new();
    obj_Tratamiento *tratamiento;
	tratamiento = tratamiento_new();
	
		printf("ALTA MASCOTA-TRATAMIENTO \n");
		
		printf("ingrese codigo de la consulta : \n");
		scanf("%d", &codConsulta);
  		fflush(stdin);
  		 if(consulta->findbykey(consulta,codConsulta) == NOT_FOUND){
    	  consulta->setId(consulta, codConsulta);
			}
			printf("ingrese codigo del tratamiento de la mascota : \n");
  			scanf("%d", &codTratamiento);
  			fflush(stdin);
   			if(tratamiento->findbykey(tratamiento,codTratamiento) == NOT_FOUND){
    		medicamento->setId(tratamiento, codTratamiento);
				}
				
			fgets(fechaDesde,MAXFECHA-1,stdin);
	    	ingresarFecha("ingrese la fecha desde: \n",fechaDesde);
	 		consulta->setFecha(consulta,fechaDesde);
	 		
	 		fgets(fechaHasta,MAXFECHA-1,stdin);
	    	ingresarFecha("ingrese la fecha hasta: \n",fechaHasta);
	 		consulta->setFecha(consulta,fechaHasta);
	 		
	 		if(consulta->saveObj(consulta)){ 
    		printf("consulta guardada correctamente \n");
      		}
    		else{
     		printf("error al guardar la consulta \n");
    }
   
   		if(tratamiento->saveObj(tratamiento)){ 
    		printf("tratamiento guardado correctamente \n");
      	}
    	else{
     		printf("error al guardar el tratamiento \n");
    		}
    		
  		destroyObj(consulta);
  		destroyObj(tratamiento); 
}

//------------------Listar--------------------------------

