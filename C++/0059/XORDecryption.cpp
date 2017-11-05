#include "../common.cpp"
#include "string.h"

using namespace std;

class functions
{
private:
	vector<int> encryptedMessage;
	vector<string> decryptedMessages;
	
public:
	void fetchEncryptedMessages(string fileName)
	{
		vector<string> inputFromFile = common.readFromFile(fileName);
		int nextCommaIndex = 0;
		for (string& line : inputFromFile)
		{
			nextCommaIndex = -1;
			
			while (nextCommaIndex != 0)
			{
				nextCommaIndex = common.stringIndexOf(line, ",");
				if (nextCommaIndex > - 1)
				{
// 					cout << common.CInt(line.substr(0, nextCommaIndex)) << endl;
					encryptedMessage.push_back(common.CInt(line.substr(0, nextCommaIndex)));
					line = line.substr(nextCommaIndex + 1, line.length() - nextCommaIndex - 1);
				}
				else if (line.length() > 0)
				{
					encryptedMessage.push_back(common.CInt(line));
// 					cout << line.length() << " : " << line << endl;
					break;
				}
				else
					break;
			}
		}
	}
	
	char XOR(int key, int encryptedCharacter)
	{
		char returnValue = (key ^ encryptedCharacter);
		return returnValue;
	}
	
	vector<int> decodeASCII(int firstCharacterOfKey, int secondCharacterOfKey, int thirdCharacterOfKey, vector<int> encodedASCII)
	{
		vector<int> key;
		key.push_back(firstCharacterOfKey);
		key.push_back(secondCharacterOfKey);
		key.push_back(thirdCharacterOfKey);
		int keyIndex = -1;
		vector<int> decodedASCII;
		
		for (int& encryptedCharacter : encodedASCII)
		{
			keyIndex++;
			if (keyIndex > 2)
				keyIndex = 0;
			decodedASCII.push_back(XOR(key.at(keyIndex), encryptedCharacter));
		}
		
		return decodedASCII;
	}
	
	vector<int> convertToASCII(string message)
	{
		vector<int> ASCIICodes;
		char currentCharacter;
		
		for (int index = 0; index < message.length(); index++)
		{
// 			strcpy(currentCharacter, message.substr(index, 1));
			currentCharacter = message[index];//.substr(index, 1);//.c_str();
			ASCIICodes.push_back(currentCharacter);
		}
		
		return ASCIICodes;
	}
	
	string convertToCharacters(vector<int> ASCIICodes)
	{
		string returnValue;
		char currentCharacter;
		stringstream stringStream;
		
		for (int& character : ASCIICodes)
		{
			currentCharacter = character;
			if (currentCharacter != ' ')
				stringStream << currentCharacter;
		}
		stringStream >> returnValue;
		
		decryptedMessages.push_back(returnValue);
		
		return returnValue;
	}
	
	bool isProperDecryption(string decryptedMessage)
	{
		if (common.stringContains(decryptedMessage, "chapter"))
			return true;
		return false;
	}
	
	long long getSumOfDecodedASCIICodes()
	{
		vector<int> decodedASCII;
		long long sumOfCodes = 0;
		
		for (int firstCharacterOfKey = 'a'; firstCharacterOfKey <= 'z'; firstCharacterOfKey++)
			for (int secondCharacterOfKey = 'a'; secondCharacterOfKey <= 'z'; secondCharacterOfKey++)
				for (int thirdCharacterOfKey = 'a'; thirdCharacterOfKey <= 'z'; thirdCharacterOfKey++)
				{
					decodedASCII = decodeASCII(firstCharacterOfKey, secondCharacterOfKey, thirdCharacterOfKey, encryptedMessage);
					decryptedMessages.push_back(convertToCharacters(decodedASCII));
					
					if (isProperDecryption(convertToCharacters(decodedASCII)))
						for (int& code : decodedASCII)
							sumOfCodes += code;
				}
		
		return sumOfCodes;
	}
} functions;

int main()
{
	functions.fetchEncryptedMessages("./cipher1.txt");
	
	cout << "The sum of decoded ASCII codes is " << functions.getSumOfDecodedASCIICodes() << endl;
	
	common.finalize();
	return 0;
}