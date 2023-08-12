#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "Contructed ShrubberyCreationForm name: "  << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other) : AForm(other), _target(other._target){
	std::cout << "Copy constructor called ShrubberyCreationForm" << std::endl;
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	std::cout << "Copy assignment called ShrubberyCreationForm" << std::endl;
    if (this == &other)
        return *this;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "Decontructed ShrubberyCreationForm " << std::endl;
}

void	ShrubberyCreationForm::doExecute(void) const {
	std::ofstream outfile;
	std::string name = _target + "_shrubbery";
	outfile.open(name.c_str(), std::ios::out);
	try {
		if (outfile)
		{
			outfile << "ASCII trees" << std::endl;
			std::cout << "File made with 'ascii trees' inside of it filename: " << _target + "_shrubbery" << std::endl;
			outfile.close();
		}
		else
			throw std::runtime_error("Caught Exeption: ");
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "Failed to open and write to " << _target + "_shrubbery" << std::endl;
	}
}

void ShrubberyCreationForm::setSigned(void){
	std::cout << getNameForm() << " ";
	AForm::setSigned();
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	try {
		if (this->getSigned() == 0)
			throw std::runtime_error("The Form is not signed, can't sign it");
		if (executor.getGrade() > getGradeExecute())
			throw std::runtime_error("The Grade of the Bureaucrat is too low");
		std::cout << "The form " << getNameForm() << " is signed by bureaucrat: " << executor.getName() << std::endl;
		this->doExecute();
		
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << ". Name: " << executor.getName() << std::endl;
	}
}