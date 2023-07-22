#include "Object\StaticObjects\Thorn.h"

bool Thorn::m_registerIt = Factory<StaticObject>::registerIt(Type::Thorn, [](const sf::Vector2f& position, b2World* world) ->
	std::unique_ptr<StaticObject> { return std::make_unique<Thorn>(position, world); });

Thorn::Thorn(const sf::Vector2f& position, b2World* world)
	: StaticObject(Type::Thorn, position)
{
	b2PolygonShape groundBox;
	b2BodyDef bodyDef;
	static const auto x = m_sprite.getGlobalBounds().width / 2;
	static const auto y = m_sprite.getGlobalBounds().height / 2;

	bodyDef.position.Set(m_sprite.getPosition().x / BOX2D_SCALE,
						 m_sprite.getPosition().y / BOX2D_SCALE);
	m_body = world->CreateBody(&bodyDef);
	groundBox.SetAsBox(x /BOX2D_SCALE, y / BOX2D_SCALE);
	m_body->CreateFixture(&groundBox, 0.0f);

	m_body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
}