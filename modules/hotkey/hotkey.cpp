#include "hotkey.h"

void Hotkey::register_hotkey(int hotkey_id, int modifier, int virtual_key, String input_name) {
	RegisterHotKey(hWnd, hotkey_id, modifier, virtual_key);
	input_map_entry entry;
	entry.input_name = input_name;
	entry.hotkey_id = hotkey_id;
	input_map.push_back(entry);
}

void Hotkey::unregister_hotkey(int hotkey_id) {
	UnregisterHotKey(hWnd, hotkey_id);
}

void Hotkey::test_hotkey() {
	print_line("hotkey testing initiated");
	hWnd = GetActiveWindow();
	MSG msg = { 0 };

	int length = input_map.size();

	while (GetMessage(&msg, hWnd, 0, 0) != 0) {
		String last_input = "";
		if (msg.message == WM_HOTKEY) {
			for (int x = 0; x < length; x++) {
				input_map_entry entry = input_map.get(x);
				int id = entry.hotkey_id;
				if (id == msg.wParam) {
					Input::get_singleton()->action_press(entry.input_name, 1.0f);
					Sleep(5);
					last_input = entry.input_name;
				}
			}
		}
	}
}

void Hotkey::_bind_methods() {
	ClassDB::bind_method(D_METHOD("register_hotkey", "hotkey_id", "modifier", "virtual_key", "input_name"), &Hotkey::register_hotkey);
	ClassDB::bind_method(D_METHOD("unregister_hotkey", "hotkey_id"), &Hotkey::unregister_hotkey);
	ClassDB::bind_method(D_METHOD("test_hotkey"), &Hotkey::test_hotkey);
	//ClassDB::bind_method(D_METHOD("initialize_hotkey_thread", "input"), &Hotkey::initialize_hotkey_thread);
	BIND_CONSTANT(MOD_ALT);
	BIND_CONSTANT(MOD_CONTROL);
	BIND_CONSTANT(MOD_SHIFT);
	BIND_CONSTANT(MOD_WIN);
}



Hotkey::Hotkey() {
}
