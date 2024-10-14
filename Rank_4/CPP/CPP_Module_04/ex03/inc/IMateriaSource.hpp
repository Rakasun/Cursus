/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:42:51 by yfang             #+#    #+#             */
/*   Updated: 2024/10/10 18:34:04 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "Cure.hpp"

class IMateriaSource {
    public:
        virtual             ~IMateriaSource(void) {}
        virtual void        learnMateria(AMateria*) = 0;
        virtual AMateria    *createMateria(std::string const & type) = 0;
};

#endif
