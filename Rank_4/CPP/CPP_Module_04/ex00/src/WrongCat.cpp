/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:31:34 by yfang             #+#    #+#             */
/*   Updated: 2024/10/03 16:31:34 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat(void) {
    this->_type = "WrongCat";
    std::cout << BLUE << "WrongCat constructor called." << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std::cout << BLUE << "WrongCat copy constructor called." << RESET << std::endl;
}

WrongCat  &WrongCat::operator=(const WrongCat &other) {
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << BLUE << "WrongCat assignment operator called" << RESET << std::endl;
    return *this;
}
WrongCat::~WrongCat(void) {
    std::cout << BLUE << "WrongCat destructor called" << RESET << std::endl;
}

void    WrongCat::makeSound(void) const {
    std::cout << GREEN << "Meow! Meow!" << RESET << std::endl;
}
