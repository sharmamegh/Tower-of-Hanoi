#include "iostream"

using namespace std;

// utilizing concept of stack data structure to construct the required tower.
class Tower {
	friend void ToH(int, Tower, Tower, Tower);
	private:
		int * arr;
		int top, size;
	public:
		Tower() {}
		Tower(int size) {
			this->size = size; // explicit use of instance variable
			arr = new int[size]; // created array of pointers to handle blocks
			top = 0;
			arr[1] = 0;
		}
		
		void buildSource() {
			int tempSize = size;
			for (; tempSize > 0; tempSize--) {
				arr[++top] = top;
			}
			cout << "**Source tower built**" << endl;
		}
		
		void display() {
			if (arr[1] == 0) {
				cout <<  "Tower currently empty." << endl;
			} else {
				for (int i = top; i > 0; i--)
					cout << arr[i] << " ";
				cout << endl;
			}
		}
		
		int pop() {
			if (top == 0) return 0;
			return arr[top--];
		}

		void push(int block) {
			if (top < size) {
				arr[top++] = block;
		}
    }
};

int  main() {
	int capacity; // var containing capacity of the tower, i.e. A tower of capacity n will have n blocks to be moved.
	cout << "A Working Tower of Hanoi Program" << endl
		<< "Enter Tower Capacity: "; // used concept of cascading i/o
	cin >> capacity;
	
	// Source Tower
	Tower S(capacity); // constructor of Tower class implicitly called.
	S.buildSource(); // building the Source tower.
	//Helper/Auxiliary Tower
	Tower H(capacity);
	// Destination Tower
	Tower D(capacity);
	
	cout<< "Source status: "; S.display();
	cout<< "Helper status: "; H.display();
	cout<< "Destination status: "; D.display();
	cout << endl;
	
	ToH(capacity, S, H, D);
	
	cout<< "Source status: "; S.display();
	cout<< "Helper status: "; H.display();
	cout<< "Destination status: "; D.display();
	
	return 0;
}

	void ToH(int cap, Tower S, Tower H, Tower D) {
		if (cap > 0) {
			ToH(cap - 1, S, D, H); // Move n-1 disks from source to helper
				int block = S.pop(); // Move the nth disk from source to destination
				D.push(block);
				cout << "Moved block " << block << " from Source to Destination." << endl;
			ToH(cap - 1, H, S, D); // Move n-1 disks from helper to destination
		}
	}