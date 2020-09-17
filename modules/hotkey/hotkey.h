#ifndef HOTKEY_H
#define HOTKEY_H

#include "core/reference.h"
#include <Windows.h>
#include "core/os/input_event.h"
#include "main/input_default.h"
#include "core/bind/core_bind.h"
#include "core/variant.h"

class Hotkey : public Reference {
	GDCLASS(Hotkey, Reference);

protected:
	static void _bind_methods();


public:
	void register_hotkey(int hotkey_id, int modifier, int virtual_key, String input_name);
	void unregister_hotkey(int hotkey_id);
	void test_hotkey();
	//void initialize_hotkey_thread(InputDefault input);

	HWND hWnd;
	InputEventAction input_action;
	_Thread thread;

	struct input_map_entry {
		String input_name;
		int hotkey_id;
	};

	Vector<input_map_entry> input_map;

	Hotkey();
};

#endif // HOTKEY_H


