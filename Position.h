#pragma once

class POS
{
public:
	int x;
	int y;
	int m_dir;

	POS() : x(0), y(0), m_dir(0) {}
	POS(int xx, int yy) : x(xx), y(yy) { m_dir = 0; }
	POS(int xx, int yy, int dir) : x(xx), y(yy), m_dir(dir) {}

	bool operator == (const POS& other) const { return (x == other.x) && (y == other.y); }
	bool operator != (const POS& other) const { return (x != other.x) || (y != other.y); }
};