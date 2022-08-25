#pragma once
#include "StaticObject.h"

class Gate : public StaticObject
{
public:
	Gate(const sf::Vector2f& pos, b2World* world);
private:
	static bool m_registerIt;
};