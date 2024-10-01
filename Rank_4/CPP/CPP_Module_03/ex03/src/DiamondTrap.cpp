/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:14:00 by yfang             #+#    #+#             */
/*   Updated: 2024/09/27 11:59:23 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

void    DiamondTrap::whoAmI(void) {
    if (_health > 0)
        std::cout << MAGENTA << "I am " << _name << " and my Clap is " << ClapTrap::_name << RESET << std::endl;
    else
        std::cout << RED << "DiamnodTrap " << _name << " id dead" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "Diamond destructor called"<< std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy) {
    if (this != &copy) {
        _name = copy._name;
        _health = copy._health;
        _energy = copy._energy;
        _damage = copy._damage;
    }
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
    *this = copy;
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name) {
    _name = name;
    ClapTrap::_name = name + "_clap_name";
    _health = FragTrap::_health;
    _energy = ScavTrap::_energy;
    _damage = FragTrap::_damage;
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(void): ClapTrap("DiamondTrap_clap_name"), ScavTrap(), FragTrap() {
    _name = "DiamondTrap";
    _health = FragTrap::_health;
    _energy = ScavTrap::_energy;
    _damage = FragTrap::_damage;
    std::cout << "Default DiamontTrap constructor called" << std::endl;
}
