#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class 	ClapTrap
{
	private:
		std::string	_name;
		int			_hitpoints;
		int 		_energypoints;
		int 		_attackdamage;

// Name, which is passed as parameter to a constructor
// • Hit points (10), represent the health of the ClapTrap
// • Energy points (10)
// • Attack damage (0)
	public:
		ClapTrap(std::string name);
		~ClapTrap( void );
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

};

#endif
