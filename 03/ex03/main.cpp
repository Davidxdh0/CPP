#include "DiamondTrap.hpp"

#include <iostream>

int main ( void )
{

	DiamondTrap Diamond("Monster");
	Diamond.whoAmI();
	Diamond.attack("Baby");
	Diamond.showHitpoint();
	Diamond.beRepaired(10);
	Diamond.showHitpoint();
	Diamond.takeDamage(50);
	Diamond.showHitpoint();
}

