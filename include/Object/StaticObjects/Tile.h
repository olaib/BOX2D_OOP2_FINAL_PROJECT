#pragma once
#include "StaticObject.h"

class Tile : public StaticObject
{
public:
	Tile(const sf::Vector2f& position, b2World* world);

private:
	static bool m_registerIt;
};