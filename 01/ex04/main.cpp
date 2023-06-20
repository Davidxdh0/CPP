#include <fstream>
#include <iostream>
#include <string>
// void	leaks()
// {
// 	system("leaks -q fight");
// }

std::string	*arguments_string(char *argv[])
{
	int i = 0;
	std::string *array;

	array = new std::string[3];
	while (argv[i + 1])
	{
		array[i] = std::string(argv[i + 1]);
		i++;
	}
	if (array[0].empty())
		return(NULL);
	return (array);
	
}
//write changed lines one to one to other temp file
std::string changefile(std::string line, const std::string &s1, const std::string &s2, int num)
{
    size_t found = 0;
    size_t lengthone = s1.size();
    size_t lengthtwo = s2.size();

    while ((found = line.find(s1)) != std::string::npos)
    {
        line.erase(found, lengthone);
        line.insert(found, s2);
        found += lengthtwo;
    }
	return line;
}

void	printArray(std::string *array)
{
	std::cout << "filename:  " << array[0] << std::endl;
	std::cout << "string s1: " << array[1] << std::endl;
	std::cout << "string s2: " << array[2] << std::endl << std::endl;
}

int main(int argc, char *argv[])
{
	std::string *array;
	int i = 0;
	if (argc != 4)
		return (1);
	if (strlen(argv[2]) <= 0)
		return (1);
	array = arguments_string(argv);
	printArray(array); 
	std::fstream file(array[0], std::ios::trunc);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
			changefile(line, array[1], array[2], i++);
		file.close();
	}
	else
	{
		std::cout << "File not opened - program terminated" << std::endl;
		exit(EXIT_FAILURE);
	}

	// if filename empty exit. 1 empty, replace niets, if 2 empty, replace 1 met ""
	// file openen *name
	// temp file maken
	// line schrijven tot s2 en dan s1 vervangen door s2 en dan verder schrijven.
	// file 1 leeg, alles van temp naar file
	// atexit(leaks);
	return (0);
}
