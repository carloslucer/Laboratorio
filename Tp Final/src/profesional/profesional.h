#ifndef PROF_INCLUDED
	#define PROF_INCLUDED
	#define CNT_COL_PROF 8
	#define POS_MAT_PROF 1
	#define POS_NOMBRES_PROF 2
	#define POS_APELLIDO_PROF 3
	#define POS_DOMICILIO_PROF 4
	#define POS_TELEFONO_PROF 5
	#define POS_COD_POSTAL_PROF 6
	#define POS_OBS_PROF 7
	//----------------------------------------------------
	typedef struct {	    
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters	    
		getPropertyIntPtr   getDni;
		getPropertyCharPtr  getMatricula;
		getPropertyCharPtr  getNombres;
		getPropertyCharPtr  getApellido;
		getPropertyCharPtr  getDomicilio;
		getPropertyCharPtr  getTelefono;
		getPropertyIntPtr   getCodPostal;		
		getPropertyCharPtr  getObservaciones;
	    //-- setters
		setPropertyIntPtr   setDni;
		setPropertyCharPtr  setMatricula;
		setPropertyCharPtr  setNombres;
		setPropertyCharPtr  setApellido;
		setPropertyCharPtr  setDomicilio;
		setPropertyCharPtr  setTelefono;
		setPropertyIntPtr   setCodPostal;		
		setPropertyCharPtr  setObservaciones;
		// getter de objeto relacionado
		getLocalidadObjPtr  getLocalidadObj;
	    obj_Localidad *localidad;
	}obj_Profesional;
	// funcionalidad publica que se implementa en Profesional.c
	extern obj_Profesional *Profesional_new ();
	// meta data para acceder a las Profesionals - definicion de las columnas de la tabla
	static Column cols_Profesional[CNT_COL_PROF]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
	{"dni",t_int,sizeof(int),true,false},	
	{"matricula",t_varchar,(sizeof(char)*MAX10)+1,false,false},
	{"nombres",t_varchar,(sizeof(char)*MAX80)+1,false,false},
	{"apellido",t_varchar,(sizeof(char)*MAX90)+1,false,false},	
	{"domicilio",t_varchar,(sizeof(char)*MAX120)+1,false,false},
	{"telefono",t_varchar,(sizeof(char)*MAX20)+1,false,false},
	{"cod_postal",t_int,sizeof(int),false,false},
	{"observaciones",t_varchar,(sizeof(char)*MAXOBS)+1,false,false},
	};
	// plantilla para la Profesional.
	static Table table_Profesional={"profesional",CNT_COL_PROF,0, cols_Profesional,NULL};
	typedef obj_Profesional *(*getProfesionalObjPtr)(void *self);
#endif
