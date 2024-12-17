#pragma once

#include <vector>

#include "MyMath.h"
#include "IVisitable.h"

#include "HelperStructs.h"

class Frame : public IVisitable {
public:
	static Frame* create(Rect<float> bounds, Units units = Units::Relative);

	void acceptVisitor(IVisitor* visitor) override;

	virtual Frame* add(Frame* element);
	virtual void remove(Frame* element);

	Frame* get(size_t idx);
	std::vector<Frame*> getAll(bool includeThis = false);

	template <class T>
	std::vector<T*> getAll(bool includeThis = false) {
		std::vector<T*> res;
		if (includeThis) {
			if(auto casted = dynamic_cast<T*>(this))
				res.push_back(casted);
		}

		for (auto& e : m_elements) {
			if (auto casted = dynamic_cast<T*>(e)) {
				res.push_back(casted);
			}
		}
		return res;
	}

	Frame* setUnits(Units units);
	Units getUnits() const;

	Frame* setBounds(BoundsPos newBounds, Units units = Units::Relative);
	BoundsPos getBounds() const;

	Frame* setStyle(FrameStyle style);
	FrameStyle getStyle() const;

	Frame* setAnchor(Anchor::Vertical vert, Anchor::Horizontal hor);
	Anchor getAnchor() const;


protected:
	Frame() = default;

	BoundsPos m_bounds;
	Units m_units;
	std::vector<Frame*> m_elements;
	FrameStyle m_style;
	Anchor m_anchor = { Anchor::Top, Anchor::Left };

};