/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:17:49 by yfang             #+#    #+#             */
/*   Updated: 2024/10/10 16:12:01 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

Ice::Ice(void) : AMateria("ice") {
    _type = "ice";
}

Ice::Ice(const Ice &other) : AMateria() {
    if (this != &other)
        *this = other;
}

Ice &Ice::operator=(const Ice &other) {
    if (this != &other)
        this->_type = other.getType();
    return *this;
}

Ice::~Ice(void) {}

AMateria *Ice::clone(void) const {
    return new Ice();
}

void Ice::use(ICharacter &target) {
    std::cout << CYAN << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
