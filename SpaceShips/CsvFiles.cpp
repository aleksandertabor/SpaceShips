#include "CsvFiles.h"

Files::Files(std::string f_name, char s_char)
{
	file_name = f_name;
	separator_char = s_char;
}

void Files::load()
{
	std::ifstream file_load;
	file_load.open(file_name.c_str());

	while (file_load)
	{
		std::getline(file_load, line);
		std::stringstream lineStream(line);
		row.clear();

		while (std::getline(lineStream, cell, separator_char))
			row.push_back(cell);

		if (!row.empty())
			matrix.push_back(row);
	}
}

void Files::show()
{
	for (int i = 0; i<int(matrix.size()); i++)
	{
		for (int j = 0; j<int(matrix[i].size()); j++)
			std::cout << matrix[i][j] << " ";

		std::cout << std::endl;
	}
}

void Files::save()
{
	std::ofstream file_save;

	file_save.open(file_name.c_str());
	for (int i = 0; i<int(matrix.size()); i++)
	{
		for (int j = 0; j<int(matrix[i].size()); j++)
			file_save << matrix[i][j] << std::string(1, separator_char);

		file_save << "\n";
	}
	file_save.close();
}

void Files::overwrite()
{
	std::ofstream file_save;
	file_save.open(file_name.c_str());

	file_save << "1000,1,0,100,100\n";
	file_save << "Ola,ma,kota,100,100\n";
	file_save << "Ola ma kota,1,0,30000,300\n";
	file_save << "4000,1,0,500,500\n";

	/*
	file_save << "1000;1;0;100;100\n";
	file_save << "2000;1;0;30000;300\n";
	file_save << "3000;1;0;500;500\n";
	file_save << "4000;1;0;700;700\n";
	*/

	file_save.close();
}
