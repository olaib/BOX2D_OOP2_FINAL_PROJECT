#pragma once
#include "Object/Object.h"

class StaticObject:public Object
{
public:
	StaticObject(Type type, const sf::Vector2f& position, b2World*, const sf::Vector2f& ratio = { 1,1 });
	StaticObject(Type type, const sf::Vector2f& position, const sf::Vector2f& ratio = { 1,1 });
private:
};