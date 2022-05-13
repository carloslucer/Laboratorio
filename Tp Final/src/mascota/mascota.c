#include "../../includes/includelib.h"
#include "../especie/especie.h"
#include "../localidad/localidad.h"
#include "../cliente/cliente.h"
#include "mascota.h"
#include<stdbool.h>
#define MSJ_REINTENTAR "Desea reintentar la operacion? s/n\t"
#define MAX_CARACTERES 50
#define fgets(cadena) fgets(cadena,MAX_CARACTERES,stdin)
<<<<<<< Updated upstream

char cadena[MAX_CARACTERES];
int codigo;
int bandera;

bool confirmar;	//permitira controlar si el usuario quiere reintentar operacion
bool registrar; //permitira controlar si el usuario quiere seguir registrando

int compara_CodigoDescM(const void *l1, const void * l2){
    obj_Mascota *masc1 =  *((obj_Mascota **)l1);
    obj_Mascota *masc2 =  *((obj_Mascota **)l2);
    
    return (masc1->getCodigo(masc1) - masc2->getCodigo(masc2))*-1;
}
//--------------------------------------------------------------------------
int compara_CodigoAscM(const void *l1, const void * l2)
{
    obj_Mascota *masc1 =  *((obj_Mascota **)l1);
    obj_Mascota *masc2 =  *((obj_Mascota **)l2);
    
    return (masc2->getCodigo(masc2)) - (masc1->getCodigo(masc1))*-1;
}
//--------------------------------------------------------------------------
=======
>>>>>>> Stashed changes

char cadena[MAX_CARACTERES];
int codigo;
int bandera;

bool confirmar;	//permitira controlar si el usuario quiere reintentar operacion
bool registrar; //permitira controlar si el usuario quiere seguir registrando
//-------------------------------------------------------------------------

int compara_CodigoDescM(const void *l1, const void * l2){
    obj_Mascota *mascota1 =  *((obj_Mascota **)l1);
    obj_Mascota *mascota2 =  *((obj_Mascota **)l2);
    
    return (mascota1->getCodigo(mascota1) - mascota2->getCodigo(mascota2))*-1;
}
//--------------------------------------------------------------------------
int compara_CodigoAscM(const void *l1, const void * l2)
{
    obj_Mascota *mascota1 =  *((obj_Mascota **)l1);
    obj_Mascota *mascota2 =  *((obj_Mascota **)l2);
    
    return (mascota2->getCodigo(mascota2)) - (mascota1->getCodigo(mascota1))*-1;
}
//--------------------------------------------------------------------------

