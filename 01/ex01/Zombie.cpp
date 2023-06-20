#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "destructing " << this->_zombiename << std::endl; 
}

void Zombie::announce( void )
{
	std::cout << this->_zombiename << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
