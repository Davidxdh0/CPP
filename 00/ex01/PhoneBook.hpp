#ifndef Phonebook_HPP
# define Phonebook_HPP
#include "Contacts.hpp"
#include <iostream>

class PhoneBook
{
    public:
	PhoneBook(void); // CPP use the name of the class for constructor
	~PhoneBook(void); // and the name of the class for destructor
	
	void		addContact(int number);
	void		searchContact(void);
	int			getAmount();
	Contacts* 	getContacts();
	static void	printContacts(int amount_of_contacts, Contacts *contacts);

	private:
	Contacts 	contact[8];
    int 		amount;
};

int		inputCheck(std::string line);

#endif