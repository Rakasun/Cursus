/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:06:37 by yfang             #+#    #+#             */
/*   Updated: 2024/10/10 16:17:30 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

Cure::Cure(void) : AMateria("cure") {
    _type = "cure";
}

Cure::Cure(const Cure &other) : AMateria() {
    if (this != &other)
        _type = other.getType();
}

Cure    &Cure::operator=(const Cure &other) {
    if (this != &other)
        _type = other.getType();
    return *this;
}

Cure::~Cure(void) {}

AMateria    *Cure::clone(void) const {
    return new Cure();
}

void    Cure::use(ICharacter &target) {
    std::cout  << GREEN << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}
