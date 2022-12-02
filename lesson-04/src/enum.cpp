#include <iostream>
#include "enum.hpp"

enum Color
{
    RED,
    YELLOW,
    BLACK
};

enum class HttpError
{
    OK = 200,
    NotFound = 404,
    Empty = 201
};

HttpError make_request()
{
    return HttpError::OK;
}

int main()
{
    Color c = YELLOW;
    HttpError error = make_request();

    switch(error)
    {
        case HttpError::OK:
            std::cout << "200 OK" << std::endl;
            break;
        default:
            std::cout << "Unknown error" << std::endl;
            break;
    }

    switch(c)
    {
        case YELLOW:
            std::cout << "Yellow" << std::endl;
            break;
        case RED:
            std::cout << "RED" << std::endl;
            break;
        case BLACK:
            std::cout << "BLACK" << std::endl;
            break;
        default:
            break;
    }
    return 0;
}
