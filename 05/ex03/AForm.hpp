#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#define TESTS 0

class Bureaucrat;

class AForm {
	private:
		const std::string 	_nameForm;
		bool				_signed;
		const int 			_gradeSign;
		const int 			_gradeExecute;
	public:
		AForm();
		AForm(const std::string name, int gradeSign, int gradeExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string 	getNameForm(void) const;
		int		 			getGradeSign(void) const;
		int		 			getGradeExecute(void) const;
		int 				getSigned(void) const;

		void 				setGradeSigned(int i);
		virtual void 		setSigned(void) = 0;
		virtual	void		execute(Bureaucrat const & executor) const = 0;
		void 				setSigneds(void);
		void				beSigned(Bureaucrat &obj);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const AForm &c);
#endif
