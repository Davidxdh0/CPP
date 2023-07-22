#include "ClapTrap.hpp"

#include <iostream>

int main ( void )
{
	ClapTrap clap[3] = { 
						ClapTrap("Clap"), 
						ClapTrap("Trap"), 
						ClapTrap("TheClapClap") };
	for (int i = 0; i < 3; ++i)
    	ClapTrap::addClap(&clap[i], i);

	clap[0].attack("Trap");
	clap[0].attack("TheClapClap");
	clap[0].attack("Problems");
	clap[1].showHitpoint();
	clap[2].showHitpoint();
	for (int i = 0; i < 3; i++)
		clap[0].takeDamage(2);
	clap[0].showHitpoint();
	clap[0].beRepaired(1);
	clap[0].showHitpoint();
    clap[0].takeDamage(2);
	clap[0].takeDamage(2);
	clap[0].takeDamage(2);
	clap[0].showHitpoint();
	clap[1].showHitpoint();
	clap[2].showHitpoint();
}
