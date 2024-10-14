/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:52:48 by yfang             #+#    #+#             */
/*   Updated: 2024/10/04 12:04:05 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat(void) : _brain(new Brain()) {
    this->_type = "Cat";
    std::cout << ORANGE << "Cat constructor called." << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), _brain(other._brain->clone()) {
    std::cout << ORANGE << "Cat copy constructor called." << RESET << std::endl;
}

Cat  &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;
        _brain = other._brain->clone();
    }
    std::cout << ORANGE << "Cat assignment operator called" << RESET << std::endl;
    return *this;
}
Cat::~Cat(void) {
    delete _brain;
    std::cout << ORANGE << "Cat destructor called" << RESET << std::endl;
}

void    Cat::makeSound(void) const {
    std::cout << GREEN << "Meow! Meow!" << RESET << std::endl;
}
