#include "HumanA.hpp"
#include "HumanB.hpp"

// void	leaks()
// {
// 	system("leaks -q fight");
// }

int main()
{
	{
		Weapon club = Weapon("Small club 1 damage");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("bigger club 5 damage"); // Changed cause reference
		bob.attack();
		Weapon mace = Weapon("club with %infinite% damage - Bob killed EVERYONE.");
		bob.setWeapon(mace);
		bob.attack();
	}
	{
		Weapon club = Weapon("tiny club 1 damage");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("Can't change this one 0 damage"); // POINTER
		jim.attack();
		Weapon mace = Weapon("small mace 2 damage");
		jim.setWeapon(mace);
		jim.attack();
	}
	// atexit(leaks);
return (0);
}