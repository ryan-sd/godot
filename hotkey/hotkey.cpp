#include "hotkey.h"

void Hotkey::register_hotkey(int hotkey_id, int modifier, int virtual_key) {
	RegisterHotKey(hWnd, hotkey_id, modifier, virtual_key);
}

void Hotkey::unregister_hotkey(int hotkey_id) {
	UnregisterHotKey(hWnd, hotkey_id);
}

void Hotkey::_bind_methods() {
	ClassDB::bind_method(D_METHOD("register_hotkey", "hotkey_id", "modifier", "virtual_key"), &Hotkey::register_hotkey);
	ClassDB::bind_method(D_METHOD("unregister_hotkey", "hotkey_id"), &Hotkey::unregister_hotkey);
	ClassDB::bind_method(D_METHOD("test_hotkey"), &Hotkey::test_hotkey);
	BIND_CONSTANT(MOD_ALT);
	BIND_CONSTANT(MOD_CONTROL);
	BIND_CONSTANT(MOD_SHIFT);
	BIND_CONSTANT(MOD_WIN);
	
}

int Hotkey::test_hotkey() {
	MSG msg = { 0 };
	if (GetMessage(&msg, hWnd, 0, 0) != 0) {
		if (msg.message == WM_HOTKEY) {
			return msg.wParam;
		}
	}
	return 0;
}

Hotkey::Hotkey() {
	hWnd = GetActiveWindow();
}
