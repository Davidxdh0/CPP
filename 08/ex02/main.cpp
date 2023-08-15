#include "MutantStack.hpp"

// void	leaks()
// {
// 	system("leaks -q Mutant");
// }

int main()
{
	// atexit(leaks);
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	MutantStack<int> mstackcpy(mstack);
	mstack.push(737);
	MutantStack<int> mstackcpyass;
	mstackcpyass = mstack;
	mstack.push(0);
	std::cout << "copy contructor and assign" << std::endl;
{
	MutantStack<int>::iterator begin = mstackcpy.begin();
	MutantStack<int>::iterator end = mstackcpy.end();
	for (;begin < end; begin++){
		std::cout << *begin << " ";
	}
	std::cout << std::endl;
}
{
	MutantStack<int>::iterator begin = mstackcpyass.begin();
	MutantStack<int>::iterator end = mstackcpyass.end();
	for (;begin < end; begin++){
		std::cout << *begin << " ";
	}
	std::cout << std::endl;
}
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout  << std::endl;
	std::stack<int> s(mstack);	
	return 0;
}