#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "Contructed PresidentialPardonForm name: " << getNameForm() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other) : AForm(other), _target(other._target){
	std::cout << "Copy constructor called PresidentialPardonForm" << std::endl;
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	std::cout << "Copy assignment called PresidentialPardonForm" << std::endl;
    if (this == &other)
        return *this;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "Decontructed PresidentialPardonForm " << getNameForm() << std::endl;
}

// void PresidentialPardonForm::setSigned(void){
// 	std::cout << getNameForm() << " ";
// 	AForm::setSigned();
// }

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	try {
		if (this->getSigned() == 0)
			throw std::runtime_error("The Form is not signed, can't sign it");
		if (executor.getGrade() > getGradeExecute())
			throw std::runtime_error("The Grade of the Bureaucrat is too low");
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox, made possible by: " << executor.getName() << std::endl;
	}
	catch (const std::exception& e){
		std::cout << e.what() << ". Name: " << executor.getName()  << ", Form name: " << getNameForm() << std::endl;
	}
}