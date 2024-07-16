#pragma once
#include "pch.h"
#include "Script.h"


Script::Script(std::wstring Scene)
{
	if (Scene == L"BarsiaScene1")
	{
		for (int i = 0; i < 17; i++)
		{
			memcpy(T.script, BarsiaText1[i], 5 * 30 * sizeof(WCHAR));
			T.scriptchar = BarsiaChar1[i];
			ScriptV.push_back(T);
		}
	}
 	else if (Scene == L"KarionScene1")
	{
		for (int i = 0; i < 11; i++)
		{
			memcpy(T.script, KarionText1[i], 5 * 30 * sizeof(WCHAR));
			T.scriptchar = KarionChar1[i];
			ScriptV.push_back(T);
		}
	}
	else if (Scene == L"BarsiaScene2")
	{
		for (int i = 0; i < 8; i++)
		{
			memcpy(T.script, BarsiaText2[i], 5 * 30 * sizeof(WCHAR));
			T.scriptchar = BarsiaChar2[i];
			ScriptV.push_back(T);
		}
	}
	else if (Scene == L"FieldBattle")
	{
		for (int i = 0; i < 3; i++)
		{
			memcpy(T.script, FieldText[i], 5 * 30 * sizeof(WCHAR));
			T.scriptchar = FieldChar[i];
			ScriptV.push_back(T);
		}
	}
	else if (Scene == L"KarionScene2")
	{
		for (int i = 0; i < 7; i++)
		{
			memcpy(T.script, KarionText2[i], 5 * 30 * sizeof(WCHAR));
			T.scriptchar = KarionChar2[i];
			ScriptV.push_back(T);
		}
	}
	else if (Scene == L"BarsiaScene3")
	{
		for (int i = 0; i < 13; i++)
		{
			memcpy(T.script, BarsiaText3[i], 5 * 30 * sizeof(WCHAR));
			T.scriptchar = BarsiaChar3[i];
			ScriptV.push_back(T);
		}
	}
	else if (Scene == L"KarionScene3")
	{
		for (int i = 0; i < 26; i++)
		{
			memcpy(T.script, KarionText3[i], 5 * 30 * sizeof(WCHAR));
			T.scriptchar = KarionChar3[i];
			ScriptV.push_back(T);
		}
	}
}

Script::~Script()
{
	
}


