#include "Bureaucrat.hpp"
#include "Form.hpp"

int main (void)
{
	Bureaucrat david("David", 1);
	Bureaucrat def;
	Bureaucrat davidlow("Davidlow", 150);
	Form A("A", 1, 1);
	Form B("B", 1, 1);
	Form C = B;
	Form D;
	D = B;
	std::cout << A;
	std::cout << B;
	std::cout << C;
	std::cout << D;
	B.beSigned(david);
	B.beSigned(def);
	std::cout << B;
	B.beSigned(davidlow);
	std::cout << B;
	std::cout << B.getNameForm() << " = Name, " << B.getGradeSign() << " = gradetosign, ";
	std::cout << B.getGradeExecute() << " = gradetoexecute, " << B.getSigned() << " = signed" << std::endl;
	B.setSigned();
	std::cout << B;
	B.setGradeSigned(5);
	std::cout << B;
	B.setGradeSigned(0);
	std::cout << B;
	davidlow.signForm(B);
	std::cout << B;
	david.signForm(B);
	std::cout << B;

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