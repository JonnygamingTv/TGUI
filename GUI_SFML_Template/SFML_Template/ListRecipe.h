#pragma once
#include <TGUI/TGUI.hpp>
class ListRecipe
{
public:
	void setText(char* txt);
	void setImage(tgui::Texture& texture);
private:
	tgui::BitmapButton::Ptr img = tgui::BitmapButton::create();
	tgui::Button::Ptr button = tgui::Button::create();
};

