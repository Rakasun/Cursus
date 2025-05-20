/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:35:00 by yfang             #+#    #+#             */
/*   Updated: 2025/05/20 18:04:17 by yfang            ###   ########.fr       */
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
        if (nb < 0 || nb > 2147483647)
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

std::vector<int> generateJacobsthal(int n) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    while (jacobsthal.back() < n) {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

void    sortPairs(std::vector<int> &vec, size_t n_pairs) {
    size_t pairs_n_elemt = vec.size() / (n_pairs * 2);

    for (size_t i = 0; i < pairs_n_elemt; i++) {
        size_t start = i * n_pairs * 2;
        size_t mid = start + n_pairs;

        if (vec[mid + n_pairs - 1] < vec[start + n_pairs - 1])
            for (size_t j = 0; j < n_pairs; j++)
                std::swap(vec[start + j], vec[mid + j]);
    }
}

struct CompareByLastElement {
    bool operator()(const std::vector<int> &a, const std::vector<int> &b) const {
        return a.back() < b.back();
    }
};

void insertBlock(std::vector<std::vector<int> > &main_chain, const std::vector<int> &block) {
    std::vector<std::vector<int> >::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), block, CompareByLastElement());

    main_chain.insert(pos, block);
}

void insertJacobstal(std::vector<std::vector<int> > &main_chain, std::vector<std::vector<int> > b_blocks, std::vector<int> jacobsthal) {
    for (size_t i = 3; i < jacobsthal.size(); i++) {
        size_t  jacob_idx = jacobsthal[i] - 1;
        size_t  jacob_stop = jacobsthal[i - 1];

        if (jacob_idx >= b_blocks.size())
            jacob_idx = b_blocks.size() - 1;

        for (size_t j = jacob_idx; j >= jacob_stop; j--) {
            const std::vector<int>  block_to_insert = b_blocks[jacob_idx];
            insertBlock(main_chain, block_to_insert);
            jacob_idx--;
        }
    }
}

void sortJacobstal(std::vector<int> &vec, size_t n_pairs, std::vector<int> &jacobsthal) {
    size_t pairs_n_elemt = vec.size() / (n_pairs * 2);

    if (n_pairs == 1)
        pairs_n_elemt = vec.size();
    std::vector<std::vector<int> > a_blocks;
    std::vector<std::vector<int> > b_blocks;

    bool finish = false;
    if (n_pairs == 1) {
        finish = true;
        for (size_t i = 0; i < vec.size(); i++) {
            if (i % 2 == 0)
                b_blocks.push_back(std::vector<int>(1, vec[i]));
            else
                a_blocks.push_back(std::vector<int>(1, vec[i]));
        }

    } else {
        for (size_t i = 0; i < pairs_n_elemt; i++) {
            size_t start = i * n_pairs * 2;
            size_t mid = start + n_pairs;

            std::vector<int>    b_block(vec.begin() + start, vec.begin() + mid);
            std::vector<int>    a_block(vec.begin() + mid, vec.begin() + mid + n_pairs);
        
            b_blocks.push_back(b_block);
            a_blocks.push_back(a_block);
        }
    }

    std::vector<int> no_part;
    if (vec.size() % (n_pairs * 2) != 0 && !finish) {
        size_t start = pairs_n_elemt * n_pairs * 2;
        no_part.insert(no_part.end(), vec.begin() + start, vec.end());
    }

    while (no_part.size() >= n_pairs) {
        std::vector<int> new_b_block(no_part.begin(), no_part.begin() + n_pairs);
        b_blocks.push_back(new_b_block);
        no_part.erase(no_part.begin(), no_part.begin() + n_pairs);
    }

    std::vector<std::vector<int> >  main_chain;

    main_chain.push_back(b_blocks[0]);

    for (size_t i = 0; i < a_blocks.size(); i++)
        main_chain.push_back(a_blocks[i]);

    insertJacobstal(main_chain, b_blocks, jacobsthal);

    if (!no_part.empty())
        main_chain.push_back(no_part);

    vec.clear();
    for (size_t i = 0; i < main_chain.size(); i++)
        vec.insert(vec.end(), main_chain[i].begin(), main_chain[i].end());
}

void PmergeMe::sortVector(std::vector<int> &vec, size_t n_pairs) {
    size_t paris_n_elemt = vec.size() / (n_pairs * 2);

    sortPairs(vec, n_pairs);
    
    if (paris_n_elemt <= 1)
        return;

    sortVector(vec, n_pairs * 2);

    std::vector<int> jacobsta = generateJacobsthal(paris_n_elemt);

    sortJacobstal(vec, n_pairs * 2, jacobsta);

    if (n_pairs == 1) {
        jacobsta = generateJacobsthal(vec.size());
        sortJacobstal(vec, n_pairs, jacobsta);
    }
}

