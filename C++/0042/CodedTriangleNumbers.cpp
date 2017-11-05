#include "../common.cpp"

using namespace std;

void generateListOfTriangleNumbers();
int getNameScore(string word);

bool triangleNumbers[10000];

int main()
{
	vector<string> wordsList = common.readFromFile("./words.txt");
	int countOfTriangles = 0;
	
	generateListOfTriangleNumbers();
	
	for (string& word : wordsList)
		if (triangleNumbers[getNameScore(word)])
			countOfTriangles++;
	
	cout << "The number of triangle words in the given list is " << countOfTriangles << endl;
	
	common.finalize();
	return 0;
}

void generateListOfTriangleNumbers()
{
	int triangleNumber = 1;
	
	for (int index = 0; triangleNumber < 10000; index++)
	{
		triangleNumbers[triangleNumber] = true;
		triangleNumber = (index * (index + 1))/2;
	}
}

int getNameScore(string word)
{
	long long wordScore = 0;
	string currentCharacter;
	
	for (int i = 0; i < word.length(); i++)
	{
		currentCharacter = word.substr(i, 1);
		
		if (currentCharacter == "A")
			wordScore += 1;
		else if (currentCharacter == "B")
			wordScore += 2;
		else if (currentCharacter == "C")
			wordScore += 3;
		else if (currentCharacter == "D")
			wordScore += 4;
		else if (currentCharacter == "E")
			wordScore += 5;
		else if (currentCharacter == "F")
			wordScore += 6;
		else if (currentCharacter == "G")
			wordScore += 7;
		else if (currentCharacter == "H")
			wordScore += 8;
		else if (currentCharacter == "I")
			wordScore += 9;
		else if (currentCharacter == "J")
			wordScore += 10;
		else if (currentCharacter == "K")
			wordScore += 11;
		else if (currentCharacter == "L")
			wordScore += 12;
		else if (currentCharacter == "M")
			wordScore += 13;
		else if (currentCharacter == "N")
			wordScore += 14;
		else if (currentCharacter == "O")
			wordScore += 15;
		else if (currentCharacter == "P")
			wordScore += 16;
		else if (currentCharacter == "Q")
			wordScore += 17;
		else if (currentCharacter == "R")
			wordScore += 18;
		else if (currentCharacter == "S")
			wordScore += 19;
		else if (currentCharacter == "T")
			wordScore += 20;
		else if (currentCharacter == "U")
			wordScore += 21;
		else if (currentCharacter == "V")
			wordScore += 22;
		else if (currentCharacter == "W")
			wordScore += 23;
		else if (currentCharacter == "X")
			wordScore += 24;
		else if (currentCharacter == "Y")
			wordScore += 25;
		else if (currentCharacter == "Z")
			wordScore += 26;
	}
	
	return wordScore;
}