#include "Object/StaticObjects/StaticObject.h"

StaticObject::StaticObject(Type type, const sf::Vector2f& position, b2World* world, const sf::Vector2f& ratio) :
	Object(type, position, ratio)
{
	setBody(world, b2_staticBody, false, false);
}

StaticObject::StaticObject(Type type, const sf::Vector2f& position, const sf::Vector2f& ratio):
	Object(type, position, ratio)
{}