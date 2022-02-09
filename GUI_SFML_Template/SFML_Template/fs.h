#pragma once
#include <stdio.h>
class fs
{
public:
	fs(char* filename = {});
	char* read(char* filename = {});
	void write(char* data,char* filename = {});
	void append(char* data,char* filename = {});
	void close();
private:
	void init();
	FILE *f;
	char* fn = 0;
};

