#include "../../includes/includelib.h"
#include "../localidad/localidad.h"
#include "../cliente/cliente.h"
#include "../profesional/profesional.h"
#include "../especie/especie.h"
#include "../mascota/mascota.h"
#include "../diagnostico/diagnostico.h"
#include "consulta.h"
#define MAXHORA 8
THIS(obj_Consulta)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_ConsultaImpl(void *self)
{
	obj_Consulta *obj=this(self);
	printf("objConsulta\n");
	//implementar con la mayor cantidad de datos
}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getIdConsulta_Impl(void *self)
{
	return *( (int *) getValue(self,POS_ID));
}
//----------------------------------------------------
static char *getFecha_C_Impl(void *self)
{
	return  (char *) getValue(self,POS_FECHA_C);
}
//----------------------------------------------------
static char *getHora_C_Impl(void *self)
{
	return  (char *) getValue(self,POS_HORA_C);
}
//----------------------------------------------------
static int getDocProfesional_C_Impl(void *self)
{
	return *( (int *) getValue(self,POS_DOC_PROF_C));
}
//----------------------------------------------------
static int getCodMascota_C_Impl(void *self)
{
	return *( (int *) getValue(self,POS_COD_MASCOTA_C));
}
//----------------------------------------------------
static int getAsistio_C_Impl(void *self)
{
	return *( (int *) getValue(self,POS_ASISTIO_C));
}
//----------------------------------------------------
static int getCodDiagnostico_C_Impl(void *self)
{
	return *( (int *) getValue(self,POS_COD_DIAG_C));
}
//----------------------------------------------------
static char *getObservaciones_C_Impl(void *self)
{
	return  (char *) getValue(self,POS_OBS_C);
}
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setIdConsulta_Impl(void *self,int val)
{
	setValue(self,POS_ID,&val);
}
//----------------------------------------------------
static void setFecha_C_Impl(void *self,char *fecha)
{
	setValue(self,POS_FECHA_C,fecha);
}
//----------------------------------------------------
static void setHora_C_Impl(void *self,char *hora)
{
	setValue(self,POS_HORA_C,hora);
}
//----------------------------------------------------
static void setDocProfesional_C_Impl(void *self,int val)
{
	setValue(self,POS_DOC_PROF_C,&val);
}
//----------------------------------------------------
static void setCodMascota_C_Impl(void *self,int val)
{
	setValue(self,POS_COD_MASCOTA_C,&val);
}
//----------------------------------------------------
static void setAsistio_C_Impl(void *self,int val)
{
	setValue(self,POS_ASISTIO_C,&val);
}
//----------------------------------------------------
static void setCodDiagnostico_C_Impl(void *self,int val)
{
	setValue(self,POS_COD_DIAG_C,&val);
}
//----------------------------------------------------
static void setObservaciones_C_Impl(void *self,char *obs)
{
	setValue(self,POS_OBS_C,obs);
}
//----------------------------------------------------
static void destroyInternalConsulta_Impl(void *self)
{
	obj_Consulta *obj = this(self);
	// implementar
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

obj_Profesional *getProfesionalConsultaObj_C_Impl(void *self)
{
	/// implementar
	return NULL;
}
//----------------------------------------------------
obj_Mascota *getMascotaConsultaObj_C_Impl(void *self)
{
	/// implementar
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
//----------------------------------------------------
listarConsultas()
{
	int size,i;
	void *list,*itm;
	obj_Consulta *consulta;
	consulta = Consulta_new();

	size = consulta->findAll(consulta,&list,NULL);

	for(i=0; i<size; ++i) {
		itm = ((Object **)list)[i];
		((Object *)itm)->toString(itm);
		printf("\n");
		fflush(stdin);

	}

	destroyObjList(list,size);
	destroyObj(consulta);

}

altaConsulta()
{
/*	char nombre[MAXNOMBRE], fecha[MAXFECHA],  hora[MAXHORA];
	int idConsulta, dni;
	obj_Consulta *consulta;
	consulta = Consulta_new();

	printf("ingrese el codigo de la consulta:  \n");
	scanf("%d", &idConsulta);
	fflush(stdin);
	if(consulta->findbykey(consulta,idConsulta) == NOT_FOUND) {
		consulta->setId (consulta,idConsulta);
	}

	printf("ALTA CONSULTA \n");

	printf("ingrese fecha de la consulta: \n");
	fgets(fecha,MAXFECHA-1,stdin);
	verificarFechaConsulta(fecha);
	consulta->setFecha(consulta,fecha);

	printf("ingrese una hora: \n");
	validarHora(hora);
	consulta->setHora(hora);

	printf("ingrese dni del profesional que atendera la consulta: \n");
	scanf("%d", &dni);
	fflush(stdin);

	if(profesional->findbykey(profesional,dni) == NOT_FOUND) {
		profesional->setDni(profesional,dni);
*/
//-------------------listar---------------------------------
	/*	listarConsultas() 
		{
			int size,i;
			void *list,*itm;
			obj_Consulta *consulta;
			consulta = Consulta_new();

			size = consulta->findAll(consulta,&list,NULL);

			for(i=0; i<size; ++i) {
				itm = ((Object **)list)[i];
				((Object *)itm)->toString(itm);
				printf("\n");
				fflush(stdin);

			}

			destroyObjList(list,size);
			destroyObj(consulta);
*/
		}

