/*
* This program is used to test sorting functions on images
* Author: Richard Purcell May 01 2020.
* Notes: This follows the template inclusion model shown in
*        https://docs.microsoft.com/en-us/cpp/cpp/source-code-organization-cpp-templates?view=vs-2019
*/

#include <iostream>
#include <vector>
#include "sorting.h"

int main( int argc, char** argv) {


    std::vector<int>vec;
    vec.push_back(13);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(7);
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(10);
    int sz = vec.size();
    std::cout << "Entered array : ";
    for (int n = 0; n < sz; n++)
    {
        std::cout << vec[n] << " ";
    }
    std::cout << "\n";
    std::cout << "Sorted array : ";
    merge_sort(vec, 0, sz - 1);
    for (int n = 0; n < sz; n++)
    {
        std::cout << vec[n] << " ";
    }
    std::cout << "\n\n";

    std::vector<char> c;
    c.push_back('d');
    c.push_back('y');
    c.push_back('h');
    c.push_back('l');
    c.push_back('e');
    c.push_back('a');
    int sz1 = c.size();
    std::cout << "Entered array : ";
    for (int n = 0; n < sz1; n++)
    {
        std::cout << c[n] << " ";
    }
    std::cout << "\n";
    std::cout << "Sorted array : ";
    merge_sort(c, 0, sz1 - 1);
    for (int n = 0; n < sz1; n++)
    {
        std::cout << c[n] << " ";
    }
    std::cout << "\n\n";

    std::vector<std::string> str;
    str.push_back("car");
    str.push_back("dog");
    str.push_back("apple");
    str.push_back("ball");
    str.push_back("tree");
    int sz2 = str.size();

    std::cout << "Entered array : ";
    for (int n = 0; n < sz2; n++)
    {
        std::cout << str[n] << " ";
    }
    std::cout << "\n";
    std::cout << "Sorted array : ";
    merge_sort(str, 0, sz2 - 1);
    for (int n = 0; n < sz2; n++)
    {
        std::cout << str[n] << " ";
    }
    std::cout << "\n";

    return 0;

    return 0;

}

