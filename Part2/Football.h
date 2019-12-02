#include <string>

using namespace std;
class Player;
class FantasyTeam;

#ifndef FOOTBALL_H
#define FOOTBALL_H
// Class for a real-life team
class Team {

friend class Player;
friend class Attacker;
friend class Midfielder;
friend class Defender;
friend class Goalkeeper;
public:

	Team(const string& name);

	~Team();

	// default 1 is assumed.
	void addGoalsConceded(int g = 1);


private:
	string name;
	int goalsScored;
	int goalsConceded;
	Player * defense[11];
	int defenseNum;

	void updatePlayers();
	//for adding Keepers and Defenders to team
	//so they can be updated when goals are conceded
	void addDefensivePlayer(Player* p);
};


// Class for a footballer
// You must turn this into an abstract class
class Player {

	friend class Team;
public:

	Player() = delete;

	Player(const string& name, Team* t);

	// Destructor
	 virtual ~Player();

	// Increases the player's number of goals scored by g.
	// If g is omitted, 1 is assumed
	virtual void addGoalsScored(int g = 1);

	// Increases the player's number of assists by a.
	// If a is omitted, 1 is assumed
	void addAssists(int a = 1);

	// Returns the score of this player, based on all the individual
	// and team statistics. It is assumed that the caller knows what
	// they are doing and have called the various add..() functions
	// before calling this function.
	virtual int getScore() const = 0;

	// Returns a string that includes the player's name, the position
	// they play (goalkeeper/attacker etc.), the name of
	virtual string print() const;

	virtual void sumPoints()=0;


protected:
	string name;
	Team* team;
	string role;
	int score;
	int goalsScored;
	int assists;
};

// Classes for each of the 4 roles
// Most functions are explained in the Player class above

class Attacker : public Player {
	friend class Team;
public:
	Attacker(const string& name, Team* t);
	~Attacker();
	void sumPoints();
	int getScore() const;
	string print() const;



};

class Midfielder : public Player {
public:
	Midfielder(const string& name, Team* t);
	~Midfielder();
	void sumPoints();
	int getScore() const;
	string print() const;

};

class Defender : public Player {
public:
	Defender(const string& name, Team* t);
	~Defender();
	void sumPoints();
	int getScore() const;
	string print() const;

};

class Goalkeeper : public Player {
public:
	Goalkeeper(const string& name, Team* t);
	~Goalkeeper();
	void sumPoints();
	int getScore() const;
	string print() const;

	// Increase the number of shots saved by this goalkeeper by ss. 
	// If ss is omitted, 1 is assumed
	void addShotsSaved(int ss = 1);

private:
	int shotsSaved;
};

// Class for a fantasy team
class FantasyTeam {

public:
	// Constructor. Should initialise team to 0 players
	FantasyTeam();

	~FantasyTeam(); // destructor

	// Add p to be part of this fantasy team, returning true if successful.
	bool addPlayer(Player* p);

	// Returns the total score of all players in this fantasy team.
	int getScore() const;

	void tallyScore();
private:
	// Member variables: the 11 players
	// You must not change this.
	Player* players[11];
	int teamSize;
	int totalScore;

};
#endif/*FOOTBALL_H*/
