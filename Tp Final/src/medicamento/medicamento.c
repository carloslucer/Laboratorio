#include "../../includes/includelib.h"
#include "../localidad/localidad.h"
#include "../especie/especie.h"
#include "medicamento.h"
#define MAXDESCRIPCION 20

THIS(obj_Medicamento)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_MedicamentoImpl(void *self)
{
     obj_Medicamento *obj=this(self);
     printf("objMedicamento\n");
    //implementar con la mayor cantidad de datos
}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getIdMedicamento_Impl(void *self)
{ return *( (int *) getValue(self,POS_ID)); }
//----------------------------------------------------
static char *getDescripcion_M_Impl(void *self)
{ return  (char *) getValue(self,POS_DESCRIPCION_M); }
//----------------------------------------------------
static int getCodEspecie_M_Impl(void *self)
{ return *( (int *) getValue(self,POS_COD_ESPECIE_M)); }
//----------------------------------------------------
static float getImporte_M_Impl(void *self)
{ return *( (int *) getValue(self,POS_IMPORTE_M)); }
//----------------------------------------------------
static int getCantidad_M_Impl(void *self)
{ return *( (int *) getValue(self,POS_CANTIDAD_M)); }

//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setIdMedicamento_Impl(void *self,int val)
{ setValue(self,POS_ID,&val); }
//----------------------------------------------------
static void setDescripcion_M_Impl(void *self,char *obs)
{ setValue(self,POS_DESCRIPCION_M,obs); }
//----------------------------------------------------
static void setCodEspecie_M_Impl(void *self,int val)
{ setValue(self,POS_COD_ESPECIE_M,&val); }
//----------------------------------------------------
static void setImporte_M_Impl(void *self,float val)
{ setValue(self,POS_IMPORTE_M,&val); }
//----------------------------------------------------
static void setCantidad_M_Impl(void *self,int val)
{ setValue(self,POS_CANTIDAD_M,&val); }
//----------------------------------------------------
static void destroyInternalMedicamento_Impl(void *self)
{
	obj_Medicamento *obj = this(self);	
	// implementar
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

obj_Especie *getEspecieMedicamentoObj_Impl(void *self)
{
	/// implementar
	return NULL;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Medicamento(void *self)
{
  obj_Medicamento *obj  = this(self);
  obj->ds                     = &table_Medicamento;
  obj->constructor            = Medicamento_new;
  obj->sizeObj                = sizeof(obj_Medicamento*);
  //incializacion de la interfaz de la entidad
  obj->toString               = toString_MedicamentoImpl;
  obj->especie			  	  = NULL;
  
    // Inicializar handlers de getters y setters
  /// getters
  obj->getId 				  = getIdMedicamento_Impl;
  obj->getDescripcion   	  = getDescripcion_M_Impl;
  obj->getCodEspecie          = getCodEspecie_M_Impl;
  obj->getImporte  	  		  = getImporte_M_Impl;
  obj->getCantidad	  	  	  = getCantidad_M_Impl;
  
    /// setters  
  obj->setId 				  = setIdMedicamento_Impl;  
  obj->setDescripcion         = setDescripcion_M_Impl;
  obj->setCodEspecie  	      = setCodEspecie_M_Impl;
  obj->setImporte  	  		  = setImporte_M_Impl;
  obj->setCantidad	  		  = setCantidad_M_Impl;  
  
  // implementar detroy internal para liberar recursos
  obj->destroyInternal        = destroyInternalMedicamento_Impl;
  //---- acceso a relaciones    
  obj->getEspecieObj		  = getEspecieMedicamentoObj_Impl;
  return obj;
}
//----------------------------------------------------
//constructor de Medicamento
obj_Medicamento *Medicamento_new()
{
  return (obj_Medicamento *)init_obj(sizeof(obj_Medicamento), init_Medicamento);
}
//----------------------------------------------------
//alta
altaMedicamento(){
	int idMedicamento, codEspecie, cantidad;
	char descripcion[MAXDESCRIPCION];
	double importe;	
	obj_Medicamento *medicamento;
  medicamento = Medicamento_new();
  
  printf("ALTA MEDICAMENTO \n")
  printf("ingrese codigo del medicamento : \n")
  scanf("%d", &idMedicamento);
  fflush(stdin);
   if(medicamento->findbykey(medicamento,idMedicamento) == NOT_FOUND){
    medicamento->setId(medicamento, idMedicamento);
	}
	 printf("Ingrese descripcion : \n") 
   fgets(descripcion,MAXDESCRIPCION-1,stdin);
   medicamento->setDescripcion(medicamento,descripcion);
   
   printf("ingrese el codigo de la especie  \n");
     scanf("%d", &idEspecie);
  fflush(stdin);
  if(medicamento->findbykey(medicamento,codEspecie) == NOT_FOUND){
    medicamento->setCodEspecie (medicamento,codEspecie);
	}
    printf("Ingrese el importe : \n");
    	scanf("%lf", &importe);
    fflush(stdin);
    return 0;
    
    printf("Ingrese cantidad : \n");
    	scanf("%d", &cantidad);
    return 0;
    
     if(medicamento->saveObj(medicamento)){ 
    printf("medicamento guardado correctamente \n");
      }
    else{
     printf("error al guardar el medicamento \n");
    }
   }
   else{
    printf("medicamento ya existe \n");
   }
  destroyObj(medicamento);
}
    
    
}

//Listar 
listarTurnos(){
int size,i;
  void *list,*itm;
  obj_Mascota *mascota;
  mascota = Mascota_new();
  
  size = mascota->findAll(mascota,&list,NULL);
  
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    ((Object *)itm)->toString(itm);
    printf("\n");
    fflush(stdin);

  }
  
  destroyObjList(list,size);
  destroyObj(mascota);
  
}


