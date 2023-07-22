#include "ResourcesSounds.h"

ResourcesSounds& ResourcesSounds::getInstance()
{
	static ResourcesSounds resourcesSounds;
	return resourcesSounds;
}

void ResourcesSounds::play(Sounds sound)
{
	if (m_sounds.find(sound)->second.getStatus() != sf::Sound::Playing)
		m_sounds.find(sound)->second.play();
}

void ResourcesSounds::stop(Sounds sound)
{
	m_sounds.find(sound)->second.stop();
}

void ResourcesSounds::pause(Sounds sound)
{
	m_sounds.find(sound)->second.pause();
}

void ResourcesSounds::setValume(const float& valume)
{
	for (auto it = m_sounds.begin(); it != m_sounds.end(); ++it)
		m_sounds[Sounds::Background].setVolume(valume);
}

void ResourcesSounds::setLoop(Sounds sound)
{
	m_sounds.find(sound)->second.setLoop(true);
}

ResourcesSounds::ResourcesSounds()
{
	if (!m_soundsBuffer[Sounds::Click].loadFromFile("resources/click.wav") ||
		!m_soundsBuffer[Sounds::Background].loadFromFile("resources/background_sound.wav") ||
		!m_soundsBuffer[Sounds::Jump].loadFromFile("resources/jump.wav") ||
		!m_soundsBuffer[Sounds::win].loadFromFile("resources/win.wav") ||
		!m_soundsBuffer[Sounds::lvlLose].loadFromFile("resources/lose.wav") ||
		!m_soundsBuffer[Sounds::key].loadFromFile("resources/key.wav") ||
		!m_soundsBuffer[Sounds::endGame].loadFromFile("resources/endGame.wav")
		)
		throw  std::runtime_error("Can't load one of sounds file!");

	for (auto it = m_soundsBuffer.begin(); it != m_soundsBuffer.end(); ++it) {
		m_sounds[it->first].setBuffer(m_soundsBuffer[it->first]);
		m_sounds[it->first].setVolume(10.f);
	}

}
