#pragma once
#include "EngineCore.h"

#include "corona.h"

namespace Glai::Renderer
{
	struct Sprite
	{
		unsigned int id;
		int nameHash;
		bool haveSpriteData = false;
		corona::Image* sprite;
	};

	static Ref<Sprite> CreateSprite(std::string fileName, std::string name)
	{
		Ref<Sprite> spriteRef = CreateRef<Sprite>();

		spriteRef->sprite = corona::OpenImage(fileName.c_str(), corona::FF_PNG, corona::PF_B8G8R8A8);
		// I will add Hashing Algorithm
		spriteRef->nameHash = name.c_str()[0];
		spriteRef->haveSpriteData = true;

		return spriteRef;
	};
}