/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:08:52 by albillie          #+#    #+#             */
/*   Updated: 2025/02/14 01:46:33 by kaveo            ###   ########.fr       */
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
		DiamondTrap(std::string name);
		using ScavTrap::attack;
		void whoAmI();
};

std::ostream &operator<<(std::ostream &out, const DiamondTrap &DiamondTrap);

#endif
