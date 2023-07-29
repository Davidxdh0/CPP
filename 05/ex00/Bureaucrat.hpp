#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private:
		std::string const	_name;
		int 				_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat( const Bureaucrat& old);
		Bureaucrat& operator=(const Bureaucrat& old);
		~Bureaucrat();
		// getName();
		// getGrade();
		// increment;
		// decrement;
		// If the grade is out of range, both of them will throw the same exceptions as the constructor.
}
//You will implement an overload of the insertion («) operator
std::ostream& operator<<(std::ostream& out, const Bureaucrat& c);
#endif