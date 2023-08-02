#include "Form.hpp"

Form::Form() :_nameForm("Default"), _signed(0),  _gradeSign(150), _gradeExecute(150){
	std::cout << "Contructed Form: Default"<< std::endl;
}

Form::Form(const std::string name, int gradeSign, int gradeExecute) : _nameForm(name), _signed(0), _gradeSign(gradeSign), _gradeExecute(gradeExecute){
	std::cout << "Contructed Form: " << this->_nameForm << std::endl;
}

Form::Form( const Form& other) : _nameForm(other._nameForm), _signed(0), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute){
	std::cout << "Copy constructor called Form" << std::endl;
}

Form& Form::operator=(const Form& other){
	std::cout << "Copy assignment called Form: " << _nameForm << std::endl;
    if (this == &other)
        return *this;
    _signed = other._signed;
    return *this;
}

Form::~Form(){
	std::cout << "Decontructed Form: " << _nameForm << std::endl;
}

std::ostream& operator<<(std::ostream &out, const Form &c) {
	out << "nameForm: " << c.getNameForm() << " gradeSign: " << c.getGradeSign() << "gradeExecute: " << c.getGradeExecute() << "bool Signed: " << c.getSigned() << std::endl;
    return out;
}

const std::string Form::getNameForm(void) const{
	return _nameForm;
}

int Form::getGradeSign(void) const{
	return _gradeSign;
}

int Form::getGradeExecute(void) const{
	return _gradeExecute;
}

int Form::getSigned(void) const{
	return _signed;
}

void Form::setSigned(void){
	_signed = 1;
}

const char *Form::GradeTooHighException::what() const throw(){
    return "Form is too high";
}

const char *Form::GradeTooLowException::what() const throw(){
    return "Form is too low";
}

// bool Form::checkGrade(int grade) const{
// 	if (TESTS == 1)
// 		std::cout << "checkGrade " << grade << std::endl;
// 	try {
// 		if (grade < 1)
// 			throw Form::GradeTooHighException();
// 		else if ( grade > 150)
// 			throw Form::GradeTooLowException();
// 		return (1);
// 	}
// 	catch (const Form::GradeTooHighException& e) {
//     	std::cout << e.what() << std::endl;
// 	}
// 	catch (const Form::GradeTooLowException& e) {
//     	std::cout << e.what() << std::endl;
// 	}
// 	return (0);
// }
