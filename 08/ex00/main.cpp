#include "easyfind.hpp"

int main(void) {
	
    std::vector<int> 		vectorContainer;
	std::unordered_set<int> unorderedSetContainer;
	std::list<int> 			listContainer;
	std::deque<int> 		dequeContainer;
	std::set<int> 			setContainer;

	// vector
    vectorContainer.push_back(1);
    vectorContainer.push_back(2);
    vectorContainer.push_back(3);
    // list
    listContainer.push_back(1);
    listContainer.push_back(2);
    listContainer.push_back(3);
    // deque
    dequeContainer.push_back(1);
    dequeContainer.push_back(2);
    dequeContainer.push_back(3);
    // set
    setContainer.insert(1);
    setContainer.insert(2);
    setContainer.insert(3);
    // unordered_set
    unorderedSetContainer.insert(1);
    unorderedSetContainer.insert(2);
    unorderedSetContainer.insert(3);

	easyfind(vectorContainer, 2);
	easyfind(unorderedSetContainer, 2);
	easyfind(listContainer, 2);
	easyfind(dequeContainer, 2);
	easyfind(setContainer, 2);

	easyfind(vectorContainer, 4);
	easyfind(unorderedSetContainer, 4);
	easyfind(listContainer, 4);
	easyfind(dequeContainer, 4);
	easyfind(setContainer, 4);
	return (1);
}