//
// Created by eldar on 13.05.22.
//

#ifndef LINQ_LINQ_H
#define LINQ_LINQ_H

#include <memory>
#include <utility>
#include "Interfaces/IOperation.h"

namespace etd::linq
{
    class Linq final
    {
    public:
        template<typename T>
        T &getController()
        {
            return dynamic_cast<T &>(*_controller);
        }

        explicit Linq(std::shared_ptr<IOperation> controller)
        {
            _controller = move(controller);
        }

        void changeController(std::shared_ptr<IOperation> controller)
        {
            _controller.swap(controller);
        }

    private:
        std::shared_ptr<IOperation> _controller;
    };

}

#endif //LINQ_LINQ_H
