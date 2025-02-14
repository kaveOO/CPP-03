/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 07:43:36 by albillie          #+#    #+#             */
/*   Updated: 2025/02/13 09:00:56 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructor(s) & Destructor(s)
ScavTrap::ScavTrap() : ClapTrap("albillie")
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap name constructor has been called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor has been called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &assign)
{
	ClapTrap::operator=(assign);
	std::cout << "Scav Trap copy assigment operator called" << std::endl;
	return (*this);
}

// Game Functions
void ScavTrap::guardGuate()
{
	std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
}


void ScavTrap::attack(const std::string &target)
{
	if (getHitPoints() <= 0)
	{
		std::cout << "ScavTrap " << getName() << " is already dead and not able to attack" << std::endl;
	}
	else if (getEnergyPoints() <= 0)
	{
		std::cout << "ScavTrap " << getName() << " is out of energy points and not able to attack" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

std::ostream &operator<<(std::ostream &out, const ScavTrap &ScavTrap)
{
	out << "ScavTrap " << ScavTrap.getName()
		<< " now have " << ScavTrap.getHitPoints()
		<< " hit points, " << ScavTrap.getEnergyPoints()
		<< " energy points and " << ScavTrap.getAttackDamage()
		<< " attack damage" << std::endl;
	return (out);
}
