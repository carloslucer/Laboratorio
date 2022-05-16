#include "../../includes/includelib.h"
#include "../localidad/localidad.h"
#include "../cliente/cliente.h"
#include "../profesional/profesional.h"
#include "../especie/especie.h"
#include "../mascota/mascota.h"
#include "../diagnostico/diagnostico.h"
#include "consulta.h"
#include <string.h>
#include <ctype.h>
#define MAXDESCRIPCION 150

 typedef struct 
	{
		int anio;
		int mes;
		int dia;
	
	}t_fecha;

typedef struct
	{
	    int hora;
		int min;
		int seg;
	}t_hora;


THIS(obj_Consulta)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_ConsultaImpl(void *self)
{
	int codigo;
     obj_Consulta *obj = this(self);
     printf("objConsulta\n");
     codigo=obj->diagnostico->getId(obj->diagnostico);
     
     obj_Diagnostico *diagnostico;
     diagnostico = Diagnostico_new();
     
     obj_Mascota *mascota;
     mascota = Mascota_new();
          
     if(diagnostico->findbykey(diagnostico, obj->getCodDiagnostico(obj))!= NOT_FOUND)
     diagnostico->toString;
     
     codigo=obj->mascota->getCodigo(obj->mascota);
     
     if(mascota->findbykey(mascota, obj->getCodMascota(obj))!= NOT_FOUND)
     diagnostico->toString;
     
    //implementado
    
    printf("Codigo: %d - FNac: %s - hora: %s - Mascota: %d - Profesional: %d - Diagnostico: %d - Especie: %d - Asistio: %d\n",
	
	obj->getId(obj),
	obj->getFecha(obj),
	obj->getHora(obj),
	obj->getDocProfesional(obj),
	obj->getMascotaObj(obj),
	obj->getDiagnosticoObj(obj),
	obj->getObservaciones(obj),
	obj->getAsistio(obj)
	);

}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getIdConsulta_Impl(void *self)
{ return *( (int *) getValue(self,POS_ID)); }
//----------------------------------------------------
static char *getFecha_C_Impl(void *self)
{ return  (char *) getValue(self,POS_FECHA_C); }
//----------------------------------------------------
static char *getHora_C_Impl(void *self)
{ return  (char *) getValue(self,POS_HORA_C); }
//----------------------------------------------------
static int getDocProfesional_C_Impl(void *self)
{ return *( (int *) getValue(self,POS_DOC_PROF_C)); }
//----------------------------------------------------
static int getCodMascota_C_Impl(void *self)
{ return *( (int *) getValue(self,POS_COD_MASCOTA_C)); }
//----------------------------------------------------
static int getAsistio_C_Impl(void *self)
{ return *( (int *) getValue(self,POS_ASISTIO_C)); }
//----------------------------------------------------
static int getCodDiagnostico_C_Impl(void *self)
{ return *( (int *) getValue(self,POS_COD_DIAG_C)); }
//----------------------------------------------------
static char *getObservaciones_C_Impl(void *self)
{ return  (char *) getValue(self,POS_OBS_C); }
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setIdConsulta_Impl(void *self,int val)
{ setValue(self,POS_ID,&val); }
//----------------------------------------------------
static void setFecha_C_Impl(void *self,char *fecha)
{ setValue(self,POS_FECHA_C,fecha); }
//----------------------------------------------------
static void setHora_C_Impl(void *self,char *hora)
{ setValue(self,POS_HORA_C,hora); }
//----------------------------------------------------
static void setDocProfesional_C_Impl(void *self,int val)
{ setValue(self,POS_DOC_PROF_C,&val); }
//----------------------------------------------------
static void setCodMascota_C_Impl(void *self,int val)
{ setValue(self,POS_COD_MASCOTA_C,&val); }
//----------------------------------------------------
static void setAsistio_C_Impl(void *self,int val)
{ setValue(self,POS_ASISTIO_C,&val); }
//----------------------------------------------------
static void setCodDiagnostico_C_Impl(void *self,int val)
{ setValue(self,POS_COD_DIAG_C,&val); }
//----------------------------------------------------
static void setObservaciones_C_Impl(void *self,char *obs)
{ setValue(self,POS_OBS_C,obs); }
//----------------------------------------------------
static void destroyInternalConsulta_Impl(void *self)
{
		//Implementado
		obj_Consulta *obj = this(self);
   	if( obj->diagnostico != NULL){
    	destroyObj(obj->diagnostico);
		}

}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

