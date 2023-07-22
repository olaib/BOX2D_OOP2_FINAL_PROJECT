#include "Object/StaticObjects/Gate.h"

bool Gate::m_registerIt = Factory<StaticObject>::registerIt(Type::Gate, [](const sf::Vector2f& position, b2World* world) ->
	std::unique_ptr<StaticObject> { return std::make_unique<Gate>(position, world); });

Gate::Gate(const sf::Vector2f& pos, b2World* world) :
	StaticObject(Type::Gate, pos, world, {DOUBLE_RATIO,DOUBLE_RATIO})
{}
