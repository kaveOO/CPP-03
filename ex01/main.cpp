/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 08:56:36 by albillie          #+#    #+#             */
/*   Updated: 2025/02/13 09:00:09 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap clapTrap("Goblin's King");
	clapTrap.attack("gbruscan");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(5);

	std::cout << std::endl;
	std::cout << clapTrap << std::endl;

	ClapTrap clapTroup;
	clapTroup.takeDamage(15);
	clapTroup.takeDamage(15000);

	std::cout << std::endl;

	ScavTrap thomas("thomiannnnnnnnnn");
	thomas.attack("jbergos");
	thomas.takeDamage(99);
	thomas.beRepaired(34);
	thomas.guardGuate();
	std::cout << thomas << std::endl;

	return 0;
}