obj_Profesional *getProfesionalConsultaObj_C_Impl(void *self)
{
	/// implementado
	obj_Consulta *obj = this(self);
    obj->profesional = Profesional_new();

    if(obj->profesional->findbykey(obj->profesional, obj->getDocProfesional(obj))!= NOT_FOUND)
    	return obj->profesional;   
	return NULL;
}
//----------------------------------------------------
obj_Mascota *getMascotaConsultaObj_C_Impl(void *self)
{
	/// implementado
	obj_Consulta *obj = this(self);
    obj->mascota = Mascota_new();
    
    if(obj->mascota->findbykey(obj->mascota, obj->getCodMascota(obj))!= NOT_FOUND)
    	return obj->mascota; 
	return NULL;
}
//----------------------------------------------------
obj_Diagnostico *getDiagnosticoConsultaObj_C_Impl(void *self)
{
	/// implementado
	obj_Consulta *obj = this(self);
    obj->diagnostico = Diagnostico_new();
    
     
    if(obj->diagnostico->findbykey(obj->diagnostico, obj->getCodDiagnostico(obj))!= NOT_FOUND)
    	return obj->diagnostico;
	return NULL;
}

//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Consulta(void *self)
{
  obj_Consulta *obj  = this(self);
  obj->ds                     = &table_Consulta;
  obj->constructor            = Consulta_new;
  obj->sizeObj                = sizeof(obj_Consulta*);
  //incializacion de la interfaz de la entidad
  obj->toString               = toString_ConsultaImpl;
  obj->profesional			  = NULL;
  obj->mascota			  	  = NULL;
  obj->diagnostico			  = NULL;
    // Inicializar handlers de getters y setters
  /// getters
  obj->getId 				  = getIdConsulta_Impl;
  obj->getFecha               = getFecha_C_Impl;  
  obj->getHora                = getHora_C_Impl;
  obj->getDocProfesional   	  = getDocProfesional_C_Impl;
  obj->getCodMascota          = getCodMascota_C_Impl;
  obj->getAsistio  	  		  = getAsistio_C_Impl;
  obj->getCodDiagnostico	  = getCodDiagnostico_C_Impl;
  obj->getObservaciones	  	  = getObservaciones_C_Impl;
  
    /// setters  
  obj->setId 				  = setIdConsulta_Impl;
  obj->setFecha               = setFecha_C_Impl;  
  obj->setHora                = setHora_C_Impl;  
  obj->setDocProfesional      = setDocProfesional_C_Impl;
  obj->setCodMascota  	      = setCodMascota_C_Impl;
  obj->setAsistio  	  		  = setAsistio_C_Impl;
  obj->setCodDiagnostico	  = setCodDiagnostico_C_Impl;
  obj->setObservaciones	  	  = setObservaciones_C_Impl;
  
  // implementar detroy internal para liberar recursos
  obj->destroyInternal        = destroyInternalConsulta_Impl;
  //---- acceso a relaciones    
  obj->getProfesionalObj	  = getProfesionalConsultaObj_C_Impl;
  obj->getMascotaObj		  = getMascotaConsultaObj_C_Impl;
  obj->getDiagnosticoObj  	  = getDiagnosticoConsultaObj_C_Impl;  
  
  return obj;
}
//----------------------------------------------------
//constructor de Consulta
obj_Consulta *Consulta_new()
{
  return (obj_Consulta *)init_obj(sizeof(obj_Consulta), init_Consulta);
}

//----------------------Validaciones--------------------------------------

