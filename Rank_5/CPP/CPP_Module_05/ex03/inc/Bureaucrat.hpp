/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:48:58 by yfang             #+#    #+#             */
/*   Updated: 2024/12/11 16:05:01 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <string>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define ORANGE "\033[38;5;214m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

class AForm;

class Bureaucrat {
    private:
        const std::string   _name;
        int                 _grade;
    public:
        Bureaucrat(void);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat  &operator=(const Bureaucrat &other);
        ~Bureaucrat(void);

        const std::string   &getName(void) const;
        int                 getGrade(void) const;
        void                incrementGrade(void);
        void                decrementGrade(void);
        
        void                signForm(AForm &form) const;
        void                executeForm(const AForm &form) const;

        class GradeTooHighException : public std::exception {
            public:
                const char  *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char  *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
