/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:57:09 by yfang             #+#    #+#             */
/*   Updated: 2024/09/12 15:40:14 by yfang            ###   ########.fr       */
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
        Fixed &operator=(const Fixed &copy);
        ~Fixed(void);
        Fixed(const int fixed_ptr);
        Fixed(const float fixed_ptr);

        int     getRawBits(void) const;
        void    setRawBits(const int raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &data);

#endif
