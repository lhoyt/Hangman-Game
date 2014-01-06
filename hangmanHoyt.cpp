// Hang Man Game
// C++ Programming
// Lindsay Hoyt

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void showBoard(vector<char> );
void showUsedLetters(vector<char> , int);
void addGuessToBoard(char, vector<char> &, vector<char> &, vector<char> & , int &);
bool checkGameOver(vector<char> board, vector<char> answer, int);
void drawMan(int);

int main()
{
	//VECTOR FOR HOLDING GUESSED LETTERS
	// usedLetters
	vector<char> usedLetters;

	//VECTOR TO HOLD THE MYSTERY WORD
	//theAnswer
	vector<char> theAnswer;

	// TO SIMPLIFY PROGRAM FOR NOW, HARD CODE A STRING WITH THE MYSTERY WORD
	// e.g. string word = "Harry Potter";
	string word = "Deltora Quest";

	//DEFINE MISCELLANEOUS VARIABLES
	bool success = false, endOfGame = false;
	char guess;
	int strikes = 0;

	//ADD MYSTERY WORD TO THE THEANSWER VECTOR
    for (unsigned int i = 0; i < word.size(); i++)
    {
		//cout << word[i] << endl;
        theAnswer.push_back(toupper(word[i]));
    }
       
    //CREATE EMPTY BOARD THE SIZE OF THE MYSTERY WORD AND FILL WITH *
    // theBoard
    vector<char> theBoard(word.size(), '*');


    //ADD SPACES IN THE BOARD WHERE NECESSARY
    for (unsigned int i = 0; i < word.size(); i++)
    {
		//LOOK IN THEANSWER FOR SPACES, IF FOUND REPLACE THAT SPOT IN THEBOARD WITH A SPACE
		if (theAnswer[i] == ' ')
        theBoard[i] = ' ';
    }

	while (!endOfGame)
	{
		showBoard(theBoard);

		cout << "Guess a Letter" << endl;
		cin >> guess;

		addGuessToBoard(toupper(guess), theBoard, theAnswer, usedLetters, strikes);
		showUsedLetters(usedLetters, strikes);
		
		endOfGame = checkGameOver(theBoard, theAnswer, strikes);
	}
	cin >> guess;

	return 0;
}


// this function will show the letters the have already been guessed
// it will also show how many strikes the user has
// used - is the vector holding the used letters
// s - is the number of strikes
void showUsedLetters(vector<char> used, int s)
{
	cout << "The letters you have used so far are: " << "\n" << endl;
	
	for (unsigned int i = 0; i < used.size(); i++)
	{
		cout << used[i] << "  ";
	}

	cout << endl;
	cout << "The number of strikes that you have are: " << s << "\n" <<  endl;
}

// This function will display the game board
// board - is the vector holding the game board
void showBoard(vector<char> board)
{
	cout << "This is the Game Board: " << "\n" << endl;
	for (unsigned int i = 0; i < board.size(); i++)
	{
		cout << board[i] << "  ";
	}

	cout << endl;
}

// THIS FUNCTION WILL CHECK TO SEE IF THE GUESSED LETTER IS PART OF THE ANSWER
// IF IT IS PART OF ANSWER, FILL IN APPROPRIATE PLACE IN THE BOARD WITH THE LETTER
// IF IT IS NOT PART OF THE ANSWER, TELL USER
// ALSO ADD THE GUESSED LETTER TO THE LETTERS USED VECTOR
// g - is the guess
// board - is the vector holding the game board
// answer - is the vector holding the solution (the mystery word)
// used - is the vector holding the used letters
// s - is the number of strikes
void addGuessToBoard(char g, vector<char> &board, vector<char> &answer, vector<char> &used, int &s)
{
	int matchesFound = 0;		
	// create a loop to itereate through entire theAnswer vector - 
	// in the loop check if guessed letter matches currrent element of the vector
	// in the loop - add 1 to a counter to check how many matches are found
	// if match found then add the letter to theBoard vector
	for(unsigned int i = 0; i < answer.size(); i++)
	{
		if(g == answer[i])
		{
			board[i] = g;
			matchesFound++;
		}	
	}

	// outside of the loop
	// check if counter is still 0, then print message to user stating letter not found
	if(matchesFound == 0)
	{
		s++;
		cout << "The letter was not found." << "\n" << endl;
	}

	// add the letter to usedLetters
	used.push_back(g);
}

// THIS FUNCTION WILL DETERMINE IF GAME IS OVER
// CHECK IF THE BOARD IS AN EXACT MATCH TO THE ANSWER - IF SO GAME OVER
//  ALSO CHECK IF USER HAS 6 STRIKES - IF SO GAME OVER
// OTHERWISE GAME NOT OVER
// board - is the vector holding the game board
// answer - is the vector holding the solution (the mystery word)
// s - is the number of strikes
bool checkGameOver(vector<char> board, vector<char> answer, int s)
{
	// WE ARE DEFINING A GAME OVER IF:
	//  THE USER HAS 6 STRIKES AGAINST THEM
	//  THE USER HAS GUESSED ALL THE LETTERS CORRECTLY

	bool gameOver = false;     //NOT OVER
	int matches = 0;

	// FIRST CHECK IF USER WINS
	// message user they won!!
	// check if every letter theAnswer matches every letter in theBoard
	// if they all match then return true
	for(unsigned int i = 0; i < answer.size(); i++)
	{
		if(answer[i] == board[i])
		{
			matches++;
		}

		if(matches == answer.size())
		{
			cout << "Congrats!! You have won!!!" << "\n" << endl;
			return true;
		}

		if(s >= 6)
		{
			cout << "You have lost!" << "\n" << endl;
			return true;
		}
	}

	// ALSO CHECK IF USER HAS 6 OR MORE STRIKES - LOSE
	// message the user they lost!!
	// if six or greater then return true
	return false;
}

// OPTIONAL
// BASED ON THE NUMBER OF STRIKES, DRAW OUT THE MAN
void drawMan(int strikes)
{
	
}