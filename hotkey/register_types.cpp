#include "register_types.h"

#include "core/class_db.h"
#include "hotkey.h"

void register_hotkey_types() {
	ClassDB::register_class<Hotkey>();
}

void unregister_hotkey_types() {
	//nothing necessary
}
