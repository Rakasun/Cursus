/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:46:27 by yfang             #+#    #+#             */
/*   Updated: 2024/10/03 16:19:26 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

AAnimal::AAnimal(void) : _type("") {
    std::cout << "AAnimal constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type) {
    std::cout << "AAnimal copy constructor called." << std::endl;
}

AAnimal  &AAnimal::operator=(const AAnimal &other) {
    if (this != &other)
        this->_type = other._type;
    std::cout << "AAnimal assignment operator called" << std::endl;
    return *this;
}
AAnimal::~AAnimal(void) {
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType(void) const {
    return _type;
}
