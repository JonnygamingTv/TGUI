#pragma once
#include <TGUI/TGUI.hpp>
class Btn
{
public:
	Btn(int x = 0,int y=0,int yLength=50,int yHeight=10, std::string cont="JonHosting");
	tgui::Button::Ptr get();
	void setColor(sf::Color background,sf::Color background_hover, sf::Color background_click = sf::Color::Transparent);
	void setTextColor(sf::Color color);
	void setText(char* str);
	void setText(const char* str);
	void setText(tgui::String str);
	void setPos(tgui::Layout x, tgui::Layout y);
	void destroy();
private:
	void init(int x, int y,int yl,int yh, std::string cont);
	// variables
	tgui::Button::Ptr button = tgui::Button::create();
};