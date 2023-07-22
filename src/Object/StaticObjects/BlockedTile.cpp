#include "Object/StaticObjects/BlockedTile.h"
#include "macros.hpp"
bool BlockedTile::m_registerIt = Factory<StaticObject>::registerIt(Type::BlockedTile, [](const sf::Vector2f& position, b2World* world) ->
	std::unique_ptr<StaticObject> { return std::make_unique<BlockedTile>(position, world); });

BlockedTile::BlockedTile(const sf::Vector2f& pos, b2World* world) :
	StaticObject(Type::BlockedTile, pos, { STANDARD_RATIO,DOUBLE_RATIO })
{
	b2PolygonShape groundBox;
	b2BodyDef bodyDef;
	b2FixtureDef fixtureDef;
	
	bodyDef.position.Set(m_sprite.getPosition().x / BOX2D_SCALE,
						 m_sprite.getPosition().y / BOX2D_SCALE);
	m_body = world->CreateBody(&bodyDef);
	groundBox.SetAsBox(m_sprite.getGlobalBounds().width * 0.005f,
					   m_sprite.getGlobalBounds().height * 0.005f);
	fixtureDef.shape = &groundBox;
	fixtureDef.friction = 0.0f;
	fixtureDef.density = 0.f;
	m_body->CreateFixture(&fixtureDef);
	m_body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
}
