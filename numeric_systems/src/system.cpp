#include "system.hpp"
#include <cmath>
#include <algorithm>

System::System()
{
    number_dec = 0;
}

System::System(std::string number, int system)
{
    if (!set_number(number, system))
    {
        this->number_dec = 0;
    }
}

System::System(System &s)
{
    this->number_dec = s.number_dec;
}

std::string System::get_number(int system) const
{
    return decimal_to_custom(this->number_dec, system);
}

bool System::set_number(const std::string &number, int system)
{
    if (!is_number_valid(number, system))
    {
        return false;
    }
    this->number_dec = number_to_decimal(number, system);
    return true;
}

bool System::is_system_valid(int system)
{
    if (system >= MIN_SYSTEM && system <= MAX_SYSTEM)
        return true;
    return false;
}

bool System::is_number_valid(const std::string &number, int system)
{
    if (!is_system_valid(system) || number.empty())
        return false;
    return number.find_first_not_of(VALID_CHARS.substr(0, system)) == std::string::npos;
}

unsigned int System::number_to_decimal(const std::string &number, int system) const
{
    unsigned int decimal_num = 0;
    for (char digit : number)
    {
        decimal_num = decimal_num * system + VALID_CHARS.find(digit);
    }
    return decimal_num;
}

std::string System::decimal_to_custom(unsigned int decimal_number, int system) const
{
    std::string temp = decimal_number == 0 ? "0" : "";

    while (decimal_number > 0)
    {
        temp += VALID_CHARS[decimal_number % system];
        decimal_number /= system;
    }
    std::reverse(temp.begin(), temp.end());
    return temp;
}

std::ostream &operator<<(std::ostream &os, const System &sys)
{
    os << "bin: " << sys.decimal_to_custom(sys.number_dec, 2) << std::endl;
    os << "dec: " << sys.decimal_to_custom(sys.number_dec, 10) << std::endl;
    os << "hex: " << sys.decimal_to_custom(sys.number_dec, 16) << std::endl;
    os << "oct: " << sys.decimal_to_custom(sys.number_dec, 8) << std::endl;
    return os;
}
