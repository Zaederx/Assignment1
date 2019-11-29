/* Please note: even though it says IMPLEMENT ME, in some cases
   the implementation can be empty. In fact, you may wish to remove
   some of the functions entirely
*/
#include "Football.h"

// -------------- Team --------------------

Team::Team(const string& name) {
	// IMPLEMENT ME
}

void Team::addGoalsConceded(int g) {
	// IMPLEMENT ME
}

Team::~Team() {
	// IMPLEMENT ME
}

// -------------- Player ------------------

Player::Player() {
	// see comment in .h
}

Player::Player(const string& name, Team* t) {
	// IMPLEMENT ME
}

// don't remove this even if you want to make the destructor pure virtual
Player::~Player() {
	// IMPLEMENT ME
}

void Player::addGoalsScored(int g) {
	// IMPLEMENT ME
}

void Player::addAssists(int a) {
	// IMPLEMENT ME
}

int Player::getScore() const {
	// IMPLEMENT ME
}

string Player::print() const {
	// IMPLEMENT ME
	// below are just stub code
	string removeMe = "";
	return removeMe;
}

// -------------- Attacker ------------------

Attacker::Attacker(const string& name, Team* t) {
	// IMPLEMENT ME
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
	// IMPLEMENT ME
	// below are just stub code
	string removeMe = "";
	return removeMe;
}

// -------------- Midfielder ------------------

Midfielder::Midfielder(const string& name, Team* t) {
	// IMPLEMENT ME
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
	// IMPLEMENT ME
	// below are just stub code
	string removeMe = "";
	return removeMe;
}

// -------------- Defender ------------------

Defender::Defender(const string& name, Team* t) {
	// IMPLEMENT ME
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
	// IMPLEMENT ME
	// below are just stub code
	string removeMe = "";
	return removeMe;
}

// -------------- Goalkeeper ------------------

Goalkeeper::Goalkeeper(const string& name, Team* t) {
	// IMPLEMENT ME
}

Goalkeeper::~Goalkeeper() {
	// IMPLEMENT ME
}

void Goalkeeper::addShotsSaved(int ss) {
	// IMPLEMENT ME
}

int Goalkeeper::getScore() const {
	// IMPLEMENT ME
	// below are just stub code
	int removeMe = 0;
	return removeMe;
}

string Goalkeeper::print() const {
	// IMPLEMENT ME
	// below are just stub code
	string removeMe = "";
	return removeMe;
}

// -------------- FantasyTeam ------------------

FantasyTeam::FantasyTeam() {
	// IMPLEMENT ME
}

FantasyTeam::~FantasyTeam() {
	// IMPLEMENT ME
}

bool FantasyTeam::addPlayer(Player* p) {
	// IMPLEMENT ME
	// below are just stub code
	bool removeMe = true;
	return removeMe;
}

int FantasyTeam::getScore() const {
	// IMPLEMENT ME
	// below are just stub code
	int removeMe = 0;
	return removeMe;
}
