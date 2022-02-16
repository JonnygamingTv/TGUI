#include "Btn.h"


Btn::Btn(int x,int y,int yLength,int yHeight, std::string cont)
{
	init(x,y,yLength,yHeight,cont);
}

tgui::Button::Ptr Btn::get()
{
	return this->button;
}

void Btn::setColor(sf::Color background, sf::Color background_hover, sf::Color background_click)
{
	this->button->getRenderer()->setBackgroundColor(background);
	this->button->getRenderer()->setBackgroundColorHover(background_hover);
	this->button->getRenderer()->setBackgroundColorDown(background_click);
}

void Btn::setTextColor(sf::Color color)
{
	this->button->getRenderer()->setTextColor(color);
}

void Btn::setText(char* str)
{
	this->button->setText(str);
}
void Btn::setText(const char* str)
{
	this->button->setText(str);
}
void Btn::setTextSize(int s)
{
	this->button->setTextSize(s);
}
void Btn::setText(tgui::String str)
{
	this->button->setText(str);
}

void Btn::setPos(tgui::Layout x, tgui::Layout y) {
	this->button->setPosition(x, y);
}

void Btn::destroy()
{
	this->button = tgui::Button::create();
}

void Btn::init(int x, int y,int yl, int yh, std::string cont)
{
	this->button->setSize(yl,yh);
	this->button->setPosition(x, y);
	this->button->setText(cont);


	/* NOT USED ---- Test code
	tgui::RendererData data = tgui::RendererData();
	std::shared_ptr<tgui::RendererData> g = std::shared_ptr<tgui::RendererData>();
	std::shared_ptr<tgui::RendererData> gg = g->create();
	this->button->setRenderer(g);*/
}
