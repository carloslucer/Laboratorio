#ifndef MED_INCLUDED
	#define MED_INCLUDED
	#define CNT_COL_MED 5
	#define POS_DESCRIPCION_M 1
	#define POS_COD_ESPECIE_M 2
	#define POS_IMPORTE_M 3
	#define POS_CANTIDAD_M 4
	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
	    getPropertyIntPtr 	getId;
		getPropertyCharPtr 	getDescripcion;
		getPropertyIntPtr 	getCodEspecie;
		getPropertyFloatPtr getImporte;
		getPropertyIntPtr 	getCantidad;
	    //-- setters
	    setPropertyIntPtr 	setId;
		setPropertyCharPtr 	setDescripcion;  
		setPropertyIntPtr 	setCodEspecie;
		setPropertyFloatPtr setImporte;
		setPropertyIntPtr 	setCantidad;
		// getter de objeto relacionado
		getEspecieObjPtr  	getEspecieObj;	    
	    obj_Especie 		*especie;	    
	}obj_Medicamento;
	// funcionalidad publica que se implementa en Medicamento.c
	extern obj_Medicamento *Medicamento_new ();
	// meta data para acceder a las Medicamentos - definicion de las columnas de la tabla
	static Column cols_Medicamento[CNT_COL_MED]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
	{"codigo",t_int,sizeof(int),true,false}, 
	{"descripcion",t_varchar,(sizeof(char)*MAX100)+1,false,false},
	{"cod_especie",t_int,sizeof(int),false,false},
	{"importe",t_float,sizeof(float),false,false},
	{"cantidad",t_int,sizeof(int),false,false},
	};
	// plantilla para la Medicamento.
	static Table table_Medicamento={"localidad",CNT_COL_MED,0, cols_Medicamento,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Medicamento
	typedef obj_Medicamento *(*getMedicamentoObjPtr)(void *self);
#endif
