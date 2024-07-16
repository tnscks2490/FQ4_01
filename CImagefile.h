#pragma once
class CImagefile
{
private:
	int mRefCount;
	void AddRef() { mRefCount++; }


	int Release() { return --mRefCount; }
public:

	std::wstring mName;

	HBITMAP  mhBitmap;
	BITMAP   mBmpInfo;

	CImagefile(const WCHAR* filename,const WCHAR* name);
	~CImagefile();
	
	static CImagefile* New(const WCHAR* filename, const WCHAR* name);
	static void Delete(CImagefile* delitem);
	static void DestoryAll();


	void Draw(HDC hdc, 
				int dest_x, int dest_y, //그릴려는 타겟
				int src_x, int src_y,   //내그림을 어디에 그릴지
				int width, int height); //그림의 크기
	void transDraw(HDC hdc, int dest_x, int dest_y, int src_x, int src_y, int width, int height, UINT color);
	void AlphaDraw(HDC hdc,
		int dest_x, int dest_y,
		int src_x, int src_y,
		int width, int height,
		BYTE alpha);
	void FadeInOut(HDC hdc,
		int dest_x, int dest_y,
		int src_x, int src_y,
		int width, int height,
		BYTE alpha);

	void OverLay(HDC hdc,
		int dest_x, int dest_y,
		int src_x, int src_y,
		int width, int height,
		BYTE alpha,UINT color);

	int Height() const { return mBmpInfo.bmHeight; }
	int Width() const { return mBmpInfo.bmWidth; }
};

