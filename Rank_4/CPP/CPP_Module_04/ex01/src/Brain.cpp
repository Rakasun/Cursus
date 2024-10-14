/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:18:52 by yfang             #+#    #+#             */
/*   Updated: 2024/10/04 12:02:39 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain(void) {
    for (int i = 0; i < 100; i++)
        _ideas[i] = "";
    std::cout << CYAN << "Brain constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &other) {
    for (int i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
    std::cout << CYAN << "Brain copy constructor called" << RESET << std::endl;
}

Brain   &Brain::operator=(const Brain &other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++)
            _ideas[i] = other._ideas[i];
    }
    std::cout << CYAN << "Brain assignment operator called" << RESET << std::endl;
    return *this;
}

Brain::~Brain(void) {
    std::cout << CYAN << "Brain destructor called" << RESET << std::endl;
}

Brain   *Brain::clone(void) {
    Brain   *clone = new Brain(*this);
    return clone;
}
