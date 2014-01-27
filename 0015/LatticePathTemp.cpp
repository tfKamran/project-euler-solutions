#include "../common.cpp"
#define GRID "20"
#define TWICEGRID "40"

using namespace std;

int main()
{
	cout << "The number of possible paths is " << common.divide(common.factorial(TWICEGRID), (common.multiply(common.factorial(GRID), common.factorial(common.subtract(TWICEGRID, GRID))))) << endl;
	
	common.finalize();
	return 0;
}