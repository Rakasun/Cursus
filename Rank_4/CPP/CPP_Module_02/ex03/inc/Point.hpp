/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:35:40 by yfang             #+#    #+#             */
/*   Updated: 2024/09/17 15:00:52 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
    private:
        const Fixed _x;
        const Fixed _y;
    public:
        Point(void);
        Point(const float x, const float y);
        Point(const Point &copy);
        Point       &operator=(const Point &copy);
        ~Point(void);
        const Fixed getx(void) const;
        const Fixed gety(void) const;
};

bool    bsp( Point const a, Point const b, Point const c, Point const point);

#endif