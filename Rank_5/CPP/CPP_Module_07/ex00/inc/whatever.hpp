/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:27:45 by yfang             #+#    #+#             */
/*   Updated: 2025/03/11 15:55:19 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void    swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T   min(T a, T b) {
    return a < b ? a : b;
}

template <typename T>
T   max(T a, T b) {
    return a > b ? a : b;
}

#endif