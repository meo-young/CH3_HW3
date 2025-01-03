#include<iostream>
#include<algorithm>

using namespace std;

template <typename T>
class SimpleVector {
public:
	SimpleVector() : currentSize(0), currentCapacity(10) {
		data = new T[currentCapacity];
	}

	SimpleVector(int capacity) : currentSize(0), currentCapacity(10) {
		data = new T[currentCapacity];
	}

	SimpleVector(const SimpleVector& other) {
		other.currentCapacity = currentCapacity;
		other.currentSize = currentSize;
		other = new T[*data];
	}

	~SimpleVector() {
		delete[] data;
	}

	void resize(int newCapacity) {
		if (currentCapacity >= newCapacity)
			return;

		T* temp = new T[newCapacity];

		for (int i = 0; i < currentSize; i++) {
			temp[i] = data[i];
		}


		delete[] data;
		data = temp;
		currentCapacity = newCapacity;
	}

	void push_back(const T& value) {
		if (currentSize >= currentCapacity) {
			resize(currentCapacity + 5);
		}

		data[currentSize++] = value;

		printData();
	}

	void pop_back() {
		if (currentSize > 0) {
			currentSize--;
		}

		printData();
	}

	int size() {
		return currentSize;
	}

	int capacity() {
		return currentCapacity;
	}

	void sortData() {
		sort(data, data + currentSize);

		printData();
	}

	void printData() {
		cout << "Current Element :";
		for (int i = 0; i < currentSize; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}

private:
	T* data;
	int currentSize;
	int currentCapacity;
};

int main() {
	SimpleVector<int> vec;
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);

	vec.pop_back();

	vec.sortData();

	return 0;
}