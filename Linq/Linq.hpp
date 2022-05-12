//
// Created by eldar on 06.05.22.
//

#ifndef LINQ_LINQ_HPP
#define LINQ_LINQ_HPP

#include <utility>

#include "IOperation.hpp"

using namespace std;
namespace etd::linq {

    class Linq : public IOperation {
    public:

        Linq() = default;

        explicit Linq(shared_ptr<IOperation> operation) {
            _linq = move(operation);
        }

        IOperation &select(string column) override {
            IOperation &result = _linq->select(column);
            return result;
        }

        IOperation &from(string table) override {
            IOperation &result = _linq->from(table);
            return result;
        }

        IOperation &where(string condition) override {
            IOperation &result = _linq->where(condition);
            return result;
        }

        IOperation &orderBy(string column) override {
            IOperation &result = _linq->orderBy(column);
            return result;
        }

        IOperation &groupBy(string column) override {
            IOperation &result = _linq->groupBy(column);
            return result;
        }

        IOperation &having(string condition) override {
            IOperation &result = _linq->having(condition);
            return result;
        }

        IOperation &limit(string limit) override {
            IOperation &result = _linq->limit(limit);
            return result;
        }

        IOperation &offset(string offset) override {
            IOperation &result = _linq->offset(offset);
            return result;
        }

        string execute() override {
            return _linq->execute();
        }

        ~Linq() override = default;

    private:
        shared_ptr<IOperation> _linq;
    };
}

#endif //LINQ_LINQ_HPP
