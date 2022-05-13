#include "../../includes/includelib.h"
#include "../localidad/localidad.h"
#include "profesional.h"
#define MAXNOMBRE 80
#define MAXAPELLIDO 90
#define MAXDOMICILIO 120
#define MAXOBSERVACION 250
#define MAXTELEFONO 20
#define MAXMATRICULA 10
THIS(obj_Profesional)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_ProfesionalImpl(void *self)
{
     obj_Profesional *obj=this(self);     
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
static int getDniProfesional_Impl(void *self)
{ return *((int *) getValue(self,POS_ID)); }
//----------------------------------------------------
static char *getMatriculaProfesional_Impl(void *self)
{ return  (char *) getValue(self,POS_MAT_PROF); }
//----------------------------------------------------
static char *getNombresProfesional_Impl(void *self)
{ return  (char *) getValue(self,POS_NOMBRES_PROF); }
//----------------------------------------------------
static char *getApellidoProfesional_Impl(void *self)
{ return  (char *) getValue(self,POS_APELLIDO_PROF); }
//----------------------------------------------------
static char *getDomicilioProfesional_Impl(void *self)
{ return  (char *) getValue(self,POS_DOMICILIO_PROF); }
//----------------------------------------------------
static char *getTelefonoProfesional_Impl(void *self)
{ return  (char *) getValue(self,POS_TELEFONO_PROF); }
//----------------------------------------------------
static int getCodPostalProfesional_Impl(void *self)
{ return *( (int *) getValue(self,POS_COD_POSTAL_PROF)); }
//----------------------------------------------------
static char *getObservacionesProfesional_Impl(void *self)
{ return  (char *) getValue(self,POS_OBS_PROF); }
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setDniProfesional_Impl(void *self,int val)
{ setValue(self,POS_ID,&val); }
//----------------------------------------------------
static void setMatriculaProfesional_Impl(void *self,char *mat_Profesional)
{ setValue(self,POS_MAT_PROF,mat_Profesional); }
//----------------------------------------------------
static void setNombresProfesional_Impl(void *self,char *nombres_Profesional)
{ setValue(self,POS_NOMBRES_PROF,nombres_Profesional); }
//----------------------------------------------------
static void setApellidoProfesional_Impl(void *self,char *apellido_Profesional)
{ setValue(self,POS_APELLIDO_PROF,apellido_Profesional); }
//----------------------------------------------------
static void setDomicilioProfesional_Impl(void *self,char *domicilio_Profesional)
{ setValue(self,POS_DOMICILIO_PROF,domicilio_Profesional); }
//----------------------------------------------------
static void setTelefonoProfesional_Impl(void *self,char *telefono_Profesional)
{ setValue(self,POS_TELEFONO_PROF,telefono_Profesional); }
//----------------------------------------------------
static void setCodPostalProfesional_Impl(void *self,int val)
{ setValue(self,POS_COD_POSTAL_PROF,&val); }
//----------------------------------------------------
static void setObservacionesProfesional_Impl(void *self,char *obs)
{ setValue(self,POS_OBS_PROF,obs); }
//----------------------------------------------------
static void destroyInternalCli_Impl(void *self)
{
	obj_Profesional *obj = this(self);	
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
obj_Localidad *getLocalidadProfesionalObj_Impl(void *self)
{
	obj_Profesional *obj = this(self);	
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
static void *init_Profesional(void *self)
{
  obj_Profesional *obj     = this(self);  
  obj->ds  			    = &table_Profesional;
  obj->constructor 	    = Profesional_new;
  obj->sizeObj 		    = sizeof(obj_Profesional*);
  obj->localidad 	    = NULL;  
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_ProfesionalImpl;
  // Inicializar handlers de getters y setters
  /// getters
  obj->getDni  	  		= getDniProfesional_Impl;  
  obj->getMatricula		= getMatriculaProfesional_Impl;
  obj->getNombres 		= getNombresProfesional_Impl;
  obj->getApellido 		= getApellidoProfesional_Impl;
  obj->getDomicilio 	= getDomicilioProfesional_Impl;
  obj->getTelefono 		= getTelefonoProfesional_Impl;    
  obj->getCodPostal 	= getCodPostalProfesional_Impl;  
  obj->getObservaciones	= getObservacionesProfesional_Impl;  
  /// setters  
  obj->setDni     		= setDniProfesional_Impl;    
  obj->setMatricula 	= setMatriculaProfesional_Impl;
  obj->setNombres 		= setNombresProfesional_Impl;
  obj->setApellido 		= setApellidoProfesional_Impl;
  obj->setDomicilio 	= setDomicilioProfesional_Impl;
  obj->setTelefono 		= setTelefonoProfesional_Impl;  
  obj->setCodPostal     = setCodPostalProfesional_Impl;  
  obj->setObservaciones = setObservacionesProfesional_Impl;
  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalCli_Impl;
  //---- acceso a relaciones  
  obj->getLocalidadObj 	= getLocalidadProfesionalObj_Impl;  
  return obj;
}
//----------------------------------------------------
//constructor de Profesional
obj_Profesional *Profesional_new()
{
  return (obj_Profesional *)init_obj(sizeof(obj_Profesional), init_Profesional);
}
//----------------------------------------------------
altaProfesional(){
    int dni, codPostal;
    char nombre[MAXNOMBRE], apellido[MAXAPELLIDO], domicilio[MAXDOMICILIO], observacion[MAXOBSERVACION], telefono[MAXTELEFONO], matricula[MAXMATRICULA];
    obj_Profesional *profesional;
    profesional = Profesional_new();
    
	  printf("ALTA PROFESIONAL \n");
	  printf("ingrese dni: \n");
	  fflush(stdin);
	  scanf("%d", &dni);
	  if(profesional->findbykey(profesional,dni) == NOT_FOUND){
	  profesional->setDni(profesional,dni);
   
    printf("ingrese matricula: \n");
    fgets(nombre,MAXNOMBRE-1,stdin); 
   	profesional->setMatricula(profesional,matricula);
   
    printf("ingrese nombre del profesional:  \n");
    fgets(nombre,MAXNOMBRE-1,stdin);
    profesional->setNombres(profesional,nombre);
    
    printf("ingrese apellido: \n");
    fgets(apellido,MAXAPELLIDO-1,stdin);
    profesional->setApellido(profesional,apellido);
    
    printf("ingrese donicilio \n");
    fgets(domicilio,MAXDOMICILIO-1,stdin);
    profesional->setDomicilio(profesional,domicilio);

    printf("ingrese telefono: \n");
    fgets(telefono,MAXTELEFONO-1,stdin);
    profesional->setTelefono(profesional,telefono);
      
    codPostal = validarCodigoPostal();
    profesional->setCodPostal(profesional,codPostal);   
    
    printf("ingrese observaciones: \n");
    fgets(observacion,MAXOBSERVACION-1,stdin);
    profesional->setObservaciones(profesional,observacion);
    fflush(stdin);
    if(profesional->saveObj(profesional)){ 
    printf("profesional guardado correctamente \n");
      }
    else{
     printf("error al guardar profesional \n");
    }
   }
   else{
    printf("profesional ya existe \n");
   }
  destroyObj(profesional);
  
}




listarProfesionales(){
}


