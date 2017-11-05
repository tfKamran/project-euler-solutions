#include "../common.cpp"
#define INPUTFILE "./poker.txt"

using namespace std;

class Hand
{
private:
	vector<string> cards;

public:
	Hand(string inputCards)
	{
		string swapCard;
		for (int index = 0; index < inputCards.length(); index += 3)
			cards.push_back(inputCards.substr(index, 2));
		for (int index1 = 0; index1 < 5; index1++)
			for (int index2 = 0; index2 < 5; index2++)
				if (index1 != index2 && getValueOfCard(index1) < getValueOfCard(index2))
				{
					swapCard = cards.at(index1);
					cards.at(index1) = cards.at(index2);
					cards.at(index2) = swapCard;
				}
		cards.push_back("endOfStack");
	}
	
	int getValueOfCard(int index)
	{
		if (cards.at(index).substr(0, 1) == "2")
			return 0;
		else if (cards.at(index).substr(0, 1) == "3")
			return 1;
		else if (cards.at(index).substr(0, 1) == "4")
			return 2;
		else if (cards.at(index).substr(0, 1) == "5")
			return 3;
		else if (cards.at(index).substr(0, 1) == "6")
			return 4;
		else if (cards.at(index).substr(0, 1) == "7")
			return 5;
		else if (cards.at(index).substr(0, 1) == "8")
			return 6;
		else if (cards.at(index).substr(0, 1) == "9")
			return 7;
		else if (cards.at(index).substr(0, 1) == "T")
			return 8;
		else if (cards.at(index).substr(0, 1) == "J")
			return 9;
		else if (cards.at(index).substr(0, 1) == "Q")
			return 10;
		else if (cards.at(index).substr(0, 1) == "K")
			return 11;
		else if (cards.at(index).substr(0, 1) == "A")
			return 12;
	}
	
	string getTypeOfCard(int index)
	{
		return cards.at(index).substr(1, 1);
	}
	
	string getTheRankOfHand()
	{
		vector<int> repeatingCards;
		vector<int> repeatingCardsValue;
		vector<int> historyOfRepeatingCards;
		
		if (getTypeOfCard(0) == getTypeOfCard(1) && getTypeOfCard(0) == getTypeOfCard(2) && getTypeOfCard(0) == getTypeOfCard(3) && getTypeOfCard(0) == getTypeOfCard(4))
		{
			if (getValueOfCard(0) == 8 && getValueOfCard(1) == 9 && getValueOfCard(2) == 10 && getValueOfCard(3) == 11 && getValueOfCard(4) == 12)
				return "9," + common.CStr(getValueOfCard(0));
			if (getValueOfCard(1) == getValueOfCard(0) + 1 && getValueOfCard(2) == getValueOfCard(0) + 2 && getValueOfCard(3) == getValueOfCard(0) + 3 && getValueOfCard(4) == getValueOfCard(0) + 4)
				return "8," + common.CStr(getValueOfCard(4));
			return "5," + common.CStr(getValueOfCard(4));
		}
		
		repeatingCards.clear();
		repeatingCardsValue.clear();
		historyOfRepeatingCards.clear();
		historyOfRepeatingCards.push_back(-1);
		for (int index1 = 0; index1 < 5; index1++)
		{
			int repeatsTimes = 1;
			
			while (find(historyOfRepeatingCards.begin(), historyOfRepeatingCards.end(), index1) != historyOfRepeatingCards.end())
				index1++;
			
			if (index1 < 5)
			{
				for (int index2 = 0; index2 < 5; index2++)
				{
					if (index1 != index2 && getValueOfCard(index1) == getValueOfCard(index2))
					{
						historyOfRepeatingCards.insert(historyOfRepeatingCards.begin(), index2);
						repeatsTimes++;
					}
				}
				if (repeatsTimes > 1)
				{
					repeatingCards.push_back(repeatsTimes);
					repeatingCardsValue.push_back(getValueOfCard(index1));
				}
			}
		}
		repeatingCardsValue.push_back(999);
		int swapCard;
		for (int index1 = 0; index1 < repeatingCardsValue.size() - 1; index1++)
			for (int index2 = 0; index2 < repeatingCardsValue.size() - 1; index2++)
				if (index1 != index2 && repeatingCardsValue.at(index1) < repeatingCardsValue.at(index2))
				{
					swapCard = repeatingCardsValue.at(index1);
					repeatingCardsValue.at(index1) = repeatingCardsValue.at(index2);
					repeatingCardsValue.at(index2) = swapCard;
				}
		if (repeatingCards.size() > 0 && repeatingCards.at(0) == 4)
			return "7," + common.CStr(repeatingCardsValue.at(repeatingCardsValue.size() - 2));
		switch(repeatingCards.size())
		{
			case 2:
				if (repeatingCards.at(0) == 2 && repeatingCards.at(1) == 3)
					return "6," + common.CStr(repeatingCardsValue.at(repeatingCardsValue.size() - 2));
				if (repeatingCards.at(0) == 3 && repeatingCards.at(1) == 2)
					return "6," + common.CStr(repeatingCardsValue.at(repeatingCardsValue.size() - 3));
				return "2," + common.CStr(repeatingCardsValue.at(repeatingCardsValue.size() - 2));
			case 1:
				if (repeatingCards.at(0) == 3)
					return "3," + common.CStr(repeatingCardsValue.at(repeatingCardsValue.size() - 2));
				return "1," + common.CStr(repeatingCardsValue.at(repeatingCardsValue.size() - 2));
		}
			
		if (getValueOfCard(1) == getValueOfCard(0) + 1 && getValueOfCard(2) == getValueOfCard(0) + 2 && getValueOfCard(3) == getValueOfCard(0) + 3 && getValueOfCard(4) == getValueOfCard(0) + 4)
			return "4," + common.CStr(getValueOfCard(4));
		
		return "0," + common.CStr(getValueOfCard(4));
	}
};

