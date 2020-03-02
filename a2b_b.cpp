//Assignment 2b: Pattern Displays written by Melinda Sterne
/*
	what does this program do

	INPUT: User enters base size of pyramid and char value to run the program again or exit the program
	OUTPUT: Outputs postcard from Giza and prompts for user
	VALIDATION: Verify user is inputting a value great than 4 and less than 20, is not negative, or non numeric.  Verify user selects correct option to run program again or quit.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	char again = 'Y';
	int row = 0, col = 0, padding = 0;
	do
	{
		cout << "Enter a value to represent the base of a pyramid (greater than 4 and not to exceed 20): ";
		cin >> col;
		//skip the newline character
		cin.ignore();
		//cin validation for extraneous input
		while(!cin || col > 20 || col < 5)
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "OOPS! Looks like you typed some bad data here!\nThe acceptable base for the pyramid should range from 5 to 20..."<< endl;
			cout << "Enter a value to represent the base of a pyramid (greater than 4 and not to exceed 20): ";
			cin >> col;
		}

		padding = (40 - col)/2;
		//if else structure to assign col an odd value and row the middle value of col
		if(col % 2 == 0)
		{
			row = (col/2)+1;
			col++;
		}
		else
		{
			row = (col/2)+1;
		}
		//output/draw postcard top
		cout << "************** A POSTCARD **************" << endl;
		for(int postage = 0; postage < 3; postage++)
		{
			for(int postageMark = 0; postageMark < 9; postageMark++)
			{
				cout << "*";
			}
			cout << endl;
		}
		//draw pyramid
		for(int rows = 0, blanks = (padding + (row-1)); rows < row; rows++, blanks--)
		{
			for(int print = 0; print < blanks; print++)
			{
				cout << " ";
			}
			
			for(int print = 0; print < rows; print++)
			{
				cout << "*";
			}
			cout << "*";
			for(int print = 0; print < rows; print++)
			{
				cout << "*";
			}
			for(int print = 0; print < blanks; print++)
			{
				cout << " ";
			}
			cout << endl;
		}
		//draw postcard bottom
		cout << endl;
		cout << "********** A PYRAMID FROM GIZA ********" << endl;
		cout << endl;

		//prompt user to run program again ro quit
		cout << "To try my shape generator program again type Y for Yes and N for No: ";
		again = cin.get();		
		
		//cin validation for extraneous input
			while(((again == 'Y') + (again == 'N')) == 0)
			{
				cin.clear();
				cin.ignore(200, '\n');
				cout << "OOPS! Looks like you typed some bad data here!\nThe acceptable response is Y for YES or N for No..."<< endl;
				cout << "To try my shape generator program again type Y for Yes and N for No: ";
				cin >> again;
			}
		
	}while(again == 'Y');
	cout << "Now exiting the shape generator program......." << endl;
	return 0;
}

