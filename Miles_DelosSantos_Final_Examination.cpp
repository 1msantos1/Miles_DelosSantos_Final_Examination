//***********************************************************************************
//Program Name: Final Examination (Connect 4 Game)
//
//Summary: It's Connect Four, whoever gets 4 in a row vertically, horizontally, or
//		   diagonally wins. Player 1 uses X checkers and Player 2 uses O checkers.
//		   Checkers sink to the bottom of whatever column you place them in.        
//         
//            
//***********************************************************************************

#include <string> // added this so I could use the string data type for naming players 1 & 2
#include <iostream> // for cin & cout
using namespace std; // If I put this in, I don't have to put std:: infront of cout or cin statements

// for rendering the board
char arr[6][7] = { {',',',',',',',',',',',',','}, {',',',',',',',',',',',',','},{',',',',',',',',',',',',','},{',',',',',',',',',',',',','},{',',',',',',',',',',',',','},{',',',',',',',',',',',',','} };

int c1 = 6;
int c2 = 6;
int c3 = 6;
int c4 = 6;
int c5 = 6;
int c6 = 6;
int c7 = 6;

int insert(int x) // function for placing the X & O checkers
{
	//check values
	if (x == 1)
	{
		if (c1 > 0)
		{
			c1--;
			return c1;
		}
		else
			return -1;
	}
	else if (x == 2)
	{
		if (c2 > 0)
		{
			c2--;
			return c2;
		}
		else
			return -1;
	}
	else if (x == 3)
	{
		if (c3 > 0)
		{
			c3--;
			return c3;
		}
		else
			return -1;
	}
	else if (x == 4)
	{
		if (c4 > 0)
		{
			c4--;
			return c4;
		}
		else
			return -1;
	}
	else if (x == 5)
	{
		if (c5 > 0)
		{
			c5--;
			return c5;
		}
		else
			return -1;
	}
	else if (x == 6)
	{
		if (c6 > 0)
		{
			c6--;
			return c6;
		}
		else
			return -1;
	}
	else if (x == 7)
	{
		if (c7 > 0)
		{
			c7--;
			return c7;
		}
		else
			return -1;
	}
	else
		return -1;
}

// Player name function
void playerNames(string& player1, string& player2)
{
	cout << "Enter name for Player 1: "; // prompt player 1 for name, retrive name and store it in player1 variable
	cin >> player1;
	cout << endl; // this line's just here to make the program look nice
	cout << "Enter name for Player 2: "; // prompt player 2 for name, retrive name and store it in player2 variable
	cin >> player2;
	cout << endl; // this line's also just here to make the program look nice
}

// Player 1 win cases
bool win_p1_row(int a) 
{
	int count = 0;
	for (int j = 0; j < 7; j++)
	{
		if (arr[a][j] == 'X')
		{
			count++;
			if (count == 4)
				return true;
		}
		else
			count = 0;
	}
	return false;
}

bool win_p1_diag(int a, int b)
{
	int count = 0;
	b--;
	if (a >= b)
	{
		a -= b;
		b = 0;
		while (a < 6)
		{
			if (arr[a][b] == 'X')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b++;
		}
	}
	else
	{
		b -= a;
		a = 0;
		while (b < 7)
		{
			if (arr[a][b] == 'X')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b++;
		}
	}
	return false;
}

bool win_p1_diag2(int a, int b)
{
	int count = 0;
	b--;
	int c = a + b;
	if (c < 7 && c>2)
	{
		b = c;
		a = 0;
		while (a < 6)
		{
			if (arr[a][b] == 'X')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b--;
		}
	}
	else if (c > 6 && c < 9)
	{
		b = 6;
		a = c - 6;
		while (a < 6)
		{
			if (arr[a][b] == 'X')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b--;
		}
	}
	return false;
}

bool win_p1_col(int a)
{
	int count = 0;
	a--;
	for (int j = 0; j < 6; j++)
	{
		if (arr[j][a] == 'X')
		{
			count++;
			if (count == 4)
				return true;
		}
		else
			count = 0;
	}
	return false;
}
// End of Player 1 win cases

// PLayer 2 win cases
bool win_p2_row(int a)
{
	int count = 0;

	for (int j = 0; j < 7; j++)
	{
		if (arr[a][j] == 'O')
		{
			count++;
			if (count == 4)
				return true;
		}
		else
			count = 0;
	}
	return false;

}

bool win_p2_col(int a)
{
	int count = 0;
	a--;
	for (int j = 0; j < 6; j++)
	{
		if (arr[j][a] == 'O')
		{
			count++;
			if (count == 4)
				return true;
		}
		else
			count = 0;
	}
	return false;

}

