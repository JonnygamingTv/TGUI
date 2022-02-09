#include "Btn.h"


Btn::Btn(int x,int y,int yLength,int yHeight, std::string cont)
{
	init(x,y,yLength,yHeight,cont);
}

tgui::Button::Ptr Btn::get()
{
	return this->button;
}

void Btn::init(int x, int y,int yl, int yh, std::string cont)
{
	this->button->setSize(yl,yh);
	this->button->setPosition(x, y);
	this->button->setText(cont);
}
