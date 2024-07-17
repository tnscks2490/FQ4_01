#include "pch.h"
#include "CMap.h"
#include "CameraManagement.h"

CameraManagement::CameraManagement(CMap* cmap)
{
	mCmap = cmap;
	mapX = cmap->mScreen.mSrcWidth/16;
	mapY = cmap->mScreen.mSrcHeight/16;
}

CameraManagement::~CameraManagement()
{

}

void CameraManagement::CameraPosSet(int Unit_x, int Unit_y)
{

	if (Unit_x < tile_width) camera_x = 0;
	else if (Unit_x + tile_width >= mapX) camera_x = mapX - (tile_width*2);
	else if (Unit_x - tile_width >= 0 && Unit_x + tile_width < mapX)
		camera_x = (Unit_x - tile_width) +1;


	if (Unit_y < tile_height)
		camera_y = 0;
	else if (Unit_y + tile_height >= mapY)
		camera_y = mapY - (tile_height*2) ;
	else if (Unit_y - tile_height >= 0 && Unit_y + tile_height < mapY)
		camera_y = Unit_y - tile_height;

	mCmap->CameraX = camera_x * 16;
	mCmap->CameraY = camera_y * 16;
}

void CameraManagement::CameraMove()
{

}
