//
// Created by eldar on 14.05.22.
//


#include "../includes/MySQLSelect.h"

MySqlSelect &MySqlSelect::select(std::string column)
{
    _query += "SELECT " + column + " ";
    return *this;
}

MySqlSelect &MySqlSelect::from(std::string table)
{
    _query += "\nFROM " + table + " ";
    return *this;
}

MySqlSelect &MySqlSelect::where(std::string condition)
{
    if (_query.find("WHERE") != std::string::npos)
    {
        if (std::count(_query.begin(), _query.end(), '(') >
            std::count(_query.begin(), _query.end(), ')'))
        {
            _query += "OR " + condition + " ";
        }
        else
            _query += " (" + condition + " ";
    }
    else
    {
        _query += "\nWHERE (" + condition + " ";
    }
    return *this;
}

MySqlSelect &MySqlSelect::whereAnd()
{
    _query += "\n AND";
    return *this;
}

MySqlSelect &MySqlSelect::whereOr()
{
    _query += "\n OR";
    return *this;
}

MySqlSelect &MySqlSelect::closeScope()
{
    if (_query.find_last_of(' ') == _query.size() - 1)
        _query = _query.substr(0, _query.size() - 1) + ')';
    else
        _query += ')';
    return *this;
}

MySqlSelect &MySqlSelect::orderBy(std::string column)
{
    if (_query.find("ORDER BY") != std::string::npos)
    {
        _query += ", " + column;
    }
    else
    {
        _query += "\nORDER BY " + column + " ";
    }
    return *this;
}

MySqlSelect &MySqlSelect::groupBy(std::string column)
{
    _query += "\nGROUP BY " + column + " ";
    return *this;
}

MySqlSelect &MySqlSelect::having(std::string condition)
{
    _query += "\nHAVING " + condition + " ";
    return *this;
}

MySqlSelect &MySqlSelect::limit(std::string limit)
{
    _query += "\nLIMIT " + limit + " ";
    return *this;
}

MySqlSelect &MySqlSelect::offset(std::string limit)
{
    _query += "OFFSET " + limit + " ";
    return *this;
}

std::string MySqlSelect::execute()
{
    std::string result = _query + ";";
    return result;
}