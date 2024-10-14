/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:40:24 by yfang             #+#    #+#             */
/*   Updated: 2024/10/10 14:45:08 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    private:
        AMateria    *_space[4];
        int         _count;
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource &other);
        MateriaSource   &operator=(const MateriaSource &other);
        ~MateriaSource(void);

        void        learnMateria(AMateria *m);
        AMateria    *createMateria(const std::string &type);
};

#endif
