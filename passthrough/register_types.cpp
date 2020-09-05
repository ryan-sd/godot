#include "register_types.h"

#include "core/class_db.h"
#include "passthrough.h"

void register_passthrough_types() {
	ClassDB::register_class<Passthrough>();
}

void unregister_passthrough_types() {
	//nothing necessary
}
