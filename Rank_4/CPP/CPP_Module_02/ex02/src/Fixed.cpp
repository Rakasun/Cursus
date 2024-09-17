/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:14:09 by yfang             #+#    #+#             */
/*   Updated: 2024/09/13 11:35:58 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

const Fixed    &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a._fixed_ptr > b._fixed_ptr)
        return a;
    return b;
}

Fixed    &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    return b;
}

const Fixed    &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a._fixed_ptr < b._fixed_ptr)
        return a;
    return b;
}

Fixed    &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return a;
    return b;
}

Fixed   Fixed::operator--(int) {
    Fixed   copy(*this);

    this->_fixed_ptr--;
    return copy;
}

Fixed   Fixed::operator++(int) {
    Fixed   copy(*this);

    this->_fixed_ptr++;
    return copy;
}

Fixed   &Fixed::operator--(void) {
    this->_fixed_ptr--;
    return *this;
}

Fixed   &Fixed::operator++(void) {
    this->_fixed_ptr++;
    return *this;
}

Fixed   Fixed::operator/(const Fixed &copy) {
    return Fixed(this->toFloat() / copy.toFloat());
}

Fixed   Fixed::operator*(const Fixed &copy) {
    return Fixed(this->toFloat() * copy.toFloat());
}

Fixed   Fixed::operator-(const Fixed &copy) {
    return Fixed(this->toFloat() - copy.toFloat());
}

Fixed   Fixed::operator+(const Fixed &copy) {
    return Fixed(this->toFloat() + copy.toFloat());
}

bool    Fixed::operator!=(const Fixed &copy) {
    if (this != &copy)
        return true;
    return false;
}

bool    Fixed::operator==(const Fixed &copy) {
    if (this == &copy)
        return true;
    return false;
}

bool    Fixed::operator<=(const Fixed &copy) {
    if (this <= &copy)
        return true;
    return false;
}

bool    Fixed::operator>=(const Fixed &copy) {
    if (this >= &copy)
        return true;
    return false;
}

bool    Fixed::operator<(const Fixed &copy) {
    if (this < &copy)
        return true;
    return  false;
}

bool    Fixed::operator>(const Fixed &copy) {
    if (this > &copy)
        return true;
    return false;
}

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
