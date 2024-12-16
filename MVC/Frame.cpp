#include "Frame.h"

Frame::Frame(Rect<float> bounds, Units units) :
	m_bounds(bounds),
	m_units(units)
{
}

void Frame::acceptVisitor(IVisitor* visitor)
{
	visitor->visitUI(this);
}

void Frame::add(Frame* element)
{
	m_elements.push_back(element);
}

void Frame::remove(Frame* element) {
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

void Frame::setUnits(Units units)
{
	m_units = units;
}

void Frame::setBounds(Rect<float> newBounds, Units units)
{
	m_bounds = newBounds;
	m_units = units;
}

Units Frame::getUnits() const
{
	return m_units;
}

Rect<float> Frame::getBounds() const
{
	return m_bounds;
}
