#include <iostream>
#include <initializer_list>
//#include <conio>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <typeinfo>

using namespace std;
class IntArray {
private:
	int length;
	int *data;

public:

	IntArray(int length = 0) :
			length(length) {
		if (length != 0)
			data = new int[length] { };
		else
			data = nullptr;
	}

	//IntArray(): IntArray(0) {}

	IntArray(const std::initializer_list<int> &list) :
			IntArray(list.size()) {
		int i = 0;
		for (auto &element : list) {
			data[i] = element;
			i++;
		}
	}

	IntArray(const IntArray &a) {
		this->length = a.length;
		this->data = new int[this->length];
		for (int i = 0; i < this->length; i++) {
			this->data[i] = a.data[i];
		}
	}

	~IntArray() {
		if (data)
			delete[] data;
	}

	int& operator[](int index) {
		if (index >= 0 && index < length)
			return data[index];
		return data[0];
	}

	int getLength() const {
		return length;
	}

	IntArray& operator=(const IntArray &a) {
		if (this->data)
			delete[] this->data;
		this->length = a.length;
		this->data = new int[this->length];
		for (int i = 0; i < this->length; i++)
			this->data[i] = a.data[i];
		return *this;
	}
};

int main() {

	int ms_i[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	IntArray a1(23);
	for (int i = 0; i < 23; i++) {
		cout << a1[i] << ' ';
	}
	cout << endl;

	IntArray array { 7, 6, 5, 4, 3, 2, 1 };
	//  { 7, 6, 5, 4, 3, 2, 1 }   ----> std::initializer_list<int>
	for (int i = 0; i < 7; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;

	IntArray array2 = array;

	for (int i = 0; i < 7; i++) {
		cout << array2[i] << ' ';
	}
	cout << endl;
	IntArray array3;
	array3 = array2;
	array3[3]=128;

	for (int i = 0; i < 7; i++) {
			cout << array3[i] << ' ';
		}

	//_getch();
	return 0;
}
