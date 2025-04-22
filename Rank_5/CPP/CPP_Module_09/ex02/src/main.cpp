/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:26:16 by yfang             #+#    #+#             */
/*   Updated: 2025/04/22 19:05:21 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error: Invalid num of arguments." << std::endl;
        return 1;
    }

    try {
        PmergeMe    obj(ac, av);

        double vec;
        double deq;

        std::cout << "Before: ";
        obj.print();

        vec = obj.sortAndMeasure(1);
        deq = obj.sortAndMeasure(0);
    
        std::cout << "After: ";
        obj.print();

        obj.printMs(vec, deq);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
