#include "easyfind.hpp"

int main(void) {
	
    vector<int> 		vectorContainer;
	vector<int> 		vectorEmpty;
	list<int> 			listContainer;
	deque<int> 		dequeContainer;
	set<int> 			setContainer;
	
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
	cout << v << endl;
	auto b = easyfind(listContainer, 5);
	cout << b << endl;
	auto c = easyfind(dequeContainer, 5);
	cout << c << endl;
	auto d = easyfind(setContainer, 5);
	cout << d << endl;	
}
	//empty container
	auto ve = easyfind(vectorEmpty, 8);
	cout << ve << endl;
	auto v = easyfind(vectorContainer, 8);
	cout << v << endl;
	auto b = easyfind(listContainer, 8);
	cout << b << endl;
	auto c = easyfind(dequeContainer, 8);
	cout << c << endl;
	auto d = easyfind(setContainer, 8);
	cout << d << endl;	
	return (1);
}