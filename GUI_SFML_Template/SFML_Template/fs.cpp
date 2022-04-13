#include "fs.h"
#pragma directive

fs::fs(char* filename)
{
	if (sizeof(filename) > 0) {
		this->fn = filename;
		init();
	}
}

char* fs::read(char* filename) // reads a file and return its contents
{
	if (sizeof(filename) == 0)filename = this->fn;
	errno_t err = 1;
	err = fopen_s(&(this->f), filename, "r"); // opens the file in read-mode
	if (err!=0) { // if there was an error the function returns empty char array
		return {};
	}
	else {
		int c;
		int i = 0;
		fseek(this->f, 0L, SEEK_END);
		const int size = ftell(this->f) +1;
		rewind(this->f);
		char* arr = new char[size]; // create a char array the size of the file
		while(fgetc(this->f) >> c){//while ((c = fgetc(this->f)) != EOF) {
			putchar(c);
			arr[i] = c; // adds character from the file to the array
			i++;
		}
		//for (int i = 0; i < size; i++)arr[i] = fgetc(this->f);
		if (ferror(this->f)) {
			puts("!!READ ERRORii");
		}
		else if (feof(this->f)) {
			puts("EOF Reached");
		}
		close(); // close file after reading
		return arr; // return with the content
	}
	return {};
}


bool fs::exists(char* filename) // check if a file exist
{
	if (sizeof(filename) == 0)filename = this->fn;
	FILE* file;
	if ((fopen_s(&file, filename, "r")) == 0) {
		fclose(file);
		return true;
	}
	return false;
}
bool fs::exists(const char* filename) // check if a file exist
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
	FILE* _ = _popen("cd %appdata%\nmkdir "+ *filename, "r");
	
	_pclose(_);
}
void fs::mkdir(const char* filename) // create a directory / folder in the path named filename
{
	_wmkdir(filename);
}

void fs::write(char* data, char* filename)
{
	if (sizeof(filename) == 0)filename = this->fn;
	errno_t err = 1;
	err = fopen_s(&this->f,this->fn, "w");
	if (err == 0) { // no error
		fputs(data, this->f); // write data to file
		close();
	}
	else {

	}
}
void fs::append(char* data, char* filename) // writes new data to file at the bottom of the file content
{
	if (sizeof(filename) == 0)filename = this->fn;
	errno_t err = 1;
	err = fopen_s(&this->f,this->fn, "a");
	if (err == 0) { // no err
		fputs(data, this->f); // write data to file
		close();
	}
}

void fs::close()
{
	fclose((this->f));
}

void fs::init()
{
	
}
