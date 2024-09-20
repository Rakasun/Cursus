/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:04:56 by yfang             #+#    #+#             */
/*   Updated: 2024/09/19 15:28:23 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

void    ClapTrap::beRepaired(unsigned int amount) {
    if (this->_health > 0 && this->_energy > 0) {
        this->_health += amount;
        this->_energy--;
        std::cout << GREEN << "ClapTrap " << this->_name << ", reparing " << amount << " points!" << RESET << std::endl;
    } else if (this->_health == 0)
        std::cout << RED << "ClapTrap " << this->_name << " can't be healed, he is dead." << RESET << std::endl;
    else
        std::cout << RED << "ClapTrap " << this->_name << " don't have energy to be healed." << RESET << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (this->_health > 0) {
        this->_health -= amount;
        std::cout << ORANGE << "ClapTrap " << this->_name << ", taking " << amount << " points of damage!" << RESET << std::endl;
    } else {
        this->_health = 0;
        std::cout << ORANGE << "ClapTrap " << this->_name << ", taking " << amount << " points of damage!" << RESET << std::endl;
        std::cout << RED << "ClapTrap " << this->_name << " has dead." << RESET << std::endl;
    }
}

void    ClapTrap::attack(const std::string &target) {
    if (this->_health > 0 && this->_energy > 0) {
        this->_energy--;
        std::cout << YELLOW << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << RESET << std::endl;
    } else if (this->_health == 0)
        std::cout << RED << "ClapTrap " << this->_name << " can't attacks, he is dead." << RESET << std::endl;
    else
        std::cout << RED << "ClapTrap " << this->_name << " don't have energy to attack." << RESET << std::endl;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "Destructor called"<< std::endl;
}

ClapTrap    &ClapTrap::operator=(const ClapTrap &copy) {
    if (this != &copy) {
        this->_name = copy._name;
        this->_health = copy._health;
        this->_energy = copy._energy;
        this->_damage = copy._damage;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
    this->_name = copy._name;
    this->_health = copy._health;
    this->_energy = copy._energy;
    this->_damage = copy._damage;
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _health(10), _energy(10), _damage(0) {
    std::cout << "Default constructor called" << std::endl;
}
