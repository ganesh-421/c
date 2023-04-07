#include<iostream>
using namespace std;
class Test {
	public: int i;
	void function() {
		this->i = 1010;
	}
	void function2() {
		cout << this->i;
	}
};
int main() {
	Test t1;
	t1.function2();
}
