#include "image_clipboard.h"


HBITMAP ImageClipboard::clipboard_to_bmp(HWND hWnd) {
	if (!OpenClipboard(hWnd)) {
		return NULL;
	}
	HBITMAP hBitMap = (HBITMAP)GetClipboardData(CF_BITMAP);
	CloseClipboard();
	return hBitMap;
}

Ref<Image> ImageClipboard::get_image() {
	CImage cimage;
	Ref<Image> image;
	PoolVector<uint8_t> pvector;
	image.instance();
	
	HWND hWnd = GetActiveWindow();
	HBITMAP hBitMap = clipboard_to_bmp(hWnd);
	if (hBitMap == NULL) {
		return NULL;
	}
	cimage.Attach(hBitMap);
	cimage.Save("clipboard_tmp.bmp", Gdiplus::ImageFormatBMP);

	image.ptr()->load("clipboard_tmp.bmp");

	remove("clipboard_tmp.bmp");

	return image;
}

ImageClipboard::ImageClipboard() {
	//nothing is required at this stage
}

void ImageClipboard::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_image"), &ImageClipboard::get_image);
}
