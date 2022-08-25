#pragma once
#include "StaticObject.h"

class Thorn : public StaticObject
{
public:
	Thorn(const sf::Vector2f& position, b2World* world);

private:
	static bool m_registerIt;
};