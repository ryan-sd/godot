#ifndef HOTKEY_H
#define HOTKEY_H

#include "core/reference.h"
#include <Windows.h>

class Hotkey : public Reference {
	GDCLASS(Hotkey, Reference);

protected:
	static void _bind_methods();

public:
	void register_hotkey(int hotkey_id, int modifier, int virtual_key);
	void unregister_hotkey(int hotkey_id);
	int test_hotkey();

	HWND hWnd;

	Hotkey();
};

#endif // HOTKEY_H


