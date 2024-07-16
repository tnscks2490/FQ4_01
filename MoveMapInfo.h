#pragma once
#include "pch.h"


struct MoveMapInfo
{
    std::wstring MoveMapName;
    int x;
    int y;
};


const MoveMapInfo KarionHall[20]
{
    {std::wstring(L"KarionCastle_Lab"),10,5},
    {std::wstring(L"KarionCastle_Lab"),11,5},
    {std::wstring(L"KarionCastle_Lab"),12,5},
    {std::wstring(L"KarionCastle_KingRoom"),38,5},
    {std::wstring(L"KarionCastle_KingRoom"),39,5},
    {std::wstring(L"KarionCastle_KingRoom"),40,5},
    {std::wstring(L"KarionCastle_AresRoom"),66,5},
    {std::wstring(L"KarionCastle_AresRoom"),67,5},
    {std::wstring(L"KarionCastle_AresRoom"),68,5},
    {std::wstring(L"KarionCastle_Armory"),10,16},
    {std::wstring(L"KarionCastle_Armory"),11,16},
    {std::wstring(L"KarionCastle_Armory"),12,16},
    {std::wstring(L"KarionCastle_MeetingRoom"),66,16},
    {std::wstring(L"KarionCastle_MeetingRoom"),67,16},
    {std::wstring(L"KarionCastle_MeetingRoom"),68,16},
    {std::wstring(L"KarionCastle_Outside"),17,31},
    {std::wstring(L"KarionCastle_Outside"),18,31},
    {std::wstring(L"KarionCastle_Outside"),19,31},
    {std::wstring(L"KarionCastle_Outside"),20,31},
    {std::wstring(L"KarionCastle_Outside"),21,31},
};

const MoveMapInfo KarionLab[5]
{
    {std::wstring(L"KarionCastle_Hall"),17,31},
    {std::wstring(L"KarionCastle_Hall"),18,31},
    {std::wstring(L"KarionCastle_Hall"),19,31},
    {std::wstring(L"KarionCastle_Hall"),20,31},
    {std::wstring(L"KarionCastle_Hall"),21,31},
};

const MoveMapInfo KarionKingRoom[6]
{
    {std::wstring(L"KarionCastle_Hall"),17,31},
    {std::wstring(L"KarionCastle_Hall"),18,31},
    {std::wstring(L"KarionCastle_Hall"),19,31},
    {std::wstring(L"KarionCastle_Hall"),20,31},
    {std::wstring(L"KarionCastle_Hall"),21,31},
    {std::wstring(L"KarionCastle_Altar"),27,6},
};

const MoveMapInfo KarionMeetingRoom[5]
{
    {std::wstring(L"KarionCastle_Hall"),17,31},
    {std::wstring(L"KarionCastle_Hall"),18,31},
    {std::wstring(L"KarionCastle_Hall"),19,31},
    {std::wstring(L"KarionCastle_Hall"),20,31},
    {std::wstring(L"KarionCastle_Hall"),21,31},
};

const MoveMapInfo KarionAresRoom[8]
{
    {std::wstring(L"KarionCastle_Hall"),9,4},
    {std::wstring(L"KarionCastle_Hall"),10,4},
    {std::wstring(L"KarionCastle_Hall"),11,4},
    {std::wstring(L"KarionCastle_Outside"),17,31},
    {std::wstring(L"KarionCastle_Outside"),18,31},
    {std::wstring(L"KarionCastle_Outside"),19,31},
    {std::wstring(L"KarionCastle_Outside"),20,31},
    {std::wstring(L"KarionCastle_Outside"),21,31},
};

const MoveMapInfo KarionArmory[5]
{
    {std::wstring(L"KarionCastle_Hall"),17,31},
    {std::wstring(L"KarionCastle_Hall"),18,31},
    {std::wstring(L"KarionCastle_Hall"),19,31},
    {std::wstring(L"KarionCastle_Hall"),20,31},
    {std::wstring(L"KarionCastle_Hall"),21,31},
};

const MoveMapInfo KarionOutSide[6]
{
    {std::wstring(L"KarionCastle_Hall"),44,93},
    {std::wstring(L"KarionCastle_Hall"),45,93},
    {std::wstring(L"KarionCastle_Hall"),46,93},
    {std::wstring(L"KarionCastle_AresRoom"),57,70},
    {std::wstring(L"KarionCastle_AresRoom"),58,70},
};

const MoveMapInfo KarionAltar[5]
{
    {std::wstring(L"KarionCastle_KingRoom"),17,51},
    {std::wstring(L"KarionCastle_KingRoom"),18,51},
    {std::wstring(L"KarionCastle_KingRoom"),19,51},
    {std::wstring(L"KarionCastle_KingRoom"),20,51},
    {std::wstring(L"KarionCastle_KingRoom"),21,51},
};