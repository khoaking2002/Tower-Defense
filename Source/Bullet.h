#pragma once
#include "BaseObject.h"
#include "Monster.h"
class Bullet : public BaseObject {
private:
	int dmg = 20;
	int speed = 8;
	Point pos;
	Monster * m;
	bool isEnd = false;
public:
	Bullet(Point start, Monster*, Screen&);
	~Bullet(){}
	void setSpeed(int Speed) { speed = Speed; }
	int getSpeed() { return speed; }
	void Move();
	void Update(SDL_Renderer* screen);
	bool GetIsEnd() { 
		return isEnd || !m->IsLife(); 
	}
};