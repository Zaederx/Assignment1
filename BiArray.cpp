#include "BiArray.h"

int size;//TODO probably shouldn't use 'new' on global constants - so there is no memory leak in main.cpp
const int INITIALCAP;//Initail Capacity
const int LO_THRESHOLD = 3;
const int HIGH_THRESHOLD = 5;
// default constructor
BiArray::BiArray() {
 size = 0;
 INITIALCAP = 10;//TODO FIRST element should be inserted into the middle

}

// value constructor
BiArray::BiArray(int arr[], int size)  {

}

// destructor
BiArray::~BiArray() {
	// IMPLEMENT ME
}

// copy constructor
BiArray::BiArray(const BiArray& other) {
	// IMPLEMENT ME
}

// move constructor
BiArray::BiArray(BiArray&& other) {
	// IMPLEMENT ME
}

// copy assignment
BiArray& BiArray::operator=(const BiArray& other) {
	// IMPLEMENT ME
	// below are just stub code
	BiArray& removeMe = *this;
	return removeMe;
}

// move assignment
BiArray& BiArray::operator=(BiArray&& other) {
	// IMPLEMENT ME
	// below are just stub code
	BiArray& removeMe = *this;
	return removeMe;
}

bool BiArray::get(int i, int& v) const {
	// IMPLEMENT ME
	// below are just stub code
	bool removeMe = false;
	return removeMe;
}

bool BiArray::set(int i, int v) {
	// IMPLEMENT ME
	// below are just stub code
	bool removeMe = false;
	return removeMe;
}

int BiArray::operator[](int i) const {
	// IMPLEMENT ME
	// below are just stub code
	int removeMe = 0;
	return removeMe;
}

int& BiArray::operator[](int i) {
	// IMPLEMENT ME
	// below are just stub code
	int removeMe = 0;
	return removeMe;
}

void BiArray::push_back(int v) {
	// IMPLEMENT ME
}

bool BiArray::pop_back() {
	// IMPLEMENT ME
	// below are just stub code
	bool removeMe = false;
	return removeMe;
}

void BiArray::push_front(int v) {
	// IMPLEMENT ME
}

bool BiArray::pop_front() {
	// IMPLEMENT ME
	// below are just stub code
	bool removeMe = false;
	return removeMe;
}

int BiArray::getSize() const {
	// IMPLEMENT ME
	// below are just stub code
	int removeMe = 0;
	return removeMe;
}

int BiArray::getCapacity() const {
	// IMPLEMENT ME
	// below are just stub code
	int removeMe = 0;
	return removeMe;
}

string BiArray::print() const {
	// IMPLEMENT ME
	// below are just stub code
	string removeMe = "";
	return removeMe;
}

string BiArray::printAll() const {
	// IMPLEMENT ME
	// below are just stub code
	string removeMe = "";
	return removeMe;
}

bool operator==(const BiArray& lhs, const BiArray& rhs) {
	// IMPLEMENT ME
	// below are just stub code
	bool removeMe = false;
	return removeMe;
}

bool operator!=(const BiArray& lhs, const BiArray& rhs) {
	// IMPLEMENT ME
	// below are just stub code
	bool removeMe = false;
	return removeMe;
}

