/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:22:35 by yfang             #+#    #+#             */
/*   Updated: 2025/03/19 19:29:47 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

const char *NotFound::what() const throw() {
    return "Error: Span can't be found.";
}

Span::Span(void) {}

Span::Span(unsigned int maxSize) : _maxSize(maxSize) {}

Span::Span(const Span &other) {
    if (this != &other)
        *this = other;
}

Span    &Span::operator=(const Span &other) {
    if (this != &other) {
        this->_maxSize = other._maxSize;
        this->_numbers = other._numbers;
    }
    return *this;
}

Span::~Span(void) {}

void    Span::addNumber(int maxSize) {
    try {
        if (this->_numbers.size() < this->_maxSize)
            this->_numbers.push_back(maxSize);
        else
            throw std::exception();
    }
    catch (std::exception &e) {
        std::cout << "Error: Vector is complete." << std::endl;
    }
}

void    Span::addNumber(int *array, size_t size) {
    try {
        if (_numbers.size() + size <= _maxSize)
            _numbers.insert(_numbers.end(), array, array + size);
        else
            throw std::exception();
    }
    catch (std::exception &e) {
        std::cout << "Error: Vector is complete." << std::endl;
    }
}

int Span::shortestSpan(void) {
    if (_numbers.size() < 2)
        throw NotFound();
    std::sort(_numbers.begin(), _numbers.end());
    int shortest = _numbers[1] - _numbers[0];
    for (size_t i = 1; i < _numbers.size() - 1; i++) {
        if (_numbers[i + 1] - _numbers[i] < shortest)
            shortest = _numbers[i + 1] - _numbers[i];
    }
    return shortest;
}

int Span::longestSpan(void) {
    if (_numbers.size() < 2)
        throw NotFound();
    std::sort(_numbers.begin(), _numbers.end());
    int longest = _numbers[_numbers.size() - 1] - _numbers[0];
    return longest;
}


