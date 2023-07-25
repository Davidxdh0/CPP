#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include "Debug.hpp"

#include <iostream>

class 	ClapTrap{
	private:
		std::string			_name;
		int					_hitpoints;
		int 				_energypoints;
		int 				_attackdamage;
		static ClapTrap* 	allClapTraps[]; 

	public:
		ClapTrap( void );
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& old);
		ClapTrap 	&operator=(const ClapTrap &old);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		showHitpoint( void );
		void 		setHitpoints( int const raw );
		void 		setName(const std::string& name);
		void 		setEnergypoints( int const raw );
		void 		setAttackdamage( int const raw );
		int 		getHitpoints() const ;
		std::string getName() const ;
		int 		getEnergypoints() const ;
		int			getAttackdamage() const ;
		static void	addClap(ClapTrap* clap, int i);
		ClapTrap* 	findTarget(const std::string& target);
		~ClapTrap( void );
};

#endif
