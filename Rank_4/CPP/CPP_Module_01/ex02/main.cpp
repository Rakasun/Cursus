/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:31:16 by yfang             #+#    #+#             */
/*   Updated: 2024/08/23 16:41:56 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
    std::string     str = "HI THIS IS BRAIN";
    std::string*    ptr = &str;
    std::string&    ref = str;

    std::cout << "memory address of the string variable: " << &str << std::endl;
    std::cout << "memory address held by stringPTR: " << ptr << std::endl;
    std::cout << "memory address held by stringREF: " << &ref << std::endl;

    std::cout << "value of the string variable: " << str << std::endl;
    std::cout << "value pointed to by stringPTR: " << *ptr << std::endl;
    std::cout << "value pointed to by stringREF: " << ref << std::endl;
}
