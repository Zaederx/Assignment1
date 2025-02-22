#include "Football.h"


// -------------- Team --------------------

Team::Team(const string& name) {
	this->name = name;
	goalsScored = 0;
	goalsConceded = 0;
	defenseNum = 0;
}

void Team::addGoalsConceded(int g) {
	goalsConceded+= g;
	updatePlayers();
}

Team::~Team() {

}

void Team::updatePlayers() {
	if (defenseNum != 0) {
		for(int i =0 ; i < defenseNum ; i++) {
			defense[i]->sumPoints();
		}
	}
}

void Team::addDefensivePlayer(Player* p) {
	defense[defenseNum] = p;
	defenseNum++;

}

// -------------- Player ------------------

Player::Player(const string& name, Team* t) {
	this->name = name;
	team = t;
	score = 0;
	goalsScored = 0;
	assists = 0;
}

// don't remove this even if you want to make the destructor pure virtual
Player::~Player() {

}

void Player::addGoalsScored(int g) {
	goalsScored+=g;
	sumPoints();


}

void Player::addAssists(int a) {
	assists += a;
	sumPoints();
}

int Player::getScore() const {
	return score;
}

string Player::print() const {

	string print = role+": "+ name+", Team: "+ team->name+"\n";
	print+=	" Goals scored: "+ to_string(goalsScored)+"\n";
	print+=	" Assists: "+ to_string(assists) +"\n";
	print+=	" Goals conceded: " + to_string(team->goalsConceded) + "\n";
	print+=	" Score: "+to_string(score);
	return print;
}


// -------------- Attacker ------------------

Attacker::Attacker(const string& name, Team* t) : Player(name, t) {
	role = "Attacker";
}

Attacker::~Attacker() {
	// IMPLEMENT ME
}

void Attacker::sumPoints() {
	int points = (assists * 3);
	points+= (goalsScored*4);
	score = points;
}

int Attacker::getScore() const {
	return score;
}

string Attacker::print() const {
	return Player::print();
}


// -------------- Midfielder ------------------

Midfielder::Midfielder(const string& name, Team* t) : Player(name, t) {
	role = "Midfielder";
	score = 1;
	t->addDefensivePlayer(this);
}

Midfielder::~Midfielder() {
	// IMPLEMENT ME
}

void Midfielder::sumPoints() {
	int points = (assists * 3);
	points+= (goalsScored*5);
	if (team->goalsConceded == 0) {
		points+=1;
	}
	score = points;
}

int Midfielder::getScore() const {
	return score;
}

string Midfielder::print() const {
	return Player::print();
}

// -------------- Defender ------------------

Defender::Defender(const string& name, Team* t) : Player(name, t) {
	role = "Defender";
	score = 4;
	t->addDefensivePlayer(this);
}

Defender::~Defender() {
	// IMPLEMENT ME
}

void Defender::sumPoints() {
	int points = (assists * 3);
	points+= (goalsScored*6);

	if (team->goalsConceded == 0) {
		points+= 4;
	} else {
		points+= -(team->goalsConceded/2);
	}
	score = points;
}

int Defender::getScore() const {
	return score;
}

string Defender::print() const {
	return Player::print();
}

// -------------- Goalkeeper ------------------

Goalkeeper::Goalkeeper(const string& name, Team* t) : Player(name, t) {
 role = "Goalkeeper";
 shotsSaved = 0;
 score = 4;
 t->addDefensivePlayer(this);
}

Goalkeeper::~Goalkeeper() {
	// IMPLEMENT ME
}

void Goalkeeper::addShotsSaved(int ss) {
	shotsSaved+=ss;
	sumPoints();
}

//sum up points per respective category and value
void Goalkeeper::sumPoints() {
	int points = (shotsSaved/3);
	points+= (assists * 3);
	points+= (goalsScored*6);

	if (team->goalsConceded == 0) {
		points+= 4;
	} else {
		points+= -(team->goalsConceded/2);
	}
 score = points;

}
int Goalkeeper::getScore()  const  {
	return score;
}


string Goalkeeper::print() const {
	string print = role+": "+ name+", Team: "+ team->name+"\n";
	print+=	" Goals scored: "+ to_string(goalsScored)+"\n";
	print+=	" Assists: "+ to_string(assists)+"\n";
	print+=	" Goals conceded: " + to_string(team->goalsConceded) + "\n";
	print+=	" Shots saved: "+to_string(shotsSaved)+"\n";
	print+=	" Score: "+ to_string(score);
	return print;
}

// -------------- FantasyTeam ------------------

FantasyTeam::FantasyTeam() {
	teamSize = 0;
	totalScore = 0;
}


FantasyTeam::~FantasyTeam() {

}

bool FantasyTeam::addPlayer(Player* p) {
	if (teamSize == 11) {return false;}
	for (int i = 0 ; i < teamSize; i++){
		if (players[i] == p){
			return false;
		}
	}

	players[teamSize] = p;
	teamSize++;
	tallyScore();
	return true;
}

int FantasyTeam::getScore() const {
	return totalScore;
}

void FantasyTeam::tallyScore() {
	int temp = 0;
	//all all team member scores to totalScore
	for (int i =0; i < teamSize; i++) {
		temp += (*players[i]).getScore();
	}
	totalScore = temp;
}

