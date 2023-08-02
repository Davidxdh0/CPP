#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#define TESTS 0

class Bureaucrat;

class Form {
	private:
		const std::string 	_nameForm;
		bool				_signed;
		const int 			_gradeSign;
		const int 			_gradeExecute;
	public:
		Form();
		Form(const std::string name, int gradeSign, int gradeExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string 	getNameForm(void) const;
		int		 			getGradeSign(void) const;
		int		 			getGradeExecute(void) const;
		int 				getSigned(void) const;

		void 				setGradeSigned(int i);
		void 				setSigned(void);
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

std::ostream& operator<<(std::ostream &out, const Form &c);
#endif
