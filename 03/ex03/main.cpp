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
	Diamond.highFivesGuys();
	Diamond.guardGate();
	return 0;
	// ClapTrap clap[3] = { 
	// 					ClapTrap("one"), 
	// 					ClapTrap("two"), 
	// 					ClapTrap("three") };
	// for (int i = 0; i < 3; ++i)
    // 	ClapTrap::addClap(&clap[i], i);
	// clap[0].setAttackdamage(5);
	// clap[0].attack("two");
	// clap[0].attack("two");
	// clap[0].attack("two");
	// clap[0].attack("three");
	// clap[0].attack("lol");
	// clap[1].showHitpoint();
	// clap[2].showHitpoint();
	// for (int i = 0; i < 3; i++)
	// 	clap[0].takeDamage(2);
	// clap[0].showHitpoint();
	// clap[0].beRepaired(1);
	// clap[0].showHitpoint();
    // clap[0].takeDamage(2);
	// clap[0].takeDamage(2);
	// clap[0].takeDamage(2);
	// clap[0].showHitpoint();
	// clap[1].showHitpoint();
	// clap[2].showHitpoint();
	//-------------------------
	// ScavTrap scav("Serena");
	// scav.attack("Mooi");
	// scav.showHitpoint();
	// scav.beRepaired(1);
	// scav.showHitpoint();
	// scav.takeDamage(20);
	// scav.showHitpoint();
	// scav.guardGate();
	//-------------------------
	// FragTrap Frag("Repetitive work");
	// FragTrap Frags;
	// Frag.attack("Target A");
	// Frag.showHitpoint();
	// Frag.beRepaired(1);
	// Frag.showHitpoint();
	// Frag.takeDamage(20);
	// Frag.showHitpoint();
	// Frag.highFivesGuys();
	// Frag.guardGate();
	//-------------------------
}

