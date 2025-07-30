#include <iostream>

using namespace std;

class demo {
	// Polymorphism example
	public:
		int f_num,s_num;

		void sum (int a, int b){
			cout << a+b;
		}

		string str(){
			return "hello\n";
		}
};

int main() {
	demo d1;
	d1.sum(d1.f_num = 10, d1.s_num = 30);
	cout << d1.str();
	return 0;
}