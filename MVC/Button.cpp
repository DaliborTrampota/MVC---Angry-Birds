#include "Button.h"

#include "Text.h"

Button::Button(Rect<float> bounds, const char* text, ClickHandler cb) :
    Frame(bounds),
    m_handler(cb),
    m_absoluteBounds({ -1, -1, -1, -1 })
{
    Text* t = new Text(text, { bounds.x + bounds.w / 2, bounds.y + bounds.h / 2 });
    t->setAlignment(Text::Middle, Text::Center);
    add(t);
}

void Button::onClick()
{
    if(m_handler) m_handler();
}

void Button::processClick(Vec2<int> clickPos)
{
    if (m_absoluteBounds.includes(clickPos))
        onClick();
}

void Button::setAbsoluteBounds(Rect<int> bounds)
{
    m_absoluteBounds = bounds;
}
