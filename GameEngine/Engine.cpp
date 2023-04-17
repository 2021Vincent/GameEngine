#include "Engine.h"
#include "TextureManager.h"
#include "Vector2D.h"
#include "MainCharacter.h"
#include <iostream>
Engine* Engine::s_Instance = nullptr;

MainCharacter* player = nullptr;

bool Engine::Init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_INIT_JPG | IMG_INIT_PNG != 0) {
		SDL_Log("Failed to initialize SDL &s",SDL_GetError());
		return false;
	}
	m_Window = SDL_CreateWindow("test engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,SCREEN_HEIGHT,SCREEN_WIDTH, SDL_WINDOW_RESIZABLE);
	if (m_Window == nullptr) {
		SDL_Log("Failed to initialize window &s", SDL_GetError());
		return false;
	}
	m_Renderer = SDL_CreateRenderer(m_Window, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Window == nullptr) {
		SDL_Log("Failed to initialize Renderer &s", SDL_GetError());
		return false;
	}
	TextureManager::GetInstance()->Load("player", "assets/idle.png");
	Properties aa("player", 0, 0, 336, 384);
	player = new MainCharacter(aa);
	
	

	return m_IsRunning = true;
}
bool Engine::Clean() {
	delete player;
	return true; 
}
void Engine::Quit() {
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	IMG_Quit();
	SDL_Quit();
	SDL_Log("engine cleaned");
}
void Engine::Update() {
	player->Update(0);
}
void Engine::Render() {
	SDL_SetRenderDrawColor(m_Renderer, 124, 210, 12, 255);
	SDL_RenderClear(m_Renderer);
	player->Draw();
	SDL_RenderPresent(m_Renderer);
}
void Engine::Events() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		m_IsRunning = false;
		Quit();
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE) {
			m_IsRunning = false;
		}
		break;
	}
}