/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 02:12:55 by albillie          #+#    #+#             */
/*   Updated: 2025/02/13 06:39:20 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Canonical functions
ClapTrap::ClapTrap() : Name("albillie"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Default construct has been called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor has been called" << std::endl;
	this->Name = copy.Name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &assign)
{
	std::cout << "Copy assigment operator called" << std::endl;
	this->Name = assign.Name;
	this->hitPoints = assign.hitPoints;
	this->energyPoints = assign.energyPoints;
	this->attackDamage = assign.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor has been called" << std::endl;
}

// Getters
std::string ClapTrap::getName() const
{
	return (this->Name);
}

int ClapTrap::getHitPoints() const
{
	return (this->hitPoints);
}

int ClapTrap::getEnergyPoints() const
{
	return (this->energyPoints);
}

int ClapTrap::getAttackDamage() const
{
	return (this->attackDamage);
}

// Setters
void ClapTrap::setName(const std::string newName)
{
	this->Name = newName;
}

void ClapTrap::setHitPoints(const int newHitPoints)
{
	this->hitPoints = newHitPoints;
}

void ClapTrap::setEnergyPoints(const int newEnergyPoints)
{
	this->energyPoints = newEnergyPoints;
}

void ClapTrap::setAttackDamage(const int newAttackDamage)
{
	this->attackDamage = newAttackDamage;
}

// Other functions
ClapTrap::ClapTrap(std::string name) : Name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Name constructor has been called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (getHitPoints() <= 0)
	{
		std::cout << this->Name << " is already dead and not able to attack" << std::endl;
	}
	else if (getEnergyPoints() <= 0)
	{
		std::cout << this->Name << " is out of energy points and not able to attack" << std::endl;
	}
	else
	{
		std::cout << this->Name << " attacks " << target << ", causing " << this->attackDamage << " points of damage" << std::endl;
		this->energyPoints--;
	}
}

void ClapTrap::takeDamage(const unsigned int amount)
{
	if (getHitPoints() <= 0)
	{
		std::cout << this->Name << " is already dead and not able to take damage" << std::endl;
		return ;
	}
	std::cout << this->Name << " take " << amount << " points of damage" << std::endl;
	setHitPoints(getHitPoints() - amount);
	if (getHitPoints() <= 0)
	{
		std::cout << this->Name << " just died after taking damage " << std::endl;
	}
}

void ClapTrap::beRepaired(const unsigned int amount)
{
	if (getHitPoints() <= 0)
	{
		std::cout << this->Name << " is already dead and not able to get repaired" << std::endl;
	}
	else if (getEnergyPoints() <= 0)
	{
		std::cout << this->Name << " is out of energy points and not able to repair himself" << std::endl;
	}
	else
	{
		std::cout << this->Name << " just repaired himself and gained " << amount << " hit points" << std::endl;
		this->energyPoints--;
	}
}

std::ostream &operator<<(std::ostream &out, const ClapTrap &ClapTrap)
{
	out << ClapTrap.getName()
		<< " now have " << ClapTrap.getHitPoints()
		<< " hit points, " << ClapTrap.getEnergyPoints()
		<< " energy points and " << ClapTrap.getAttackDamage()
		<< " attack damage" << std::endl;
	return (out);
}
