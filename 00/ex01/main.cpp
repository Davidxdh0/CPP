#include "PhoneBook.hpp"

int	main(void)
{
	std::string line;
	int			contacts;
	size_t		i;
	PhoneBook	phonebook;	
	
	i = 0;
	while (1)
	{
		line = "";
		std::cout << "Type add, search or exit." << std::endl;
		if(!std::getline(std::cin, line))
		{
			std::cout << "EOF detected" << std::endl;
			exit(1);
		}
		for (i = 0; i < line.length(); i++)
			line[i] = std::toupper(line[i]);
		if (line == "ADD")
		{
			if (contacts == 8)
				contacts = 0;
			phonebook.addContact(contacts);
			contacts++;
		}
		if (line == "SEARCH")
		{
			if (contacts == 0)
			{
				std::cout << "No contacts" << std::endl;
				continue;
			}
			else
				phonebook.searchContact();
		}
		if (line == "EXIT")
			exit(0);
	}
	return (0);
}