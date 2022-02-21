#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H_
#include "Screen.h"
#pragma once
class Point {
public:
	int x;
	int y;
public:
	Point(){
		x = 0;
		y = 0;
	}
	Point(const int _x, const int _y){
		x = _x; y = _y;
	}
	int Distance(int x, int y) {
		return sqrt((x - this->x) * (x - this->x) + (y - this->y) * (y - this->y));
	}
	static int Distance2Point(Point a, Point b) {
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}
};
class BaseObject {
protected:
	SDL_Texture* p_object_;
	SDL_Rect rec_;
	Point pos_;
public:
	BaseObject();
	~BaseObject();
	void setRect(const int& x, const int& y) { rec_.x = x; rec_.y = y; }
	void setRect(Point p) { rec_.x = p.x; rec_.y = p.y; }
	Point GetPosition() { return Point(rec_.x, rec_.y); }
	Point GetCenterPosition() { return Point(rec_.x + rec_.w/2, rec_.y + rec_.h/2); }
	SDL_Rect GetRect() const { return rec_; }
	SDL_Rect* GetRectPointer() { return &rec_; }
	SDL_Texture* GetObject() const { return p_object_; }
	bool LoadImg(std::string path, Screen &MainScreen);
	void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
	void Free();
};
class TextObject :public BaseObject {
private:
	string _text;
	SDL_Color text_color_;
	SDL_Texture* texture_;
	int widthText;
	int heightText;
public: 
	enum TextColor {
		RED_TEXT = 0, WHITE_TEXT=1, BLACK_TEXT=2,
	};
	TextObject();
	~TextObject();
	bool LoadFromFile(string path);
	bool LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen);
	void SetText(const string& textValue) {_text = textValue;}
	void SetColor(const int&);
	void CreateGameText(TTF_Font* font, SDL_Renderer* des);
	void Free();
	void RenderText(SDL_Renderer* screen, int xp, int yp, SDL_Rect* clip = NULL, double Angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip=SDL_FLIP_NONE);
	int GetWIdth() { return widthText; }
	int GetHeight() { return heightText; }
};



#endif