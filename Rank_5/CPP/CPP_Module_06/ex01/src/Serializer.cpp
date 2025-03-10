/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:13:36 by yfang             #+#    #+#             */
/*   Updated: 2025/03/05 12:38:16 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &other) {
    (void)other;
}

Serializer  &Serializer::operator=(const Serializer &other) {
    (void)other;
    return *this;
}

Serializer::~Serializer(void) {}

uintptr_t   Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data    *Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}
