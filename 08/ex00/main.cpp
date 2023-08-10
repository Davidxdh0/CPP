#include "easyfind.hpp"

int main(void) {
	
    std::vector<int> 		vectorContainer;
	std::vector<int> 		vectorEmpty;
	std::list<int> 			listContainer;
	std::deque<int> 		dequeContainer;
	std::set<int> 			setContainer;
	
	// vector
    vectorContainer.push_back(1);
    vectorContainer.push_back(3);
    vectorContainer.push_back(4);
	vectorContainer.push_back(7);
	vectorContainer.push_back(5);
    // list
    listContainer.push_back(1);
    listContainer.push_back(3);
    listContainer.push_back(5);
    // deque
    dequeContainer.push_back(1);
    dequeContainer.push_back(3);
    dequeContainer.push_back(5);
    // set
    setContainer.insert(3);
    setContainer.insert(1);
    setContainer.insert(5);


{
	auto v = easyfind(vectorContainer, 5);
	std::cout << v << std::endl;
	auto b = easyfind(listContainer, 5);
	std::cout << b << std::endl;
	auto c = easyfind(dequeContainer, 5);
	std::cout << c << std::endl;
	auto d = easyfind(setContainer, 5);
	std::cout << d << std::endl;	
}
	//empty container
	auto ve = easyfind(vectorEmpty, 8);
	std::cout << ve << std::endl;
	auto v = easyfind(vectorContainer, 8);
	std::cout << v << std::endl;
	auto b = easyfind(listContainer, 8);
	std::cout << b << std::endl;
	auto c = easyfind(dequeContainer, 8);
	std::cout << c << std::endl;
	auto d = easyfind(setContainer, 8);
	std::cout << d << std::endl;	
	return (1);
}