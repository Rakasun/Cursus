/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:59:59 by yfang             #+#    #+#             */
/*   Updated: 2025/03/12 15:16:15 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/inter.hpp"

int main(void) {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original intArray: ";
    iter(intArray, intSize, printElement<int>);
    std::cout << std::endl;

    iter(intArray, intSize, doubleElement<int>);

    std::cout << "Modified intArray: ";
    iter(intArray, intSize, printElement<int>);
    std::cout << std::endl;

    std::string strArray[] = {"Hello", "World", "C++"};
    size_t strSize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "strArray: ";
    iter(strArray, strSize, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