std::deque<int> generateJacobsthalDeque(int n) {
    std::deque<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    while (jacobsthal.back() < n) {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

void sortPairs(std::deque<int> &deq, size_t n_pairs) {
    size_t pairs_n_elemt = deq.size() / (n_pairs * 2);

    for (size_t i = 0; i < pairs_n_elemt; i++) {
        size_t start = i * n_pairs * 2;
        size_t mid = start + n_pairs;

        if (deq[mid + n_pairs - 1] < deq[start + n_pairs - 1])
            for (size_t j = 0; j < n_pairs; j++)
                std::swap(deq[start + j], deq[mid + j]);
    }
}

struct CompareByLastElementDeque {
    bool operator()(const std::deque<int> &a, const std::deque<int> &b) const {
        return a.back() < b.back();
    }
};

void insertBlock(std::deque<std::deque<int> > &main_chain, const std::deque<int> &block) {
    std::deque<std::deque<int> >::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), block, CompareByLastElementDeque());

    main_chain.insert(pos, block);
}

void insertJacobstal(std::deque<std::deque<int> > &main_chain, std::deque<std::deque<int> > b_blocks, std::deque<int> jacobsthal) {
    for (size_t i = 3; i < jacobsthal.size(); i++) {
        size_t jacob_idx = jacobsthal[i] - 1;
        size_t jacob_stop = jacobsthal[i - 1];

        if (jacob_idx >= b_blocks.size())
            jacob_idx = b_blocks.size() - 1;

        for (size_t j = jacob_idx; j >= jacob_stop; j--) {
            const std::deque<int> block_to_insert = b_blocks[jacob_idx];
            insertBlock(main_chain, block_to_insert);
            jacob_idx--;
        }
    }
}

void sortJacobstal(std::deque<int> &deq, size_t n_pairs, std::deque<int> &jacobsthal) {
    size_t pairs_n_elemt = deq.size() / (n_pairs * 2);

    if (n_pairs == 1)
        pairs_n_elemt = deq.size();
    std::deque<std::deque<int> > a_blocks;
    std::deque<std::deque<int> > b_blocks;

    bool finish = false;

    if (n_pairs == 1) {
        finish = true;
        for (size_t i = 0; i < deq.size(); i++) {
            if (i % 2 == 0)
                b_blocks.push_back(std::deque<int>(1, deq[i]));
            else
                a_blocks.push_back(std::deque<int>(1, deq[i]));
        }
    } else {
        for (size_t i = 0; i < pairs_n_elemt; i++) {
            size_t start = i * n_pairs * 2;
            size_t mid = start + n_pairs;

            std::deque<int> b_block(deq.begin() + start, deq.begin() + mid);
            std::deque<int> a_block(deq.begin() + mid, deq.begin() + mid + n_pairs);
        
            b_blocks.push_back(b_block);
            a_blocks.push_back(a_block);
        }
    }

    std::deque<int> no_part;
    if (deq.size() % (n_pairs * 2) != 0 && !finish) {
        size_t start = pairs_n_elemt * n_pairs * 2;
        no_part.insert(no_part.end(), deq.begin() + start, deq.end());
    }

    while (no_part.size() >= n_pairs) {
        std::deque<int> new_b_block(no_part.begin(), no_part.begin() + n_pairs);
        b_blocks.push_back(new_b_block);
        no_part.erase(no_part.begin(), no_part.begin() + n_pairs);
    }

    std::deque<std::deque<int> > main_chain;

    main_chain.push_back(b_blocks[0]);

    for (size_t i = 0; i < a_blocks.size(); i++)
        main_chain.push_back(a_blocks[i]);

    insertJacobstal(main_chain, b_blocks, jacobsthal);

    if (!no_part.empty())
        main_chain.push_back(no_part);

    deq.clear();
    for (size_t i = 0; i < main_chain.size(); i++)
        deq.insert(deq.end(), main_chain[i].begin(), main_chain[i].end());
}

void PmergeMe::sortDeque(std::deque<int> &deq, size_t n_pairs) {
    size_t pairs_n_elemt = deq.size() / (n_pairs * 2);

    sortPairs(deq, n_pairs);

    if (pairs_n_elemt <= 1)
        return;

    sortDeque(deq, n_pairs * 2);

    std::deque<int> jacobsta = generateJacobsthalDeque(pairs_n_elemt);

    sortJacobstal(deq, n_pairs * 2, jacobsta);

    if (n_pairs == 1) {
        jacobsta = generateJacobsthalDeque(deq.size());
        sortJacobstal(deq, n_pairs, jacobsta);
    }
}

double    PmergeMe::sortAndMeasure(int i) {
    clock_t start = clock();
    
    if (i)
        sortVector(_vec, 1);
    else
        sortDeque(_deq, 1);
    
    clock_t end = clock();

    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;

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
