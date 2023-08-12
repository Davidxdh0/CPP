#include <fstream>
#include <iostream>
#include <vector>
#include <unistd.h>

// void	leaks()
// {
// 	system("leaks -q sed");
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

std::string changefile(std::string line, const std::string &s1, const std::string &s2)
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
	std::string	*array;
	int			index;

	if (argc != 4 || !strcmp(argv[1], "") || strlen(argv[2]) <= 0)
	{
		std::cout << "I DID NOT CHANGE THE FILE" << std::endl;
		return 1;
	}
	array = arguments_string(argv);
	if (array == NULL)
		return 1;
	printArray(array); 

	std::ifstream file(array[0]);
    if (file.is_open()){
        std::string line;
        while (std::getline(file, line))
            index++;
        file.close();
    }

	std::string* changedfile = new std::string[index]; 
	index = 0;
	std::ifstream file(array[0]);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
            changedfile[index] = changefile(line, array[1], array[2]);
            index++;
        }
		file.close();
        std::ofstream outputFile("Output");
        if (!outputFile.is_open()) 
		{
            std::cout << "Failed to open file: Output"  << std::endl;
            return 1;
        }
        for (int i = 0; i < changedfile.size(); ++i) 
			outputFile << changedfile[i] << std::endl;
        outputFile.close();
	}
	else
	{
		std::cout << "Failed to open file: " << array[0] << std::endl;
		return 1;
	}
	delete[] array;
	// //atexit(leaks);
	return (0);
}

// #!/bin/bash

// sentences=(
// "Take time to work, it is the price of success."
// "Take time to think, it is the source of power."
// "Take time to play, it is the secret of perpetual youth."
// "Take time to read, it is the foundation of wisdom."
// "Take time to worship, it is the highway to reverence."
// "Take time to be friendly, it is the road to happiness."
// "Take time to dream, it is hitching your wagon to a star."
// "Take time to love and be loved, it is the privilege of the gods."
// "Take time to look around; it is too short a day to be selfish."
// "Take time to laugh; it is the music of the soul.")

// file_name="loser"

// # Write sentences to the file
// if [ ! -s "$file_name" ]; then
// 	for sentence in "${sentences[@]}"; do
// 		echo "$sentence" >> "$file_name"
// 	done
// fi
