/* 7.22.c program to find an exit out of a maze
 * Steven Gonzale 009387092
 */
#include <stdio.h>

//definitions
#define MSIZE 12

//function declarations
void printMaze();
void mazeTraverse(char m[MSIZE][MSIZE], int x, int y, int d);

//main function
void main()	{
	//maze 
	char myMaze[MSIZE][MSIZE] = {
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
		'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#',
		'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#',
		'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#',
		'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.',
		'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', 
		'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',   
		'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
		'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#',
		'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#',
		'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#', 
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
		};
		
	//call to mazeTraverse function 
	mazeTraverse(myMaze, 2, 0, 0);
}

//mazeTraverse function 
void mazeTraverse(char m[MSIZE][MSIZE], int x, int y, int d)	{
	int i, j;	// counter for loops 
	m[x][y] = 'X';	// represents where we currently are in the maze
	printMaze(m);	// call to print the maze
	m[x][y] ='-';	// set just visited cell to visited
	
	//condition is we reach end of maze then return 
	if(x == MSIZE - 1 || y == MSIZE - 1)	{
		return;
	}
	
	// direction 0 == west
	if(d == 0)	{
		if(checkNext(m, x + 1, y) == 1)	{
		// first check if you can move to next cell in d direction 
		//recursive all to mazeTraverse
			mazeTraverse(m, x + 1, y, 3);
		}
		else if(checkNext(m, x, y + 1) == 1)	{
		// checks if you can move north from current cell
		//recursive all to mazeTraverse
			mazeTraverse(m, x, y + 1, 0);
		}
		else if(checkNext(m, x - 1, y) == 1)	{
		// checks if you can move each from current cell
		//recursive all to mazeTraverse
			mazeTraverse(m, x - 1, y, 1);
		}
		else if(checkNext(m, x, y - 1) == 1)	{
		//checks if you can move south from current cell 
		//recursive all to mazeTraverse
			mazeTraverse(m, x, y - 1, 2);
		} // end of nested checks 
	} // end to d == 0
	else if(d == 1)	{
	// direction 1 = north
		if(checkNext(m, x, y + 1) == 1)	{
		// first check if you can move to next cell in d direction 
		//recursive all to mazeTraverse
			mazeTraverse(m, x, y + 1, 0);
		}
		else if(checkNext(m, x - 1, y))	{
		//checks if you can move east from current cell 
		//recursive all to mazeTraverse
			mazeTraverse(m, x - 1, y, 1);
		}
		else if(checkNext(m, x, y - 1))	{
		// checks if you can move south from current sell
		//recursive all to mazeTraverse
			mazeTraverse(m, x, y - 1, 2);
		}
		else if(checkNext(m, x + 1, y, 3))	{
		//checks if you can move west from current cell
		//recursive all to mazeTraverse
			mazeTraverse(m, x + 1, y, 3);
		}//end to nested checks 
	}// end d = 1
	else if(d == 2)	{
	//direction 2 = east
		if(checkNext(m, x - 1, y))	{
		// first check if you can move to next cell in d direction 
		//recursive all to mazeTraverse
			mazeTraverse(m, x - 1, y, 1);
		}
		else if(checkNext(m, x, y - 1))	{
		// checks if you can move south from current direction
		//recursive all to mazeTraverse
			mazeTraverse(m, x, y - 1, 2);
		}
		else if(checkNext(m, x + 1, y))	{
		// checks if you can move west from the current cell 
		//recursive all to mazeTraverse
			mazeTraverse(m, x + 1, y, 3);
		}
		else if(checkNext(m, x, y + 1, 0))	{
		// checks if you can move north from current cell
		//recursive all to mazeTraverse
			mazeTraverse(m, x, y + 1, 0);
		}//end nested checks 
	}//end d = 2 
	else if(d == 3)	{
	//direction 3 = south 
		if(checkNext(m, x, y - 1))	{
		// first check if you can move to next cell in d direction 
		//recursive all to mazeTraverse
			mazeTraverse(m, x, y - 1, 2);
		}
		else if(checkNext(m, x + 1, y))	{
		//checks if you can move west from current cell
		//recursive all to mazeTraverse
			mazeTraverse(m, x + 1, y, 3);
		}
		else if(checkNext(m, x, y + 1))	{
		//checks to see if you can move north from current cell 
		//recursive all to mazeTraverse
			mazeTraverse(m, x, y + 1, 0);
		}
		else if(checkNext(m, x - 1, y))	{
		//checks to see if you can moce south from current cell 
		//recursive all to mazeTraverse
			mazeTraverse(m, x - 1, y, 1);
		} // end nested checks 
	} // end d = 3 
} // end mazeTraversal function 

// check next function checks a index of the next cell
int checkNext(char m[MSIZE][MSIZE], int x, int y)	{
	if(m[x][y] != '#')	{
		return 1;
	}
	else 	{
		return 0;
	} // end if - else statement 
} // end checkNext function 

// printMaze function prints the given 2d array
void printMaze(char m[MSIZE][MSIZE])	{
	int i, j; //varaible counters for the loops 
	printf("\n");
	for(i = 0; i < 12; i++)	{
		for(j = 0; j < 12; j++)	{
				printf("%c ", m[i][j]);
		}// end for statement 
		printf("\n");
	}//end for statmeent 
}// end printMaze function 
