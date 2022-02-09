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
	errno_t err;
	err = fopen_s(&this->f, filename, "r");
	if (!this->f) {
		close();
		return 0;
	}
	else {
		int c;
		
		char* arr; int i = 0;
		while ((c = fgetc(this->f)) != EOF) {
			putchar(c);
			//arr[i] = c;
			i++;
		}
		if (ferror(this->f)) {
			puts("!!READ ERRORii");
		}
		else if (feof(this->f)) {
			puts("EOF Reached");
		}
		close();
		
		return {};
	}
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
	fclose(this->f);
}

void fs::init()
{
	
}
