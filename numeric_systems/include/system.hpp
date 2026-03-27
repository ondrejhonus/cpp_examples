#pragma once
#include <ostream>
#include <iostream>
#include <string>

class System
{
public:
    System();
    System(std::string number, int system);
    System(System& s);

    ~System() = default;

    std::string get_number(int system) const;
    // void get_system();

    bool set_number(const std::string &number, int system);

    friend std::ostream& operator<<(std::ostream& os, const System& sys);

private:
    unsigned int number_dec;
    static const unsigned int MIN_SYSTEM = 2;
    static const unsigned int MAX_SYSTEM = 16;
    inline static const std::string VALID_CHARS = "0123456789ABCDEF";

    bool is_system_valid(int system);
    bool is_number_valid(const std::string &number, int system);

    unsigned int number_to_decimal(const std::string &number, int system) const;
    std::string decimal_to_custom(unsigned int decimal_number, int system) const;

};