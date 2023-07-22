#include "Object/StaticObjects/Key.h"

bool Key::m_registerIt = Factory<StaticObject>::registerIt(Type::Key, [](const sf::Vector2f& position, b2World* world) ->
	std::unique_ptr<StaticObject> { return std::make_unique<Key>(position, world); });

Key::Key(const sf::Vector2f& pos, b2World* world) :
	StaticObject(Type::Key, pos, world, {DOUBLE_RATIO, STANDARD_RATIO})
{}
