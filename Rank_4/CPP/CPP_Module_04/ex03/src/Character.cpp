/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:06:19 by yfang             #+#    #+#             */
/*   Updated: 2024/10/16 19:08:34 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

Character::Character(void) : _name(""), _count(0), _trashCount(0) {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
        _trash[i] = NULL;
    }
}

Character::Character(const std::string name) : _name(name), _count(0), _trashCount(0) {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
        _trash[i] = NULL;
    }
}

Character::Character(const Character &other) : _name(other.getName()), _count(0), _trashCount(0) {
    for (int i = 0; i < 4; i++) {
        if (i < other._count)
            equip(other._inventory[i]->clone());
        else
            _inventory[i] = NULL;
        if (i < other._trashCount)
            equip(other._trash[i]->clone());
        else
            _trash[i] = NULL;
    }
}

Character   &Character::operator=(const Character &other) {
    if (this != &other) {
        _name = other.getName();
        _count = other._count;
        _trashCount = other._trashCount;
        for (int i = 0; i < 4; i++) {
            if (_inventory[i] != NULL)
                delete _inventory[i];
            if (i < other._count)
                equip(other._inventory[i]->clone());
            else
                _inventory[i] = NULL;
            if (_trash[i] != NULL)
                delete _trash[i];
            if (i < other._trashCount)
                equip(other._trash[i]->clone());
            else
                _trash[i] = NULL;
        }
    }
    return *this;
}

Character::~Character(void) {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] != NULL)
            delete _inventory[i];
        if (_trash[i] != NULL)
            delete _trash[i];
    }
}

const std::string   &Character::getName(void) const {
    return _name;
}

void    Character::equip(AMateria *m) {
    if (_count < 4 && m) {
        _inventory[_count] = m;
        _count++;
    } else {
        if (m)
            delete m;
        std::cout << RED << "ERROR: Inventory complete or materia is NULL." << RESET << std::endl;
    }
}

void    Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        if (_inventory[idx] != NULL) {
            AMateria    *copy;
            copy = _inventory[idx];
            delete _inventory[idx];
        }
        _inventory[idx] = NULL;
        _count--;
    } else
        std::cout << RED << "ERROR: Out of inventory space." << RESET << std::endl;
}

void    Character::use(int idx, ICharacter &target) {
    if (_inventory[idx] != NULL && (idx >= 0 && idx < 4))
        _inventory[idx]->use(target);
    else
        std::cout << RED << "ERROR: Out of inventory space or not materia stored." << RESET << std::endl;
}