int consultaExiste(char *fecha,char *hora){
    int consultaExiste=0;
    int size,i;
	void *list,*itm;
	obj_Consulta *consulta;
	consulta = Consulta_new();

	size = consulta->findAll(consulta,&list,NULL);

	for(i=0; i<size; ++i)
    {
		consulta = ((obj_Consulta**)list)[i];
		char* fechaDb = consulta->getFecha(consulta);
		char* horaDb =  consulta->getHora(consulta);
		if ( !strcmp(fechaDb,fecha) && !strcmp(fechaDb, hora))
		{
			consultaExiste=1;
		}
	
    }
	    
	destroyObjList(list,size);
	destroyObj(consulta);
	return consultaExiste;

}

validarFecha(char* fecha)
{
	
	int esfechaValida =0;
	printf("ingrese fecha de la consulta: formato  yyyy-mm-dd \n");
	do
	{   
	    fflush(stdin);
		fgets(fecha,MAXFECHA-1,stdin);
		if ((strlen(fecha)-1) == 10) {
		      	char auxFecha[MAXFECHA];
				strcpy(auxFecha,fecha);
				char *anio;   
			    char *mes;      
			    char *dia;
			    
			    anio=strtok(auxFecha,"-");
			    mes=strtok(NULL,"-");
			    dia=strtok(NULL,"-");
			    
			    //validamos que sea una fecha 
		    	if(fecha[4] =='-' && fecha[7] =='-' && atoi(anio) >= 2022 && atoi(mes) <= 12 && atoi(mes) !=0 && atoi(dia)<=30  && atoi(dia) !=0)	
				{   char fechaActual[MAXFECHA];
	
				    strcpy(fechaActual,getFecha()); //fecha actual
	
			    	if(esFechaMayor(fechaActual,fecha)) //validamos que la fecha actual sea mayor o igual a la actual
					{
			    	   esfechaValida=1;
					}else printf("ingrese un fecha valida sdf");
			   
			   	}else printf("ingrese un fecha valida3:\n");
			   	
		}else printf("ingrese un fecha valida \n");
    }
    while(!esfechaValida);   
    
}

validarHora(char* hora){

    int esHoraValida =0;
    
	printf("ingrese Hora de la consulta: formato HH:mm:ss \n");
	do
	{ 	
	    fflush(stdin);
	    fgets(hora,MAXFECHA-1,stdin);
		if ((strlen(hora)-1) == 8) 
	    {
		      	char auxHora[MAXFECHA];
				strcpy(auxHora,hora);	
				char *hora;   
			    char *min;      
			    char *seg;
			    
			    hora=strtok(auxHora,"-");
			    min=strtok(NULL,"-");
			    seg=strtok(NULL,"-");
			    
			    //validamos que sea una fecha 
		    	if(hora[2] ==':' && hora[5] ==':' && atoi(hora) < 24  && atoi(hora) > 0 && atoi(min)<60  && atoi(min) >=0  &&  atoi(seg) <60 && atoi(seg)>=0  )
				{   
			    	   esHoraValida=1;
				
				}else printf("ingrese un hora valida \n");
			   
	
			   	
		}else printf("ingrese un fecha valida \n");
    }
    while(!esHoraValida);   	
}

