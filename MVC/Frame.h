#pragma once

#include <vector>

#include "MyMath.h"
#include "IVisitable.h"

class TextObject;

enum class Units {
	Relative,
	Absolute,
};

class Frame : public IVisitable {
public:
	Frame(Rect<float> bounds, Units units = Units::Relative);

	void acceptVisitor(IVisitor* visitor) override;

	virtual void add(Frame* element);
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

	void setUnits(Units units);
	void setBounds(Rect<float> newBounds, Units units = Units::Relative);
	Units getUnits() const;
	Rect<float> getBounds() const;


protected:
	Rect<float> m_bounds;
	Units m_units;
	std::vector<Frame*> m_elements;
};