/*
 * function.c
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
void initallgrids(int defensive[SIZE][SIZE],int offensive[SIZE][SIZE],int shootgrid[SIZE][SIZE]);
int RandomNumber(int max);
void printdeffensivegrid(int defensive[SIZE][SIZE], int size);
void placeshipallships(int defensive[SIZE][SIZE]);
void placeship(int defensive[SIZE][SIZE],int len);
int Isvalidplacement( int defensive[SIZE][SIZE],int x,int y,int len,int orientation);
int gamewon(int shootgrid[SIZE][SIZE],int defensive[SIZE][SIZE],int offensive[SIZE][SIZE],int size);
void printshootgrid(int defensive[SIZE][SIZE]);
void printoffensivegrid(int offensive[SIZE][SIZE]);
void initallgrids(int defensive[SIZE][SIZE],int offensive[SIZE][SIZE],int shootgrid[SIZE][SIZE])
{
	int i,j;
	int size=SIZE;
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			defensive[i][j]=0;
		
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			offensive[i][j]=0;		
	
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			shootgrid[i][j]=0;		

}
int RandomNumber(int max)
{  
	int max1=max;
   int number;
   int r;
   
	   number = rand();
   r=(number % (max1+1)); 
   
   return r;
}
void printdeffensivegrid(int defensive[SIZE][SIZE],int size)
{	
	//printf("\n enter print defensive grid function \n");
	int size1=SIZE;
	printf("\n The Deffensive Grid (only for debug purpose, user odes should not see this\n");
	printf("    A B C D E F G H I J K L M N O\n"); 		
	int i,j;
	for(i=0;i<size1;i++)
	{   printf("%3d ", i);
		for(j=0;j<size1;j++)
			{if (defensive[i][j]==2)
				printf("\x1b[31m""%d ""\x1b[0m",defensive[i][j]);
			else
				printf("%d ",defensive[i][j]);
			}
			
		printf("\n");
	}
	//printf("\n exit print defensive grid function \n");
}

void printshootgrid(int shootgrid[SIZE][SIZE])
{
	int i,j,show,size;
	size=SIZE;
	for(i=0;i<size;i++)
		{   printf("%3d ", i);
			for(j=0;j<size;j++)
				{
					if (shootgrid[i][j] == 0)
						show= '.';
					else if (shootgrid[i][j] == 1)
						show= '*';
				printf("%c ",show);
			}
			printf("\n");
		}
}
void printoffensivegrid(int offensive[SIZE][SIZE])
{
	int i,j,show,size;
	
	size=SIZE;
	

	printf("\n The Offensive Grid \n");
	printf("    A B C D E F G H I J K L M N O\n"); 	
	
	for(i=0;i<size;i++)
		{   printf("%3d ", i);
			for(j=0;j<size;j++)
				{
					if ((offensive[i][j] == 0)||(offensive[i][j] == 2))
						show= '.';
					else if (offensive[i][j] == 1)
						show= '-';
					else if (offensive[i][j] == 3)
						show= '*';
				printf("%c ",show);
			}
			printf("\n");
		}
}

void placeshipallships(int defensive[SIZE][SIZE])
{	int L;
	int size=SIZE;
	for (L=4;L<5;L++)
	{
	//printf("\n Length = %d\n",L);
	placeship(defensive,L);
	printdeffensivegrid(defensive,size);
	}
}

void placeship(int defensive[SIZE][SIZE],int len)
{	//printf("\n enter placeship function \n");
	int len2=len;
	int orientation;
	int x1,y1,v,k;
	int x1d;
	int y1d;
	int size=SIZE;
	do
	{
		orientation=RandomNumber(1);
		if(orientation==1)
		{
			x1=RandomNumber(size-len2-1);
			y1=RandomNumber(size-1);
		}
		else
		{
			y1=RandomNumber(size-len2-1);
			x1=RandomNumber(size-1);
		}
		
		
		v= Isvalidplacement(defensive,x1,y1,len2,orientation);
	
	}while(v==0);

	 x1d=x1;
	 y1d=y1;

	for(k=0;k<len2;k++)
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
	
	printf("orient = %d, x1 = %d, y1 = %d\n", orientation, x1,y1);
	
	//printf("\n exit placeship function \n");
}

int Isvalidplacement( int defensive[SIZE][SIZE],int x,int y,int len,int orientation)
{ 	int len2=len;
	int v;int xi=x;
    int yi=y;
	int a;
	int orient=orientation; 
		if (orient==0)
		{	for(a=0;a<len2;a++)
			{  
				if (defensive[xi][yi]==2)
                {v=0;
		        } 
				else 
				{v=1;
				}
				yi=yi+1;
			}
		}

		else
        {
			for(a=0;a<len;a++)
            {  
				if (defensive[xi][yi]==2)
                {v=0;
		        } 
				else 
				{v=1;
				}
                xi=xi+1;
			}

		}

		return v;
}

int gamewon(int shootgrid[SIZE][SIZE],int defensive[SIZE][SIZE],int offensivegrid[SIZE][SIZE],int size)
{
	int io;int jo;int flag=1;int win;
	//int size1 = size;
	//int offensivegrid[size1][size1];
	for(io=0;io<15;io++)
		for(jo=0;jo<15;jo++)
		{
			offensivegrid[io][jo]=defensive[io][jo]+shootgrid[io][jo];
		}
	io=0;jo=0;
	//printoffensivegrid(offensivegrid);

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


//function takes input as max. output will be a random number from 0 to max
//eg. input >>2 , output can be 0/1/2.

