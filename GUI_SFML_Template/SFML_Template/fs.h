#pragma once
#include <stdio.h>
class fs
{
public:
	fs(char* filename = {});
	char* read(char* filename = {});
	//char* read(const char* filename = {});
	bool exists(char* filename = {});
	bool exists(const char* filename = {});
	void mkdir(char* filename = {});
	void write(char* data,char* filename = {});
	void write(const char* data, char* filename = {});
	void append(char* data,char* filename = {});
	void append(const char* data, char* filename = {});
	void close();
private:
	void init();
	FILE *f;
	char* fn = 0;
};

