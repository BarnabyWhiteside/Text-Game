#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print_vector( std::vector<int>::iterator beginningOfVector,
                   std::vector<int>::iterator endOfVector )
{


    for( auto it=beginningOfVector; it!=endOfVector; it=next(it) )
        std::cout << *it << ", ";

    for( auto it=prev(endOfVector); it!=beginningOfVector; it=prev(it) )
        std::cout << *it << ", ";


    std::cout << *beginningOfVector << std::endl;

}
