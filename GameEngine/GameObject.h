#pragma once
#include "IObject.h"
#include "Transform.h"
#include "SDL.h"
struct Properties {
public:
	Properties(std::string textureID, float x, float y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE) {
		TextureID = textureID;
		X = x;
		Y = y;
		Width = width;
		Height = height;
		Flip = flip;
	}
public:
	int Width, Height;
	float X, Y;
	std::string TextureID;
	SDL_RendererFlip Flip;
};
class GameObject :public IObject{
public:
	GameObject (const Properties &props):m_TextureID(props.TextureID),m_Width(props.Width),m_Height(props.Height),m_Flip(props.Flip){
		m_Transform = new Transform(props.X, props.Y);
	}
	virtual void Draw() = 0;
	virtual void Update(float dt) = 0;
	virtual void Clean() = 0;
protected:
	Transform* m_Transform;
	std::string m_TextureID;
	int m_Width, m_Height;
	SDL_RendererFlip m_Flip;
	
};

