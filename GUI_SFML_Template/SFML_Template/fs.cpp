#include "fs.h"

fs::fs(char* filename)
{
	if (strlen(filename) > 0) {
		this->fn = filename;
		init();
	}
}

char* fs::read(char* filename)
{
	if (strlen(filename) == 0)filename = this->fn;
	this->f = std::fopen(this->fn,"r");
	if (!this->f) {
		close();
		return 0;
	}
	else {
		int c;
		char* arr{}; int i = 0;
		while ((c = std::fgetc(this->f)) != EOF) {
			std::putchar(c);
			arr[i] = c;
			i++;
		}
		if (std::ferror(this->f)) {
			std::puts("!!READ ERRORii");
		}
		else if (std::feof(this->f)) {
			std::puts("EOF Reached");
		}
		close();
		return arr;
	}
}
void fs::write(char* data, char* filename)
{
	if (strlen(filename) == 0)filename = this->fn;
	this->f = std::fopen(this->fn, "r+");
	close();
}
void fs::append(char* data, char* filename)
{
	if (strlen(filename) == 0)filename = this->fn;
	this->f = std::fopen(this->fn, "a");
	close();
}

void fs::close()
{
	std::fclose(this->f);
}

void fs::init()
{
	
}
