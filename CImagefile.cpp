#include "pch.h"
#include "CImagefile.h"
#include "CApplication.h"
#pragma comment(lib, "Msimg32.lib")

static std::vector <CImagefile*> g_ImgFileArray;

CImagefile* CImagefile::New(const WCHAR* filename, const WCHAR* name)
{

	std::wstring n = name;
	for (auto it : g_ImgFileArray)
	{
		if (it->mName == n)
		{
			it->AddRef();
			return it;
		}
	}
	CImagefile* it = new CImagefile(filename, name);
	it->AddRef();

	bool success = false;
	for (int i=0;i <g_ImgFileArray.size();i++)
	{
		if (g_ImgFileArray[i] == nullptr)
		{
			g_ImgFileArray[i] = it;
			success = true;
			break;
		}
	}
	if(!success)
		g_ImgFileArray.push_back(it);
	
	return it;
}

void CImagefile::Delete(CImagefile* delitem)
{
	delitem->Release();
	if (delitem->mRefCount <= 0)
	{
		for (int i = 0; i < g_ImgFileArray.size(); i++)
		{
			if (g_ImgFileArray[i] == delitem)
				g_ImgFileArray[i] = nullptr;
		}
		delete delitem;
	}
}

void CImagefile::DestoryAll()
{
	for (auto it : g_ImgFileArray)
		if(it)	delete it;
}


CImagefile::CImagefile(const WCHAR* filename,const WCHAR* name)
{
	mRefCount = 0;
	mName = name;
	mhBitmap = LoadBitmapW(CApplication::theApp->mhInst, filename);
	GetObject(mhBitmap, sizeof(BITMAP), &mBmpInfo);

	//GetObject (관심있는 그래픽개체에 대한 핸들, 
	//			버퍼에 쓸 바이트 수, 
	//			지정된 그래픽개체에 대한 정보를 수신하는 버퍼에 대한 포인터)
}

CImagefile::~CImagefile()
{
	DeleteObject(mhBitmap);
}



void CImagefile::Draw(HDC hdc, int dest_x, int dest_y, int src_x, int src_y, int width, int height)
{
	HDC hBmpDC = CreateCompatibleDC(hdc);
	HBITMAP old = (HBITMAP)SelectObject(hBmpDC, mhBitmap);


	BitBlt(hdc, dest_x, dest_y, width, height,
		hBmpDC, src_x, src_y, SRCCOPY);


	//지우기전에 되돌리기
	SelectObject(hBmpDC, old);
	DeleteDC(hBmpDC);
}

void CImagefile::transDraw(HDC hdc, int dest_x, int dest_y, int src_x, int src_y, int width, int height, UINT color)
{
	HDC hBmpDC = CreateCompatibleDC(hdc);
	HBITMAP old = (HBITMAP)SelectObject(hBmpDC, mhBitmap);


	TransparentBlt(hdc, dest_x, dest_y, width, height,
		hBmpDC, 
		src_x, src_y,width, height,
		color);


	//지우기전에 되돌리기
	SelectObject(hBmpDC, old);
	DeleteDC(hBmpDC);
}


void CImagefile::FadeInOut(HDC hdcWnd, int dest_x, int dest_y, int src_x, int src_y, int width, int height, BYTE alpha)
{
	BLENDFUNCTION bf;

	BITMAPINFO bmi;        // bitmap header
	ZeroMemory(&bmi, sizeof(BITMAPINFO));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = width;
	bmi.bmiHeader.biHeight = height;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;         // four 8-bit components 
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = width * height * 4;

	VOID* pvBits;          // pointer to DIB section 
	HDC hdc = CreateCompatibleDC(hdcWnd);
	HBITMAP hbitmapDIB = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, &pvBits, NULL, 0x0);
	SelectObject(hdc, hbitmapDIB);

	UINT32 rgba = alpha;
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			((UINT32*)pvBits)[y * width + x] = 0xFF000000;


	{
		HDC hBmpDC = CreateCompatibleDC(hdcWnd);
		HBITMAP old = (HBITMAP)SelectObject(hBmpDC, mhBitmap);

		bf.BlendOp = AC_SRC_OVER;
		bf.BlendFlags = 0;
		bf.SourceConstantAlpha = alpha;
		bf.AlphaFormat = 0;
		AlphaBlend(hdc, 0, 0, width, height,
			hBmpDC, src_x, src_y, width, height,
			bf);


		SelectObject(hBmpDC, old);
		DeleteDC(hBmpDC);
	}


	//bf.SourceConstantAlpha = 0xff;
	//bf.AlphaFormat = AC_SRC_ALPHA;

	//AlphaBlend(hdcWnd,
	//	dest_x, dest_y, width, height,
	//	hdc, 
	//	0, 0, width, height,
	//	bf);
	BitBlt(hdcWnd, dest_x, dest_y, width, height,
		hdc, 0, 0, SRCCOPY);
	DeleteObject(hbitmapDIB);
	DeleteDC(hdc);
}

void CImagefile::OverLay(HDC hdcWnd, int dest_x, int dest_y, int src_x, int src_y, int width, int height, BYTE alpha, UINT color)
{
	BLENDFUNCTION bf;


	BITMAPINFO bmi;        // bitmap header
	ZeroMemory(&bmi, sizeof(BITMAPINFO));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = width;
	bmi.bmiHeader.biHeight = height;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;         // four 8-bit components 
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = width * height * 4;

	VOID* pvBits;          // pointer to DIB section 
	HDC hdc = CreateCompatibleDC(hdcWnd);
	HBITMAP hbitmapDIB = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, &pvBits, NULL, 0x0);
	SelectObject(hdc, hbitmapDIB);

	UINT32 rgba = alpha;
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			((UINT32*)pvBits)[y * width + x] = 0xFF000000;


	{
		HDC hBmpDC = CreateCompatibleDC(hdcWnd);
		HBITMAP old = (HBITMAP)SelectObject(hBmpDC, mhBitmap);

		bf.BlendOp = AC_SRC_OVER;
		bf.BlendFlags = 0;
		bf.SourceConstantAlpha = alpha;
		bf.AlphaFormat = 0;
		AlphaBlend(hdc, 0, 0, width, height,
			hBmpDC, src_x, src_y, width, height,
			bf);


		SelectObject(hBmpDC, old);
		DeleteDC(hBmpDC);
	}


	//bf.SourceConstantAlpha = 0xff;
	//bf.AlphaFormat = AC_SRC_ALPHA;

	//AlphaBlend(hdcWnd,
	//	dest_x, dest_y, width, height,
	//	hdc, 
	//	0, 0, width, height,
	//	bf);
	BitBlt(hdcWnd, dest_x, dest_y, width, height,
		hdc, 0, 0, SRCCOPY);
	DeleteObject(hbitmapDIB);
	DeleteDC(hdc);
}


void CImagefile::AlphaDraw(HDC hdcWnd, int dest_x, int dest_y, int src_x, int src_y, int width, int height, BYTE alpha)
{
	HDC hBmpDC = CreateCompatibleDC(hdcWnd);
	HBITMAP old = (HBITMAP)SelectObject(hBmpDC, mhBitmap);

	BLENDFUNCTION bf;
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.SourceConstantAlpha = alpha;
	bf.AlphaFormat = 0;
	AlphaBlend(hdcWnd, dest_x, dest_y, width, height,
		hBmpDC, src_x, src_y, width, height,
		bf);

	SelectObject(hBmpDC, old);
	DeleteDC(hBmpDC);
}



