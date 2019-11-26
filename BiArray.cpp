#include "BiArray.h"


// default constructor
BiArray::BiArray() {
 size = 0;
 INITIALCAP = 10;//TODO FIRST element should be inserted into the middle

}

// value constructor
BiArray::BiArray(int arr[], int size)  {
	if ((LO_THRESHOLD * size) > INITIALCAP) {
		INITIALCAP = new int((LO_THRESHOLD*size));//3*size
	}
	p = new int[INITIALCAP];//initial capacity
	int start = (INITIALCAP - size)/2;//to get it to be inserted into center
	for (int i = start; i < size; i++) {
		p[i] = arr[i];
	}
}

// destructor
BiArray::~BiArray() {
	delete p;
	delete HI_THRESHOLD;
	delete LO_THRESHOLD;
	delete INITIALCAP;
	delete size;
}

// copy constructor
BiArray::BiArray(const BiArray& other) :
	size(other.size), p(new int[other.size]){
	int start = (INITIALCAP - size)/2;
	for (int i = start; i , size; i++) {
		p[i] = other[i];
	}
}

// move constructor
BiArray::BiArray(BiArray&& other) : size(other.size), p(other.p) {
	other.p = nullptr;
	other.size = 0;
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

