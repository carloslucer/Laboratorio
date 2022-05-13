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
//----------------------------------------------------
//-----------------LISTAR---------------------------------------
listarClientes(){
  
  int size,i;
  void *list,*itm;
  obj_Cliente *cliente;
  cliente = Cliente_new();
  
  size = cliente->findAll(cliente,&list,NULL);
  
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    ((Object *)itm)->toString(itm);
    printf("\n");
    fflush(stdin);

  }
  
  destroyObjList(list,size);
  destroyObj(cliente);
  
}

//-------------------ALTAS---------------------------------------------
altaCliente(){
  int dni, codPostal;
    char nombre[MAXNOMBRE], apellido[MAXAPELLIDO], domicilio[MAXDOMICILIO], observacion[MAXOBSERVACION], telefono[MAXTELEFONO];
  obj_Cliente *cliente;
    cliente = Cliente_new();
    
  printf("ALTA CLIENTE \n");
  printf("ingrese dni: \n");
  scanf("%d", &dni);
  fflush(stdin);
  if(cliente->findbykey(cliente,dni) == NOT_FOUND){
    cliente->setDni(cliente,dni);
     
    printf("ingrese nombre: \n");
    fgets(nombre,MAXNOMBRE-1,stdin);
    cliente->setNombres(cliente,nombre);
    
    printf("ingrese apellido: \n");
    fgets(apellido,MAXAPELLIDO-1,stdin);
    cliente->setApellido(cliente,apellido);
    
    printf("ingrese donicilio \n");
    fgets(domicilio,MAXDOMICILIO-1,stdin);
    cliente->setDomicilio(cliente,domicilio);

    printf("ingrese telefono: \n");
    fgets(telefono,MAXTELEFONO-1,stdin);
    cliente->setTelefono(cliente,telefono);
      
    codPostal = validarCodigoPostal();
    cliente->setCodPostal(cliente,codPostal);   
    
      printf("ingrese observaciones: \n");
    fgets(observacion,MAXOBSERVACION-1,stdin);
    cliente->setObservaciones(cliente,observacion);
    
    if(cliente->saveObj(cliente)){ 
    printf("cliente guardado correctamente \n");
      }
    else{
     printf("error al guardar cliente \n");
    }
   }
   else{
    printf("cliente ya existe \n");
   }
  destroyObj(cliente);
}
//-------------validarcliente----------------------
//
int validarDniCliente(){
   int valido=0;
   int dni;	  
   obj_Cliente *cliente;
   cliente = Cliente_new();
  printf("ingrese dni del cliente: \n");
  while(!valido){
  scanf("%d", &dni);
  fflush(stdin);
  if(cliente->findbykey(cliente,dni) == NOT_FOUND){
      printf("dni no encontrado, ingrese un dni cargado en sistema \n");
  } else {
  	   return dni;
  }
  
     
}
}


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

int compara_CodigoDescC(const void *l1, const void * l2){
    obj_Cliente *clie1 =  *((obj_Cliente **)l1);
    obj_Cliente *clie2 =  *((obj_Cliente **)l2);
    
    return (clie1->getDni(clie1) - clie2->getDni(clie2))*-1;
}
//--------------------------------------------------------------------------
int compara_CodigoAscC(const void *l1, const void * l2)
{
    obj_Cliente *clie1 =  *((obj_Cliente **)l1);
    obj_Cliente *clie2 =  *((obj_Cliente **)l2);
    
    return (clie2->getDni(clie2)) - (clie1->getDni(clie1))*-1;
}






listarClientePorLocalidad(char* archivo, bool descendente){
	
	obj_Cliente *cliente;
	cliente = Cliente_new();
	
	FILE*salida = stdin;
	
	char criterio[MAX_SQL];
	void *list, *itm;
	int i, size;
	
	if(archivo != NULL){
		printf("Exportando al archivo....\n");
		salida = fopen(archivo, "w+");
	}
	
	sprintf(criterio, "cod_postal=9100 or cod_postal=9103 or cod_postal=9120");
	size = cliente->findAll(cliente,&list,criterio);
	
	if (descendente)
		qsort(list, size, sizeof(obj_Cliente*),compara_CodigoDescC);
	else
		qsort(list, size, sizeof(obj_Cliente*),compara_CodigoAscC);

	
	for(i=0; i<size; ++i){
		
		cliente = ((obj_Cliente **)list)[i];
		
		if(archivo != NULL)
			fprintf(salida, "DNI:%d Nombre:%s Apellido: %s",
				cliente->getDni(cliente),
				cliente->getNombres(cliente),
				cliente->getApellido(cliente));
		else
			cliente->toString(cliente);
	}
	
	if (archivo != NULL){
		fclose(salida);
		printf("\nListado de clientes exportado\n\n");
	}
}





void actualizarCliente()
{
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
			
		//	listarLocalidades(NULL,false);
			
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




