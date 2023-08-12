#include "Base.hpp"

Base * generate(void){
	std::random_device rd;
	std::mt19937 rng(rd()); 
	std::uniform_int_distribution<int> distribution(0, 2);
	int valuerng = distribution(rng);
	if (valuerng == 0)
		return new A();
	else if (valuerng == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p){
	try {
		if (dynamic_cast<A*>(p) != nullptr ) 
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B*>(p) != nullptr )
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C*>(p) != nullptr ) 
			std::cout << "C" << std::endl;
	}
	catch(const std::bad_cast&){
		std::cout << "Dynamic cast failed" << std::endl;
	}
	catch(...){
		std::cout << "Dynamic cast failed" << std::endl;
	}
}

void identify(Base& p){
		try {
				A a = dynamic_cast<A&>(p);
				std::cout << "A" << std::endl;
		}
		catch (const std::bad_cast&) {	
			try {
				B b = dynamic_cast<B&>(p);
				std::cout << "B" << std::endl;
			}
			catch (const std::bad_cast&) {	
				try {
					C c = dynamic_cast<C&>(p);
					std::cout << "C" << std::endl;
				}
				catch(const std::bad_cast&){
					std::cout << "Dynamic cast failed" << std::endl;
				}
			}
		}
		catch (...){
			std::cout << "Dynamic cast failed" << std::endl;
		}
}
void	aleaks(void)
{
	system("leaks -q serializer");
}
int main(void) {
	// //atexit(aleaks);
	std::cout << "-----NullPointers-----" << std::endl;
	Base* p = nullptr;
	identify(p);
	identify(*p);
	// delete p;
	std::cout << "-----Pointer&&&-----" << std::endl;
	for (int i = 0; i < 6; i++){
		Base* p = generate();
		identify(p);
		identify(*p);
		if (p != nullptr)
			delete p;
	}
	return 0;
}
