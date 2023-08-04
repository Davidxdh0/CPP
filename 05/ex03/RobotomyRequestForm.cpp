#include "RobotomyRequestForm.hpp"
#include <random>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "Contructed RobotomyRequestForm name: " << getNameForm() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other) : AForm(other), _target(other._target){
	std::cout << "Copy constructor called RobotomyRequestForm" << std::endl;
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	std::cout << "Copy assignment called RobotomyRequestForm" << std::endl;
    if (this == &other)
        return *this;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "Decontructed RobotomyRequestForm " << getNameForm() << std::endl;
}

// void RobotomyRequestForm::setSigned(void){
// 	std::cout << getNameForm() << " ";
// 	AForm::setSigned();
// }

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	
	try {
		if (this->getSigned() == 0)
			throw std::runtime_error("The Form is not signed, can't sign it");
		if (executor.getGrade() > getGradeExecute())
			throw std::runtime_error("The Grade of the Bureaucrat is too low");
		std::random_device rd;
		std::mt19937 rng(rd()); 
		std::uniform_int_distribution<int> distribution(0, 99);
		std::cout << "Drilling boem boem boem with " << executor.getName() << " result: ";
		if (distribution(rng) > 49) 
			std::cout << _target << " has been robotomized successfully" << std::endl;
		else
			std::cout << getNameForm() << " has been failed" << std::endl;
	}
	catch (const std::exception& e){
		std::cout << e.what() << ". Name: " << executor.getName() << ", Form name: " << getNameForm() << std::endl;
	}
	
}