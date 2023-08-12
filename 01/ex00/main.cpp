#include "Zombie.hpp"

// void	leaks()
// {
// 	system("leaks -q zombie");
// }

int	main()
{
	Zombie* Frank;

	Frank = newZombie("Frankenstein");
	Frank->announce();
	randomChump("HELLLOOOOOO");
	delete(Frank);
	// //atexit(leaks);
	return (0);
}