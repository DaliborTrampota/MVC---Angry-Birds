#pragma once

#include "math.h"

template <class T>
struct Vec2 {
	T x, y;

	//Vec2(T x, T y) : x(x), y(y) {}

	float length() const {
		return sqrt(x * x + y * y);
	}

	void setLength(float newLength) {
		if (x == 0 && y == 0) return;
		float factor = newLength / length();
		x *= factor;
		y *= factor;
	}

	static Vec2<T> moveTowards(Vec2<T> src, Vec2<T> target, float maxStep) {
		float distSq = distanceSq(src, target);

		if (distSq == 0 || (maxStep >= 0 && distSq <= maxStep * maxStep))
			return target;

		distSq = sqrt(distSq);
		return {
			src.x + (target.x - src.x) / distSq * maxStep,
			src.y + (target.y - src.y) / distSq * maxStep
		};
	}

	static float distanceSq(const Vec2<T>& A, const Vec2<T>& B) {
		return pow(A.x - B.x, 2) + pow(A.y - B.y, 2);
	}

	static float distance(const Vec2<T>& A, const Vec2<T>& B) {
		return sqrt(distance(A, B));
	}


	Vec2& operator+=(const Vec2& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	Vec2& operator*=(const float scalar) {
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vec2 operator+(const Vec2& other) const {
		return { x + other.x, y + other.y };
	}

	Vec2 operator-(const Vec2& other) const {
		return { x - other.x, y - other.y };
	}

	Vec2 operator*(const float scalar) {
		return { x * scalar, y * scalar };
	}
};

template <class T = int>
struct Rect {
	T x, y, w, h;
};