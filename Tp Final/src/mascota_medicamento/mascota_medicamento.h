#ifndef MASC_MED_INCLUDED
	#define MASC_MED_INCLUDED
	#define CNT_COL_MAS_MED 4
	#define POS_COD_TRAT_MM 1
	#define POS_COD_MED_MM 2
	#define POS_CANTIDAD_MM 3
	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
	    getPropertyIntPtr getId;
		getPropertyIntPtr getCodTratamiento;
		getPropertyIntPtr getCodMedicamento;
		getPropertyIntPtr getCantidad;
	    //-- setters
	    setPropertyIntPtr setId;
		setPropertyIntPtr setCodTratamiento;
		setPropertyIntPtr setCodMedicamento;
		setPropertyIntPtr setCantidad;
		obj_Tratamiento *tratamiento;
		obj_Medicamento *medicamento;
		getTratamientoObjPtr  getTratamientoObj;
		getMedicamentoObjPtr  getMedicamentoObj;
	}obj_MascotaMedicamento;
	// funcionalidad publica que se implementa en MascotaMedicamento.c
	extern obj_MascotaMedicamento *MascotaMedicamento_new ();
	// meta data para acceder a las MascotaMedicamentos - definicion de las columnas de la tabla
	static Column cols_MascotaMedicamento[CNT_COL_MAS_MED]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
	{"codigo",t_int,sizeof(int),true,false}, 
	{"cod_tratamiento",t_int,sizeof(int),false,false},
	{"cod_medicamento",t_int,sizeof(int),false,false},
	{"cantidad",t_int,sizeof(int),false,false},
	};
	// plantilla para la MascotaMedicamento.
	static Table table_MascotaMedicamento={"masco_medicamento",CNT_COL_MAS_MED,0, cols_MascotaMedicamento,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto MascotaMedicamento
	typedef obj_MascotaMedicamento *(*getMascotaMedicamentoObjPtr)(void *self);
#endif
