/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:35:48 by yfang             #+#    #+#             */
/*   Updated: 2024/09/26 14:11:56 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

void    FragTrap::highFivesGuys(void) {
    std::cout << CYAN << "High Five!!!" << RESET << std::endl;
}

FragTrap::~FragTrap(void) {
    std::cout << "Destructor called"<< std::endl;
}

FragTrap    &FragTrap::operator=(const FragTrap &copy) {
    if (this != &copy) {
        _name = copy._name;
        _health = copy._health;
        _energy = copy._energy;
        _damage = copy._damage;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy.getName(), 100, 100, 30) {
    std::cout << "Copy constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30) {
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(void): ClapTrap("mohojojo", 100, 100, 30) {
    std::cout << "Default constructor called" << std::endl;
} 
