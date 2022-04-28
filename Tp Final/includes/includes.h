#include <string.h>
#include <errno.h>
#include "../config/config.h"
#include "../lib/orm/orm.h"
#include "../lib/utils/utils.h"
/* incluir los archivos que representen las entidades */

#include "../src/localidad/localidad.h"
#include "../src/especie/especie.h"
#include "../src/cliente/cliente.h"
#include "../src/profesional/profesional.h"
#include "../src/mascota/mascota.h"
#include "../src/diagnostico/diagnostico.h"
#include "../src/consulta/consulta.h"
#include "../src/medicamento/medicamento.h"
#include "../src/tratamiento/tratamiento.h"
#include "../src/mascota_medicamento/mascota_medicamento.h"
#include "../src/mascota_tratamiento/mascota_tratamiento.h"
