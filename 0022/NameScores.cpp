#include "../common.cpp"
#define LISTFILE "./names.txt"

using namespace std;

long long calculateNameScore(int index, string name);

string* namesList;

int main()
{
	int numberOfNames = 5163;
	namesList = common.fetchFromFile(LISTFILE);
	
	for (int i = 0; i < numberOfNames; i++)
		for (int j = 0; j < numberOfNames; j++)
			if (i != j && namesList[j].compare(namesList[i]) > 0)
			{
				string nameToBeSwapped = namesList[j];
				namesList[j] = namesList[i];
				namesList[i] = nameToBeSwapped;
			}
	
	string output = "";
	long long totalNameScores = 0;
	for (int i = 0; i < numberOfNames; i++)
	{
		totalNameScores += calculateNameScore(i + 1, namesList[i]);
// 		cout << i + 1 << ": " << namesList[i] << ": " << calculateNameScore(i + 1, namesList[i]) << endl;
		output = output + common.CStr(i + 1) + ": " + namesList[i] + ": " + common.CStr(calculateNameScore(i + 1, namesList[i])) + "\n";
	}
	
	cout << "The total of name score is " << totalNameScores << endl;
	output += "The total of name score is " + common.CStr(totalNameScores);
	
	common.writeToFile("./output.txt", output);
	
	return 0;
}

long long calculateNameScore(int index, string name)
{
	long long nameScore = 0;
	string currentCharacter;
	
	for (int i = 0; i < name.length(); i++)
	{
		currentCharacter = name.substr(i, 1);
		
		if (currentCharacter == "A")
			nameScore += 1;
		else if (currentCharacter == "B")
			nameScore += 2;
		else if (currentCharacter == "C")
			nameScore += 3;
		else if (currentCharacter == "D")
			nameScore += 4;
		else if (currentCharacter == "E")
			nameScore += 5;
		else if (currentCharacter == "F")
			nameScore += 6;
		else if (currentCharacter == "G")
			nameScore += 7;
		else if (currentCharacter == "H")
			nameScore += 8;
		else if (currentCharacter == "I")
			nameScore += 9;
		else if (currentCharacter == "J")
			nameScore += 10;
		else if (currentCharacter == "K")
			nameScore += 11;
		else if (currentCharacter == "L")
			nameScore += 12;
		else if (currentCharacter == "M")
			nameScore += 13;
		else if (currentCharacter == "N")
			nameScore += 14;
		else if (currentCharacter == "O")
			nameScore += 15;
		else if (currentCharacter == "P")
			nameScore += 16;
		else if (currentCharacter == "Q")
			nameScore += 17;
		else if (currentCharacter == "R")
			nameScore += 18;
		else if (currentCharacter == "S")
			nameScore += 19;
		else if (currentCharacter == "T")
			nameScore += 20;
		else if (currentCharacter == "U")
			nameScore += 21;
		else if (currentCharacter == "V")
			nameScore += 22;
		else if (currentCharacter == "W")
			nameScore += 23;
		else if (currentCharacter == "X")
			nameScore += 24;
		else if (currentCharacter == "Y")
			nameScore += 25;
		else if (currentCharacter == "Z")
			nameScore += 26;
	}
	
	nameScore *= index;
		
	return nameScore;
}