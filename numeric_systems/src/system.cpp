#include "system.hpp"

system::system(){
    number_dec = 0;}

std::string system::get_number(int system)
{
    return "";
}

bool system::set_number(std::string number, int system)
{
    if (is_number_valid(number))
}

bool system::is_system_valid(int system)
{
    if (system >= MIN_SYSTEM && system <= MAX_SYSTEM) return true;
    return false;
}

bool system::is_number_valid(std::string number)
{
    const std::string allowed_characters = VALID_CHARS.substr(0, system_base);
    return number.find_first_not_of(allowed_characters) == std::string::npos;
}

std::string system::decimal_to_custom(int system)
{
    
}
