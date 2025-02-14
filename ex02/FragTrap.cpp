/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 07:43:36 by albillie          #+#    #+#             */
/*   Updated: 2025/02/13 10:53:24 by albillie         ###   ########.fr       */
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
	std::cout << "Scav Trap copy assigment operator called" << std::endl;
	return (*this);
}

// Game Functions
void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << getName() << " requested for high fives !" << std::endl;
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
