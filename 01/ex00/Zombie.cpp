#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	_zombiename = name;
}

Zombie::~Zombie(void)
{
	std::cout << "destructing " << this->_zombiename << std::endl; 
}

void Zombie::announce( void )
{
	std::cout << this->_zombiename << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
