/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:52:48 by yfang             #+#    #+#             */
/*   Updated: 2024/10/03 15:57:26 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat(void) {
    this->_type = "Cat";
    std::cout << ORANGE << "Cat constructor called." << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << ORANGE << "Cat copy constructor called." << RESET << std::endl;
}

Cat  &Cat::operator=(const Cat &other) {
    if (this != &other)
        Animal::operator=(other);
    std::cout << ORANGE << "Cat assignment operator called" << RESET << std::endl;
    return *this;
}
Cat::~Cat(void) {
    std::cout << ORANGE << "Cat destructor called" << RESET << std::endl;
}

void    Cat::makeSound(void) const {
    std::cout << GREEN << "Meow! Meow!" << RESET << std::endl;
}
