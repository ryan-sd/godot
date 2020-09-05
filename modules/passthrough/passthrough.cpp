#include "passthrough.h"

void Passthrough::set_passthrough(bool p_enabled) {
	if (p_enabled) {
		passthrough_enabled = true;
		LONG cur_style = GetWindowLong(hWnd, GWL_EXSTYLE);
		SetWindowLong(hWnd, GWL_EXSTYLE, cur_style | WS_EX_TRANSPARENT | WS_EX_LAYERED);
	} else {
		passthrough_enabled = false;
		LONG cur_style = GetWindowLong(hWnd, GWL_EXSTYLE);
		cur_style &= ~WS_EX_TRANSPARENT;
		cur_style &= ~WS_EX_LAYERED;
		SetWindowLong(hWnd, GWL_EXSTYLE, cur_style);
	}
}

bool Passthrough::get_enabled() {
	return passthrough_enabled;
}

void Passthrough::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_passthrough", "enabled"), &Passthrough::set_passthrough);
	ClassDB::bind_method(D_METHOD("get_enabled"), &Passthrough::get_enabled);
}

Passthrough::Passthrough() {
	passthrough_enabled = false;
	hWnd = GetActiveWindow();
}
