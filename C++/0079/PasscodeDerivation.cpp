#include "../common.cpp"

using namespace std;

int getIndexOf(vector<string> theVector, string item);

vector<string> loggedAttempts;
vector<string> passcode;

int main()
{
	loggedAttempts = common.readFromFile("./keylog.txt");
	passcode.push_back("-");
	string currentAttempt;
	int previousDigitIndex, currentDigitIndex, nextDigitIndex;
	string currentDigit;
	
	for (string& attempt : loggedAttempts)
	{
		currentAttempt = attempt;
		
		attempt = " " + attempt + " ";
		for (int index = 1; index < attempt.length() - 1; index++)
		{
			currentDigit = attempt.substr(index, 1);
			previousDigitIndex = getIndexOf(passcode, attempt.substr(index - 1, 1));
			currentDigitIndex = getIndexOf(passcode, currentDigit);
			nextDigitIndex = getIndexOf(passcode, attempt.substr(index + 1, 1));
			
			if (currentDigitIndex == passcode.size())
			{
				if (previousDigitIndex != passcode.size())
				{
					if (previousDigitIndex != passcode.size() - 1)
						passcode.insert(passcode.begin() + previousDigitIndex + 1, currentDigit);
					else
						passcode.push_back(currentDigit);
				}
				else if (nextDigitIndex != passcode.size())
					passcode.insert(passcode.begin() + nextDigitIndex, currentDigit);
				else
					passcode.push_back(currentDigit);
			}
			else
			{
				if (previousDigitIndex != passcode.size() && currentDigitIndex < previousDigitIndex)
				{
					passcode.at(currentDigitIndex) = passcode.at(previousDigitIndex);
					passcode.at(previousDigitIndex) = currentDigit;
				}
				
				if (nextDigitIndex != passcode.size() && currentDigitIndex > nextDigitIndex)
				{
					passcode.at(currentDigitIndex) = passcode.at(nextDigitIndex);
					passcode.at(nextDigitIndex) = currentDigit;
				}
			}
		}
	}
	
	passcode.at(0) = "";
	cout << "The passode is ";
	for (string& digit : passcode)
		cout << digit;
	cout << endl;
	
	common.finalize();
	return 0;
}

int getIndexOf(vector<string> theVector, string item)
{
	for (int index = 0; index < theVector.size(); index++)
		if (theVector.at(index) == item)
			return index;
	
		return theVector.size();
}