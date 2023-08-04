/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contacts.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 13:28:03 by dyeboa        #+#    #+#                 */
/*   Updated: 2023/06/19 16:21:05 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// ADD: save a new contact

// ◦ If the user enters this command, they are prompted to input the information
// of the new contact one field at a time. Once all the fields have been completed,
// add the contact to the phonebook.
// ◦ The contact fields are: first name, last name, nickname, phone number, and
// darkest secret. A saved contact can’t have empty fields.
Contacts::Contacts(void)
{
	return ;
}
Contacts::~Contacts(void)
{
	return ;
}

void Contacts::setFirstname(std::string firstname)
{
	this->firstname = firstname;
}

void Contacts::setLastname(std::string lastname)
{
	this->lastname = lastname;
}
void Contacts::setNickname(std::string nickname)
{
	this->nickname = nickname;
}
void Contacts::setNumber(std::string number)
{
	this->number = number;
}
void Contacts::setDarkestsecret(std::string darkestsecret)
{
	this->darkestsecret = darkestsecret;
}

std::string	Contacts::getFirst(void)
{
	return (this->firstname);
}

std::string	Contacts::getLast(void)
{
	return (this->lastname);
}

std::string	Contacts::getNick(void)
{
	return (this->nickname);
}

std::string	Contacts::getNumber(void)
{
	return (this->number);
}

std::string	Contacts::getDarkest(void)
{
	return (this->darkestsecret);
}
