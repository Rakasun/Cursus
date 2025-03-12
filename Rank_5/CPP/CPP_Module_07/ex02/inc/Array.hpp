/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:11:43 by yfang             #+#    #+#             */
/*   Updated: 2025/03/12 16:00:17 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>
# include <stdlib.h>

template <typename T>
class Array {
    private:
        T               *_data;
        unsigned int    _size;
    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array(void);

        T   &operator[](unsigned int i);
        const T &operator[](unsigned int i) const;
        unsigned int size(void) const;
};

# include "Array.tpp"

#endif