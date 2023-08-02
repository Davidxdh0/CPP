#include "Bureaucrat.hpp"

int main (void)
{
	Bureaucrat defa;
	Bureaucrat david("David", 1);
	Bureaucrat bentoolow("bentoolow", -1);
	Bureaucrat bentoohigh("bentoohigh", 151);
	std::cout << bentoohigh << std::endl;
	std::cout << "-------------------------------" << std::endl;
	Bureaucrat twindavid = david;
	Bureaucrat Monster("Monster", 5);
	Monster = david;
	std::cout << Monster << std::endl;
	std::cout << david << std::endl;
	std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;
	std::cout << "name: (twin)" << twindavid.getName() << " grade: " << twindavid.getGrade()  << std::endl;
	david.doDecrement();
	std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;
	std::cout << "name: (twin)" << twindavid.getName() << " grade: " << twindavid.getGrade()  << std::endl;
	david.doIncrement();
	std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;
	david.setGrade(-1);
	std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;
	david.setGrade(10);
	std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;
	david.setGrade(151);
	std::cout << "name: " << david.getName() << " grade: " << david.getGrade()  << std::endl;


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
	return (1);
}