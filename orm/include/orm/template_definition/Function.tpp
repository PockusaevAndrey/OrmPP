//
// Created by pokys on 01.06.2022.
//
template<typename T, typename ...Args>
orm::db::Function<T, Args...>::Function(std::string name) : orm::db::Column<T>(name) {
}
template<typename T, typename ...Args>
orm::db::Function<T, Args...> orm::db::Function<T, Args...>::operator()(Args... args){
    std::string result;
    ([&](auto &arg) {
        result += std::to_string(arg) + ", ";
    }(args), ...);
    result = result.substr(0, result.length()-2);
    this->name = this->name + "(" + result + ")";
    return *this;
}
