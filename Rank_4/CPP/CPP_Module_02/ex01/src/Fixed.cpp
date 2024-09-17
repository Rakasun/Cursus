/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:19:10 by yfang             #+#    #+#             */
/*   Updated: 2024/09/12 15:27:10 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

std::ostream &operator<<(std::ostream &out, const Fixed &data) {
    return (out<<data.toFloat());
}

int Fixed::toInt(void) const {
    return (_fixed_ptr >> fractional_bits);
}

float   Fixed::toFloat(void) const {
    return (static_cast<float>(_fixed_ptr) / (1 << fractional_bits));
}

Fixed::Fixed(const float fixed_ptr) {
    _fixed_ptr = roundf(fixed_ptr * (1 << fractional_bits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int fixed_ptr) {
    _fixed_ptr = fixed_ptr << fractional_bits;
    std::cout << "Int constructor called" << std::endl;
}

void    Fixed::setRawBits(const int raw) {
    _fixed_ptr = raw;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fixed_ptr;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called"<< std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy) {
    if (this != &copy)
        this->_fixed_ptr = copy._fixed_ptr;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::Fixed(const Fixed &copy): _fixed_ptr(copy._fixed_ptr) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(void): _fixed_ptr(0) {
    std::cout << "Default constructor called"<< std::endl;
}
