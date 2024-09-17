/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:02:50 by yfang             #+#    #+#             */
/*   Updated: 2024/09/12 15:40:12 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
    private:
        int                 fixed_ptr;
        const static int    fractional_bits = 8;
    public:
        Fixed(void);
        Fixed(const Fixed &copy);
        Fixed   &operator=(const Fixed &copy);
        ~Fixed(void);

        int     getRawBits(void) const;
        void    setRawBits(const int raw);
};

#endif
