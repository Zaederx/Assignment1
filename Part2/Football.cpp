/* Please note: even though it says IMPLEMENT ME, in some cases
   the implementation can be empty. In fact, you may wish to remove
   some of the functions entirely
*/
#include "Football.h"

// -------------- Team --------------------

Team::Team(const string& name) {
	this->name = name;
	goalsScored = 0;
	goalsConceded = 0;
}

void Team::addGoalsConceded(int g) {
	goalsConceded+= g;
}

Team::~Team() {
	// IMPLEMENT ME
}

// -------------- Player ------------------

Player::Player() {
	name = nullptr;
	team = nullptr;
	role = "unassigned";
	score = 0;
	goals = 0;
	assists = 0;

}

Player::Player(const string& name, Team* t) {
	this->name = name;
	team = t;
	score = 0;
	goals = 0;
	assists = 0;
}

// don't remove this even if you want to make the destructor pure virtual
Player::~Player() {
	delete name;
	delete [] team;
}

void Player::addGoalsScored(int g) {
	goals+=g;
}

void Player::addAssists(int a) {
	assists += a;
}

int Player::getScore() const {
	return score;
}

string Player::print() const {

	string print = role+": "+ name+", Team: "+ team->name+"\n";
	print+=	" Goals scored: "+ goals+"\n";
	print+=	" Assists: "+ assists +"\n";
	print+=	" Goals conceded: " + team->goalsConceded + "\n";
	print+=	" Score: "+ score;
	return print;
}

// -------------- Attacker ------------------

Attacker::Attacker(const string& name, Team* t) : Player(name, t) {
	role = "Attacker";
}

Attacker::~Attacker() {
	// IMPLEMENT ME
}

int Attacker::getScore() const {
	// IMPLEMENT ME
	// below are just stub code
	int removeMe = 0;
	return removeMe;
}

string Attacker::print() const {
	return Player::print();
}

// -------------- Midfielder ------------------

Midfielder::Midfielder(const string& name, Team* t) : Player(name, t) {
	role = "Midfielder";
}

Midfielder::~Midfielder() {
	// IMPLEMENT ME
}

int Midfielder::getScore() const {
	// IMPLEMENT ME
	// below are just stub code
	int removeMe = 0;
	return removeMe;
}

string Midfielder::print() const {
	return Player::print();
}

// -------------- Defender ------------------

Defender::Defender(const string& name, Team* t) : Player(name, t) {
	role = "Defender";
}

Defender::~Defender() {
	// IMPLEMENT ME
}

int Defender::getScore() const {
	// IMPLEMENT ME
	// below are just stub code
	int removeMe = 0;
	return removeMe;
}

string Defender::print() const {
	return Player::print();
}

// -------------- Goalkeeper ------------------

Goalkeeper::Goalkeeper(const string& name, Team* t) : Player(name, t) {
 role = "Goalkeeper";
 shotsSaved = 0;
}

Goalkeeper::~Goalkeeper() {
	// IMPLEMENT ME
}

void Goalkeeper::addShotsSaved(int ss) {
	shotsSaved+=ss;
}

int Goalkeeper::getScore() const {
	// IMPLEMENT ME
	// below are just stub code
	int removeMe = 0;
	return removeMe;
}

string Goalkeeper::print() const {
	string print = role+": "+ name+", Team: "+ team->name+"\n";
	print+=	" Goals scored: "+ goals+"\n";
	print+=	" Assists: "+ assists +"\n";
	print+=	" Goals conceded: " + team->goalsConceded + "\n";
	print+=	" Shots saved: "+shotsSaved+"\n";
	print+=	" Score: "+ score;
	return print;
}

// -------------- FantasyTeam ------------------

FantasyTeam::FantasyTeam() {
	teamSize = 0;
	totalScore = 0;
}


FantasyTeam::~FantasyTeam() {
	delete [] players;
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
	return true;
}

int FantasyTeam::getScore() const {
	return totalScore;
}

void FantasyTeam::tallyScore() {
	//loop through all team members and add their score to total score
	for (Player p : players) {
		totalScore += p.getScore();
	}
}

