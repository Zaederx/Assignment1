#include "BiArray.h"


// default constructor
BiArray::BiArray() {
 size = 0;
 start = (LO_THRESHOLD*size);//TODO FIRST element should be inserted into the middle
capacity = INITIALCAP;
}

// value constructor
BiArray::BiArray(int arr[], int size)  {
	if ((LO_THRESHOLD * size) > INITIALCAP) {
		capacity = (LO_THRESHOLD*size);//3*size
	}
	p = new int[capacity];//initial capacity
	start = ((capacity - size)/2);//to get it to be inserted into center
	for (int i = start; i < size; i++) {
		p[i] = arr[i];
	}
}

// destructor
BiArray::~BiArray() {
	delete [] p;
	delete HI_THRESHOLD;
	delete LO_THRESHOLD;
	delete INITIALCAP;
	delete size;
	delete capacity;
	delete start;
}

// copy constructor
BiArray::BiArray(const BiArray& other) :
	size(other.size), p(new int[other.size]){
	start = (capacity - size)/2;
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
	if (this != &other) {
		if (size != other.size) {
			delete [] p;
			p = new int[other.size];
			size = other.size;
		}
	}
	int start = (INITIALCAP - size)/2;
	for (int i = start; i < size ; i++) {
		p[i] = other.p[i];
	}

	return *this;
}

// move assignment
BiArray& BiArray::operator=(BiArray&& other) {
	if(this != &other) {
		int* pTemp = p;
		p = other.p;
		other.p = pTemp;

		int sTemp = size;
		size = other.size;
		other.size = pTemp;
	}

	return *this;
}

bool BiArray::get(int i, int& v) const {
	if (i >= size) {return false;}
	v = p[i];
	return true;
}

bool BiArray::set(int i, int v) {
	if (i >= size) {return false;}
	p[i] = v;
	return true;
}

int BiArray::operator[](int i) const {
	return p[i];
}

int& BiArray::operator[](int i) {
	return *p[i];
}

void BiArray::push_back(int v) {

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
	return size;
}

int BiArray::getCapacity() const {
	return capacity;
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

