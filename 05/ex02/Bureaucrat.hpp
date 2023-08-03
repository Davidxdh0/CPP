#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
#define TESTS 0

class AForm;
class Bureaucrat {
	private:
		std::string const	_name;
		int 				_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat( const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string 	getName(void) const;
		int 				getGrade(void) const;
		int 				setGrade(int i);
		void 				doIncrement();
		void 				doDecrement();
		void				signForm(AForm &formobj);
		void				executeForm(AForm const & form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &c);
#endif
