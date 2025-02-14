/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 07:43:36 by albillie          #+#    #+#             */
/*   Updated: 2025/02/13 23:25:34 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructor(s) & Destructor(s)
FragTrap::FragTrap() : ClapTrap("albillie")
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap name constructor has been called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &FragTrap) : ClapTrap(FragTrap)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor has been called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &assign)
{
	ClapTrap::operator=(assign);
	std::cout << "FragTrap copy assigment operator called" << std::endl;
	return (*this);
}

// Game Functions
void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << getName() << " requested for high fives !" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (getHitPoints() <= 0)
	{
		std::cout << "FragTrap " << getName() << " is already dead and not able to attack" << std::endl;
	}
	else if (getEnergyPoints() <= 0)
	{
		std::cout << "FragTrap " << getName() << " is out of energy points and not able to attack" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

void FragTrap::takeDamage(const unsigned int amount)
{
	if (getHitPoints() <= 0)
	{
		std::cout << "FragTrap " << getName() << " is already dead and not able to take damage" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << getName() << " take " << amount << " points of damage" << std::endl;
	setHitPoints(getHitPoints() - amount);
	if (getHitPoints() <= 0)
	{
		std::cout << "FragTrap " << getName() << " just died after taking damage " << std::endl;
	}
}

void FragTrap::beRepaired(const unsigned int amount)
{
	if (getHitPoints() <= 0)
	{
		std::cout << "FragTrap " << getName() << " is already dead and not able to get repaired" << std::endl;
	}
	else if (getEnergyPoints() <= 0)
	{
		std::cout << "FragTrap " << getName() << " is out of energy points and not able to repair himself" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << getName() << " just repaired himself and gained " << amount << " hit points" << std::endl;
		setHitPoints(getHitPoints() + amount);
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

std::ostream &operator<<(std::ostream &out, const FragTrap &FragTrap)
{
	out << "FragTrap " << FragTrap.getName()
		<< " now have " << FragTrap.getHitPoints()
		<< " hit points, " << FragTrap.getEnergyPoints()
		<< " energy points and " << FragTrap.getAttackDamage()
		<< " attack damage" << std::endl;
	return (out);
}
