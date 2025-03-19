/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:15:08 by yfang             #+#    #+#             */
/*   Updated: 2025/03/19 16:46:34 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <iostream>

class NotFoundExc : public std::exception {
    public:
        const char *what() const throw();
};

template <typename T>
typename T::iterator easyfind(T &container, int value);

# include "easyfind.tpp"

#endif