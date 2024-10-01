/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:13:55 by yfang             #+#    #+#             */
/*   Updated: 2024/09/27 13:30:20 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

int main(void) {
    DiamondTrap	protagonist("Tarnished");

	protagonist.takeDamage(9);
	protagonist.beRepaired(10);
	protagonist.takeDamage(1);
	protagonist.guardGate();
	protagonist.highFivesGuys();
	protagonist.whoAmI();
	protagonist.attack("Maliketh");
	DiamondTrap _2 = protagonist;
}
