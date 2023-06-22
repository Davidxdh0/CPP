#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* zombiehorde = new Zombie[N];
	int i = 0;

	if (N <= 0)
		return (NULL);
	while (i < N)
		zombiehorde[i++].setName(name);
	return (zombiehorde);
}

void	Zombie::setName(std::string name)
{
	this->_zombiename = name;
}
