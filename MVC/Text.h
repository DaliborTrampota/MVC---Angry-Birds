#pragma once

#include <string>

#include "Frame.h"


class Text : public Frame {
public:
	static Text* create(std::string text, Vec2<float> pos, Font font = { "arial.ttf", 16 });

	Frame* add(Frame* element) override { return this; };
	void remove(Frame* element) override {};

	Font getFont() const;

	const char* getText() const;
	Text* setText(std::string text);

	Alignment getAlignment() const;
	Text* setAlignment(Alignment::Baseline bl, Alignment::Align a);


protected:
	Text(Font f) : m_font(f) {};

	std::string m_text;
	Font m_font;
	Alignment m_alignment = { Alignment::Top, Alignment::Left };
};