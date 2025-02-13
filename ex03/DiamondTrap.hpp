/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:08:52 by albillie          #+#    #+#             */
/*   Updated: 2025/02/13 20:05:04 by albillie         ###   ########.fr       */
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
		DiamondTrap();
		DiamondTrap(const DiamondTrap &DiamondTrap);
		DiamondTrap(const std::string name);
		DiamondTrap &operator=(const DiamondTrap &assign);
		~DiamondTrap();
		std::string getName() const;
		void whoAmI();
};

#endif
