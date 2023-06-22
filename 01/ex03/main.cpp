#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

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
		club.setType("bigger club 5 damage");
		bob.attack();
	}
	{
		Weapon club = Weapon("tiny club 1 damage");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("baby"); 
		jim.attack();
	}
	// atexit(leaks);
return (0);
}
