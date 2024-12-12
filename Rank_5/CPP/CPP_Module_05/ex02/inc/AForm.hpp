/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:48:28 by yfang             #+#    #+#             */
/*   Updated: 2024/12/02 18:26:02 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class AForm {
    private:
        const std::string   _name;
        bool                _status;
        const int           _gradeToSign;
        const int           _gradeToExecute;
    public:
        AForm(void);
        AForm(const AForm &oter);
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm    &operator=(const AForm &other);
        virtual ~AForm(void);

        std::string getName(void) const;
        bool        getStatus(void) const;
        int         getSignGrade(void) const;
        int         getExecGrade(void) const;

        virtual void    execute(Bureaucrat const &executor) const = 0;
        bool            beSigned(Bureaucrat const &bureaucrat);
        void            verifyExecution(const Bureaucrat &executor) const;

        class GradeTooHighException : public std::exception {
            public:
                const char  *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char  *what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public:
                const char *what() const throw();
        };
};
std::ostream    &operator<<(std::ostream &out, const AForm &f);

#endif
