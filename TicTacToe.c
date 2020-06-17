#include <stdio.h>
int box[3][3],P1=1,P2=2;
int checkDiag1()
{
	int i,j;
	int key=box[0][0],flag=1;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
			{
				if(box[i][j]!=key)
				{
					flag--;
					break;
				}
			}
		}
	}
	return flag;
}
int checkDiag2()
{
	int i,j;
	int key=box[0][2],flag=1;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i+j==2)
			{
				if(box[i][j]!=key)
				{
					flag--;
					break;
				}
			}
		}
	}
	return flag;
}
int checkRow(int row)
{
	int i,j;
	int flag=1;
	int key= box[row][0];
	for(i=0;i<3;i++)
	{
		if(box[row][i]!=key)
		{
			flag--;
			break;
		}
	}
	return flag;
}
int checkColumn(int column)
{
	int i,j;
	int flag=1;
	int key=box[0][column];
	for(i=0;i<3;i++)
	{
		if(box[i][column]!=key)
		{
			flag--;
			break;
		}
	}
	return flag;
}
void DrawBox()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(box[i][j]==NULL)
				printf("%d%d ",i,j);
			else if(box[i][j]==P1)
				printf("X  ");
			else
				printf("O  ");
		}
		printf("\n\n");
	}
}
void getInput(int player)
{
	
	printf("Player %d turn\nSelect box of you choice: ",player);
	int bx;
	scanf("%d",&bx);
	int i=bx%10;
	int j=bx/10;
	box[i][j]=player;
}

int nullCount()
{
	int i,j,count=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(box[i][j]==NULL)
				count++;
		}
	}
	return count;
}

int checkWinner()
{
	int i,j;
	int RowCheck=0,ColumnCheck=0;
	for(i=0;i<3;i++)
	{
		if(checkRow(i))
		{
			RowCheck=1;
			break;
		}
		if(checkColumn(i))
		{
			ColumnCheck=1;
			break;
		}
	}
	if(RowCheck || ColumnCheck || checkDiag1() || checkDiag2())
		return 1;
	else
		return 0;
}



void startGame()
{
	DrawBox();
	int player=1;
	int tieCheck=0;
	while(1)
	{
		getInput(player);
		system("clear");
		DrawBox();
		if(checkWinner())
			break;
		if(nullCount()==0)
		{
			tieCheck++;
			break;
		}
		player=(player==1)?2:1;
	}
	if(tieCheck)
		printf("It's a Draw.\n");
	else
		printf("Player %d Wins!!!\n",player);
}
void newGame()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			box[i][j]=NULL;
		}
	}
}
void main()
{
	int ch=0;
	do
	{
		printf("1. New Game\n2. Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					newGame();
					startGame();
					break;
				}
			case 2:
				{
					printf("Exitng......\n");
					break;
				}
			default:
				printf("Wrong Choice\n");
		}
	}while(ch!=2);
}
