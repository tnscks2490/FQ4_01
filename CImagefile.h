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
				int dest_x, int dest_y, //�׸����� Ÿ��
				int src_x, int src_y,   //���׸��� ��� �׸���
				int width, int height); //�׸��� ũ��
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

