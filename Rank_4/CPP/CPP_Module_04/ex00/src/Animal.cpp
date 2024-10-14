/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:46:27 by yfang             #+#    #+#             */
/*   Updated: 2024/10/03 16:19:26 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal(void) : _type("") {
    std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
    std::cout << "Animal copy constructor called." << std::endl;
}

Animal  &Animal::operator=(const Animal &other) {
    if (this != &other)
        this->_type = other._type;
    std::cout << "Animal assignment operator called" << std::endl;
    return *this;
}
Animal::~Animal(void) {
    std::cout << "Animal destructor called" << std::endl;
}

void    Animal::makeSound(void) const {
    std::cout << "speliarmus" << std::endl;
}

std::string Animal::getType(void) const {
    return _type;
}
