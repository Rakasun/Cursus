/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:13:43 by yfang             #+#    #+#             */
/*   Updated: 2025/03/19 19:30:10 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class NotFound : public std::exception {
    public:
        const char *what() const throw();
};

class Span {
    private:
        unsigned int        _maxSize;
        std::vector<int>    _numbers;
    public:
        Span(void);
        Span(unsigned int maxSize);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span(void);

        void    addNumber(int maxSize);
        void    addNumber(int *array, size_t size);
        int     shortestSpan(void);
        int     longestSpan(void);
};

#endif