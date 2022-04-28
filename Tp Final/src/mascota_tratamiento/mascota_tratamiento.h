#ifndef MASC_TRAT_INCLUDED
	#define MASC_TRAT_INCLUDED
	#define CNT_COL_MAS_TRAT 5
	#define POS_COD_COSULTA_MT 1
	#define POS_COD_TRAT_MT 2
	#define POS_FECHA_D_MT 3
	#define POS_FECHA_H_MT 4
	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
	    getPropertyIntPtr  getId;
		getPropertyIntPtr  getCodConsulta;
		getPropertyIntPtr  getCodTratamiento;
		getPropertyCharPtr getFechaDesde;
		getPropertyCharPtr getFechaHasta;
	    //-- setters
	    setPropertyIntPtr setId;
		setPropertyIntPtr setCodConsulta;
		setPropertyIntPtr setCodTratamiento;
		setPropertyCharPtr setFechaDesde;
		setPropertyCharPtr setFechaHasta;
		obj_Consulta *consulta;
		obj_Tratamiento *tratamiento;
		
		getConsultaObjPtr  	getConsultaObj;	    
		getTratamientoObjPtr  	getTratamientoObj;
	}obj_MascotaTratamiento;
	// funcionalidad publica que se implementa en MascotaTratamiento.c
	extern obj_MascotaTratamiento *MascotaTratamiento_new ();
	// meta data para acceder a las MascotaTratamientos - definicion de las columnas de la tabla
	static Column cols_MascotaTratamiento[CNT_COL_MAS_TRAT]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
	{"codigo",t_int,sizeof(int),true,false}, 
	{"cod_consulta",t_int,sizeof(int),false,false},
	{"cod_tratamiento",t_int,sizeof(int),false,false},
	{"fecha_desde",t_varchar,(sizeof(char)*MAX10)+1,false,false},
	{"fecha_hasta",t_varchar,(sizeof(char)*MAX10)+1,false,false},
	};
	// plantilla para la MascotaTratamiento.
	static Table table_MascotaTratamiento={"mascota_tratamiento",CNT_COL_MAS_TRAT,0, cols_MascotaTratamiento,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto MascotaTratamiento
	typedef obj_MascotaTratamiento *(*getMascotaTratamientoObjPtr)(void *self);
#endif
