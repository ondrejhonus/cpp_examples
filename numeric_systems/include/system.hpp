#pragma once
#include <ostream>
#include <iostream>

class system
{
public:
    system();
    system(int system, std::string number);
    system(system& s);

    ~system() = default;

    std::string get_number(int system);
    // void get_system();

    bool set_number(std::string number, int system);

    friend std::ostream& operator<<(std::ostream& os, system& sys);

private:
    int system_base, number_dec;
    static const unsigned int MIN_SYSTEM = 2;
    static const unsigned int MAX_SYSTEM = 16;
    inline static const std::string VALID_CHARS = "0123456789ABCDEF";

    bool is_system_valid(int system);
    bool is_number_valid(std::string number);

    void number_to_decimal();
    std::string decimal_to_custom(int system);

};