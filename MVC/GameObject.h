#pragma once

#include "Math.h"
#include "IVisitable.h"

class GameObject : public IVisitable
{
public:
	GameObject(Vec2<int> pos);
	GameObject(Vec2<int> pos, const char* texName);
	~GameObject();
	void move(Vec2<int> dir);

	void setName(const char* name);
	void setTexture(const char* name);
	void setDims(int w, int h);

	const char* getName() const;
	const char* getTextureName() const;
	Vec2<int> getPosition() const;
	Vec2<int> getDimensions() const;


	// Inherited via IVisitable
	virtual void acceptVisitor(IVisitor* visitor) = 0;

	static inline int m_sCount = 0;

protected:
	const char* m_name;
	const char* m_texName;
	Vec2<int> m_pos;
	int m_width, m_height;



};