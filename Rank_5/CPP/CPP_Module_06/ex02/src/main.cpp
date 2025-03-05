/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:17:00 by yfang             #+#    #+#             */
/*   Updated: 2025/03/05 13:22:39 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base    *generate(void) {
    srand(time(0));
    int random = rand() % 3;

    switch(random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            std::cerr << "Error: No Class Created" << std::endl;
            return NULL;
    }
}

void    identify(Base *p) {
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unlnown type" << std::endl;
}

void    identify(Base &p) {
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "Unlnown type" << std::endl;
}

int main(void) {
    Base *instance = generate();

    std::cout << "Identify using pointer: " << std::endl;
    identify(instance);

    std::cout << "Identify using reference: " << std::endl;
    identify(*instance);

    delete instance;

    return 0;
}
