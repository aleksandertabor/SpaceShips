#ifndef CsvFiles_h
#define CsvFiles_h
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class Files
{
	std::string f_name;
	char s_char;
	std::string file_name;
	char separator_char;

public:
	std::vector <std::vector<std::string>> matrix;
	std::vector <std::string> row;
	std::string line;
	std::string cell;

	Files(std::string f_name, char s_char);
	void load();
	void show();
	void save();
	void overwrite();
};

#endif