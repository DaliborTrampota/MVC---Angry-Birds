#include "Text.h"

Text::Text(std::string text, Vec2<float> pos, int fontSize, const char* font) :
	Frame({ pos.x, pos.y, -1, -1 }),
	m_text(text),
	m_font(font),
	m_fontSize(fontSize)
{
}


Text::Style Text::getStyle() const
{
	return {
		m_font.c_str(),
		m_fontSize,
		{ m_color[0], m_color[1], m_color[2] },
	};
}

const char* Text::getText() const
{
	return m_text.c_str();
}

std::pair<Text::Baseline, Text::Align> Text::getAlignment() const
{
	return std::pair<Baseline, Align>(m_baseline, m_align);
}

Text* Text::setText(std::string text)
{
	m_text = text;
	return this;
}

Text* Text::setAlignment(Baseline bl, Align a)
{
	m_baseline = bl;
	m_align = a;
	return this;
}
