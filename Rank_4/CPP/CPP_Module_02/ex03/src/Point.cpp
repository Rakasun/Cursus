/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:45:23 by yfang             #+#    #+#             */
/*   Updated: 2024/09/17 15:32:45 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

const Fixed Point::gety(void) const {
    return _y;
}

const Fixed Point::getx(void) const {
    return _x;
}

Point::~Point(void) {}

Point   &Point::operator=(const Point &copy) {
    (void)copy;
    return *this;
}

Point::Point(const Point &copy): _x(copy._x), _y(copy._y) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(void): _x(0), _y(0) {}
