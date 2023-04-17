#pragma once
#include "Character.h"
class MainCharacter : public Character{

public:
	MainCharacter(Properties &props);
	virtual void Draw() ;
	virtual void Update(float dt) ;
	virtual void Clean() ;
private:
	int m_FrameCount;
	int m_Frame;
	int m_Row;
	int m_AnimationSpeed;
};

