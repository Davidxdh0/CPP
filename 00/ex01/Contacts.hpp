#ifndef Contacts_H
# define Contacts_H

# include <iostream>

//phonebook contact
class Contacts
{
    public:
	Contacts(void);
	~Contacts(void);

	void setFirstname(std::string firstname);
	void setLastname(std::string lastname);
	void setNickname(std::string nickname);
	void setNumber(std::string number);
	void setDarkestsecret(std::string darkestsecret);

	std::string	getFirst(void);
	std::string	getLast(void);
	std::string	getNick(void);
	std::string	getNumber(void);
	std::string	getDarkest(void);
	
	private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string number;
	std::string	darkestsecret;
};

#endif