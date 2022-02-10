#include "fs.h"

fs::fs(char* filename)
{
	if (sizeof(filename) > 0) {
		this->fn = filename;
		init();
	}
}

char* fs::read(char* filename)
{
	if (sizeof(filename) == 0)filename = this->fn;
	errno_t err = 1;
	err = fopen_s(&(this->f), filename, "r");
	if (err!=0) {
		return {};
	}
	else {
		int c;
		int i = 0;
		char* arr={};
		while ((c = fgetc(this->f)) != EOF) {
			putchar(c);
			arr[i] = c;
			i++;
		}
		if (ferror(this->f)) {
			puts("!!READ ERRORii");
		}
		else if (feof(this->f)) {
			puts("EOF Reached");
		}
		close();
		
		return arr;
	}
	return {};
}


void fs::write(char* data, char* filename)
{
	if (sizeof(filename) == 0)filename = this->fn;
	fopen_s(&this->f,this->fn, "r+");
	close();
}
void fs::append(char* data, char* filename)
{
	if (sizeof(filename) == 0)filename = this->fn;
	fopen_s(&this->f,this->fn, "a");
	close();
}

void fs::close()
{
	fclose((this->f));
}

void fs::init()
{
	
}
