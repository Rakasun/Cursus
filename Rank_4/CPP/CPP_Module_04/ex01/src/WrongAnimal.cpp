/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:31:36 by yfang             #+#    #+#             */
/*   Updated: 2024/10/03 16:31:36 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("") {
    std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
    std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal  &WrongAnimal::operator=(const WrongAnimal &other) {
    if (this != &other)
        this->_type = other._type;
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    return *this;
}
WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void    WrongAnimal::makeSound(void) const {
    std::cout << "abadakadabra" << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return _type;
}
