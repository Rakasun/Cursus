/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:06:29 by yfang             #+#    #+#             */
/*   Updated: 2025/05/12 18:18:43 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGME_HPP
# define PMERGME_HPP

# include <vector>
# include <deque>
# include <string>
# include <algorithm>
# include <iostream>
# include <ctime>

class PmergeMe {
    private:
        std::vector<int>    _vec;
        std::deque<int>     _deq;
        PmergeMe(void);
        void    sortVector(std::vector<int> &vec, size_t n_pairs);
        void    sortDeque(std::deque<int> &deq, size_t n_pairs);
    public:
        PmergeMe(int ac, char** av);
        PmergeMe(const PmergeMe &other);
        PmergeMe    &operator=(const PmergeMe &other);
        ~PmergeMe(void);

        void    print(void);
        double  sortAndMeasure(int i);
        void    printMs(double vec, double deq);

        class InvalidInputException : public std::exception {
            public:
                const char *what() const throw() {
                    return "Invalid input provided.";
                }
        };
};

#endif