#pragma once
#include <map>
#include "SFML/audio.hpp"
#include "macros.hpp"

//singelton class for sounds

class ResourcesSounds 
{
public:
	static ResourcesSounds& getInstance();
	void play(Sounds sound);
	void stop(Sounds sound);
	void pause(Sounds sound);
	void setValume(const float& valume);
	void setLoop(Sounds sound);

private:
	//==============private func======================
	ResourcesSounds();
	ResourcesSounds(const ResourcesSounds&) = default;
	ResourcesSounds& operator=(const ResourcesSounds&) = default;
	//================== members =====================
	std::map<Sounds, sf::SoundBuffer> m_soundsBuffer;
	std::map<Sounds, sf::Sound> m_sounds;
};