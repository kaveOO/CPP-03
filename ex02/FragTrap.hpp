/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:40:46 by albillie          #+#    #+#             */
/*   Updated: 2025/02/13 10:47:12 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		// Canonical Form
		FragTrap();
		FragTrap(const FragTrap &FragTrap);
		FragTrap(std::string name);
		FragTrap &operator=(const FragTrap &assign);
		~FragTrap();
		// Game Functions
		void highFivesGuys(void);
};

std::ostream &operator<<(std::ostream &out, const FragTrap &FragTrap);

#endif
