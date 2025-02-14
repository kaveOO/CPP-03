/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:34:00 by albillie          #+#    #+#             */
/*   Updated: 2025/02/14 00:46:19 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructor(s) & Destructor(s)
DiamondTrap::DiamondTrap() : ClapTrap("Default _clap_name"), name("Default")
{
	std::cout << "DiamondTrap, default constructor has been called" << std::endl;
	DiamondTrap::setHitPoints(FragTrap::getHitPoints());
	DiamondTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
	DiamondTrap::setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap &DiamondTrap)
{
	std::cout << "DiamondTrap copy constructor has been called" << std::endl;
	this->name = DiamondTrap.getName();
	DiamondTrap::setHitPoints(DiamondTrap.getHitPoints());
	DiamondTrap::setEnergyPoints(DiamondTrap.getEnergyPoints());
	DiamondTrap::setAttackDamage(DiamondTrap.getAttackDamage());
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &assign)
{
	std::cout << "DiamondTrap assignment operator has been called" << std::endl;
	this->name = assign.getName();
	DiamondTrap::setHitPoints(assign.getHitPoints());
	DiamondTrap::setEnergyPoints(assign.getEnergyPoints());
	DiamondTrap::setAttackDamage(assign.getAttackDamage());
	return (*this);
}

DiamondTrap::DiamondTrap(std::string Name) : name(Name)
{
	std::cout << "DiamondTrap, string constructor has been called" << std::endl;
	DiamondTrap::setHitPoints(DiamondTrap::getHitPoints());
	DiamondTrap::setEnergyPoints(DiamondTrap::getEnergyPoints());
	DiamondTrap::setAttackDamage(DiamondTrap::getAttackDamage());
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap has been destroyed !" << std::endl;
}

// Game Functions
void DiamondTrap::takeDamage(const unsigned int amount)
{
	if (getHitPoints() <= 0)
	{
		std::cout << "DiamondTrap " << getName() << " is already dead and not able to take damage" << std::endl;
		return ;
	}
	std::cout << "DiamondTrap " << getName() << " take " << amount << " points of damage" << std::endl;
	setHitPoints(getHitPoints() - amount);
	if (getHitPoints() <= 0)
	{
		std::cout << "DiamondTrap " << getName() << " just died after taking damage " << std::endl;
	}
}

void DiamondTrap::beRepaired(const unsigned int amount)
{
	if (getHitPoints() <= 0)
	{
		std::cout << "DiamondTrap " << getName() << " is already dead and not able to get repaired" << std::endl;
	}
	else if (getEnergyPoints() <= 0)
	{
		std::cout << "DiamondTrap " << getName() << " is out of energy points and not able to repair himself" << std::endl;
	}
	else
	{
		std::cout << "DiamondTrap " << getName() << " just repaired himself and gained " << amount << " hit points" << std::endl;
		setHitPoints(getHitPoints() + amount);
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

void DiamondTrap::whoAmI()
{
	std::cout << this->name << " and " << ClapTrap::getName() << std::endl;
}

std::ostream &operator<<(std::ostream &out, const DiamondTrap &DiamondTrap)
{
	out << "DiamondTrap " << DiamondTrap.getName()
		<< " now have " << DiamondTrap.getHitPoints()
		<< " hit points, " << DiamondTrap.getEnergyPoints()
		<< " energy points and " << DiamondTrap.getAttackDamage()
		<< " attack damage" << std::endl;
	return (out);
}
