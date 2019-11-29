#include "BiArray.h"


// default constructor
BiArray::BiArray() {
 p = new int [INITIALCAP];
 size = 0;
 capacity = INITIALCAP;// 5
 start = 2;//TODO FIRST element should be inserted into the middle
 end = 3;// end = start + size

}

// value constructor
//TODO What if size == 0???
BiArray::BiArray(int arr[], int size)  {
	int check = LO_THRESHOLD*size;
	if (check > INITIALCAP) { //if size >= 2
	this->size = size;
	//can't call reCapacity till initialised
	capacity = (LO_THRESHOLD*this->size);
	start = ((capacity - this->size)/2);
	end = (start+this->size - 1);
	p = new int[capacity];
	for (int i = 0; i <= size - 1; i++) {
				p[start+i] = arr[i];
			}
	} else { //if size <= 0
		capacity = INITIALCAP;//5
		p = new int [capacity];
		this->size = 1;
		start = 2; //same as ((capacity - size)/2); if size == 1
		end = 2; // start - size - 1
		p[start] = arr[0];

	}
}

//renews the cacpcity to suit array size (number of elements
void BiArray::reCapacity() {
	int *temp = p;
	capacity = (LO_THRESHOLD*size);//new capacity
	//because p is now 3*size so size is start point
	int oldStart = start;
	int oldEnd = start + size - 1;
	start = size;
	end = start+size - 1;
	p = new int[capacity];
	/*copy entire oldP temp - which is a full array at this point
	into the middle of the resized array */
	int j = 0;
	for (int i=oldStart; i <= oldEnd; i++) {
		p[start+j] = temp[i];
		j++;
	}
//	delete [] temp;
}


// destructor
BiArray::~BiArray() {
	delete [] p;
}

// copy constructor
BiArray::BiArray(const BiArray& other) :
	size(other.size), p(new int[other.capacity]), //new memory
	start(other.start), end(other.end), capacity(other.capacity){
	for (int i = 0; i < capacity; i++) {
		p[i] = other.p[i];
	}
}

// move constructor
BiArray::BiArray(BiArray&& other) : size(other.size), p(other.p),
		start(other.start), end(other.end), capacity(other.capacity) {
	//other object set to valid but unspecified state
	other.p = nullptr;
	other.size = 0;
	other.start= 0;
	other.end = 0;
	other.capacity = 0;
	//other destroyed by compiler
}

// copy assignment
BiArray& BiArray::operator=(const BiArray& other) {
	if (this != &other) {//compare addresses
		if (capacity != other.capacity) {
			delete [] p;
			int * temp = p;
			//Resize / Recapacity
			size = other.size;
			start = other.start;
			start = other.start;
			end = other.end;
			capacity = other.capacity;

			p = new int[other.capacity];
		}
		// when they are the same size
//		int start = (INITIALCAP - size)/2;
			for (int i = other.start ; i <= other.end ; i++) {
				p[i] = other.p[i];
			}
	}


	return *this;
}

// move assignment
BiArray& BiArray::operator=(BiArray&& other) {
	if(this != &other) {
		//size
		int sTemp = size;
		size = other.size;
		other.size = sTemp;

		//start
		int stTemp = start;
		start = other.start;
		other.start = stTemp;

		//end
		int eTemp = end;
		end = other.end;
		other.end = eTemp;

		//capacity
		int cTemp = capacity;
		capacity = other.capacity;
		other.capacity = cTemp;

		//p - internal array
		int* pTemp = p;
		p = other.p;
		other.p = pTemp;

		//compiler cleans up other as they go out of scope
	}

	return *this;
}

bool BiArray::get(int i, int& v) const {
	if (i >= size || i < 0) {return false;}
	v = p[start+i];
	return true;
}

bool BiArray::set(int i, int v) {
	if (i >= size || i < 0) {return false;}
	p[start+i] = v;
	return true;
}

int BiArray::operator[](int i) const {
	return p[start+i];
}

int& BiArray::operator[](int i) {
	return p[start+i];
}


void BiArray::push_back(int v) {
	//new array
	//do temp swap for new rray and old array values
	//i.e.insert old values into new array
	//insert new var v into array at tail
	if (end == capacity || capacity == size) {//If no space
		reCapacity();
		size++;//so size now increased
//star altration??
		end = start+size - 1;
		p[end] = v;// add new variable to array
	} else {
	 size++;//increase BiArray size counter
	 end = start + size - 1;//position for new element - works because size was increased by one
	 p[end] = v;
	}

}

bool BiArray::pop_back() {
	//if empty return false
	if (size == 0) {return false;}
	// For Removal - get last element position
	p[end] = -1;//remove last element
	end--;
	size--;//decrement array size
	// if at minimum capacity - do not make smaller
	if (capacity == INITIALCAP){return true;}
	// if not at mimimum capacity -
	//but at maximum threshold(5* BIGGER) make it smaller
	if (capacity >= (size*HI_THRESHOLD)) {
		reCapacity(); // decrease capacity
	}
	return true;
}

void BiArray::push_front(int v) {
	//if front side is fill or capacity is filled
	if (start == 0 || capacity == size) {
		reCapacity();
		//increase size and add new element to front
		size++;//TODO IF THIS DOESNT WORK - INCREAAE SIZE AND REWORK START FORMULA BFORE FOR LOOP
		start--; //because ((capacity-size)/2) = start--
		p[start] = v;
	} else {
	size++;
	start--;
	p[start] = v;
	}
}

bool BiArray::pop_front() {

	if (size == 0){return false;}
	p[start] = -1;
	//update array start(head) and size
	start++;
	size--;

	if (capacity == INITIALCAP) {return true;}
	if (capacity >= (size*HI_THRESHOLD)) {
		reCapacity();//decrease capacity
	}

	return true;
}

int BiArray::getSize() const {
	return size;
}

int BiArray::getCapacity() const {
	return capacity;
}

string BiArray::print() const {
	if (size <= 0) {
		return "[]";
	}
	string pArray = "[";
	for (int i = start; i <= end; i++ ) {
		if (i < end) {
		pArray+= to_string(p[i])+" ";
		} else {
			pArray+= to_string(p[i]);
		}
	}
	pArray+="]";
	return pArray;
}

string BiArray::printAll() const {
	if (size <= 0) {
			return "[]";
		}
	string pArray = "[";
	for (int i = 0; i < capacity; i++ ) {
		if (1 != capacity) {
		pArray+= to_string(p[i])+" ";
		} else {
			pArray+=to_string(p[i]);
		}
	}
	pArray+="]";
	return pArray;
}

bool operator==(const BiArray& lhs, const BiArray& rhs) {
	const char *str1 = lhs.print().c_str();
	const char *str2 = rhs.print().c_str();

	if (strcmp(str1,str2) == 0){
		return true;
	}
	return false;
}

bool operator!=(const BiArray& lhs, const BiArray& rhs) {
	const char *str1 = lhs.print().c_str();
	const char *str2 = rhs.print().c_str();

	if (strcmp(str1,str2) == 0){
		return false;
	}
	return true;
}


