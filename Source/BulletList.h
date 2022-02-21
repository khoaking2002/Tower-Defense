#pragma once
#include "Bullet.h"
#include "Monster.h"
class BulletList {
private:
	vector<Bullet*> list;
public:
	void addBullet(Point Machine, Monster* m, Screen&);
	void Update(Screen&);
};