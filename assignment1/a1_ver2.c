//My signation version, history
//Matrix shooting game
//Version 1; 
//Date February 8, 2015
//working version Feb15
//for debug
//
//
//
#define SIZE 15
#include "function.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
//variable declarations
	int size = SIZE;
	int defensive[size][size],offensive[size][size],shootgrid[size][size];
	int i,j,cd,col,col2,n,random,L,win,shipor,shipxy,shipl;
	char c,show,user_command[4];


	//starts here
	initallgrids(defensive,offensive,shootgrid);

	placeshipallships(defensive);

	//place a ship. get a randomm orientation and position
	//if or ==0 then horizontal..and position is x for length of ship l
	//ship is in d[x][y] d[x][y+1]..d[x][y+(l-1)]
	//start with ship of length 2	
	//if(user_command[0]!='q')
	do
	{
		printoffensivegrid(offensive);
		printf("Shoot at target by entering column letter and row number. E.g. b6 \n");
		
		//take the user input , contains a letter and a number 0-99. e.g, a3, g15
		
		scanf("%s", user_command);
		
		//if user does to opt to quit ('q') then continue with the program, else exit program.
		if (user_command[0]!='q')
		{
			
			user_command[3]=0;
			//first letter entered
			cd = user_command[0]-'a';
			//first digit entered
			col=user_command[1]-'0';
			//second digit entered
			col2=user_command[2]-'0';
			
			//if user gives a single digit, then [2] character is a null character.
			//else the input is a two digit number
			if(user_command[2]=='\0')
				n=col;//printf("single digit \n");
			else
				n=col*10+col2;//printf("two digit \n");
			
			printf(" entered letter and number coresponds to arrary %d , %d  \n", cd,n);
			
			shootgrid[n][cd]= 1;
			//printshootgrid(shootgrid);
			
			
		}
		else
			break;
		
		win=gamewon(shootgrid,defensive,offensive,size);
		//printf("win = %d\n",win);
	
	}while(win==0);
	
	if (win ==1)
		printf("\x1b[34m"" CONGRATULATIONS !!!. YOU HAVE SHOT ALL THE SHIPS""\x1b[0m");
	
	
	return 0;		
}
