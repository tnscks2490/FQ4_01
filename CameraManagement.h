#pragma once


class CMap;


class CameraManagement
{
public:
	CameraManagement(CMap* camp);
	~CameraManagement();



	void CameraPosSet(int Unit_x,int Unit_y);
	void CameraMove();


public:

	CMap* mCmap;

	
	int camera_x = 0;
	int camera_y = 0;
	
	
	int tile_width = 19;
	int tile_height = 10;

	int mapX;
	int mapY;
};

