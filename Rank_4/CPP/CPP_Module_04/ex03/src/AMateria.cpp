/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:31 by yfang             #+#    #+#             */
/*   Updated: 2024/10/10 14:54:32 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

AMateria::AMateria(void) {}

AMateria::AMateria(const std::string &type) : _type(type) {}

AMateria::AMateria(const AMateria &other) {
    if (this != &other)
        *this = other;
}

AMateria    &AMateria::operator=(const AMateria &other) {
    if (this != &other)
        _type = other.getType();
    return *this;
}

AMateria::~AMateria(void) {}

const std::string   &AMateria::getType(void) const {
    return _type;
}
