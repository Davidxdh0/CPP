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

	const std::vector<int> 		const_vectorContainer(vectorContainer);
	const std::list<int> 		const_listContainer(listContainer);
	const std::deque<int> 		const_dequeContainer(dequeContainer);
	const std::set<int> 		const_setContainer(setContainer);

std::cout << "-------Finds:-------" << std::endl;
{
	auto v = easyfind(vectorContainer, 5);
	std::cout << *v << std::endl;
	auto b = easyfind(listContainer, 5);
	std::cout << *b << std::endl;
	auto c = easyfind(dequeContainer, 5);
	std::cout << *c << std::endl;
	auto d = easyfind(setContainer, 5);
	std::cout << *d << std::endl;	
}
std::cout << "-------Finds const:-------" << std::endl;
{
	auto v = easyfind(const_vectorContainer, 5);
	std::cout << *v << std::endl;
	auto b = easyfind(const_listContainer, 5);
	std::cout << *b << std::endl;
	auto c = easyfind(const_dequeContainer, 5);
	std::cout << *c << std::endl;
	auto d = easyfind(const_setContainer, 5);
	std::cout << *d << std::endl;	
}
std::cout << "--------Not found:---------" << std::endl;
	// empty containers segmentation fault, same behaviour.
	auto test1 = find(vectorEmpty.begin(), vectorEmpty.end(), 1);
	if (test1 == vectorEmpty.end()) {
		std::cout << "Element not found" << std::endl;
	}
	else
		std::cout << "empty test  = " << *test1 << std::endl;
	auto ve = easyfind(vectorEmpty, 8);
	if (ve == vectorEmpty.end()) {
		std::cout << "Element not found" << std::endl;
	}
	else
		std::cout << "empty test  = " << *ve << std::endl;

	std::cout << std::endl;
	auto test = find(vectorContainer.begin(), vectorContainer.end(), 8);
	std::cout << *test << std::endl;
	auto v = easyfind(vectorContainer, 8);
	std::cout << *v << std::endl;

	std::cout << std::endl;
	auto b1 = find(listContainer.begin(), listContainer.end(), 8);
	std::cout << *b1 << std::endl;
	auto b = easyfind(listContainer, 8);
	std::cout << *b << std::endl;
	std::cout << std::endl;
	
	auto c1 = find(dequeContainer.begin(), dequeContainer.end(), 8);
	std::cout  << *c1 << std::endl;
	auto c = easyfind(dequeContainer, 8);
	std::cout << *c << std::endl;
	std::cout << std::endl;
	
	auto d1 = find(setContainer.begin(), setContainer.end(), 8);
	std::cout << *d1 << std::endl;
	auto d = easyfind(setContainer, 8);
	std::cout << *d << std::endl;	
	std::cout << std::endl;
	return (0);
}