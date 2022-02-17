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
		fseek(this->f, 0L, SEEK_END);
		const int size = ftell(this->f) +1;
		rewind(this->f);
		char* arr = new char[size];
		while ((c = fgetc(this->f)) != EOF) {
			putchar(c);
			arr[i] = c;
			i++;
		}
		//for (int i = 0; i < size; i++)arr[i] = fgetc(this->f);
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


bool fs::exists(char* filename)
{
	if (sizeof(filename) == 0)filename = this->fn;
	FILE* file;
	if ((fopen_s(&file, filename, "r")) == 0) {
		fclose(file);
		return true;
	}
	return false;
}
bool fs::exists(const char* filename)
{
	if (sizeof(filename) == 0)filename = this->fn;
	FILE* file;
	if ((fopen_s(&file,filename, "r")) == 0) {
		fclose(file);
		return true;
	}
	return false;
}

void fs::mkdir(char* filename)
{
	
}

void fs::write(char* data, char* filename)
{
	if (sizeof(filename) == 0)filename = this->fn;
	errno_t err = 1;
	err = fopen_s(&this->f,this->fn, "w");
	if (err == 0) { // no error
		fputs(data, this->f);
		close();
	}
	else {

	}
	close();
}
void fs::append(char* data, char* filename)
{
	if (sizeof(filename) == 0)filename = this->fn;
	errno_t err = 1;
	err = fopen_s(&this->f,this->fn, "a");
	if (err == 0) {
		fputs(data, this->f);
		close();
	}
	close();
}

void fs::close()
{
	fclose((this->f));
}

void fs::init()
{
	
}
