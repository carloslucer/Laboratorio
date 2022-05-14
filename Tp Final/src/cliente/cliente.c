#include "../../includes/includelib.h"
#include "../localidad/localidad.h"
#include "cliente.h"
#define MAX_CARACTERES 50
#define MSJ_REINTENTAR "Desea reintentar la operacion? s/n\t"

char cadena[MAX_CARACTERES];
int codigo;
int bandera;

bool confirmar;	//permitira controlar si el usuario quiere reintentar operacion
bool registrar; //permitira controlar si el usuario quiere seguir registrando

//--------------Ordenamientos----------------------------
int compara_CodigoDesc(const void *l1, const void * l2){
    obj_Cliente *clie1 =  *((obj_Cliente **)l1);
    obj_Cliente *clie2 =  *((obj_Cliente **)l2);
    
    return (clie1->getDni(clie1) - clie2->getDni(clie2))*-1;
}
//--------------------------------------------------------------------------
int compara_CodigoAsc(const void *l1, const void * l2)
{
    obj_Cliente *clie1 =  *((obj_Cliente **)l1);
    obj_Cliente *clie2 =  *((obj_Cliente **)l2);
    
    return (clie2->getDni(clie2)) - (clie1->getDni(clie1))*-1;
}

//--------------------------------------------------------------------------


