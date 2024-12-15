#include "TextObject.h"
#include "Configuration.h"

TextObject::TextObject() :
	TextObject("", { 0, 0 })
{
}

TextObject::TextObject(std::string text, Vec2<int> pos, int fontSize, const char* font) :
	GameObject((Vec2<float>)pos),
	m_text(text),
	m_fontSize(fontSize)
{
	//std::string fontPath(FontPath);
	//fontPath.append(font);

	m_font = font;// fontPath;
}

TextObject::Style TextObject::getStyle() const
{
	return {
		m_font.c_str(),
		m_fontSize,
		{ m_color[0], m_color[1], m_color[2] },
	};
}

const char* TextObject::getText() const
{
	return m_text.c_str();
}

void TextObject::setText(std::string text)
{
	m_text = text;
}

void TextObject::acceptVisitor(IVisitor* visitor)
{
	visitor->visitTextObject(this);
}
