#ifndef Zombie_HPP
# define Zombie_HPP
#include <iostream>

class Zombie
{
	public:
		Zombie();
		~Zombie(void);
		void 	announce( void );
		void	setName(std::string name);

	private:
		std::string	_zombiename;
};

Zombie* zombieHorde( int N, std::string name );

#endif