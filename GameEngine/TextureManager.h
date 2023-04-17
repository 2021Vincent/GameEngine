#pragma once
#include <string>
#include "SDL.h"
#include "Engine.h"
#include <map>
class TextureManager {
public:
	static TextureManager* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new TextureManager(); }
	bool Load(std::string id, std::string filename);
	void Drop(std::string id);
	void Clean();
	void Draw(std::string id ,int x, int y, int width, int height, double angle = 0,SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFrame(std::string id ,int x, int y, int width, int height, int row, int frame, double angle = 0,SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
	TextureManager(){}
	std::map<std::string, SDL_Texture*> m_TextureMap;
	static TextureManager* s_Instance;
};