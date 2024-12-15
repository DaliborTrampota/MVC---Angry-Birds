#pragma once

#include "GameObject.h"
#include <string>

class TextObject : public GameObject {
public:
	TextObject();
	TextObject(std::string text, Vec2<int> pos, int fontSize = 16, const char* font = "arial.ttf");
	using GameObject::GameObject;

	struct Style {
		const char* fontPath;
		int fontSize;
		float color[3];
	};

	Style getStyle() const;
	const char* getText() const;
	void setText(std::string text);

	void acceptVisitor(IVisitor* visitor) override;

protected:
	std::string m_text;
	std::string m_font;
	int m_fontSize;
	float m_color[3] = { 0, 0, 0 };
};