#pragma once
#include<iostream>
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
	std::FILE* f = 0;
	char* fn = 0;
};

