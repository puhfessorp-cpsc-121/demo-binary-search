
//
#include <vector>


//	PROTO
int bSearch(const std::vector<int>& v, int q);


//
int main()
{
	return 0;
}


//
int bSearch(const std::vector<int>& v, int q) {
	int start = 0;
	int end = v.size() - 1;

	int result = -1;
	while ( true ) {
		if (start == end) {// Handle end of search
			if (v[start] == q) {
				result = start;
			}
			break;
		}
		int middle = static_cast<int>(floor(
			(end - start) / 2
		));
		if (v[middle] == q) {
			result = middle;
			break;
		}
		if ( v[middle] > q ) {	// Get rid of the right side
			end = middle - 1;
		}
		else {	// Get rid of the left side
			start = middle + 1;
		}
	}
}
