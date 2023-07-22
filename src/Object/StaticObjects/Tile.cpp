#include "Object/StaticObjects/Tile.h"

bool Tile::m_registerIt = Factory<StaticObject>::registerIt(Type::Tile, [](const sf::Vector2f& position, b2World* world) ->
	std::unique_ptr<StaticObject> { return std::make_unique<Tile>(position, world); });

Tile::Tile(const sf::Vector2f& position, b2World* world) :
	StaticObject(Type::Tile, position)
{
	setBody(position, world);
}