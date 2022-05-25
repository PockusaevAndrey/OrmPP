//
// Created by pokys on 25.05.2022.
//

#ifndef LINQ_ERRORS_HPP
#define LINQ_ERRORS_HPP

#include <exception>

namespace linq {
    class InvalidColumn : public std::exception {
        const char *what() const noexcept override;
    };

    class InvalidQuery : public std::exception {
        const char *what() const noexcept override;
    };


}


#endif //LINQ_ERRORS_HPP
