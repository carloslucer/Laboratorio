#include "../../includes/includelib.h"
#include "../localidad/localidad.h"
#include "../cliente/cliente.h"
#include "../profesional/profesional.h"
#include "../especie/especie.h"
#include "../mascota/mascota.h"
#include "../diagnostico/diagnostico.h"
#include "consulta.h"
<<<<<<< Updated upstream
=======
#include <string.h>
#include <ctype.h>

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
>>>>>>> Stashed changes

THIS(obj_Consulta)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_ConsultaImpl(void *self)
{
<<<<<<< Updated upstream
     obj_Consulta *obj=this(self);
     printf("objConsulta\n");
    //implementar con la mayor cantidad de datos
=======
	obj_Consulta *obj=this(self);
	printf("objConsulta\n");
    obj_Mascota *mascota = obj->getMascotaObj(obj);
    obj_Especie *especie = obj->getEspecieObj(obj);
    obj_Profesional *profesional = obj->getProfesionalObj(obj);
    obj_Diagnostico *diagnostico = obj->getDiagnosticoObj(obj);
    
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
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
	obj_Consulta *obj = this(self);	
	// implementar
=======
		//Implementado
		obj_Consulta *obj = this(self);
   	if( obj->diagnostico != NULL){
    	destroyObj(obj->diagnostico);
		}
>>>>>>> Stashed changes
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

obj_Profesional *getProfesionalConsultaObj_C_Impl(void *self)
{
	/// implementado
	obj_Consulta *obj = this(self);
    obj->Profesional = Profesional_new();
    
    if(obj->Profesional->findbykey(obj->profesional, obj->getDocProfesional(obj))!= NOT_FOUND)
    	return obj->profesional;   
	return NULL;
}
//----------------------------------------------------
obj_Mascota *getMascotaConsultaObj_C_Impl(void *self)
{
	/// implementado
	obj_Consulta *obj = this(self);
    obj->Mascota = Mascota_new();
    
    if(obj->Masccota->findbykey(obj->Mascota, obj->getCodMascota(obj))!= NOT_FOUND)
    	return obj->mascota; 
	return NULL;
}
//----------------------------------------------------
obj_Diagnostico *getDiagnosticoConsultaObj_C_Impl(void *self)
{
	/// implementar
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

<<<<<<< Updated upstream
//Alta 
altaConsulta(){
	char nombre[MAXNOMBRE], char fecha[MAXFECHA], char hora[MAXHORA], observacion[MAXDESCRIPCION];
	int idConsulta, dni;
	 obj_Consulta *consulta;
  consulta = Consulta_new();
  
  printf("ingrese el codigo de la consulta:  \n");
     scanf("%d", &idConsulta);
  fflush(stdin);
  if(consulta->findbykey(consulta,idConsulta) == NOT_FOUND){
    consulta->setId (consulta,idConsulta);
}

	 printf("ALTA CONSULTA \n");
 	 printf("ingrese fecha de la consulta: \n");
 	 fgets(fecha,MAXFECHA-1,stdin);
 	 consulta->setFecha(consulta,fecha);

	printf("ingrese una hora: \n");
	validarHora(hora);

	printf("ingrese dni del profesional: \n");
 	  scanf("%d", &dni);
  fflush(stdin);
  if(profesional->findbykey(profesional,dni) == NOT_FOUND){
    profesional->setDni(profesional,dni);

  	 listarMascota();
  	 validarMascota();
     scanf("%d", &CodMascota);
  fflush(stdin);
  if(mascota->findbykey(mascota,codEspecie) == NOT_FOUND){
    mascota->setCodigo(mascota,codEspecie);
    
	printf("ingrese observacion de la consulta: \n");
		fgets(observacion,MAXOBSERVACION-1,stdin);
    consulta->setObservaciones(consulta,observacion);
	}
    
//-------------------listar---------------------------------
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
=======
//----------------------------------------------------------
void obtenerConsulta(int dni, int codigo){
	
	obj_Consulta *consulta;
	consulta = Consulta_new();
	
	char criterio[MAX_SQL];

	void *list, *itm;
	int i, aux=0;
	int diagnostico = 0;
	
	CLEAR(criterio,MAX_SQL);
	int size = sprintf(criterio, "nro_dni_cliente=%d and cod_mascota=%d and asistio=TRUE",dni, codigo);
	size = consulta->findAll(consulta,&list,criterio);

	printf("\n");
	
	for(i=0; i<size; ++i){
		consulta = ((obj_Consulta **)list)[i];
		
		diagnostico = consulta->getAsistio(consulta);
			
		if (diagnostico)
			++aux;
	}
	++aux;
	
	return aux;	
}
//------------------------------------------------------------

int obtenerCodDiagnostico(int dni, int codigo){

	obj_Consulta *consulta;
	consulta = Consulta_new();

	char criterio[MAX_SQL];

	void *list, *itm;
	int i, aux=0;
	int diagnostico = 0;
		
	CLEAR(criterio,MAX_SQL);
	int size = sprintf(criterio, "nro_doc_cliente=%d and cod_mascota=%d",dni, codigo);
	size = consulta->findAll(consulta,&list,criterio);

	consuta = ((obj_Consulta **)list)[size-1];	
	return consulta->getCodDiagnostico(consulta);
}
//------------------------------------------------
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

	if (turnosAsistidos == 0)
		return 4;		// si no tiene registro lo tratamos como mascota nueva
	else{
		obj_Diagnostico *diagnostico;
		diagnostico = Diagnostico_new();	
	}
}

//------------ALTAS------------------------

void altaConsulta()
{
	obj_Consulta *consulta;
	consulta = Consulta_new();
	
	bool esClienteNuevo = false; //para comprobar si el cliente es nuevo
	bool esMascotaNueva = false; //para comprobar si la mascota es nuevo
	
	printf("USTED ESTA REGISTRANDO UNA CONSULTA\n\n");
	
	// CLIENTE
	obj_Cliente *cliente;
	cliente = cliente_new();
	
	ingresarNumero("Ingrese el DNI del cliente:\t",&cadena);
	int codigoDNI = atoi(cadena);

	int codLocalidad;
	//si no existe se registra, caso contrario se verifica el estado del cliente
	if (cliente->findbykey(cliente,codigoDNI) == NOT_FOUND){
		
		printf("EL CLIENTE NO ESTA REGISTRADO EN EL SISTEMA\n");
		resp = continuar("Desea registrar al cliente? s/n:\t");

			
		if (resp){
			esClienteNuevo = true;
			consulta->setDocCliente(consulta,codigoDNI);
			registrarConsulta();		
			codLocalidad = obtenerCodLocalidad(codigoDNI);
		}
		else
			exit;
	}else{
		esClienteNuevo = false;
		codLocalidad = cliente->getCodPostal(cliente);	
	}
	
	obj_Localidad *loc;
	loc = Localidad_new();

>>>>>>> Stashed changes
}

