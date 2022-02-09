#pragma once
#include <TGUI/TGUI.hpp>
class Input
{
public:
	Input(int x = 0, int y = 0, int yLength = 50, int yHeight = 10, std::string cont = "JonHosting");

private:
	void init(int x = 0, int y = 0, int yLength = 50, int yHeight = 10, std::string cont = "JonHosting");
	tgui::TextArea::Ptr txt = tgui::TextArea::create();

};

