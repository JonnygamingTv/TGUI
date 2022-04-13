#include "ListRecipe.h"

void ListRecipe::setText(char* txt)
{
	this->button->setText(txt);
}

void ListRecipe::setImage(tgui::Texture& texture)
{
	this->img->setImage(texture);
}
