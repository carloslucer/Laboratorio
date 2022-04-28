#ifndef CONS_INCLUDED
	#define CONS_INCLUDED
	#define CNT_COL_CONS 8
	#define POS_FECHA_C 1
	#define POS_HORA_C 2
	#define POS_DOC_PROF_C 3
	#define POS_COD_MASCOTA_C 4
	#define POS_ASISTIO_C 5	
	#define POS_COD_DIAG_C 6
	#define POS_OBS_C 7
	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
	    getPropertyIntPtr       getId;
	    getPropertyCharPtr      getFecha;  //formato: yyyy-mm-dd
	    getPropertyCharPtr      getHora;  //formato:  HH:mm:ss
	    getPropertyIntPtr       getDocProfesional;
	    getPropertyIntPtr       getCodMascota;
	    getPropertyIntPtr       getAsistio;
	    getPropertyIntPtr       getCodDiagnostico;	    
	    getPropertyCharPtr      getObservaciones;
	    //-- setters
	    setPropertyIntPtr       setId;
	    setPropertyCharPtr      setFecha;
	    setPropertyCharPtr      setHora;
	    setPropertyIntPtr       setDocProfesional;
		setPropertyIntPtr       setCodMascota;
		setPropertyIntPtr       setAsistio;
		setPropertyIntPtr       setCodDiagnostico;
		setPropertyCharPtr      setObservaciones;
		obj_Profesional 		*profesional;
		obj_Mascota 			*mascota;
		obj_Diagnostico 		*diagnostico;
		
		getProfesionalObjPtr  	getProfesionalObj;	    
		getMascotaObjPtr  		getMascotaObj;	    
		getDiagnosticoObjPtr  	getDiagnosticoObj;	    
		
	}obj_Consulta;
	// funcionalidad publica que se implementa en Consulta.c
	extern obj_Consulta *Consulta_new ();
	// meta data para acceder a las Consultas - definicion de las columnas de la tabla
	static Column cols_Consulta[CNT_COL_CONS]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
	{"codigo",t_int,sizeof(int),true,true}, 
	{"fecha",t_varchar,(sizeof(char)*MAX10)+1,false,false},
	{"hora",t_varchar,(sizeof(char)*MAX10)+1,false,false},
	{"dni_prof",t_int,sizeof(int),false,false},
	{"cod_mascota",t_int,sizeof(int),false,false},
	{"asistio",t_bool,sizeof(int),false,false},    	
	{"cod_diag",t_int,sizeof(int),false,false},	
	{"observaciones",t_varchar,(sizeof(char)*MAX150)+1,false,false},	
	};
	// plantilla para la Consulta.
	static Table table_Consulta={"consulta",CNT_COL_CONS,0, cols_Consulta,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Consulta
	typedef obj_Consulta *(*getConsultaObjPtr)(void *self);
#endif
