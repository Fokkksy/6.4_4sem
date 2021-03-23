
#include <fstream>
#include <iostream>
#include <vector>
#include "json.hpp"

using nlohmann::json;

struct Personality
{
    std::string first_name;
    std::string last_name;
    std::size_t phone_number;
    std::string address;
};

// Personality enterPerson(Personality p)
// {
//     std::cout << "Enter name: ";
//     std::cin >> p.first_name;
//     std::cout << std::endl;
//     std::cout << "Enter surname: ";
//     std::cin >> p.last_name;
//     std::cout << std::endl;
//     std::cout << "Enter phone number: ";
//     std::cin >> p.phone_number;
//     std::cout << std::endl;
//     std::cout << "Enter address: ";
//     std::cin >> p.address;
//     std::cout << std::endl; 
//     return p;  
// }

void to_JSON(Personality p, std::ofstream& f)
{
    std::cout << "Enter name: ";
    std::cin >> p.first_name;
    std::cout << std::endl;
    std::cout << "Enter surname: ";
    std::cin >> p.last_name;
    std::cout << std::endl;
    std::cout << "Enter phone number: ";
    std::cin >> p.phone_number;
    std::cout << std::endl;
    std::cout << "Enter address: ";
    std::cin >> p.address;
    std::cout << std::endl;

    json j;
    j["first_name"] = p.first_name;
    j["last_name"] = p.last_name;
    j["phone"] = p.phone_number;
    j["address"] = p.address;

    f << j.dump(4);
}
int main()
{
    std::size_t N;
    std::cout << "Enter number of people: ";
    std::cin >> N;
    std::cout << std::endl;

    std::vector<Personality> persons(N);

    for (auto i = 0; i < std::size(persons); ++i)
    {
        std::ofstream fout(std::string("hw6e4_P/person" + std::to_string(i + 1) + ".txt").c_str());
        // enterPerson(persons[i]);
        std::cout << "Data for " << i + 1 << " person" << std::endl;
        to_JSON(persons[i], fout);
    }




    return 0;
}