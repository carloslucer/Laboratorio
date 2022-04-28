#ifndef ESP_INCLUDED
	#define ESP_INCLUDED
	#define CNT_COL_ESP 2
	#define POS_NOM_E 1
	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
	    getPropertyIntPtr getId;
		getPropertyCharPtr getNombre;	    
	    //-- setters
	    setPropertyIntPtr setId;
		setPropertyCharPtr setNombre;  
	}obj_Especie;
	// funcionalidad publica que se implementa en Especie.c
	extern obj_Especie *Especie_new ();
	// meta data para acceder a las Especies - definicion de las columnas de la tabla
	static Column cols_Especie[CNT_COL_ESP]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
	{"codigo",t_int,sizeof(int),true,false}, 
	{"nombre",t_varchar,(sizeof(char)*MAX40)+1,false,false}
	};
	// plantilla para la Especie.
	static Table table_Especie={"especie",CNT_COL_ESP,0, cols_Especie,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Especie
	typedef obj_Especie *(*getEspecieObjPtr)(void *self);
#endif
