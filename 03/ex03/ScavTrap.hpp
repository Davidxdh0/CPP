#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

#include "Debug.hpp"

class ScavTrap : public virtual ClapTrap {
	private:
        std::string _name;
	public:
		ScavTrap( void );
		ScavTrap(std::string name);
		~ScavTrap( void );
		void guardGate( void );
};

#endif
