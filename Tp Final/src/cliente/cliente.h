#ifndef CLI_INCLUDED
	#define CLI_INCLUDED
	#define CNT_COL_CLI 7
	#define POS_NOMBRES_CLI 1
	#define POS_APELLIDO_CLI 2
	#define POS_DOMICILIO_CLI 3
	#define POS_TELEFONO_CLI 4
	#define POS_COD_POSTAL_CLI 5
	#define POS_OBS_CLI 6
	#define MAXNOMBRE 80
	#define MAXAPELLIDO 90
	#define MAXDOMICILIO 120
	#define MAXOBSERVACION 250
	#define MAXTELEFONO 20
	
	
	//----------------------------------------------------
	typedef struct {	    
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters	    
		getPropertyIntPtr   getDni;
		getPropertyCharPtr  getNombres;
		getPropertyCharPtr  getApellido;
		getPropertyCharPtr  getDomicilio;
		getPropertyCharPtr  getTelefono;
		getPropertyIntPtr   getCodPostal;		
		getPropertyCharPtr  getObservaciones;
	    //-- setters
		setPropertyIntPtr   setDni;
		setPropertyCharPtr  setNombres;
		setPropertyCharPtr  setApellido;
		setPropertyCharPtr  setDomicilio;
		setPropertyCharPtr  setTelefono;
		setPropertyIntPtr   setCodPostal;		
		setPropertyCharPtr  setObservaciones;
		// getter de objeto relacionado
		getLocalidadObjPtr  getLocalidadObj;
	    obj_Localidad *localidad;
	}obj_Cliente;
	// funcionalidad publica que se implementa en Cliente.c
	extern obj_Cliente *Cliente_new ();
	// meta data para acceder a las Clientes - definicion de las columnas de la tabla
	static Column cols_Cliente[CNT_COL_CLI]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
	{"dni",t_int,sizeof(int),true,false},	
	{"nombres",t_varchar,(sizeof(char)*MAX80)+1,false,false},
	{"apellido",t_varchar,(sizeof(char)*MAX90)+1,false,false},	
	{"domicilio",t_varchar,(sizeof(char)*MAX120)+1,false,false},
	{"telefono",t_varchar,(sizeof(char)*MAX20)+1,false,false},
	{"cod_postal",t_int,sizeof(int),false,false},
	{"observaciones",t_varchar,(sizeof(char)*MAXOBS)+1,false,false},
	};
	// plantilla para la Cliente.
	static Table table_Cliente={"cliente",CNT_COL_CLI,0, cols_Cliente,NULL};
	typedef obj_Cliente *(*getClienteObjPtr)(void *self);
#endif
