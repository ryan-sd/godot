#include "register_types.h"

#include "core/class_db.h"
#include "image_clipboard.h"

void register_image_clipboard_types() {
	ClassDB::register_class<ImageClipboard>();
}

void unregister_image_clipboard_types() {
	//nothing necessary
}
