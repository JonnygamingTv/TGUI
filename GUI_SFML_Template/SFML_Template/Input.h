#pragma once
#include <TGUI/TGUI.hpp>
class Input
{
public:
	Input(int x = 0, int y = 0, int yLength = 50, int yHeight = 10, std::string cont = "JonHosting");
	void isPass(bool p = false);
	void setTextSize(int s);

	tgui::EditBox::Ptr get();
	
private:
	void init(int x = 0, int y = 0, int yLength = 50, int yHeight = 10, std::string cont = "JonHosting");
	
	tgui::EditBox::Ptr edit = tgui::EditBox::create();
	//tgui::TextArea::Ptr txt = tgui::TextArea::create();
};

