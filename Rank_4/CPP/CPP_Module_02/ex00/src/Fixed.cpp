/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:01:43 by yfang             #+#    #+#             */
/*   Updated: 2024/09/12 15:24:02 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

void    Fixed::setRawBits(const int raw) {
    fixed_ptr = raw;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_ptr;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called"<< std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy) {
    if (this != &copy)
        this->fixed_ptr = copy.fixed_ptr;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::Fixed(const Fixed &copy): fixed_ptr(copy.fixed_ptr) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(void): fixed_ptr(0) {
    std::cout << "Default constructor called"<< std::endl;
}
