/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:02:49 by yfang             #+#    #+#             */
/*   Updated: 2024/09/13 11:00:02 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
    private:
        int                 _fixed_ptr;
        const static int    fractional_bits = 8;
    public:
        Fixed(void);
        Fixed(const Fixed &copy);
        ~Fixed(void);
        Fixed(const int fixed_ptr);
        Fixed(const float fixed_ptr);
        Fixed               &operator=(const Fixed &copy);
        Fixed               operator+(const Fixed &copy);
        Fixed               operator-(const Fixed &copy);
        Fixed               operator*(const Fixed &copy);
        Fixed               operator/(const Fixed &copy);
        Fixed               &operator++(void);
        Fixed               &operator--(void);
        Fixed               operator++(int);
        Fixed               operator--(int);
        bool                operator>(const Fixed &copy);
        bool                operator<(const Fixed &copy);
        bool                operator>=(const Fixed &copy);
        bool                operator<=(const Fixed &copy);
        bool                operator==(const Fixed &copy);
        bool                operator!=(const Fixed &copy);

        static Fixed        &min(Fixed &a, Fixed &b);
        const static Fixed  &min(const Fixed &a, const Fixed &b);
        static Fixed        &max(Fixed &a, Fixed &b);
        const static Fixed  &max(const Fixed &a, const Fixed &b);
        int                 getRawBits(void) const;
        void                setRawBits(const int raw);
        float               toFloat(void) const;
        int                 toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &data);

#endif
