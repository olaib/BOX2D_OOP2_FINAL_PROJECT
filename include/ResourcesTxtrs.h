#pragma once
#include <map>
#include "macros.hpp"

//singelton class for textures

class ResourcesTxtrs
{
public:
	static ResourcesTxtrs& getInstance();
	sf::Sprite getSprite(Type image);
	sf::Vector2u size(Type index)const;
private:
	//==============private func======================
	ResourcesTxtrs();
	ResourcesTxtrs(const ResourcesTxtrs&) = default;
	ResourcesTxtrs& operator=(const ResourcesTxtrs&) = default;
	//================== members =====================
	std::map<Type, sf::Texture> m_textures;
};