int validarvalidarMascota(){
   int valido=0;
   int codigo;	  
   obj_Mascota *mascota;
   mascota = Mascota_new();
  printf("ingrese codigo: \n");
  while(!valido){
  scanf("%d", &codigo);
  fflush(stdin);
  if(mascota->findbykey(mascota,codigo) == NOT_FOUND){
      printf("codigo no encontrado, ingrese un codigo cargado en sistema \n");
  } else {
  	   return codigo;
  	}
    
	}
}
//-----------------------------Alta------------------------------------------------------
void altaConsulta(){
char  fecha[MAXFECHA],  hora[MAXFECHA];
	int idConsulta, dni,codMascota;
	obj_Consulta *consulta;
	consulta = Consulta_new();

	printf("ALTA CONSULTA \n");
	int turnoDisponible=0;
	do{
	
		
		char fecha[MAXFECHA];
		char hora[MAXFECHA];
	    validarFecha(fecha);
	    validarHora(hora);
		if (consultaExiste(fecha,hora)){
			printf("ya existe una consulta para esa fecha y hora desea ingresar nuevamente los datos si / no");
	        char resp[3];
		    fgets(resp,sizeof(resp)-1,stdin);
		    if(resp == "no")
			{
				exit;
			}
        }else{
            turnoDisponible=1;
		}
			
	}
    while(!turnoDisponible);
    
   	consulta->setFecha(consulta,fecha);
	consulta->setHora(consulta,hora);
    
    obj_Profesional *profesional;
	profesional = Profesional_new();

	printf("ingrese dni del profesional que atendera la consulta: \n");
	scanf("%d", &dni);
	fflush(stdin);

	if(profesional->findbykey(profesional,dni) == NOT_FOUND)
	 {
	    printf("profesional no exite desea ingresarlo? 1:si | 2:no /n ");
	    int resp;
	    fflush(stdin);
	    scanf("%d",resp);
	    if(resp == 1)
		{
	     altaProfesional();
		}
		else{
			   exit;
		     }
      }
      consulta->setDocProfesional(consulta,dni);
        
		obj_Mascota *mascota;
		mascota = Mascota_new();	
		
	    printf("ingrese el codigo de la mascota");
		scanf("%d", &codMascota);
		
	 if(mascota->findbykey(mascota,codMascota) == NOT_FOUND)
	 {
	    printf("la mascota no existe desea darla de alta? 1:si | 2:no \n");
	    int resp;
	    fflush(stdin);
	    scanf("%d",resp);
	    if(resp == 1)
		{
	     altaMascota();
		}
		else{
			   exit;
		     }
      }
      consulta->setCodMascota(consulta,codMascota);
	
	fflush(stdin);
	destroyObj(consulta);
		destroyObj(profesional);
			destroyObj(mascota);
}
    
//-------------------listado---------------------------------
listarConsultas(){
	int size,i;
  void *list,*itm;
  obj_Consulta *consulta;
  consulta = Consulta_new();
  
  size = consulta->findAll(consulta,&list,NULL);
  
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    ((Object *)itm)->toString(itm);
    printf("\n");
    fflush(stdin);

  }
  
  destroyObjList(list,size);
  destroyObj(consulta);
  
}
//-------------------------Fechas--------------------------------------------
t_fecha convertirFecha(char* fecha){
   
	char fechaAux[MAXFECHA];
	strcpy(fechaAux,fecha);
	t_fecha ffecha;
    char *anioc;
	char *mesc;
	char*dia;
    anioc=strtok(fechaAux,"-");
    mesc= strtok(NULL,"-");
    dia= strtok(NULL,"-");
    
   
	ffecha.anio = atoi(anioc);
	ffecha.mes  = atoi(mesc);
	ffecha.dia  = atoi(dia);
	return ffecha;
}

int esFechaMayor(char *fecha1 ,char *fecha2){  //devuelve 1 si la fecha2 es mayor o igual a la fecha 1
	t_fecha f1 = convertirFecha(fecha1);
	t_fecha f2 = convertirFecha(fecha2);
	
   if (f1.anio <= f2.anio && f1.mes < f2.mes){
   	return 1;
   }
   if (f1.anio <= f2.anio && f1.mes == f1.mes){   
        return (f1.dia <= f2.mes);
	   }
   
    return 0;
   
   
}
//-----------------Verificaciones---------------------
 int verificarConsultasPrevias(int dni, int codigo){
	
	obj_Consulta *consulta;
	consulta = Consulta_new();

	char criterio[MAX_SQL];
	void *list;
	int size;
	int i;

	int consultasAsistidas=0;
	int estado;
	int codigoConsulta;
	char fechaActual[MAXFECHA];
	strcpy(fechaActual, getFecha());

	CLEAR(criterio,MAX_SQL);
	//OBTENEMOS TODOS LAS CONSULTAS DE LA MASCOTA 
	sprintf(criterio, "nro_doc_cliente=%d and cod_mascota<>%d",dni,codigo);
	size = consulta->findAll(consulta,&list,criterio); // cosnultas totales de la mascota que ha asistido

	if (consultasAsistidas == 0)
		return 4;		// si no tiene registro lo tratamos como mascota nueva
	else{
		obj_Diagnostico *diagnostico;
		diagnostico = Diagnostico_new();	
	}
}




