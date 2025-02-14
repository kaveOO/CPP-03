/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:34:00 by albillie          #+#    #+#             */
/*   Updated: 2025/02/14 01:53:37 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructor(s) & Destructor(s)
DiamondTrap::DiamondTrap() : ClapTrap("Default _clap_name"), name("Default")
{
	std::cout << "DiamondTrap, default constructor has been called" << std::endl;
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap &DiamondTrap) : ClapTrap(DiamondTrap), ScavTrap(DiamondTrap), FragTrap(DiamondTrap)
{
	std::cout << "DiamondTrap copy constructor has been called" << std::endl;
	this->attackDamage = DiamondTrap.attackDamage;
	this->energyPoints = DiamondTrap.energyPoints;
	this->hitPoints = DiamondTrap.hitPoints;
	this->name = DiamondTrap.name;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &DiamondTrap)
{
	std::cout << "DiamondTrap assignment operator has been called" << std::endl;
	this->attackDamage = DiamondTrap.attackDamage;
	this->energyPoints = DiamondTrap.energyPoints;
	this->hitPoints = DiamondTrap.hitPoints;
	this->name = DiamondTrap.name;
	return (*this);
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name)
{
	std::cout << "DiamondTrap, string constructor has been called" << std::endl;
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap has been destroyed !" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << this->name << " and " << ClapTrap::name << std::endl;
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
