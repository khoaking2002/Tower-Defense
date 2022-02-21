#include "CommonFunction.h"
#define DEBUG_PATH false
#define DEBUG_TOWER false
//Luu path vao file
void savePath(vector<Point> &path){
	ofstream fo;
	if(DEBUG_TOWER)
		fo.open("GamePathBorder.txt");
	else 
		fo.open("GamePath.txt");
	fo << path.size() << endl;
	for(Point &p : path) {
		fo << p.x << ' ' << p.y << endl;
	}
	fo.close();
}
//Doc file path
void readPath(vector<Point> &path, string file_path){
	ifstream fi(file_path);
	int _size; fi >> _size;
	path.resize(_size);
	for(Point &p : path) {
		fi >> p.x >> p.y;
	}
	fi.close();
}
//Lay duong di
void getPath(vector<Point> &path, vector<Point> &pathBorder, vector<SDL_Rect> &pathRect) {
	if(DEBUG_PATH) return;
    readPath(path, "GamePath.txt");
    readPath(pathBorder, "GamePathBorder.txt");
    for(int i = 0; i < pathBorder.size(); i += 2) {
        SDL_Rect rect;
        rect.x = pathBorder[i].x;
        rect.y = pathBorder[i].y;
        rect.w = pathBorder[i + 1].x - pathBorder[i].x;
        rect.h = pathBorder[i + 1].y - pathBorder[i].y;
        pathRect.push_back(rect);
    }
}
//Gan gia tri cho path
void setPath(vector<Point> &path, Screen &MainScreen) {
    if(DEBUG_PATH){
        if(DEBUG_TOWER) {
            if (MainScreen.g_event.type == SDL_MOUSEBUTTONDOWN) {
                int xMouse, yMouse;
                SDL_GetMouseState(&xMouse, &yMouse);
                cout << xMouse <<" " << yMouse << endl;
                path.push_back(Point(xMouse, yMouse));
            }
        }else{
            if(MainScreen.g_event.type == SDL_MOUSEMOTION)
            {
                int xMouse, yMouse;
                SDL_GetMouseState(&xMouse,&yMouse);
                path.push_back(Point(xMouse, yMouse));
            }
        }
    }
}