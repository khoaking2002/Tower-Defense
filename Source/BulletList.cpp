#include "BulletList.h"
//Them dan vao bang dan
void BulletList::addBullet(Point location, Monster* m, Screen& MainScreen) {
    list.push_back(new Bullet(location, m, MainScreen));
}
//Cap nhat bang dan
void BulletList::Update(Screen& MainScreen) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i] && list[i]->GetIsEnd() == false) {
            list[i]->Update(MainScreen.g_screen);
        }
        if(list[i] && list[i]->GetIsEnd()) {
            delete list[i];
            list[i] = NULL;
        }
    }
}