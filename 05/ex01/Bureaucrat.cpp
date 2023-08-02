#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :_name("Default"), _grade(150){
	std::cout << "Contructed Bureaucrat: Default"<< std::endl;
	if (TESTS == 1)
		std::cout << "name: " << _name << " grade: " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name){
	try {
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if ( grade > 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade = grade;
		std::cout << "Contructed Bureaucrat: " << _name << std::endl;
		if (TESTS == 1)
			std::cout << "name: " << _name << " grade: " << _grade << std::endl;
	}
 	catch (const Bureaucrat::GradeTooHighException& e) {
    	std::cout << e.what() << std::endl;
		this->_grade = 1;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
    	std::cout << e.what() << std::endl;
		this->_grade = 150;
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat& other) : _name(other._name), _grade(other._grade){
	std::cout << "Copy constructor called Bureaucrat" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	std::cout << "Copy assignment called Bureaucrat: " << _name << std::endl;
    if (this == &other)
        return *this;
    _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Decontructed Bureaucrat: " << _name << std::endl;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &c) {
    out << c.getName() << ", bureaucrat grade " << c.getGrade();
    return out;
}

const std::string Bureaucrat::getName(void) const{
	return _name;
}

int Bureaucrat::getGrade(void) const{
	return _grade;
}

void Bureaucrat::doIncrement(){
	if (TESTS == 1)
		std::cout << "doIncrement " << _grade << std::endl;
	try {
		if (_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		_grade--;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
    	std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::doDecrement(){
	if (TESTS == 1)
		std::cout << "do Decrement" << _grade << std::endl;
	try {
		if (_grade >= 150)
			throw Bureaucrat::GradeTooLowException();;
		_grade++;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
    	std::cout << e.what() << std::endl;
	}
}

int Bureaucrat::setGrade(int grade){
	if (TESTS == 1)
		std::cout << "setGrade " << grade << std::endl;
	try {
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if ( grade > 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade = grade;
		return _grade;
	}
 	catch (const Bureaucrat::GradeTooHighException& e) {
    	std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
    	std::cout << e.what() << std::endl;
	}
	return (_grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade is too low";
}

const char *Bureaucrat::FormTooLowException::what() const throw(){
    return "Form is already signed";
}

void Bureaucrat::signForm(Form &form){
	// try {
	// 	if (grade < 1)
	// 		throw Bureaucrat::GradeTooHighException();
	// 	else if ( grade > 150)
	// 		throw Bureaucrat::GradeTooLowException();
	// 	return (1);
	// }
	// catch (const Bureaucrat::GradeTooHighException& e) {
    // 	std::cout << e.what() << std::endl;
	// }
	// catch (const Bureaucrat::GradeTooLowException& e) {
    // 	std::cout << e.what() << std::endl;
	// }
}
// bool Bureaucrat::checkGrade(int grade) const{
// 	if (TESTS == 1)
// 		std::cout << "checkGrade " << grade << std::endl;
// 	try {
// 		if (grade < 1)
// 			throw Bureaucrat::GradeTooHighException();
// 		else if ( grade > 150)
// 			throw Bureaucrat::GradeTooLowException();
// 		return (1);
// 	}
// 	catch (const Bureaucrat::GradeTooHighException& e) {
//     	std::cout << e.what() << std::endl;
// 	}
// 	catch (const Bureaucrat::GradeTooLowException& e) {
//     	std::cout << e.what() << std::endl;
// 	}
// 	return (0);
// }
