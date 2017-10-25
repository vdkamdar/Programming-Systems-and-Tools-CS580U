#include"tournament.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>

Team * initializeTeam(int num, char * teamName)               //Initialize values to players. (offensive and defensive)
{

	int i,k,rand1,rand2;

	Team * t = calloc(1,sizeof(*t));

	for(i=0;i<num;i++)
	{
		t->players[i].offensive = 0;
		t->players[i].defensive = 0;
	}

	for(i=0;i<num;i++)
	{
		rand1 = (rand() % 10) + 1;
		rand2 = (rand() % 7) + 1;

		t->players[i].offensive = rand1;
		t->players[i].defensive = rand2;
	}

	for(k=0;k<strlen(teamName);k++)
	{
		t->name[k] = teamName[k];
	}

	t->nofplayer = num;
return t;

}

Team * game(Team * t1, Team * t2)             //Computes the winner of the game. Also implements the handicap mechanism.
{
	if(t1==NULL && t2==NULL) { return NULL; }

	int totalofft1=0, totaldeft1=0, totalofft2=0, totaldeft2=0, finalofft1=0, finalofft2=0, scoret1=0, scoret2=0, j=0;

	for(j=0;j< (t1->nofplayer);j++)
	{
		totalofft1 = totalofft1 + t1->players[j].offensive;
		totaldeft1 = totaldeft1 + t1->players[j].defensive;
	}

	if(totalofft1 - totaldeft1 == 1)
	{
		totaldeft1++;
	}
	else if(totalofft1 - totaldeft1 ==2)
	{
		totaldeft1 = totaldeft1 + 2;
	}

	 for(j=0;j< (t1->nofplayer);j++)
        {
		totalofft2 = totalofft2 + t2->players[j].offensive;
                totaldeft2 = totaldeft2 + t2->players[j].defensive;
        }

// ~~~~~~~~~  Handicap mechanism :
//	      If defensive team is 4 or less points backwards than the offensive team,
//            it gets a the difference added to its score as bonus, and hence a chance to score more
//	      totaling with the next 10 attempts acting as offensive against the then defensive team.

        if(totalofft2 - totaldeft1 == 1)
        {
                totaldeft1++;
		printf("\n Handicap Mechanism used!");
        }

	else if(totalofft2 - totaldeft1 == 2)
        {
                totaldeft1 = totaldeft1 + 2;
                printf("\n Handicap Mechanism used!");
        }

	 else if(totalofft2 - totaldeft1 == 3)
        {
                totaldeft1 = totaldeft1 + 3;
                printf("\n Handicap Mechanism used!");
        }

	else  if(totalofft2 - totaldeft1 == 4)
        {
                totaldeft1 = totaldeft1 + 4;
                printf("\n Handicap Mechanism used!");
        }


// ~~~~~~~~~~~~~


	for(j=0;j<10;j++)
	{
		finalofft1 = (rand() % totalofft1) + 1;

		if(finalofft1 < totaldeft2) { scoret2++; }

		else if(finalofft1 > totaldeft2) { scoret1++; }

		else if(finalofft1 == totaldeft2) { scoret2++; }
	}

	for(j=0;j<10;j++)
        {
                finalofft2 = (rand() % totalofft2) + 1;

                if(finalofft2 < totaldeft1) { scoret1++; }

                else if(finalofft2 > totaldeft1) { scoret2++; }

                else if(finalofft2 == totaldeft1) { scoret1++; }
        }

	printf("\n\n************** SCORES ***************\n\n");

	printf("\n%s :\t %d ", t1->name, scoret1);
	printf("\t%s :\t %d \n", t2->name, scoret2);

	if(scoret1>scoret2) { printf("\nWinner of the game is:\t%s\n", t1->name); return t1; }

	else if(scoret2>scoret1) { printf("\nWinner of the game is:\t%s\n", t2->name); return t2; }

	else if(scoret1==scoret2) { printf("\nIt`s a tie and Winner of the game is:\t%s\n", t1->name); return t1; }
}

Team * tournament(Team ** league, int numofteams)                     //creates a single elimination tournament where if a team loses a single game, it eliminates.
{

	int n, i=0, j=1, k=0, l=0, m=1, p=0, round=1, totalround, z;
	n = numofteams;
	totalround = log2(n);

	Team * winner[100];                                //keeps track of the winner of each game

	if((n != 0) && !(n & (n - 1)))                       //checks if the number of teams is a power of two
	{
		if(round==1)
		{
			while(i<(n-1) && j<n)
			{
				winner[k]=game(league[i],league[j]);
				i=i+2;
				j=j+2;
				k++;
			}
		}

		n = n/2;
		round++;

		while(round!=1 && round<=totalround)
		{
			while(l<(n-1) && m<n)
			{
				winner[p]=game(winner[l],winner[m]);
				l=l+2;
				m=m+2;
				p++;
			}

			round++;
			n = n/2;
			l=0;
			m=1;
			p=0;
		}
		return winner[0];
	}

	else
	{
		printf("\n The number of teams is invalid!!\n");
		return NULL;
	}

}

void deleteTeam(Team * t)            //cleans the memory
{
	free(t);
	t = NULL;
}
