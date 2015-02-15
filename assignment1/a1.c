/*
 * a1.c
 * 
 * Copyright 2015 subin <subin@subin-HP-G62-Notebook-PC>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

/* battleship game*/

/* trial1.cpp : Defines the entry point for the console application.*/


//#include "stdafx.h"
#include <stdio.h> 
//#include <conio.h>
#include<time.h>
#include<stdlib.h>
//#include<process.h>


///function declerations

int RandomNumber(int max);//RandomNumber declaration
void placeship(int defensive[15][15],int len);
void placeallship(int defensive[15][15]);
int Isvalidplacement( int defensive[15][15],int x,int y,int len,int orientation);
void showoffensivegrid( int shootgrid[15][15], int defensivegrid[15][15]);
int gamewon(int shootgrid[15][15],int defensive[15][15]);

///main funtion starting here
int main(int argc, char **argv)
{
	int io;int max1;int number;int w=0;int q=1;
int e; int f;int jo;
int r=0;int n;
int k;
int i=0;int j=0;int c=0;int defensive[15][15];
int shootgrid[15][15];
int offensivegridplayer[15][15];
int offensivegrid[15][15];
int len; int x=16;
int y=0;int valid=0;
char s='a';
//printf("i am here\n %c",s);
	//variable decleratiion

//printf("i am here2\n");
//initialise the defensive grid to zeros
for(i=0;i<15;i++)
	for(j=0;j<15;j++)
		defensive[i][j]=0;

i=0;j=0;
//initialise the shootgrid-----required	 
	 for(i=0;i<15;i++)
	    for(j=0;j<15;j++)
		   shootgrid[i][j]=0;
i=0;j=0;

placeallship(defensive);///!placed all the ships in the defensive grid


 do
{
	


/////updated offensive grid after the initial inside the while loop
showoffensivegrid( shootgrid, defensive);
   
			  ////taking input from the user----------------------------------------------------------

			  printf("enter the column and row number or press 'q' to quit\n");
	                scanf("%c%d",&s,&n);
				
	                  c=s-'a';                 ///ascii value is used to determine the column number
	             	  if(s!='q'){
					   shootgrid[n-1][c]=1;
                         if(gamewon(shootgrid,defensive))
			              { printf("congratulations");
			                w=1;
			                 }
				       }
             //   else break;
		 

//w= gamewon(shootgrid,defensive);
//printf(" %d  \n",w);




	
}while((w==0)||(s!='q'));
//getch();
//printf("i am here 34");
//getch();
	return 0;
	}

  
//RandomNumber definition   
 
    
int RandomNumber(int max)
{
	int max1=max;
	int number;
	int r;
	number = rand();
	r=(number % (max1)) +1; 
	return r;
}

////function to place the ship
void placeship(int defensive[15][15],int len)
{
	int len2=len;
	int orientation;
	int x1,y1,v,k;
	int x1d;
	int y1d;
	do
	{
		orientation=RandomNumber(1);
	// printf(" ori %d",orientation);
		if(orientation==1)
		{
			x1=RandomNumber(14);
			y1=RandomNumber(14-len);
		}
		else
		{
			y1=RandomNumber(14);
			x1=RandomNumber(14-len);
		}
		v= Isvalidplacement(defensive,x1,y1,len2,orientation);
	
	}while(v==0);

	 x1d=x1;
	 y1d=y1;

	for(k=0;k<len+1;k++)
	{	//int x1d,y1d;
	  
		if(orientation==0)
		{
			defensive[x1d][y1d]=2;
			y1d=y1d+1;
		}
		else
		{
			defensive[x1d][y1d]=2;
			x1d=x1d+1;
		}
	}
	
}

		//after geting the coordinates write the code to place the ships at their aray location,put values as 1 if there is ship

///function to check valid position
int Isvalidplacement( int defensive[15][15],int x,int y,int len,int orientation)
{ int len2=len;
	int v;int xi=x;
    int yi=y;
	int a;
	int orient=orientation; 
          if (orient==0)
             {for(a=0;a<len2;a++)
                 {  if (defensive[xi][yi]==2)
                         {v=0;
		                 } 
					else {v=1;}
						yi=yi+1;
                 }

             }

 else
             {for(a=0;a<len;a++)
                 {  if (defensive[xi][yi]==2)
                         {v=0;
		                 } 
				 else {v=1;}
                 xi=xi+1;
		          }

             }

		  return v;
}
//function to place all the ships randomly
void placeallship(int defensive[15][15])
{
	placeship(defensive,3);
	placeship(defensive,3);
	placeship(defensive,4);
	placeship(defensive,4);
	placeship(defensive,4);
	placeship(defensive,5);
	placeship(defensive,5);
}
//function to check if the game has been won;
int gamewon(int shootgrid[15][15],int defensive[15][15])
{
	int io;int jo;int flag=1;int win;
	int offensivegrid[15][15];
	for(io=0;io<15;io++)
		for(jo=0;jo<15;jo++)
		{
			offensivegrid[io][jo]=defensive[io][jo]+shootgrid[io][jo];
		}
	io=0;jo=0;

	for(io=0;io<15;io++)
	{	for(jo=0;jo<15;jo++)
		{
			if (offensivegrid[io][jo]==2)
			{ flag=0;}
		}
	}

	if (flag ==0)
	{
		win=0;
	}
	else
	{	win=1;
	}
return win;
}
//function to show the offensive grid
void showoffensivegrid( int shootgrid[15][15], int defensive[15][15])
{
int i,j,f,io,jo,e;
int offensivegrid[15][15];
	for(io=0;io<15;io++)
	for(jo=0;jo<15;jo++)
	{
	offensivegrid[io][jo]=defensive[io][jo]+shootgrid[io][jo];
	}

io=0;jo=0;	

//to print "." , " * " and "-" for various conditions.
printf("A  B  C  D  E  F  G  H  I  J  K  L  M  N  O\n");
for(i=0;i<15;i++)
{
	for(j=0;j<15;j++)
	{  if (offensivegrid[i][j]==1)
	{printf("-  ");}
	else  if (offensivegrid[i][j]==3)
	{printf("*  ");}
    else if ((offensivegrid[i][j]==0)||(offensivegrid[i][j]==2))
	{printf(".  ");}

    }
	
	printf(" %d  \n",i+1);
}

i=0;j=0;


}
