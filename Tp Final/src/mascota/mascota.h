#ifndef MASC_INCLUDED
	#define MASC_INCLUDED
	#define CNT_COL_MASC 7
	#define POS_NOMBRE_MASC 1
	#define POS_F_NAC_MASC 2
	#define POS_DNI_CLI_MASC 3
	#define POS_COD_ESP_MASC 4
	#define POS_VACUNADO_MASC 5
	#define POS_OBS_MASC 6
	//----------------------------------------------------
	typedef struct {	    
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters	    
		getPropertyIntPtr   getCodigo;
		getPropertyCharPtr  getNombre;
		getPropertyCharPtr  getFechaNac;		
		getPropertyIntPtr   getDniCliente;
		getPropertyIntPtr   getCodEspecie;
		getPropertyIntPtr   getVacunado;		
		getPropertyCharPtr  getObservaciones;
	    //-- setters
		setPropertyIntPtr   setCodigo;
		setPropertyCharPtr  setNombre;
		setPropertyCharPtr  setFechaNac;
		setPropertyIntPtr   setDniCliente;
		setPropertyIntPtr   setCodEspecie;
		setPropertyIntPtr   setVacunado;		
		setPropertyCharPtr  setObservaciones;
		// getter de objeto relacionado
		getEspecieObjPtr  	getEspecieObj;	    
	    obj_Especie 		*especie;
	    getClienteObjPtr  	getClienteObj;	    
	    obj_Cliente 		*cliente;
	    
	}obj_Mascota;
	// funcionalidad publica que se implementa en Mascota.c
	extern obj_Mascota *Mascota_new ();
	// meta data para acceder a las Mascotas - definicion de las columnas de la tabla
	static Column cols_Mascota[CNT_COL_MASC]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
	{"codigo",t_int,sizeof(int),true,false},	
	{"nombre",t_varchar,(sizeof(char)*MAX80)+1,false,false},	
	{"fecha_nac",t_varchar,(sizeof(char)*MAX10)+1,false,false},
	{"dni_cliente",t_int,sizeof(int),false,false},
	{"cod_especie",t_int,sizeof(int),false,false},
	{"vacunado",t_bool,sizeof(int),false,false},
	{"observaciones",t_varchar,(sizeof(char)*MAXOBS)+1,false,false},
	};
	// plantilla para la Mascota.
	static Table table_Mascota={"mascota",CNT_COL_MASC,0, cols_Mascota,NULL};
	typedef obj_Mascota *(*getMascotaObjPtr)(void *self);
#endif
