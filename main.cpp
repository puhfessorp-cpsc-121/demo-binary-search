
//
#include <iostream>
#include <math.h>
#include <vector>


//	PROTO
int bSearch(const std::vector<int>& v, int q);


//
using std::cout, std::endl;


//
int main()
{

	//	Pre-sorted vector
	std::vector<int> v = {1, 2, 4, 4, 10, 28, 29};

	//	Query every item in the vector
	std::vector<int> queries = v;

	//
	cout << "Searching every item in the following vector:" << endl;
	cout << "[";
	for ( size_t i = 0; i < v.size(); i++ ) {
		if ( i > 0 ) {
			cout << ", ";
		}
		cout << v[i];
	}
	cout << "]" << endl;

	for ( int q : queries ) {
		cout << "Result of searching for \"" << q << "\" is: " << bSearch(v, q) << endl;
	}

	return 0;
}


//
int bSearch(const std::vector<int>& v, int q) {

	//
	int start = 0;
	int end = v.size() - 1;

	int result = -1;

	// Loop until done
	while ( true ) {

		//	Handle only one item left to search
		if (start == end) {
			if (v[start] == q) {
				result = start;
			}
			break;
		}

		//	Inspect the middle point
		int middle = static_cast<int>(floor(
			(start + end) / 2					// This part needed correction
												// The "middle" should have been the average of start and end, not their difference
		));

		//	Middle point was a match: Success
		if (v[middle] == q) {
			result = middle;
			break;
		}

		//	Discard one side or the other
		if ( v[middle] > q ) {	// Get rid of the right side
			end = middle - 1;
		}
		else {	// Get rid of the left side
			start = middle + 1;
		}
	}

	return result;
}