bool win_p2_diag(int a, int b)
{
	int count = 0;
	b--;
	if (a >= b)
	{
		a -= b;
		b = 0;
		while (a < 6)
		{
			if (arr[a][b] == 'O')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b++;
		}
	}
	else
	{
		b -= a;
		a = 0;
		while (b < 7)
		{
			if (arr[a][b] == 'O')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b++;
		}
	}
	return false;
}

bool win_p2_diag2(int a, int b)
{
	int count = 0;
	b--;
	int c = a + b;
	if (c < 7 && c>2)
	{
		b = c;
		a = 0;
		while (a < 6)
		{
			if (arr[a][b] == 'O')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b--;
		}
	}
	else if (c > 6 && c < 9)
	{
		b = 6;
		a = c - 6;
		while (a < 6)
		{
			if (arr[a][b] == 'O')
			{
				count++;
				if (count == 4)
					return true;
			}
			else
				count = 0;
			a++;
			b--;
		}
	}
	return false;
}
// End of Player 2 win cases

void board(int a, int b, char x) // shows the board
{
	arr[a][b - 1] = x; // When a move is made, a piece of the board is filled by a checker.

	// top of the board
	for (int f = 1; f < 8; f++)
	{
		cout << f << '|';
	}
	cout << endl;
	// rest of the board
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << arr[i][j] << '|';
		}
		cout << endl;
	}
}

int main()
{
	string player1, player2; // Declaring the strings that hold the player names
	playerNames(player1, player2); // Retrieves player names


	cout << "**********************" << endl;
	cout << "Connect 4: C++ Edition" << endl; // Renders a little title screen
	cout << "**********************" << endl << endl;
	// top of the board
	for (int f = 1; f < 8; f++)
	{
		cout << f << '|';
	}
	cout << endl;
	// rest of the board
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << arr[i][j] << '|';
		}
		cout << endl;
	}
	int c = 0; // board starts out empty
	while (c < 21) // the game will keep going until the board is filled up or a player gets 4 in a row
	{
		int p1 = 0, p2 = 0; // variable for players 1 & 2
		int col = 0; // column variable
		int k = 0; // row variable

		while (p1 < 1) // Player 1's turn
		{
			cout << player1 << ", pick a column: ";
			col = 0;
			cin >> col;
			k = insert(col); // finds out what row the checker will end up on
			while (k == -1) // for when Player 1 enters an invalid column
			{
				cout << "That isn't a valid column, try again: ";
				cin >> col;
				k = insert(col);
			}
			board(k, col, 'X'); // display board after Player 1 makes a successful move

			p1++;
		}
		// Did Player 1 win the game?
		if (win_p1_row(k) == true) // if player 1 gets four in a row horizontally
		{
			cout << player1 << " Wins!" << endl;
			break;
		}

		if (win_p1_col(col) == true) // if player 1 gets four in a row vertically
		{
			cout << player1 << " Wins!" << endl;
			break;
		}

		if (win_p1_diag(k, col) == true) // if player 1 gets four in a row diagonally
		{
			cout << player1 << " Wins!" << endl;
			break;
		}
		if (win_p1_diag2(k, col) == true) // if player 1 gets four in a row diagonally
		{
			cout << player1 << " Wins!" << endl;
			break;
		}

		while (p2 < 1) // Player 2's turn
		{
			cout << player2 << ", pick a column: ";
			col = 0;
			cin >> col;
			k = insert(col);// finds out what row the checker will end up on
			while (k == -1) // for when Player 2 enters an invalid column
			{
				cout << "That isn't a valid column, try again: ";
				cin >> col;
				k = insert(col);
			}
			board(k, col, 'O'); // displays board after player 2 makes a successful move
			p2++;
		}
		// Did Player 2 win the game?
		if (win_p2_row(k) == true) // if player 2 gets four in a row horizontally
		{
			cout << player2 << " Wins!" << endl;
			break;
		}
		if (win_p2_col(col) == true) // if player 2 gets four in a row vertically
		{
			cout << player2 << " Wins!" << endl;
			break;
		}
		if (win_p2_diag(k, col) == true) // if player 2 gets four in a row diagonally
		{
			cout << player2 << " Wins!" << endl;
			break;
		}
		if (win_p2_diag(k, col) == true) // if player 2 gets four in a row diagonally
		{
			cout << player2 << " Wins!" << endl;
			break;
		}
		c++;

		if (c == 21) // displays message if game ends in a tie (board is filled up and nobody got 4 in a row)
		{
			cout << "This game's a tie!";
		}
	}
}