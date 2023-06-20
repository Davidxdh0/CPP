#ifndef Zombie_HPP
# define Zombie_HPP
#include <iostream>

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void announce( void );

	private:
		std::string	_zombiename;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif