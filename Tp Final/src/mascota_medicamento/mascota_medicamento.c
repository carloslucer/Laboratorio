#include "../../includes/includelib.h"
#include "../localidad/localidad.h"
#include "../especie/especie.h"
#include "../tratamiento/tratamiento.h"
#include "../medicamento/medicamento.h"
#include "mascota_medicamento.h"
#define MAXNOMBRE 50

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
	// implementado	
	obj_MascotaMedicamento *obj = this(self);	
		
	if(obj->tratamiento!=NULL)
	{	
	  destroyObj(obj->tratamiento);
	  obj->tratamiento = NULL;
	}
	
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

obj_Tratamiento *getTratamientoMascotaMedicamentoObj_Impl(void *self)
{
	/// implementado
	obj_TratamientoMascotaMedicamento *obj = this(self);
    obj->mascota = Mascota_new();

    if(obj->mascota->findbykey(obj->mascota, obj->getId(obj))!= NOT_FOUND)
    	return obj->mascota
	return NULL;
}
//----------------------------------------------------
obj_Medicamento *getMedicamentoMascotaMedicamentoObj_Impl(void *self)
{
	/// implementado
	obj_Medicamento *obj = this(self);
    obj->mascota = Mascota_new();

    if(obj->mascota->findbykey(obj->mascota, obj->getId(obj))!= NOT_FOUND)
    	return obj->mascota
	
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

//---------------------Altas--------------------------------
void altaMascotaMedicamento(){
	int idMascotaMedicamento, codMedicamento, codTratamiento;
	double cantidad;
	
	obj_Medicamento *medicamento;
	medicamento = Medicamento_new();
    obj_Tratamiento *tratamiento;
	tratamiento = tratamiento_new();
	
		printf("ALTA MASCOTA-MEDICAMENTO \n");
		
		printf("ingrese codigo del medicamento : \n");
		scanf("%d", &codMedicamento);
  		fflush(stdin);
  		 if(medicamento->findbykey(medicamento,codMedicamento) == NOT_FOUND){
    	  medicamento->setId(medicamento, codMedicamento);
			}
			printf("ingrese codigo del tratamiento : \n");
  			scanf("%d", &codTratamiento);
  			fflush(stdin);
   			if(tratamiento->findbykey(tratamiento,codTratamiento) == NOT_FOUND){
    		medicamento->setId(tratamiento, codTratamiento);
				}
  		
  		printf("Ingrese la cantidad : \n");
    	scanf("%lf", &cantidad);
    	fflush(stdin);
    	return 0;
    	
    	if(medicamento->saveObj(medicamento)){ 
    	printf("medicamento guardado correctamente \n");
      		}
    		else{
     			printf("error al guardar el medicamento \n");
    }
   
   		if(medicamento->saveObj(tratamiento)){ 
    		printf("tratamiento guardado correctamente \n");
      		}
    		else{
     		printf("error al guardar el tratamiento \n");
    		}
   
  			destroyObj(medicamento);
  			destroyObj(tratamiento);  
}




//----------------------Listar------------------------------
void listarMedicamentosMascota(){
	int size,i;
  void *list,*itm;
  obj_Medicamento *medicamento;
  medicamento = Medicamento_new();
  
  size = medicamento->findAll(medicamento,&list,NULL);
  
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    ((Object *)itm)->toString(itm);
    printf("\n");
    fflush(stdin);

  }
  
  destroyObjList(list,size);
  destroyObj(medicamento);
}


