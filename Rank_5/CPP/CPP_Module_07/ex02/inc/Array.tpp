/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:32:32 by yfang             #+#    #+#             */
/*   Updated: 2025/03/12 16:00:49 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    _data = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &other) : _size(other._size) {
    _data = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _data[i] = other._data[i];
}

template <typename T>
Array<T>    &Array<T>::operator=(const Array &other) {
    if (this != &other) {
        delete[] _data;

        _size = other._size;
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array(void) {
    delete[] _data;
}

template <typename T>
T   &Array<T>::operator[](unsigned int i) {
    if (i >= _size)
        throw std::out_of_range("Index out of range");
    return _data[i];
}

template <typename T>
const T   &Array<T>::operator[](unsigned int i) const {
    if (i >= _size)
        throw std::out_of_range("Index out of range");
    return _data[i];
}

template <typename T>
unsigned int    Array<T>::size(void) const {
    return _size;
}

#endif