#include "Frame.h"


Frame* Frame::create(Rect<float> bounds, Units units)
{
	Frame* f = new Frame();
	return f->setBounds(BoundsPos{ bounds }, units);
}

void Frame::acceptVisitor(IVisitor* visitor)
{
	visitor->visitUI(this);
}

Frame* Frame::add(Frame* element)
{
	m_elements.push_back(element);
	return static_cast<Frame*>(this);
}

void Frame::remove(Frame* element) 
{
	m_elements.erase(std::find(m_elements.begin(), m_elements.end(), element));
}

Frame* Frame::get(size_t idx)
{
	return m_elements.at(idx);
}

std::vector<Frame*> Frame::getAll(bool includeThis)
{
	if (includeThis) {
		std::vector<Frame*> els = { m_elements };
		els.push_back(this);
		return els;
	}
	return m_elements;
}

Frame* Frame::setUnits(Units units) {
	m_units = units;
	return this;
}

Units Frame::getUnits() const {
	return m_units;
}

Frame* Frame::setBounds(BoundsPos newBounds, Units units) {
	m_bounds = newBounds;
	m_units = units;
	return this;
}
BoundsPos Frame::getBounds() const {
	return m_bounds;
}

Frame* Frame::setStyle(FrameStyle style) {
	m_style = style;
	return this;
}
FrameStyle Frame::getStyle() const {
	return m_style;
}

Frame* Frame::setAnchor(Anchor::Vertical vert, Anchor::Horizontal hor) {
	m_anchor.vertical = vert;
	m_anchor.horizontal = hor;
	return this;
}
Anchor Frame::getAnchor() const {
	return m_anchor;
}