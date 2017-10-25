#ifndef tournament_h
#define tournament_h

typedef struct player
{
	int offensive;
	int defensive;
}Player;

typedef struct team
{
	char name[30];
	Player players[10];
	int nofplayer;
}Team;

Team * initializeTeam(int, char *);

Team * game(Team *,Team *);

Team * tournament(Team **, int);

void deleteTeam(Team *);

#endif
