/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 02:11:30 by albillie          #+#    #+#             */
/*   Updated: 2025/02/13 06:44:42 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("Goblin's King");
	clapTrap.attack("gbruscan");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(5);

	std::cout << std::endl;
	std::cout << clapTrap << std::endl;

	ClapTrap clapTroup("damian");
	clapTroup.takeDamage(15);
	clapTroup.takeDamage(15000);
	return 0;
}
