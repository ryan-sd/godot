#ifndef PASSTHROUGH_H
#define PASSTHROUGH_H

#include "core/reference.h"
#include <Windows.h>


class Passthrough : public Reference {
	GDCLASS(Passthrough, Reference);

protected:
	static void _bind_methods();

public:
	void set_passthrough(bool p_enabled);
	bool get_enabled();

	bool passthrough_enabled;
	HWND hWnd;

	Passthrough();
};

#endif // PASSTHROUGH_H
