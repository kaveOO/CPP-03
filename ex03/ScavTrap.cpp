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

void ScavTrap::takeDamage(const unsigned int amount)
{
	if (getHitPoints() <= 0)
	{
		std::cout << "ScavTrap " << getName() << " is already dead and not able to take damage" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << getName() << " take " << amount << " points of damage" << std::endl;
	setHitPoints(getHitPoints() - amount);
	if (getHitPoints() <= 0)
	{
		std::cout << "ScavTrap " << getName() << " just died after taking damage " << std::endl;
	}
}

void ScavTrap::beRepaired(const unsigned int amount)
{
	if (getHitPoints() <= 0)
	{
		std::cout << "ScavTrap " << getName() << " is already dead and not able to get repaired" << std::endl;
	}
	else if (getEnergyPoints() <= 0)
	{
		std::cout << "ScavTrap " << getName() << " is out of energy points and not able to repair himself" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << getName() << " just repaired himself and gained " << amount << " hit points" << std::endl;
		setHitPoints(getHitPoints() + amount);
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
