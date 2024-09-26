/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:13:55 by yfang             #+#    #+#             */
/*   Updated: 2024/09/26 13:38:03 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

int main(void) {
    ClapTrap trap ("Voldemore");
	ScavTrap trop ("Harry_Popoter");

	trap.attack("Hermaiony");
	trop.attack("Hermaiony");
	trap.takeDamage(8);
	trop.takeDamage(8);
	trap.beRepaired(2);
	trop.beRepaired(2);
	trop.guardGate();
	for (int i = 0; i < 10; i++)
	{
		trap.attack("Hermaiony");
		trop.attack("Hermaiony");
	}
	trap.takeDamage(6);
	trop.takeDamage(6);
	trap.takeDamage(6);
	trop.takeDamage(6);
	trap.beRepaired(3);
	trop.beRepaired(3);
}
