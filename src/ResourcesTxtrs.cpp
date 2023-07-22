#include "ResourcesTxtrs.h"
#include <optional>

ResourcesTxtrs& ResourcesTxtrs::getInstance()
{
	static auto image = ResourcesTxtrs();
	return image;
}

ResourcesTxtrs::ResourcesTxtrs()
{
	//open textures and check if the opening is ok, if not, throw exception
	if (!m_textures[Type::Background].loadFromFile("resources/background.png") ||
		!m_textures[Type::Background2].loadFromFile("resources/background2.png")||
		!m_textures[Type::Cursor ].loadFromFile("resources/cursor.png") ||
		!m_textures[Type::Tile ].loadFromFile("resources/tile.png") ||
		!m_textures[Type::Box ].loadFromFile("resources/box.png") ||
		!m_textures[Type::Thorn ].loadFromFile("resources/thorn.png") ||
		!m_textures[Type::Big ].loadFromFile("resources/bluerun.png") ||
		!m_textures[Type::Small].loadFromFile("resources/pinky_idle.png") ||
		!m_textures[Type::Tall ].loadFromFile("resources/green_idle.png") ||
		!m_textures[Type::BlockedTile ].loadFromFile("resources/blockedTile.png") ||
		!m_textures[Type::Key].loadFromFile("resources/key.png") ||
		!m_textures[Type::Gate ].loadFromFile("resources/gate.png") ||
		!m_textures[Type::arrow ].loadFromFile("resources/arrow.png") ||
		!m_textures[Type::Help ].loadFromFile("resources/helpBtn.png") ||
		!m_textures[Type::infoScreen ].loadFromFile("resources/instructions.png") ||
		!m_textures[Type::PlayBtn ].loadFromFile("resources/playButton.png") ||
		!m_textures[Type::menuButton ].loadFromFile("resources/menuButton.png") ||
		!m_textures[Type::HomeBtn].loadFromFile("resources/homeButton.png") ||
		!m_textures[Type::restartBtn ].loadFromFile("resources/restart.png") ||
		!m_textures[Type::resumeBtn ].loadFromFile("resources/resume.png") ||
		!m_textures[Type::pauseBtn].loadFromFile("resources/PauseButton.png")||
		!m_textures[Type::levelsButton].loadFromFile("resources/levelsButton.png")||
		!m_textures[Type::musicOn].loadFromFile("resources/musicOn.png")||
		!m_textures[Type::musicOff].loadFromFile("resources/musicOff.png")||
		!m_textures[Type::GameOver].loadFromFile("resources/game-over.png") ||
		!m_textures[Type::youLose].loadFromFile("resources/youLose.png")||
		!m_textures[Type::title].loadFromFile("resources/gameTitle.png")
		)
		throw  std::runtime_error("Can't load image file...");
}

sf::Sprite ResourcesTxtrs::getSprite(Type image)
{
	return sf::Sprite(m_textures.find(image)->second);
}

sf::Vector2u ResourcesTxtrs::size(Type index)const
{
	return m_textures.find(index)->second.getSize();
}