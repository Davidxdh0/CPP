#include "AForm.hpp"

AForm::AForm() :_nameForm("Default"), _signed(0),  _gradeSign(150), _gradeExecute(150){
	std::cout << "Contructed Form: Default"<< std::endl;
}

AForm::AForm(const std::string name, int gradeSign, int gradeExecute) : _nameForm(name), _signed(0), _gradeSign(gradeSign), _gradeExecute(gradeExecute){
	std::cout << "Contructed Form: " << this->_nameForm << std::endl;
}

AForm::AForm( const AForm& other) : _nameForm(other._nameForm), _signed(0), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute){
	std::cout << "Copy constructor called Form" << std::endl;
}

AForm& AForm::operator=(const AForm& other){
	std::cout << "Copy assignment called Form: " << _nameForm << std::endl;
    if (this == &other)
        return *this;
    _signed = other._signed;
    return *this;
}

AForm::~AForm(){
	std::cout << "Decontructed Form: " << _nameForm << std::endl;
}

std::ostream& operator<<(std::ostream &out, const AForm &c) {
	out << "nameForm: " << c.getNameForm() << " gradeSign: " << c.getGradeSign() << " gradeExecute: " << c.getGradeExecute() << " Signed: " << c.getSigned() << std::endl;
    return out;
}

const std::string AForm::getNameForm(void) const{
	return this->_nameForm;
}

int AForm::getGradeSign(void) const{
	return this->_gradeSign;
}

int AForm::getGradeExecute(void) const{
	return this->_gradeExecute;
}

int AForm::getSigned(void) const{
	return this->_signed;
}

void AForm::setGradeSigned(int i){
	try {
		if (i == 0 || i == 1 ){
			std::cout << "Form signed is set to " << i << std::endl;
			_signed = i;
		}
		else
			throw std::invalid_argument("Not a valid sign value, 0 or 1 please");
	}
	catch(std::invalid_argument &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void AForm::setSigned(void){
	try {
		if (_signed == 0){
			std::cout << "Form is set to signed" << std::endl;
			_signed = 1;
		}
		else
			throw std::invalid_argument("Form was already signe");
		}
	catch(std::invalid_argument &e)
	{
		std::cout << e.what() << std::endl;
			std::cout	<< __func__	<< __LINE__	<<std::endl;

	}
}

const char *AForm::GradeTooHighException::what() const throw(){
    return "Form grade is too high";
}

void	AForm::beSigned(Bureaucrat &obj)
{
	try{
		if (obj.getGrade() > _gradeSign)
			throw AForm::GradeTooHighException();
		if (_signed == 1)
			throw std::invalid_argument("Form was already signed");
		std::cout << "Form signed: " << _nameForm <<  " by: " << obj.getName()<< std::endl;
		_signed = 1;
	}
	catch (const AForm::GradeTooHighException& e) {
		std::cout << e.what() << ", " << obj.getName() << " can't signt it"<<std::endl;
	}
	catch(std::invalid_argument &e)
	{
		std::cout << e.what() << std::endl;
	}
}
