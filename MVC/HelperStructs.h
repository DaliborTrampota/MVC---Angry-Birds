#pragma once

#include <string>
#include "MyMath.h"

union BoundsPos {
	Rect<float> bounds;
	Vec2<float> position;
};


enum class Units {
	Relative,
	Absolute,
};

struct Font {
	Font(int size) : size(size) {};
	Font(const char* font, int size) : size(size), font(font) {};
	std::string font = "arial.ttf";
	int size = 16;
	float color[3] = { 0, 0, 0 };
};

struct FrameStyle {
	bool filled = false;
	float color[4] = { 1, 1, 1, 1 };
};



struct Anchor {
	enum Vertical {
		Top, Middle, Bottom
	};

	enum Horizontal {
		Left, Center, Right
	};

	Vertical vertical;
	Horizontal horizontal;
};

struct Alignment {
	enum Baseline {
		Top, Middle, Bottom
	};

	enum Align {
		Left, Center, Right
	};

	Baseline baseline;
	Align align;
};
