#pragma once

#include "MyMath.h"
#include "IVisitable.h"

class GameObject : public IVisitable
{
public:
	GameObject(Vec2<float> pos);
	GameObject(Vec2<float> pos, const char* texName);
	~GameObject();
	virtual void move(Vec2<float> dir);

	void setName(const char* name);
	void setTexture(const char* name);
	void setDims(int w, int h);
	void setPos(Vec2<float> pos);

	const char* getName() const;
	virtual const char* getTextureName() const;
	Vec2<float> getPosition() const;
	Vec2<int> getDimensions() const;


	// Inherited via IVisitable
	virtual void acceptVisitor(IVisitor* visitor) = 0;

	static inline int m_sCount = 0;

protected:
	const char* m_name;
	const char* m_texName;
	Vec2<float> m_pos;
	int m_width, m_height;



};