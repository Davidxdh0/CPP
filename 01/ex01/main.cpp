#include "Zombie.hpp"

// void	leaks()
// {
// 	system("leaks -q zombie");
// }

int	main()
{
	int i = 0;
	Zombie* HORDE;

	HORDE = zombieHorde(3, "Frankenstein");
	if (HORDE == NULL)
		return (0);
	while (i < 3)
		HORDE[i++].announce();
	delete[] HORDE;
	// atexit(leaks);
	return (0);
}
