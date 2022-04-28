#ifndef TRAT_INCLUDED
	#define TRAT_INCLUDED
	#define CNT_COL_TRAT 3
	#define POS_DESCRIPCION_M 1
	#define POS_COD_ESPECIE_M 2	
	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
	    getPropertyIntPtr 	getId;
		getPropertyCharPtr 	getDescripcion;
		getPropertyIntPtr 	getCodEspecie;		
	    //-- setters
	    setPropertyIntPtr 	setId;
		setPropertyCharPtr 	setDescripcion;  
		setPropertyIntPtr 	setCodEspecie;		
		// getter de objeto relacionado
		getEspecieObjPtr  	getEspecieObj;	    
	    obj_Especie 		*especie;	    
	}obj_Tratamiento;
	// funcionalidad publica que se implementa en Tratamiento.c
	extern obj_Tratamiento *Tratamiento_new ();
	// meta data para acceder a las Tratamientos - definicion de las columnas de la tabla
	static Column cols_Tratamiento[CNT_COL_TRAT]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
	{"codigo",t_int,sizeof(int),true,false}, 
	{"descripcion",t_varchar,(sizeof(char)*MAX100)+1,false,false},
	{"cod_especie",t_int,sizeof(int),false,false},
	};
	// plantilla para la Tratamiento.
	static Table table_Tratamiento={"tratamiento",CNT_COL_TRAT,0, cols_Tratamiento,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Tratamiento
	typedef obj_Tratamiento *(*getTratamientoObjPtr)(void *self);
#endif
