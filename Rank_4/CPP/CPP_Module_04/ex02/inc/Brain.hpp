/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:12:34 by yfang             #+#    #+#             */
/*   Updated: 2024/10/07 11:35:27 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "AAnimal.hpp"

class Brain {
    private:
        std::string _ideas[100];
    public:
        Brain(void);
        Brain(const Brain &other);
        Brain   &operator=(const Brain &other);
        ~Brain(void);
        Brain   *clone(void);
};

#endif
