/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:27:52 by yfang             #+#    #+#             */
/*   Updated: 2024/10/10 17:55:24 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _count(0) {
    for (int i = 0; i < 4; i++)
        _space[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) : _count(0) {
    for (int i = 0; i < 4; i++) {
        if (other._space[i] != NULL)
            learnMateria(other._space[i]->clone());
        else
            _space[i] = NULL;
    }
}

MateriaSource   &MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other) {
        _count = other._count;
        for (int i = 0; i < 4; i++) {
            delete _space[i];
            if (other._space[i] != NULL)
                learnMateria(other._space[i]->clone());
            else
                _space[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource(void) {
    for (int i = 0; i < 4; i++)
        delete _space[i];
}

void    MateriaSource::learnMateria(AMateria *m) {
    if (_count <= 4 && m) {
        _space[_count] = m;
        _count++;
    } else {
        if (m)
            delete m;
        std::cout << RED << "ERROR: Space complete or materia is NULL." << RESET << std::endl;
    }
}

AMateria    *MateriaSource::createMateria(const std::string &type) {
    for (int i = 0; i < _count; i++)
        if (_space[i]->getType() == type)
            return _space[i]->clone();
    return 0;
}
