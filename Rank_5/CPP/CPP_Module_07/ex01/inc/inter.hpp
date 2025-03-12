/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:03:31 by yfang             #+#    #+#             */
/*   Updated: 2025/03/12 15:06:19 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTER_HPP
# define INTER_HPP

# include <iostream>

template <typename T, typename F>
void    iter(T *array, size_t length, F func) {
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

template <typename T>
void    printElement(const T &element) {
    std::cout << element << " ";
}

template <typename T>
void    doubleElement(T &element) {
    element *= 2;
}

#endif