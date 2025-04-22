/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:35:00 by yfang             #+#    #+#             */
/*   Updated: 2025/04/22 19:04:10 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}



PmergeMe::PmergeMe(int ac, char** av) {
    for (int i = 1; i < ac; i++) {
        std::string arg(av[i]);
        
        if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
            throw InvalidInputException();

        long nb = std::atol(arg.c_str());
        if (nb <= 0)
            throw InvalidInputException();

        if (std::find(_vec.begin(), _vec.end(), nb) == _vec.end()) {
            _vec.push_back(static_cast<int>(nb));
            _deq.push_back(static_cast<int>(nb));
        }
    }
}

PmergeMe::PmergeMe(const PmergeMe &other) {
    _vec = other._vec;
    _deq = other._deq;
}

PmergeMe    &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe(void) {}

void    PmergeMe::sortVector(std::vector<int> &vec) {
    if (vec.size() <= 1 || vec.empty())
        return;
    
    std::vector<int>    big;
    std::vector<int>    small;

    if (vec.size() % 2 != 0) {
        small.push_back(vec.back());
        vec.pop_back();
    }

    for (size_t i = 0; i < vec.size(); i += 2) {
        if (vec[i] > vec[i + 1]) {
            big.push_back(vec[i]);
            small.push_back(vec[i + 1]);
        } else {
            big.push_back(vec[i + 1]);
            small.push_back(vec[i]);
        }
    }

    std::sort(big.begin(), big.end());

    for (size_t i = 0; i < small.size(); i++) {
        std::vector<int>::iterator pos;
        pos = std::lower_bound(big.begin(), big.end(), small[i]);
        big.insert(pos, small[i]);
    }
    vec = big;
}


void    PmergeMe::sortDeque(std::deque<int> &deq) {
    if (deq.size() <= 1)
        return;
    
    std::deque<int>    big;
    std::deque<int>    small;

    if (deq.size() % 2 != 0) {
        small.push_back(deq.back());
        deq.pop_back();
    }

    for (size_t i = 0; i < deq.size(); i += 2) {
        if (deq[i] > deq[i + 1]) {
            big.push_back(deq[i]);
            small.push_back(deq[i + 1]);
        } else {
            big.push_back(deq[i + 1]);
            small.push_back(deq[i]);
        }
    }

    std::sort(big.begin(), big.end());

    for (size_t i = 0; i < small.size(); i++) {
        std::deque<int>::iterator pos;
        pos = std::lower_bound(big.begin(), big.end(), small[i]);
        big.insert(pos, small[i]);
    }
    deq = big;
}

double    PmergeMe::sortAndMeasure(int i) {
    clock_t start = clock();
    
    if (i)
        sortVector(_vec);
    else
        sortDeque(_deq);
    
    clock_t end = clock();

    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    return (time);
}

void    PmergeMe::print(void) {
    for (size_t j = 0; j < _vec.size() && j < 10; j++)
        std::cout << _vec[j] << " ";
    if (_vec.size() > 10)
        std::cout << "[...]";
    std::cout << std::endl;
}

void    PmergeMe::printMs(double vec, double deq) {
    std::cout << "Time to process a range of " << _vec.size()
        << " elements with std::vector: " << vec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
        << " elements with std::deque: " << deq << " us" << std::endl;
}