THIS(obj_Mascota)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_MascotaImpl(void *self)
{
     obj_Mascota *obj=this(self);     
     
     printf("codigo: %d  - Nombre:%s, %s \n",
	 obj->getCodigo(obj),
	 obj->getFechaNac(obj),
	 obj->getNombre(obj)	 
	 );
}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getCodigoMascota_Impl(void *self)
{ return *((int *) getValue(self,POS_ID)); }
//----------------------------------------------------
static char *getNombreMascota_Impl(void *self)
{ return  (char *) getValue(self,POS_NOMBRE_MASC); }
//----------------------------------------------------
static char *getFechaNacMascota_Impl(void *self)
{ return  (char *) getValue(self,POS_F_NAC_MASC); }
//----------------------------------------------------
static int getDniClienteMascota_Impl(void *self)
{ return *( (int *) getValue(self,POS_DNI_CLI_MASC)); }
//----------------------------------------------------
static int getCodEspecieMascota_Impl(void *self)
{ return *( (int *) getValue(self,POS_COD_ESP_MASC)); }
//----------------------------------------------------
static int getVacunadoMascota_Impl(void *self)
{ return *( (int *) getValue(self,POS_VACUNADO_MASC)); }
//----------------------------------------------------
static char *getObservacionesMascota_Impl(void *self)
{ return  (char *) getValue(self,POS_OBS_MASC); }
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setCodigoMascota_Impl(void *self,int val)
{ setValue(self,POS_ID,&val); }
//----------------------------------------------------
static void setNombreMascota_Impl(void *self,char *nombres_Mascota)
{ setValue(self,POS_NOMBRE_MASC,nombres_Mascota); }
//----------------------------------------------------
static void setFechaNacMascota_Impl(void *self,char *apellido_Mascota)
{ setValue(self,POS_F_NAC_MASC,apellido_Mascota); }
//----------------------------------------------------
static void setDniClienteMascota_Impl(void *self,int val)
{ setValue(self,POS_DNI_CLI_MASC,&val); }
//----------------------------------------------------
static void setCodEspecieMascota_Impl(void *self,int val)
{ setValue(self,POS_COD_ESP_MASC,&val); }
//----------------------------------------------------
static void setVacunadoMascota_Impl(void *self,int val)
{ setValue(self,POS_VACUNADO_MASC,&val); }
//----------------------------------------------------
static void setObservacionesMascota_Impl(void *self,char *obs)
{ setValue(self,POS_OBS_MASC,obs); }
//----------------------------------------------------
static void destroyInternalMasc_Impl(void *self)
{
	obj_Mascota *obj = this(self);	

}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
obj_Especie *getEspecieMascotaObj_Impl(void *self)
{
	obj_Mascota *obj = this(self);		
	return NULL;
}
//----------------------------------------------------
obj_Cliente *getClienteMascotaObj_Impl(void *self)
{
	obj_Mascota *obj = this(self);		
	return NULL;
}
/// ....
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Mascota(void *self)
{
  obj_Mascota *obj     = this(self);  
  obj->ds  			    = &table_Mascota;
  obj->constructor 	    = Mascota_new;
  obj->sizeObj 		    = sizeof(obj_Mascota*);
  obj->especie 	    = NULL;  
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_MascotaImpl;
  // Inicializar handlers de getters y setters
  /// getters
  obj->getCodigo  	  		= getCodigoMascota_Impl;  
  obj->getNombre 		= getNombreMascota_Impl;
  obj->getFechaNac 		= getFechaNacMascota_Impl;
  obj->getDniCliente 	= getDniClienteMascota_Impl;
  obj->getCodEspecie 	= getCodEspecieMascota_Impl;  
  obj->getVacunado 		= getVacunadoMascota_Impl;  
  obj->getObservaciones	= getObservacionesMascota_Impl;  
  /// setters  
  obj->setCodigo     		= setCodigoMascota_Impl;    
  obj->setNombre 		= setNombreMascota_Impl;
  obj->setFechaNac 		= setFechaNacMascota_Impl;
  obj->setDniCliente 	= setDniClienteMascota_Impl;
  obj->setCodEspecie    = setCodEspecieMascota_Impl;  
  obj->setVacunado      = setVacunadoMascota_Impl;  
  obj->setObservaciones = setObservacionesMascota_Impl;
  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalMasc_Impl;
  //---- acceso a relaciones  
  obj->getEspecieObj 	= getEspecieMascotaObj_Impl;  
  obj->getClienteObj 	= getClienteMascotaObj_Impl;  
  return obj;
}
//----------------------------------------------------
//constructor de Mascota
obj_Mascota *Mascota_new()
{
  return (obj_Mascota *)init_obj(sizeof(obj_Mascota), init_Mascota);
}
<<<<<<< Updated upstream
//-----------------LISTAR---------------------------------------
//listar mascotas
listarMascotas(){
	 printf("\n\t\t\t\tMASCOTAS\n");
	
	FILE *salida = stdin;
	
	obj_Mascota *masc, *aux;
	void *list,*itm;
	int i,size=0;
	
	masc = Mascota_new();
	size = masc->findAll(masc,&list,NULL);
=======
//----------------------LISTAR------------------------------
//listar Mascotas
void listarMascotas(char* archivo, bool descendente){
	
	printf("\n\t\t\t\tMASCOTAS\n");
	
	FILE *salida = stdin;
	
	obj_Mascota *mascota, *aux;
	void *list,*itm;
	int i,size=0;
	
	mascota = Mascota_new();
	size = mascota->findAll(mascota,&list,NULL);
>>>>>>> Stashed changes
	
	if(archivo != NULL) {
		printf("Exportando a archivo...\n");
        salida = fopen(archivo, "w+");
    }
<<<<<<< Updated upstream
	
	if (descendente)
		qsort(list, size, sizeof(obj_Mascota*),compara_CodigoDescM);
	else
		qsort(list, size, sizeof(obj_Mascota*),compara_CodigoAscM);
		
	// IMPRIME
	for(i=0;i<size;++i){
		itm = ((obj_Mascota **)list)[i];
		aux = (obj_Mascota*)itm; 
			
		if(archivo != NULL)
			fprintf(salida, "CODIGO:%d  Nombre:%s especie:%s \n",
				aux->getCodigo(aux),
				aux->getNombre(aux),
				aux->getCodEspecie(aux)
			);
		else
			((Object *)itm)->toString(itm);
	}
=======
>>>>>>> Stashed changes
  
  	if (descendente)
		qsort(list, size, sizeof(obj_Mascota*),compara_CodigoDescM);
	else
		qsort(list, size, sizeof(obj_Mascota*),compara_CodigoAscM)
		
	// IMPRIME
	for(i=0;i<size;++i){
		itm = ((obj_Mascota **)list)[i];
		aux = (obj_Mascota*)itm; 
			
		if(archivo != NULL)
			fprintf(salida, "CODIGO:%d  Nombre:%s Especie:%s \n",
				aux->getCodigo(aux),
				aux->getNombre(aux),
				aux->getCodEspecie(aux)
			);
		else
			((Object *)itm)->toString(itm);
	}
	
	if (archivo != NULL){
	fclose(salida); 
	printf("\nListado de pacientes exportado\n\n");
	}
	printf("\n");
	destroyObjList(list,size); 
	destroyObj(pac);
	
}
<<<<<<< Updated upstream
   //Alta mascota
=======

//+++++++++++++++++++++++++++++++++++++++++++++
void actualizarMascota()
{
	obj_Mascota *mascota;
	mascota = Mascota_new();
	
	printf("USTED ESTA ACTUALIZANDO UNA MASCOTA\n\n");	
	listarMascotas(NULL,false);
	
	do{
		confirmar = false;

		ingresarNumero("Ingrese el codigo de Documento de la mascota:\t\t",&cadena);
		codigo = atoi(cadena);
		
		if(mascota->findbykey(paciente,codigo) != NOT_FOUND)
		{
			ingresarCadena("Ingrese los nombres de la mascota:\t\t\t",&cadena);
			mascota->setNombres(mascota,cadena);
 
/*
validarFecha(*char fecha){

}*/
>>>>>>> Stashed changes
altaMascota(){
	char nombre[MAXNOMBRE];
	char fechaNac[MAXFECHA];

	int codEspecie;

	int dni;
obj_Mascota *mascota;
  mascota = Mascota_new();
  obj_Cliente *cliente;
  cliente = Cliente_new();
	
	printf("ALTA MASCOTA \n");
	 printf("ingrese nombre de la mascota: \n");
    fgets(nombre,MAXNOMBRE-1,stdin);
    mascota->setNombre(mascota,nombre);

 	 printf("ingrese fecha de nacimiento: \n");
 	 fgets(fechaNac,MAXFECHA-1,stdin);
 	 mascota->setFechaNac(mascota,fechaNac);
 	 
 	  printf("ingrese dni del cliente: \n");
 	  scanf("%d", &dni);
  fflush(stdin);
  if(cliente->findbykey(cliente,dni) == NOT_FOUND){
    cliente->setDni(cliente,dni);
   
     printf("ingrese el codigo de la especie  \n");
     scanf("%d", &CodEspecie);
  fflush(stdin);
  if(mascota->findbykey(mascota,codEspecie) == NOT_FOUND){
    mascota->setCodigo(mascota,codEspecie);

    printf("ingrese 1 si la mascota esta vacunada o ingrese 0 si la mascota no esta vacunada \n");
    	scanf("%d", &vacunado);
    fflush(stdin);
		}
    printf("ingrese observacion de la moscota \n");
		fgets(observacion,MAXOBSERVACION-1,stdin);
    mascota->setObservaciones(mascota,observacion);
	}
	
	 if(mascota->saveObj(mascota)){ 
    printf("mascota guardada correctamente \n");
      }
    else{
     printf("error al guardar la mascota \n");
    }
   }
   else{
    printf("mascota ya existe \n");
   }
}
