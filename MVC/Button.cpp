#include "Button.h"

#include "Text.h"


Button* Button::create(Rect<float> bounds, const char* text, ClickHandler cb)
{
    Button* btn = new Button(cb);
    btn
        ->setAbsoluteBounds({ -1, -1, -1, -1 })
        ->setBounds(BoundsPos{ bounds })
        ->add(
            Text::create(text, { 0.5, 0.5 })
            ->setAlignment(Alignment::Middle, Alignment::Center)
            ->setAnchor(Anchor::Middle, Anchor::Center)
        );
    return btn;  
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

Button* Button::setAbsoluteBounds(Rect<int> bounds)
{
    m_absoluteBounds = bounds;
    return this;
}
