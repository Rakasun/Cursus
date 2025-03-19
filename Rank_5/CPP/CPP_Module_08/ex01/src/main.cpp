/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:04:55 by yfang             #+#    #+#             */
/*   Updated: 2025/03/19 19:35:10 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int main(void) {
    try {
        Span sp(10);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        int nums[] = {20, 50, 8, 4, 30};
        sp.addNumber(nums, 5);


        std::cout << "Shortest Span (after adding more numbers): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span (after adding more numbers): " << sp.longestSpan() << std::endl;

        
        int nums3[] = {100, 200};
        sp.addNumber(nums3, 2);

    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}