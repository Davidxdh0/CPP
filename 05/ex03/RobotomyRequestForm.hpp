#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define TESTS 0

class Bureaucrat;
class RobotomyRequestForm : public AForm {
	private:
		const std::string _target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const std::string name, int grade);
		RobotomyRequestForm( const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		void	setSigned(void);
		void	execute(Bureaucrat const & executor) const;


};

#endif
