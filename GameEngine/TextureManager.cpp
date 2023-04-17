#include "TextureManager.h"
TextureManager* TextureManager::s_Instance = nullptr;
bool TextureManager::Load(std::string id, std::string filename) {
	SDL_Texture* texture = IMG_LoadTexture(Engine::GetInstance()->GetRenderer(), filename.c_str());
	if (texture == nullptr) {
		SDL_Log("Fail to create texture from surface: %s ", SDL_GetError());
		return false;
	}
	m_TextureMap[id] = texture;
}
void TextureManager::Draw(std::string id, int x, int y, int width, int height, double angle,SDL_RendererFlip flip) {
	SDL_Rect srcRect = { 0, 0, width, height };
	SDL_Rect destRect = {x, y, width, height};
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &destRect, angle, nullptr, flip);
}
void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, double angle, SDL_RendererFlip flip) {
	SDL_Rect srcRect = {width*frame, height*(row-1) , width, height};
	SDL_Rect destRect = { x, y, width, height };
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &destRect, angle, nullptr, flip);
}
void TextureManager::Drop(std::string id) {
	SDL_DestroyTexture(m_TextureMap.at(id));
	m_TextureMap.erase(id);
}
void TextureManager::Clean() {
	std::map<std::string, SDL_Texture*>::iterator it;
	for (it = m_TextureMap.begin(); it != m_TextureMap.end();it++) {
		SDL_DestroyTexture(it->second);
	}
	m_TextureMap.clear();
	SDL_Log("texture map cleaned");
}