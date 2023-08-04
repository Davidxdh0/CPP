#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->amount = 0;
	return ;
}
PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::addContact(int id)
{
	std::string line;
	
	std::cout << "Adding contact" << std::endl;
	while (line.empty())
	{
		std::cout << "first name:" << std::endl;
		if (!std::getline(std::cin, line))
		{
			std::cout << "EOF detected - exiting" << std::endl;
			exit(1);
		}
	}
	this->contact[id].setFirstname(line);
	line.clear(); // = "";
	while (line.empty())
	{
		std::cout << "last name:" << std::endl;
		if (!std::getline(std::cin, line))
		{
			std::cout << "EOF detected - exiting" << std::endl;
			exit(1);
		}
	}
	std::cin.clear();
	this->contact[id].setLastname(line);
	line = "";
	while (line.empty())
	{
		std::cout << "nickname:" << std::endl;
		if (!std::getline(std::cin, line))
		{
			std::cout << "EOF detected - exiting" << std::endl;
			exit(1);
		}
	}
	this->contact[id].setNickname(line);
	line = "";
	while (line.empty())
	{
		std::cout << "number:" << std::endl;
		if (!std::getline(std::cin, line))
		{
			std::cout << "EOF detected - exiting" << std::endl;
			exit(1);
		}
	}
	this->contact[id].setNumber(line);
	line = "";
	while (line.empty())
	{
		std::cout << "darkest secret:" << std::endl;
		if (!std::getline(std::cin, line))
		{
			std::cout << "EOF detected - exiting" << std::endl;
			exit(1);
		}
	}
	this->contact[id].setDarkestsecret(line);
	line = "";
	if (this->amount < 8)
		this->amount++;
}

void	PhoneBook::printContacts(int amount_of_contacts, Contacts* contacts)
{
	int		i;
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;

	i = 0;
	std::cout << "Choose one of the contacts" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	while(i < amount_of_contacts)
	{
		firstname = "";
		lastname = "";
		nickname = "";
		firstname = contacts[i].getFirst();
		lastname = contacts[i].getLast();
		nickname = contacts[i].getNick();
		if (firstname.length() > 10)
			firstname.resize(9);
		if (lastname.length() > 10)
			lastname.resize(9);
		if (nickname.length() > 10)
			nickname.resize(9);
		firstname += '.';
		lastname += '.';
		nickname += '.';
		std::cout.width (10);
		std::cout << i + 1 << "|";
		std::cout.width (10);
		std::cout << firstname << "|";
		std::cout.width (10);
		std::cout << lastname << "|";
		std::cout.width (10);
		std::cout << nickname << std::endl;
		i++;
	}
	std::cout << std::endl;
}

int PhoneBook::getAmount()
{
    return this->amount;
}
Contacts* PhoneBook::getContacts() 
{
        return contact;
}

void PhoneBook::searchContact(void)
{
	int			id;
	std::string	line;
	PhoneBook::printContacts(this->getAmount(), this->getContacts());
	while (1)
	{
		line = "";
		while (line.empty())
		{
			std::cout << "Enter an index number between 1 and " << this->amount << std::endl;
			if (!std::getline(std::cin, line))
			{
				std::cout << "EOF detected - exiting" << std::endl;
				exit(1);
			}
		}
		if (inputCheck(line) == 1)
		{
			id = std::stoi(line);
			if (id > 0 && id <= this->amount)
				break;
		}
	}
	std::cout << "contact id:  	 " << id << std::endl;
	std::cout << "Firstname: 	 " << contact[id - 1].getFirst() << std::endl;
	std::cout << "Lastname:   	 " << contact[id - 1].getLast() << std::endl;
	std::cout << "Nickname:        " << contact[id - 1].getNick() << std::endl;
	std::cout << "Phonenumber:     " << contact[id - 1].getNumber() << std::endl;
	std::cout << "Darksest secret: " << contact[id - 1].getDarkest() << std::endl;
}
int	inputCheck(std::string line)
{
	std::size_t	i;

	i = 0;
	while (i < line.size())
	{
		if (!std::isdigit(line[i]))
		{
			std::cout << "Enter a valid number" << std::endl;
			return (0);
		}
		i++;
	}
	return (1);
}