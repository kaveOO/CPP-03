/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:08:52 by albillie          #+#    #+#             */
/*   Updated: 2025/02/14 00:18:37 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "FragTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;
	public:
		// Canonical Functions
		DiamondTrap();
		DiamondTrap(const DiamondTrap &DiamondTrap);
		DiamondTrap &operator=(const DiamondTrap &assign);
		~DiamondTrap();
		// Other Functions
		DiamondTrap(const std::string name);
		void takeDamage(const unsigned int amount);
		void beRepaired(const unsigned int amount);
		using ScavTrap::attack;
		void whoAmI();
};

std::ostream &operator<<(std::ostream &out, const DiamondTrap &DiamondTrap);

#endif
