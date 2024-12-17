#include "Text.h"

Text* Text::create(std::string text, Vec2<float> pos, Font font)
{
	Text* t = new Text(font);
	return static_cast<Text*>(t->setText(text)->setBounds(BoundsPos{ pos.x, pos.y }));
}

Font Text::getFont() const
{
	return m_font;
}

const char* Text::getText() const
{
	return m_text.c_str();
}

Alignment Text::getAlignment() const
{
	return m_alignment;
}

Text* Text::setText(std::string text)
{
	m_text = text;
	return this;
}

Text* Text::setAlignment(Alignment::Baseline bl, Alignment::Align a)
{
	m_alignment.baseline = bl;
	m_alignment.align = a;
	return this;
}
