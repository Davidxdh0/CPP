#ifndef SHRUBERY_HPP
#define SHRUBERY_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#define TESTS 0

class Bureaucrat;
class ShrubberyCreationForm : public AForm {
	private:
		const std::string _target;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const std::string name, int grade);
		ShrubberyCreationForm( const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		void	doExecute() const ;
		void	setSigned(void);
		void	execute(Bureaucrat const & executor) const;


};

#endif
