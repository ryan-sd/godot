#ifndef IMAGE_CLIPBOARD_H
#define IMAGE_CLIPBOARD_H

#include "modules/bmp/image_loader_bmp.h"

//  global compilation flag configuring windows sdk headers
//  preventing inclusion of min and max macros clashing with <limits>
#define NOMINMAX 1

//  override byte to prevent clashes with <cstddef>
#define byte win_byte_override

#include <Windows.h> // gdi plus requires Windows.h
// ...includes for other windows header that may use byte...

//  Define min max macros required by GDI+ headers.
#ifndef max
#define max(a, b) (((a) > (b)) ? (a) : (b))
#else
#error max macro is already defined
#endif
#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#else
#error min macro is already defined
#endif

#include <gdiplus.h>
#include <atlimage.h>

#include "core/reference.h"
#include <gdiplusimaging.h>
#include "core/image.h"
#include <stdio.h>



class ImageClipboard : public Reference {
	GDCLASS(ImageClipboard, Reference);

protected:
	static void _bind_methods();

public:
	HBITMAP clipboard_to_bmp(HWND hWnd);
	Ref<Image> get_image();

	ImageClipboard();
};

#endif // IMAGE_CLIPBOARD_H
