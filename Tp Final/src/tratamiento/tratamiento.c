#include "../../includes/includelib.h"
#include "../localidad/localidad.h"
#include "../especie/especie.h"
#include "tratamiento.h"
#define MAXDESCRIPCION 100

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
	/// implementado
	obj_Tratamiento *obj = this(self);
	
	obj->especie = Especie_new();
	if(obj->especie->findbykey(obj->especie,obj->getCodEspecie(obj))!=NOT_FOUND)
	  {
	  	return obj->especie;
	  }
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

//---------------------Altas--------------------------------
void altaTratamiento(){
	int  codEspecie;
	char descripcion[MAXDESCRIPCION];
	
	obj_Tratamiento *tratamiento;
  	tratamiento = Tratamiento_new();
  	
  	printf("ALTA TRATAMIENTO \n");
  	
	printf("Ingrese descripcion del medicamento : \n");
   fgets(descripcion,MAXDESCRIPCION-1,stdin);
 	 if(!tratamientoExiste(descripcion)){
 	 	tratamiento->setDescripcion(tratamiento,descripcion);
	
	
   printf("ingrese el codigo de la especie  \n");
   	 codEspecie=validarEspecie();
   	 tratamiento->setCodEspecie(tratamiento,codEspecie);
   	
	if(tratamiento->saveObj(tratamiento)){ 
    printf("tratamiento guardado correctamente \n");
      }
    else{
     printf("error al guardar el tratamiento \n");
    }
   
   }else{
    printf("tratamiento ya existe \n");
   }
  destroyObj(tratamiento);
}

tratamientoExiste(char *descripcion){
   int size,i;
  void *list,*itm;
  obj_Tratamiento *tratamiento;
  tratamiento = Tratamiento_new();
  
  size = tratamiento->findAll(tratamiento,&list,NULL);
  
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    tratamiento=((obj_Tratamiento *)itm);
    if(tratamiento->getDescripcion == descripcion){
    	return 1;
    }else
    	return 0;
  }
  
  destroyObjList(list,size);
  destroyObj(tratamiento);

}

//--------------Listar--------------------------------------
void listarTratamientosMascota(){
	int size,i;
  void *list,*itm;
  obj_Tratamiento *tratamiento;
  tratamiento = Tratamiento_new();
  
  size = tratamiento->findAll(tratamiento,&list,NULL);
  
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    ((Object *)itm)->toString(itm);
    printf("\n");
    fflush(stdin);

  }
  
  destroyObjList(list,size);
  destroyObj(tratamiento);
  
}

