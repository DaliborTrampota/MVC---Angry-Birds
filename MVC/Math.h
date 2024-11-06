#pragma once


template <class T>
struct Vec2 {
	T x, y;


	Vec2& operator+=(const Vec2& other) {
		x += other.x;
		y += other.y;
		return *this;
	}
};