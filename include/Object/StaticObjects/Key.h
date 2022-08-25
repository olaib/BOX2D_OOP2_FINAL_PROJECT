#pragma once
#include "StaticObject.h"

class Key : public StaticObject
{
public:
	Key(const sf::Vector2f& pos, b2World* world);

private:
	static bool m_registerIt;
};