/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:04:26 by yfang             #+#    #+#             */
/*   Updated: 2024/09/26 14:08:25 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

void    ScavTrap::attack(const std::string &target) {
    if (this->getHealth() > 0 && this->getEnergy() > 0) {
        this->setEnergy(this->getEnergy() - 1);
        std::cout << YELLOW << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getDamage() << " points of damage!" << RESET << std::endl;
    } else if (this->getHealth() == 0)
        std::cout << RED << "ScavTrap " << this->getName() << " can't attacks, he is dead." << RESET << std::endl;
    else
        std::cout << RED << "ScavTrap " << this->getName() << " don't have energy to attack." << RESET << std::endl;
}

void    ScavTrap::guardGate(void) {
    std::cout << CYAN << "ScavTrap is now in Gate keeper mode!" << RESET << std::endl;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "Destructor called"<< std::endl;
}

ScavTrap    &ScavTrap::operator=(const ScavTrap &copy) {
    if (this != &copy) {
        _name = copy._name;
        _health = copy._health;
        _energy = copy._energy;
        _damage = copy._damage;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy.getName(), 100, 50, 20) {
    std::cout << "Copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20) {
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(void): ClapTrap("mohojojo", 100, 50, 20) {
    std::cout << "Default constructor called" << std::endl;
} 
