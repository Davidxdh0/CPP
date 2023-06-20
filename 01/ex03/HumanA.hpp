#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon&		weapon;
		std::string name;
	
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);
		void	attack(void);
		void 	setWeapon(Weapon weapon);
		void 	setName(std::string name);

		Weapon getWeapon(void);
		std::string	getName(void);
};

#endif
