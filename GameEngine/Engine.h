#pragma once
#include "SDL.h"
#include "SDL_image.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 960
class Engine {

public:
	static Engine* GetInstance() {
		return s_Instance = (s_Instance != nullptr)?s_Instance:new Engine();
	}
	bool Init();
	bool Clean();
	void Quit();
	void Update();
	void Render();
	void Events();
	inline bool IsRunning() { return m_IsRunning; }
	inline SDL_Renderer* GetRenderer() { return m_Renderer; }
private:
	static Engine* s_Instance;
	Engine() {}
	bool m_IsRunning;
	SDL_Renderer* m_Renderer;
	SDL_Window* m_Window;
};