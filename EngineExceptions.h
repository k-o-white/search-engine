//
// Created by teena on 30.03.2023.
//

#ifndef SEARCH_ENGINE_ENGINEEXCEPTIONS_H
#define SEARCH_ENGINE_ENGINEEXCEPTIONS_H
#include <exception>

class ConfigFileMissingException : public std::exception
{
public:
    ConfigFileMissingException() = default;

    [[nodiscard]] const char* what() const noexcept override
    {
        return "Config file is missing.";
    }
};

class ConfigFileEmptyException : public std::exception
{
public:
    ConfigFileEmptyException() = default;

    [[nodiscard]] const char* what() const noexcept override
    {
        return "Config file is empty.";
    }
};

class IncorrectVersionException : public std::exception
{
public:
    IncorrectVersionException() = default;

    [[nodiscard]] const char* what() const noexcept override
    {
        return "\"config.json\" has incorrect file version.";
    }
};

class RequestsFileMissingException : public std::exception
{
public:
    RequestsFileMissingException() = default;

    [[nodiscard]] const char* what() const noexcept override
    {
        return "Config file is missing.";
    }
};

#endif //SEARCH_ENGINE_ENGINEEXCEPTIONS_H
