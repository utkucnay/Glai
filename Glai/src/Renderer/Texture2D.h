#pragma once
#include "EngineCore.h"

#include "corona.h"

namespace Glai::Renderer
{
	struct Texture2D
	{
		unsigned int id;
		int nameHash;
		std::string name;
		corona::Image* imageData;
	};

	static Ref<Texture2D> CreateTexture2D(std::string fileName, std::string name)
	{
		Ref<Texture2D> texture2D = CreateRef<Texture2D>();

		texture2D->imageData = corona::OpenImage(fileName.c_str(), corona::FF_PNG, corona::PF_B8G8R8A8);
		texture2D->nameHash = HashHelper::HashFunction(name);

		return texture2D;
	};

	static void CopyToGPUTexture2D(Ref<Texture2D> texture2D, bool holdCPUCopyImageData = false)
	{
		if (texture2D->imageData)
		{
			glGenTextures(1, &texture2D->id);
			glBindTexture(GL_TEXTURE_2D, texture2D->id);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture2D->imageData->getWidth(), texture2D->imageData->getHeight()
				, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture2D->imageData->getPixels());
			glGenerateMipmap(GL_TEXTURE_2D);
			if (!holdCPUCopyImageData)
			{
				texture2D->imageData->operator delete;
			}
		}
		else
		{
			ENG_CORE_ASSERT("Haven't Texture. Texture Name: " + texture2D->name)
		}
	};
}