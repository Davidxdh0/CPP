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

cout << "-------Finds:-------" << endl;
{
	auto v = easyfind(vectorContainer, 5);
	cout << *v << endl;
	auto b = easyfind(listContainer, 5);
	cout << *b << endl;
	auto c = easyfind(dequeContainer, 5);
	cout << *c << endl;
	auto d = easyfind(setContainer, 5);
	cout << *d << endl;	
}
cout << "--------Not found:---------" << endl;
	try{
		// empty containers segmentation fault, same behaviour.
		// auto test1 = find(vectorEmpty.begin(), vectorEmpty.end(), 8);
		// cout << "empty test  = " << *test1 << endl;
		auto ve = easyfind(vectorEmpty, 8);
		cout << "empty container = " << *ve << endl;
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
	}
	
	cout << endl;
	auto test = find(vectorContainer.begin(), vectorContainer.end(), 8);
	cout << *test << endl;
	auto v = easyfind(vectorContainer, 8);
	cout << *v << endl;

	cout << endl;
	auto b1 = find(listContainer.begin(), listContainer.end(), 8);
	cout << *b1 << endl;
	auto b = easyfind(listContainer, 8);
	cout << *b << endl;
	cout << endl;
	auto c1 = find(dequeContainer.begin(), dequeContainer.end(), 8);
	cout  << *c1 << endl;
	auto c = easyfind(dequeContainer, 8);
	cout << *c << endl;
	cout << endl;
	auto d1 = find(setContainer.begin(), setContainer.end(), 8);
	cout << *d1 << endl;
	auto d = easyfind(setContainer, 8);
	cout << *d << endl;	
	cout << endl;
	return (1);
}