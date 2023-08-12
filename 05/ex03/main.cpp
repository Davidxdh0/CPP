#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void checkleaks(void){
	system("leaks -q intern");
}

int main (void)
{
	//atexit(checkleaks);
	Intern someRandomIntern;
	
	AForm* rob = someRandomIntern.makeForm("Robot", "One");
	AForm* pres = someRandomIntern.makeForm("Presidential", "Three");
	AForm* shrub = someRandomIntern.makeForm("Shrubbery", "Three");
	AForm* Notexist = someRandomIntern.makeForm("Pres", "Babe");
	std::cout << Notexist << std::endl;
	Bureaucrat david("David", 1);
	rob->beSigned(david);
	pres->beSigned(david);
	shrub->beSigned(david);
	
	david.executeForm(*rob);
	david.executeForm(*pres);
	david.executeForm(*shrub);
	std::cout << "----------------" << std::endl;
	// No->beSigned(david);
	// No->setGradeSigned(5);
	// No->setSigned();
	// std::cout	<< __func__	<< __LINE__	<<std::endl;
	// david.executeForm(*Notexist);
	// david.signForm(*Notexist);
	std::cout << "----------------" << std::endl;
	delete rob;
	delete pres;
	delete shrub;
	// Bureaucrat david("David", 1);
	// // Bureaucrat david("David", 150);
	// ShrubberyCreationForm B("Find");
	// PresidentialPardonForm 	p("President");
	// RobotomyRequestForm		r("Robot");
	// david.executeForm(B);
	// B.setSigned();
	// david.executeForm(B);
	// david.executeForm(p);
	// std::cout << std::endl;
	// for (int i = 0; i < 10; i++)
	// 	david.executeForm(r);
	// std::cout << std::endl;
	// Bureaucrat david("David", 1);
	// Bureaucrat def;
	// Bureaucrat davidlow("Davidlow", 150);
	// AForm A("A", 1, 1);
	// AForm B("B", 1, 1);
	// AForm C = B;
	// AForm D;
	// D = B;
	// std::cout << A;
	// std::cout << B;
	// std::cout << C;
	// std::cout << D;
	// B.beSigned(david);
	// B.beSigned(def);
	// std::cout << B;
	// B.beSigned(davidlow);
	// std::cout << B;
	// std::cout << B.getNameForm() << " = name " << B.getGradeSign() << " = gradetosign " << B.getGradeExecute() << " = gradetoexecute " << B.getSigned() << " = signed" << std::endl;
	// B.setSigned();
	// std::cout << B;
	// B.setGradeSigned(5);
	// std::cout << B;
	// B.setGradeSigned(0);
	// std::cout << B;
	// davidlow.signForm(B);
	// std::cout << B;
	// david.signForm(B);
	// std::cout << B;

	// Bureaucrat defa;
	// Bureaucrat david("David", 1);
	// Bureaucrat bentoolow("bentoolow", -1);
	// Bureaucrat bentoohigh("bentoohigh", 151);
	// std::cout << bentoohigh << std::endl;
	// std::cout << "-------------------------------" << std::endl;
	// Bureaucrat twindavid = david;
	// Bureaucrat Monster("Monster", 5);
	// Monster = david;
	// std::cout << Monster << std::endl;
	// std::cout << david << std::endl;
	// std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;
	// std::cout << "name: (twin)" << twindavid.getName() << " grade: " << twindavid.getGrade()  << std::endl;
	// david.doDecrement();
	// std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;
	// std::cout << "name: (twin)" << twindavid.getName() << " grade: " << twindavid.getGrade()  << std::endl;
	// david.doIncrement();
	// std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;
	// david.setGrade(-1);
	// std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;
	// david.setGrade(10);
	// std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;
	// david.setGrade(151);
	// std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;


	// try {
    //     Bureaucrat defa;
    // }
    // catch (const Bureaucrat::GradeTooHighException& e) {
    //     std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
    // }
    // catch (const Bureaucrat::GradeTooLowException& e) {
    //     std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
    // }
	// try {
    //     Bureaucrat david("david", 1);
    // }
    // catch (const Bureaucrat::GradeTooHighException& e) {
    //     std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
    // }
    // catch (const Bureaucrat::GradeTooLowException& e) {
    //     std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
    // }
	// try {
    //     Bureaucrat empty("", 1);
    // }
    // catch (const Bureaucrat::GradeTooHighException& e) {
    //     std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
    // }
    // catch (const Bureaucrat::GradeTooLowException& e) {
    //     std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
    // }
	// try {
    //     Bureaucrat bentoohigh("bentoohigh", 151);
    // }
    // catch (const Bureaucrat::GradeTooHighException& e) {
    //     std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
    // }
    // catch (const Bureaucrat::GradeTooLowException& e) {
    //     std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
    // }
	// try {
    //     Bureaucrat bentoolow("bentoolow", -1); 
    // }
    // catch (const Bureaucrat::GradeTooHighException& e) {
    //     std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
    // }
    // catch (const Bureaucrat::GradeTooLowException& e) {
    //     std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
    // }
	// try {
    //     Bureaucrat bbentoohigh("ben", 0);
    // }
    // catch (const Bureaucrat::GradeTooHighException& e) {
    //     std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
    // }
    // catch (const Bureaucrat::GradeTooLowException& e) {
    //     std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
    // }
	// try {
	// 	Bureaucrat david("david", 1);
    //     Bureaucrat twindavid = david;
    // }
    // catch (const Bureaucrat::GradeTooHighException& e) {
    //     std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
    // }
    // catch (const Bureaucrat::GradeTooLowException& e) {
    //     std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
    // }
	// try {
    //     Bureaucrat Monster("Monster", 5);
    // }
    // catch (const Bureaucrat::GradeTooHighException& e) {
    //     std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
    // }
    // catch (const Bureaucrat::GradeTooLowException& e) {
    //     std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
    // }
	// try {
	// 	Bureaucrat Monster("Monster", 5);
	// 	Bureaucrat david("OtherMonster", 10);
    //     Monster = david;
    // }
    // catch (const Bureaucrat::GradeTooHighException& e) {
    //     std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
    // }
    // catch (const Bureaucrat::GradeTooLowException& e) {
    //     std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
    // }


	// std::cout << "-------------------------------" << std::endl;
	// std::cout << Monster << std::endl;
	// std::cout << david << std::endl;
	// std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;
	// std::cout << "name: (twin)" << twindavid.getName() << " grade: " << twindavid.getGrade()  << std::endl;
	// david.doDecrement();
	// std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;
	// std::cout << "name: (twin)" << twindavid.getName() << " grade: " << twindavid.getGrade()  << std::endl;
	// david.doIncrement();
	// std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;
	// david.setGrade(-1);
	// std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;
	// david.setGrade(10);
	// std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;
	// david.setGrade(151);
	// std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;
	return (0);
}