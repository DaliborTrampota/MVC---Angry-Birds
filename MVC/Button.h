#pragma once

#include <string>
#include <functional>

#include "Frame.h"
#include "IClickable.h"


class Button : public Frame, public IClickable {
public:
	using ClickHandler = std::function<void()>;
	
	Button(Rect<float> bounds, const char* text, ClickHandler cb = nullptr);

	virtual void onClick() override;
	void processClick(Vec2<int> clickPos) override;
	void setAbsoluteBounds(Rect<int> bounds);

protected:
	ClickHandler m_handler;
	Rect<int> m_absoluteBounds;
};
