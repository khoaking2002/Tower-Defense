#include "Bullet.h"
//Khoi tao co tham so
Bullet::Bullet(Point start, Monster * _m, Screen &MainScreen) {
	pos = start;
	m = _m;
	LoadImg("bullet.png", MainScreen);
	setRect(start.x, start.y);
}
//Dan di chuyen theo toa do quai
void Bullet::Move() {
	Point mPos = m->GetCenterPosition();
	int distance = Point::Distance2Point(pos, mPos);
	if(distance == 0) {
		pos = mPos;
		return;
	}
	Point newPos;
	newPos.x = pos.x + speed*(mPos.x-pos.x)/distance;
	newPos.y = pos.y + speed*(mPos.y-pos.y)/distance;
	if(Point::Distance2Point(pos, newPos) > Point::Distance2Point(pos, mPos)){
		pos = mPos;
		m->HPChange(this->dmg);
		isEnd = true;
	}
	else{
		pos = newPos;
	}
}
//Cap nhat vi tri va trang thai cua dan
void Bullet::Update(SDL_Renderer* screen) {
	Move();
	setRect(pos.x, pos.y);
	this->Render(screen);
}