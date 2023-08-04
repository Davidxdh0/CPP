#ifndef PRESI_HPP
#define PRESI_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define TESTS 0

class Bureaucrat;
class PresidentialPardonForm : public AForm {
	private:
		const std::string _target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const std::string name, int grade);
		PresidentialPardonForm( const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		void	execute(Bureaucrat const & executor) const;


};

#endif
