/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:13:55 by yfang             #+#    #+#             */
/*   Updated: 2024/09/19 15:30:17 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int main(void) {
    ClapTrap voldemord("voldemord");
	ClapTrap Harry_Popoter("Harry_Popoter");

	voldemord.attack("Harry_Popoter");
	voldemord.attack("Harry_Popoter");
	voldemord.attack("Harry_Popoter");
	voldemord.attack("Harry_Popoter");
	voldemord.attack("Harry_Popoter");
	voldemord.attack("Harry_Popoter");
	voldemord.attack("Harry_Popoter");
	voldemord.attack("Harry_Popoter");
	voldemord.attack("Harry_Popoter");
	voldemord.attack("Harry_Popoter");
	voldemord.attack("Harry_Popoter");
	Harry_Popoter.takeDamage(9);
	Harry_Popoter.beRepaired(9);
	Harry_Popoter.takeDamage(10);
	Harry_Popoter.beRepaired(9);
}
