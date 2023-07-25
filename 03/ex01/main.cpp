#include "ScavTrap.hpp"

#include <iostream>

int main ( void )
{
	ScavTrap scav("Serena");
	ScavTrap a;
	scav.attack("Serenab");
	scav.showHitpoint();
	scav.beRepaired(1);
	scav.takeDamage(20);
	scav.showHitpoint();
	scav.guardGate();
}
