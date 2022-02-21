#include "BaseObject.h"
//Khoi tao mac dinh
BaseObject::BaseObject() {
	p_object_ = NULL;
	rec_.x = 0;
	rec_.y = 0;
	rec_.h = 0;
	rec_.w = 0;
}
//Huy
BaseObject::~BaseObject() {
	Free();
}
//Load Img
bool BaseObject::LoadImg(std::string path, Screen &MainScreen) {
	SDL_Texture* new_texture = NULL;
	SDL_Surface* load_surface = IMG_Load(path.c_str());
	if (load_surface != NULL) {
		SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, MainScreen.COLOR_KEY_R, MainScreen.COLOR_KEY_B, MainScreen.COLOR_KEY_G));
		new_texture = SDL_CreateTextureFromSurface(MainScreen.g_screen, load_surface);
		if (new_texture != NULL) {
			rec_.w = load_surface->w;
			rec_.h = load_surface->h;
		}
		else { cout << "error"; }
		SDL_FreeSurface(load_surface);
	}else{
		cerr << "Error image load: " << IMG_GetError()  << endl;
		cout << path << endl;
	}
	p_object_ = new_texture;
	if (p_object_ ==  NULL) {
		cerr << "Error image load: " << IMG_GetError() << endl;
		cout << path << endl;
	}
	return p_object_ != NULL;
}
//Render ra man hinh
void BaseObject::Render(SDL_Renderer* des, const SDL_Rect* clip) {
	SDL_Rect renderquad = { rec_.x, rec_.y, rec_.w, rec_.h };
	SDL_RenderCopy(des, p_object_, clip, &renderquad);
}
//Giai phong
void BaseObject::Free() {
	if (p_object_ != NULL) {
		SDL_DestroyTexture(p_object_);
		p_object_ = NULL;
		rec_.w = 0;
		rec_.h = 0;
	}
}

TextObject::TextObject() {
	text_color_.r = 255;
	text_color_.g = 255;
	text_color_.b = 255;
	texture_ = NULL;
}
void TextObject::SetColor(const int& num) {
	if (num == RED_TEXT) {
		SDL_Color color = { 255, 0, 0 };
		text_color_ = color;
	}
	else if (num == WHITE_TEXT) {
		SDL_Color color = { 255,255,255 };
		text_color_ = color;
	}
	else {
		SDL_Color color = { 0,0,0 };
		text_color_ = color;
	}
}
bool TextObject::LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen) {
	SDL_Surface* text_surface = TTF_RenderText_Solid(font, this->_text.c_str(), text_color_);
	if (text_surface) {
		texture_ = SDL_CreateTextureFromSurface(screen, text_surface);
		widthText = text_surface->w;
		heightText = text_surface->h;
		SDL_FreeSurface(text_surface);
	}
	return texture_ != NULL;
}
void TextObject::RenderText(SDL_Renderer* screen, int xp, int yp, SDL_Rect* clip, double Angle, SDL_Point* center, SDL_RendererFlip flip) {
	SDL_Rect renderQuad = { xp,yp,widthText,heightText };
	if (clip != NULL) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(screen, texture_, clip, &renderQuad, Angle, center, flip);
}
TextObject::~TextObject(){}