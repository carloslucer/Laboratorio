#ifndef DIAG_INCLUDED
	#define DIAG_INCLUDED
	#define CNT_COL_DIAG 2
	#define POS_NOM_D 1
	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
	    getPropertyIntPtr getId;
		getPropertyCharPtr getNombre;	    
	    //-- setters
	    setPropertyIntPtr setId;
		setPropertyCharPtr setNombre;  
	}obj_Diagnostico;
	// funcionalidad publica que se implementa en Diagnostico.c
	extern obj_Diagnostico *Diagnostico_new ();
	// meta data para acceder a las Diagnosticos - definicion de las columnas de la tabla
	static Column cols_Diagnostico[CNT_COL_DIAG]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
	{"codigo",t_int,sizeof(int),true,false}, 
	{"nombre",t_varchar,(sizeof(char)*MAX60)+1,false,false}
	};
	// plantilla para la Diagnostico.
	static Table table_Diagnostico={"diagnostico",CNT_COL_DIAG,0, cols_Diagnostico,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Diagnostico
	typedef obj_Diagnostico *(*getDiagnosticoObjPtr)(void *self);
#endif
