#include "Input.h"

Input::Input(int x, int y, int yLength, int yHeight, std::string cont)
{
	init(x,y,yLength,yHeight,cont);
}

void Input::isPass(bool p)
{

}

void Input::setTextSize(int s)
{
	this->edit->setTextSize(s);
}

tgui::EditBox::Ptr Input::get()
{
	return this->edit;
}

void Input::init(int x, int y, int yLength, int yHeight, std::string cont)
{
	this->edit->setPosition(x, y);
	this->edit->setSize(yLength, yHeight);
	this->edit->setDefaultText(cont);
}
