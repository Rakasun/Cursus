/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:04:54 by yfang             #+#    #+#             */
/*   Updated: 2024/09/17 15:31:44 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

static Fixed area(Point const a, Point const b, Point const c)
{
    return Fixed(static_cast<float>(std::abs(
        (a.getx().toFloat() * (b.gety().toFloat() - c.gety().toFloat()) +
         b.getx().toFloat() * (c.gety().toFloat() - a.gety().toFloat()) +
         c.getx().toFloat() * (a.gety().toFloat() - b.gety().toFloat())) / 2.0f)));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed A = area(a, b, c);
    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);

    if (A == A1 + A2 + A3)
        return (true);
    return (false);
}