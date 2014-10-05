#include "../util/logger.h"
#include "../util/defines.h"
#include <unistd.h>
#include "../util/lock_file.h"
#include "../util/memoria_compartida2.h"

int main( int argc __attribute__ ((unused)), char* argv[] __attribute__ ((unused))){
	Logger::compileInfo("ADMINISTRADOR");

	LockFile lock(MONEY_BOX);

	MemoriaCompartida2<int> box(MONEY_BOX, MONEY_BOX_CHAR);
	lock.tomarLock();
	int recaudacion = box.leer();
	lock.liberarLock();

	Logger::log("ADMINISTRADOR: recaudacion %d", recaudacion);

	Logger::log("ADMINISTRADOR: END");
	return 0;
}
