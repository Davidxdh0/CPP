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
		if (dynamic_cast<A*>(p)) 
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B*>(p))
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C*>(p)) 
			std::cout << "C" << std::endl;
	}
	catch(const std::bad_cast&){
		std::cout << "Dynamic cast failed" << std::endl;
	}
}

void identify(Base& p){
		try {
			static_cast<void>(dynamic_cast<A&>(p));
			std::cout << "A" <<  std::endl;
		}
		catch (const std::bad_cast&) {	
			try {
				static_cast<void>(dynamic_cast<B&>(p));
				std::cout << "B" << std::endl;
			}
			catch (const std::bad_cast&) {	
				try {
					static_cast<void>(dynamic_cast<C&>(p));
					std::cout << "C" << std::endl;
				}
				catch(const std::bad_cast&){
					std::cout << "Dynamic cast failed" << std::endl;
				}
			}
		}
}

int main(void) {
	std::cout << "-----Pointers-----" << std::endl;
	for (int i = 0; i < 6; i++){
		Base* p = generate();
		identify(p);
		delete p;
	}
	std::cout << "-----References-----" << std::endl;
	for (int i = 0; i < 6; i++){
		Base* p = generate();
		identify(*p);
		delete p;
	}
	return 1;
}
