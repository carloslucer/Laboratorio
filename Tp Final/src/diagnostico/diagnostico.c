#include "../../includes/includelib.h"
#include "diagnostico.h"
#define MAXNOMBRE 60

THIS(obj_Diagnostico)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_DiagnosticoImpl(void *self)
{
     obj_Diagnostico *obj=this(self);
     printf("Cod Diagnostico: %d  Nom.Diagnostico:%s \n",
	 obj->getId(obj),
	 obj->getNombre(obj)
	 );
}
//----------------------------------------------------
//implementacion de getters
//----------------------------------------------------
static int getIdDiagnostico_Impl(void *self)
{
  return *( (int *) getValue(self,POS_ID));
}
//----------------------------------------------------
static char *getNombreDiagnostico_Impl(void *self)
{
  return  (char *) getValue(self,POS_NOM_D);
}
//----------------------------------------------------
//implementacion setters
//----------------------------------------------------
static void setIdDiagnostico_Impl(void *self,int val)
{ 
	setValue(self,POS_ID,&val);
}
//----------------------------------------------------
static void setNombreDiagnostico_Impl(void *self,char *descripcion_Diagnostico)
{ 
	setValue(self,POS_NOM_D,descripcion_Diagnostico);
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
/// ....
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Diagnostico(void *self)
{
  obj_Diagnostico *obj 	  = this(self);
  obj->ds  				  = &table_Diagnostico;
  obj->constructor 		  = Diagnostico_new;
  obj->sizeObj 			  = sizeof(obj_Diagnostico*);
  //incializacion de la interfaz de la entidad  
  obj->toString    		  = toString_DiagnosticoImpl;
  // Inicializar handlers de getters y setters
  /// getters
  obj->getId  	  		  = getIdDiagnostico_Impl;
  obj->getNombre		  = getNombreDiagnostico_Impl;  
  /// setters  
  obj->setId     		  = setIdDiagnostico_Impl;
  obj->setNombre   		  = setNombreDiagnostico_Impl;  
  return obj;
}
//----------------------------------------------------
//constructor de Diagnostico
obj_Diagnostico *Diagnostico_new()
{
  return (obj_Diagnostico *)init_obj(sizeof(obj_Diagnostico), init_Diagnostico);
}
//--------------Alta --------------------------------------

void altaDiagnostico(){
	char nombre[MAXNOMBRE];
	int idDiagnostico;
	
	obj_Diagnostico *diagnostico;
  	diagnostico = Diagnostico_new();
	
	 printf("ingrese el codigo del diagnostico:  \n");
     scanf("%d", &idDiagnostico);
  fflush(stdin);
	  if(diagnostico->findbykey(diagnostico,idDiagnostico) == NOT_FOUND){
	    diagnostico->setId(diagnostico,idDiagnostico);

	
	 printf("ALTA DIAGNOSTICO \n");
	  printf("Ingrese nombre del diagnostico: \n");
	   fgets(nombre,MAXNOMBRE-1,stdin);
	    diagnostico->setNombre(diagnostico,nombre);
	    
	     if(diagnostico->saveObj(diagnostico)){ 
	    printf("diagnostico guardado correctamente \n");
	      }
	    else{
	     printf("error al guardar el diagnostico \n");
	    }
	}else
	    printf("diagnostico ya existe \n");
	  	
   }

//----------------------Listar----------------------------
void listaDiagnostico(){
  int size,i;
  void *list,*itm;
  obj_Diagnostico *diagnostico;
  diagnostico = Diagnostico_new();
  
  size = diagnostico->findAll(diagnostico,&list,NULL);
  
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    ((Object *)itm)->toString(itm);
    printf("\n");
    fflush(stdin);

  }
  
  destroyObjList(list,size);
  destroyObj(diagnostico);
}


