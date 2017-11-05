#include "../common.cpp"

using namespace std;

long long howManySolutionsPossible(int perimeter);
long long squareOf(long long inputNumber);

long long numberOfSolutions[1000000];

int main()
{
for (int perimeter = 1; perimeter <= 1000; perimeter++)
		numberOfSolutions[howManySolutionsPossible(perimeter)] = perimeter;
	
	long long maximumSolutions;
	for (maximumSolutions = 999999; numberOfSolutions[maximumSolutions] < 1; maximumSolutions--);
	
	cout << "For " << numberOfSolutions[maximumSolutions] << " there are " << maximumSolutions << " solutions possible, which is the maximum for perimeters under 1000 by the way" << endl;
	
	common.finalize();
	return 0;
}

long long howManySolutionsPossible(int perimeter)
{
	long long numberOfSolutions = 0;
	
	for (long long hypotenuse = perimeter/2; hypotenuse > 0; hypotenuse--)
		for (long long side1 = hypotenuse - 1; side1 > 0; side1--)
				if (squareOf(hypotenuse) == squareOf(side1) + squareOf(perimeter - hypotenuse - side1))
					numberOfSolutions++;
	
	return numberOfSolutions/2;
}

long long squareOf(long long inputNumber)
{
	return inputNumber * inputNumber;
}