class pokerHands
{
private:
	vector<Hand> playerOne;
	vector<Hand> playerTwo;
	
public:
	void distributeCards(vector<string> input)
	{
		for (string& line : input)
		{
			playerOne.push_back(Hand(line.substr(0, 14)));
			playerTwo.push_back(Hand(line.substr(15, 14)));
		}
	}
	
	int whoWins(int hand)
	{
		string rankOfPlayerOnesHand = "Gelooo";
		rankOfPlayerOnesHand = playerOne.at(hand).getTheRankOfHand();
		string rankOfPlayerTwosHand = playerTwo.at(hand).getTheRankOfHand();
		
		if (common.CInt(rankOfPlayerOnesHand.substr(0, 1)) > common.CInt(rankOfPlayerTwosHand.substr(0, 1)))
			return 1;
		else if (common.CInt(rankOfPlayerOnesHand.substr(0, 1)) < common.CInt(rankOfPlayerTwosHand.substr(0, 1)))
			return 2;
		
		if (common.CInt(rankOfPlayerOnesHand.substr(2, rankOfPlayerOnesHand.length() - 2)) > common.CInt(rankOfPlayerTwosHand.substr(2, rankOfPlayerTwosHand.length() - 2)))
			return 1;
		else if (common.CInt(rankOfPlayerOnesHand.substr(2, rankOfPlayerOnesHand.length() - 2)) < common.CInt(rankOfPlayerTwosHand.substr(2, rankOfPlayerTwosHand.length() - 2)))
			return 2;
		else
		{
			int index = 4;
			
			for (; playerOne.at(hand).getValueOfCard(index) == playerTwo.at(hand).getValueOfCard(index); index--);
			
			if (playerOne.at(hand).getValueOfCard(index) > playerTwo.at(hand).getValueOfCard(index))
				return 1;
			else
				return 2;
		}
	}
	
	int howManyHandsDoesPlayerOneWin()
	{
		int winsOfPlayerOne = 0;
		
		for (int handIndex = 0; handIndex < playerOne.size(); handIndex++)
			if (whoWins(handIndex) == 1)
				winsOfPlayerOne++;
		
		return winsOfPlayerOne;
	}
} pokerHands;

int main()
{
	pokerHands.distributeCards(common.readFromFile(INPUTFILE));
	
	cout << "Player 1 wins " << pokerHands.howManyHandsDoesPlayerOneWin() << " hands" << endl;
	
	common.finalize();
	return 0;
}

/*
 * "Highest value card" = 0
 * "One pair" = 1
 * "Two pairs" = 2
 * "Three of a kind" = 3
 * "Straight" = 4
 * "Flush" = 5
 * "Full house" = 6
 * "Four of a kind" = 7
 * "Straight flush" = 8
 * "Royal flush" = 9
*/