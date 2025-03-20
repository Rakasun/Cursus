/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:24:55 by yfang             #+#    #+#             */
/*   Updated: 2025/03/20 18:36:23 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other) {}

template<typename T>
MutantStack<T>  &MutantStack<T>::operator=(const MutantStack &other) {
    if (this != &other)
        std::stack<T>::operator = (other);
    return *this;
}

template<typename T>
MutantStack<T>::~MutantStack(void) {}

template<typename T>
typename    MutantStack<T>::iterator MutantStack<T>::begin(void) {
    return this->c.begin();
}

template<typename T>
typename    MutantStack<T>::iterator MutantStack<T>::end(void) {
    return this->c.end();
}
