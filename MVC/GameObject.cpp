#include "GameObject.h"

GameObject::GameObject(Vec2<int> pos) : 
	m_name("object"),
	m_texName(), 
	m_pos(pos),
	m_height(0),
	m_width(0)
{
	m_sCount++;
}

GameObject::GameObject(Vec2<int> pos, const char* texName) :
	m_name("object"),
	m_texName(texName),
	m_pos(pos),
	m_height(0),
	m_width(0)
{
}

GameObject::~GameObject()
{
	m_sCount--;
}

void GameObject::move(Vec2<int> dir)
{
	m_pos += dir;
}

void GameObject::setDims(int w, int h)
{
	m_width = w;
	m_height = h;
}

const char* GameObject::getName() const
{
	return m_name;
}

const char* GameObject::getTextureName() const
{
	return m_texName;
}

Vec2<int> GameObject::getPosition() const
{
	return m_pos;
}

Vec2<int> GameObject::getDimensions() const
{
	return Vec2<int>{ m_width, m_height };
}

void GameObject::setName(const char* name)
{
	m_name = name;
}

void GameObject::setTexture(const char* name)
{
	m_texName = name;
}
