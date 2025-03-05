/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:13:49 by yfang             #+#    #+#             */
/*   Updated: 2025/03/05 12:48:01 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int main(void) {
    Data myData = {42, "Hello world!"};

    std::cout << "Original Data Address: " << &myData << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized uintptr_t: " << raw << std::endl;

    Data    *deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized Data Addess: " << deserialized << std::endl;

    if (deserialized == &myData) {
        std::cout << "Success: Deserialized pointer matches original!" << std::endl;
    } else {
        std::cout << "Error: Deserialized pointer does not match original!" << std::endl;
    }

    std::cout << "ID: " << deserialized->id << ", Name: " << deserialized->name << std::endl;

    return 0;
}
