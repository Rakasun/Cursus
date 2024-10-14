/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:49:04 by yfang             #+#    #+#             */
/*   Updated: 2024/10/04 12:03:50 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog(void) : _brain(new Brain()) {
    this->_type = "Dog";
    std::cout << YELLOW << "Dog constructor called." << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), _brain(other._brain->clone()) {
    std::cout << YELLOW << "Dog copy constructor called." << RESET << std::endl;
}

Dog  &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;
        _brain = other._brain->clone();
    }
    std::cout << YELLOW << "Dog assignment operator called" << RESET << std::endl;
    return *this;
}
Dog::~Dog(void) {
    delete _brain;
    std::cout << YELLOW << "Dog destructor called" << RESET << std::endl;
}

void    Dog::makeSound(void) const {
    std::cout << GREEN << "Woof! Woof!" << RESET << std::endl;
}
