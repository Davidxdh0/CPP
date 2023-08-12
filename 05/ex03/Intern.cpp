#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){
	std::cout << "Contructed Intern"<< std::endl;
}

Intern::Intern( const Intern& other) {
	std::cout << "Copy constructor called Intern" << std::endl;
	*this = other;
}

Intern& Intern::operator=(const Intern& other){
	std::cout << "Copy assignment called Intern" << std::endl;
    if (this == &other)
        return *this;
    return *this;
}

Intern::~Intern(){
	std::cout << "Decontructed Intern" << std::endl;
}

AForm* Intern::createRobot(std::string str) {
    return new RobotomyRequestForm(str);
}

AForm* Intern::createPresident(std::string str) {
    return new PresidentialPardonForm(str);
}

AForm* Intern::createShrubbery(std::string str) {
    return new ShrubberyCreationForm(str);
}

AForm*	Intern::makeForm(const std::string nameForm,  std::string str){
	const std::string array[] = {"Robot", "Presidential", "Shrubbery"};
	AForm* (Intern::*forms[])(std::string) = {
												&Intern::createRobot, 
	 											&Intern::createPresident,
	 											&Intern::createShrubbery};
	try {
		for (int i = 0; i < 3; i++){
			if ( nameForm == array[i]){
				std::cout << "Intern creates " << nameForm << " with " << str << std::endl;
				return (this->*forms[i])(str);
			}
			if (i == 2)
				throw std::runtime_error("The intern can't find the form you want to make named: ");
		}
	}
	catch (const std::exception& e){
		std::cout << e.what() << nameForm << std::endl;
	}
	return nullptr;
}

// void Intern::setSigned(AForm* form){
// 		form->setSigned();
// }