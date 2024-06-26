#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void copy(int array1[52][102],int array2[52][102])
{
	for (int j=0;j<52;j++)
	{
		for (int i=0;i<102;i++)
		{
			array1[j][i] = array2[j][i];
		}
	}
}

//The life function is the most important function in the program.
//It counts the number of cells surrounding the center cell, and 
//determines whether it lives, dies, or stays the same.
void life(int array[52][102], char choice)
{
	//Copies the main array to a temp array so changes can be entered into a grid
	//without effecting the other cells and the calculations being performed on them.
	int temp[52][102];
	copy(array, temp);
	for (int j=1; j<51; j++)
	{
		for (int i=0; i<101; i++)
		{
			if (choice == 'm')
			{
				//The Moore neighborhood checks all 8 cells surrounding the current cell in the array.
				int count = 0;
				count = array[j-1][i] + 
						array[j-1][i-1] +
						array[j][i-1] +
						array[j+1][i-1] +
						array[j+1][i] +
						array[j+1][i+1] +
						array[j][i+1] +
						array[j-1][i+1];
				if (count < 2 || count > 3) temp[j][i] = 0; // cell dies
				if (count == 2) temp[j][i] = array[j][i]; // stays the same
				if (count == 3) temp[j][i] = 1; // stays alive or is born
			} else if (choice == 'v') 
			{
		        //The Von Neumann neighborhood checks only the 4 surrounding cells in the array,
		        //(N, S, E, and W).
		        int count = 0;
				count = array[j-1][i] +
						array[j][i-1] +
						array[j+1][i] +
						array[j][i+1];
				if (count < 2 || count > 3) temp[j][i] = 0; // the cell dies
				if (count == 2) temp[j][i] = array[j][i]; // stays the same
				if (count == 3) temp[j][i] = 1; // stays alive or is born

			}
		}
	}
	// copies completed temp array to array
	copy(temp, array);
}

//Checks to see if two arrays are exactly the same. 
//This is used to end the simulation early, if it 
//becomes stable before the 100th generation. This
//occurs fairly often in the Von Neumann neighborhood,
//but almost never in the Moore neighborhood.
bool compare(int array1[52][102], int array2[52][102])
{
	int count = 0;
	for (int j=0;j<52;j++){
		for (int i=0;i<102;i++)
		{
			if (array1[j][i]==array2[j][i]) count++;
		}
		//Since the count gets incremented every time the cells are exactly the same,
		//an easy way to check if the two arrays are equal is to compare the count to 
		//the dimensions of the array multiplied together.
		if (count == 52*102) return true;
		else return false;
	}
}

//This function prints the 50 x 100 part of the array, since that's the only
//portion of the array that we're really interested in. A live cell is marked
//by a '*', and a dead or vacant cell by a ' '.
void print(int array[52][102])
{
	for (int j=1;<51;j++)
	{
		for (int i=1;i<101;i++)
		{
			if (array[j][i] == 1) cout << '*';
			else cout << ' ';
		}
		cout << endl;
	}
}

int main()
{
	int gen0[52][102];
	int todo[52][102];
	int backup[52][102];
	char neighborhood;
	char again;
	char cont;
	bool comparison;
	string decoration;
	//Instructions on how the program is used, along with the rules of the game.
	cout << endl << "This program is a C++ implementation of John Conway's Game of Life."
	<< endl << "With it, you can simulate how \"cells\" interact with each other." << endl 
	<< endl << "There are two types of neighborhoods you can choose, the"
	<< endl << "Moore, and the Von Neumann.  The Moore neighborhood checks"
	<< endl << "all 8 surrounding cells, whereas the Von Neumann checks"
	<< endl << "only the 4 cardinal directions: (N, S, E, and W)." << endl
	<< endl << "The rules of the \"Game of Life\" are as follows:" << endl
	<< endl << "1. Any live cell with fewer than two live neighbors dies, as if caused by under-population."
	<< endl << "2. Any live cell with two or three live neighbors lives on to the next generation."
	<< endl << "3. Any live cell with more than three live neighbors dies, as if by overcrowding."
	<< endl << "4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction." << endl
	<< endl << "The initial configuration (Generation 0) of the board is determined randomly."
	<< endl << "Every hundred Generations you will get the option to end or continue the simulation." 
	<< endl << "If a system becomes \"stable\" (meaning the system does not change from one"
	<< endl << "generation to the next), the simulation will end automatically." << endl << endl;
	
	//Loop to check if user wants to keep simulating.
	do
	{
		// loop to check for proper inputs
		do
		{
			cout << "Which neighborhood would you like to use (m or v): ";
			cin >> neighborhood;
		} while (neighborhood != 'm' && neighborhood != 'v');
		// clear screen for program to start fresh
		system("clear");
		int i = 0;
		// this loop does the bulk of simulation
		do
		{
			// generate intitial random state of the board
			srand(time(NULL));

			//The actual array is 102 x 52, but it's easier to just leave the surrounding part of
			//the array blank so it doesn't effect the calculations in the life function above.
			for (int j =1;j<52;j++)
			{
				for (int i=1; i<101; i++) gen0[j][i] = rand() % 2;
			} 
			// determine size of decoration
			if (i<10) decoration = "#############";
			else if (i>=10 && i<100) decoration = "##############";
			else if (i>=100 && i<1000) decoration = "###############";
			else if (i>=1000 && i<10000) decoration = "################";
			else decoration = "#################";

			//Prints the generation.  If i == 0, the gen0 array is copied to the 
			//todo array, and is printed before any functions act upon it.
			cout << decoration << endl <<< "Generation " << i << ":" << decoration << endl;
		}
	}
}