THIS(obj_Cliente)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_ClienteImpl(void *self)
{
     obj_Cliente *obj=this(self);     
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
static int getDniCliente_Impl(void *self)
{ return *((int *) getValue(self,POS_ID)); }
//----------------------------------------------------
static char *getNombresCliente_Impl(void *self)
{ return  (char *) getValue(self,POS_NOMBRES_CLI); }
//----------------------------------------------------
static char *getApellidoCliente_Impl(void *self)
{ return  (char *) getValue(self,POS_APELLIDO_CLI); }
//----------------------------------------------------
static char *getDomicilioCliente_Impl(void *self)
{ return  (char *) getValue(self,POS_DOMICILIO_CLI); }
//----------------------------------------------------
static char *getTelefonoCliente_Impl(void *self)
{ return  (char *) getValue(self,POS_TELEFONO_CLI); }
//----------------------------------------------------
static int getCodPostalCliente_Impl(void *self)
{ return *( (int *) getValue(self,POS_COD_POSTAL_CLI)); }
//----------------------------------------------------
static char *getObservacionesCliente_Impl(void *self)
{ return  (char *) getValue(self,POS_OBS_CLI); }
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setDniCliente_Impl(void *self,int val)
{ setValue(self,POS_ID,&val); }
//----------------------------------------------------
static void setNombresCliente_Impl(void *self,char *nombres_Cliente)
{ setValue(self,POS_NOMBRES_CLI,nombres_Cliente); }
//----------------------------------------------------
static void setApellidoCliente_Impl(void *self,char *apellido_Cliente)
{ setValue(self,POS_APELLIDO_CLI,apellido_Cliente); }
//----------------------------------------------------
static void setDomicilioCliente_Impl(void *self,char *domicilio_Cliente)
{ setValue(self,POS_DOMICILIO_CLI,domicilio_Cliente); }
//----------------------------------------------------
static void setTelefonoCliente_Impl(void *self,char *telefono_Cliente)
{ setValue(self,POS_TELEFONO_CLI,telefono_Cliente); }
//----------------------------------------------------
static void setCodPostalCliente_Impl(void *self,int val)
{ setValue(self,POS_COD_POSTAL_CLI,&val); }
//----------------------------------------------------
static void setObservacionesCliente_Impl(void *self,char *obs)
{ setValue(self,POS_OBS_CLI,obs); }
//----------------------------------------------------
static void destroyInternalCli_Impl(void *self)
{
	obj_Cliente *obj = this(self);	
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
obj_Localidad *getLocalidadClienteObj_Impl(void *self)
{
	obj_Cliente *obj = this(self);	
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
static void *init_Cliente(void *self)
{
  obj_Cliente *obj     = this(self);  
  obj->ds  			    = &table_Cliente;
  obj->constructor 	    = Cliente_new;
  obj->sizeObj 		    = sizeof(obj_Cliente*);
  obj->localidad 	    = NULL;  
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_ClienteImpl;
  // Inicializar handlers de getters y setters
  /// getters
  obj->getDni  	  		= getDniCliente_Impl;  
  obj->getNombres 		= getNombresCliente_Impl;
  obj->getApellido 		= getApellidoCliente_Impl;
  obj->getDomicilio 	= getDomicilioCliente_Impl;
  obj->getTelefono 		= getTelefonoCliente_Impl;    
  obj->getCodPostal 	= getCodPostalCliente_Impl;  
  obj->getObservaciones	= getObservacionesCliente_Impl;  
  /// setters  
  obj->setDni     		= setDniCliente_Impl;    
  obj->setNombres 		= setNombresCliente_Impl;
  obj->setApellido 		= setApellidoCliente_Impl;
  obj->setDomicilio 	= setDomicilioCliente_Impl;
  obj->setTelefono 		= setTelefonoCliente_Impl;  
  obj->setCodPostal     = setCodPostalCliente_Impl;  
  obj->setObservaciones = setObservacionesCliente_Impl;
  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalCli_Impl;
  //---- acceso a relaciones  
  obj->getLocalidadObj 	= getLocalidadClienteObj_Impl;  
  return obj;
}
//----------------------------------------------------
//constructor de Cliente
obj_Cliente *Cliente_new()
{
  return (obj_Cliente *)init_obj(sizeof(obj_Cliente), init_Cliente);
}

//-----------------LISTAR---------------------------------------
//listar clientes
void listarClientes(char* archivo, bool descendente){
	
	printf("\n\t\t\t\tCLIENTES\n");
	
	FILE *salida = stdin;
	
	obj_Cliente *cliente, *aux;
	void *list,*itm;
	int i,size=0;
	
	cliente = Cliente_new();
	size = cliente->findAll(cliente,&list,NULL);
	
	if(archivo != NULL) {
		printf("Exportando a archivo...\n");
        salida = fopen(archivo, "w+");
    }
    
	if (descendente)
		qsort(list, size, sizeof(obj_Cliente*),compara_CodigoDesc);
	else
		qsort(list, size, sizeof(obj_Cliente*),compara_CodigoAsc);
		
	// IMPRIME
	for(i=0;i<size;++i){
		itm = ((obj_Cliente **)list)[i];
		aux = (obj_Cliente*)itm; 
			
		if(archivo != NULL)
			fprintf(salida, "DNI:%d  Nombre:%s Apellido:%s \n",
				aux->getDni(aux),
				aux->getNombres(aux),
				aux->getApellido(aux)
			);
		else
			((Object *)itm)->toString(itm);
	}
	
	if (archivo != NULL){
		fclose(salida); 
		printf("\nListado de clientes exportado\n\n");
	}
	printf("\n");
	destroyObjList(list,size); 
	destroyObj(cliente);
}
			
//-------------------ALTAS---------------------------------------------
void altaCliente(){
  
  obj_Cliente *cliente;
  cliente = Cliente_new();
  
  printf("USTED ESTA REGISTRANDO UN CLIENTE\n\n");
  
  ingresarNumero("Ingrese el numero de documento:\t\t",&cadena);
  codigo = atoi(cadena);
  cliente->setDni(cliente,codigo); //seteamos el id
  
  ingresarCadena("Ingrese el/los apellido/s del cliente:\t", &cadena);
  cliente->setApellido(cliente,cadena);
  
  ingresarCadena("Ingrese el/los nombres del cliente:\t", &cadena);
  cliente->setApellido(cliente,cadena);
  
  ingreseCadena("Ingrese el domicilio del cliente:\t",&cadena);
  cliente->setDomicilio(cliente,cadena);
  
  obj_Localidad *localidad;
  localidad = Localidad_new();
  
  listarLocalidades(NULL,false);
  
  do{
  		confirmar = false;
  		
  		ingresarNumero("Ingrese codigo postal del cliente:\t\t",&cadena);
  		codigo = atoi(cadena);
  		
  		if(localidad->findbykey(localidad,codigo) != NOT_FOUND)
  		{
  			cliente->setCodPostal(cliente,codigo);
  			
  			ingresarNumero("Ingrese el numero de telefono:\t\t",&cadena);
  			cliente->setTelefono(cliente,cadena);
		  
			ingresarCadena("Ingrese observaciones:\t",&cadena);
			cliente->setObservaciones(cliente,cadena);
		
			if(!cliente->saveObj(cliente))
				printf("\nOcurrio un error al agregar un cliente: \n%s\n",getLasrError());
			else
				printf("\nCLIENTE CREADO\n");
			system("pause");
  		}else{
  			printf("\nERROR: no se pudo encontrar la localidad ingresada\n\n");
  			confirmar = continuar(MSJ_REINTENTAR);
		}
	}while(confirmar);
     
     destroyObj(cliente);
     destroyObj(localidad);	
}
//-------------validarLocalidad----------------------

int obtenerCodLocalidad(int dni){
	
	obj_Cliente *clie;
	clie = Cliente_new();
	
	char criterio[MAX_SQL];
	void *list;
	int i,size=0;
	
	//Listamos por el numero de documento
	sprintf(criterio, "nro_documento=%d",dni);
	size = clie->findAll(clie,&list,criterio);
	
	clie = ((obj_Cliente **)list)[size-1];
	return clie->getCodPostal(clie);
}


//-------------ListadoDeClientesPorLocalidad------------

listarClientePorLocalidad(char* archivo, bool descendente){
	
	obj_Cliente *clie;
	clie = Cliente_new();
	
	FILE*salida = stdin;
	
	char criterio[MAX_SQL];
	void *list, *itm;
	int i, size;
	
	if(archivo != NULL){
		printf("Exportando al archivo....\n");
		salida = fopen(archivo, "w+");
	}
	
	sprintf(criterio, "cod_postal=9100 or cod_postal=9103 or cod_postal=9120");
	size = clie->findAll(clie,&list,criterio);
	
	if (descendente)
		qsort(list, size, sizeof(obj_Cliente*),compara_CodigoDesc);
	else
		qsort(list, size, sizeof(obj_Cliente*),compara_CodigoAsc);

	
	for(i=0; i<size; ++i){
		
		clie = ((obj_Cliente **)list)[i];
		
		if(archivo != NULL)
			fprintf(salida, "DNI:%d Nombre:%s Apellido: %s",
				clie->getDni(clie),
				clie->getNombres(clie),
				clie->getApellido(clie));
		else
			clie->toString(clie);
	}
	
	if (archivo != NULL){
		fclose(salida);
		printf("\nListado de clientes exportado\n\n");
	}
}
//-------------------ActualizarCliente---------------------------------

void actualizarCliente()
{
	int codigo;
	obj_Cliente *cliente;
	cliente = Cliente_new();
	
	printf("USTED ESTA ACTUALIZANDO UN CLIENTE\n\n");
	listarClientes(NULL,false);
	
	do{
		confirmar = false;
		
		ingresarNumero("Ingrese el Numero de Documento del cliente:\t\t",&cadena);
		codigo = atoi(cadena);
		
		if(cliente->findbykey(cliente,codigo) != NOT_FOUND)
		{
			ingresarCadena("Ingrese el/los apellido/s del cliente:\t\t\t",&cadena);
			cliente->setApellido(cliente,cadena);
			
			ingresarCadena("Ingrese los nombres del cliente:\t\t\t",&cadena);
			cliente->setNombres(cliente,cadena);
			
			ingresarCadena("Ingrese el domicilio del cliente:\t\t\t",&cadena);
			cliente->setDomicilio(cliente,cadena);
			
			obj_Localidad *localidad;
			localidad = Localidad_new();
			
			listarLocalidades(NULL,false);
			
			bool reintentar;
			
			do{
				reintentar = false;
				
				ingresarNumero("Ingrese el nuevo codigo postal del cliente:\t\t\t", &cadena);
				codigo = atoi(cadena);
				
				if(localidad->findbykey(localidad,codigo) != NOT_FOUND)
				{
					cliente->setCodPostal(cliente,codigo);
					
					ingresarNumero("Ingrese el numero de telefono:\t\t\t\t",&cadena);
					cliente->setTelefono(cliente,cadena);
					
					ingresarCadena("Ingrese observaciones:\t\t\t\t\t", &cadena);
					cliente->setObservaciones(cliente,cadena);
					
					if(!cliente->saveObj(cliente))
						printf("\nOcurrio un error al agregar al cliente:\n%s\n",getLastError());
					else
						printf("\nCLIENTE ACTUALIZADO\n");
					
					system("pause");
					destroyObj(localidad);
				}else{
					printf("\nERROR: no se pudo encontrar la localidad\n\n");
					reintentar = continuar(MSJ_REINTENTAR);
				}					
			}while(reintentar);
		}else{
			printf("\nERROR: cliente no encontrado\n\n");
			confirmar = continuar(MSJ_REINTENTAR);
		}
	}while(confirmar);
	destroyObj(cliente);
}
