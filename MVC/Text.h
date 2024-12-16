#pragma once

#include <string>

#include "Frame.h"


class Text : public Frame {
public:
	Text(std::string text, Vec2<float> pos, int fontSize = 16, const char* fontPath = "arial.ttf");

	void add(Frame* element) override {};
	void remove(Frame* element) override {};

	enum Baseline {
		Bottom,
		Middle,
		Top,
	};

	enum Align {
		Left,
		Center,
		Right
	};

	struct Style {
		const char* fontPath;
		int fontSize;
		float color[3];
	};

	Style getStyle() const;
	const char* getText() const;
	std::pair<Baseline, Align> getAlignment() const;
	Text* setText(std::string text);
	Text* setAlignment(Baseline bl, Align a);


protected:
	std::string m_text;
	std::string m_font;
	int m_fontSize;
	float m_color[3] = { 0, 0, 0 };

	Baseline m_baseline = Baseline::Top;
	Align m_align = Align::Left;

};