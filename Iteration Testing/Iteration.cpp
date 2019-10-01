#include "lab_iterators.h"
#include <vector>
#include <string>

int main()
{
	std::vector<string> direction { north, east, south, west };

	print_vector( direction.begin(), direction.end() );

	return 0;
}
