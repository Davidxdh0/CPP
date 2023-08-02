#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#define TESTS 0

class Form;
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
		void				signForm(Form &formobj);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &c);
#endif
