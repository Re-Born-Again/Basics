// C++ program to create a global function as a friend
#include <iostream>
using namespace std;

class base {
private:
	int private_variable;
protected:
	int protected_variable;
public:
	base(){
		private_variable = 10;
		protected_variable = 99;
	}
	
	// friend function declaration
	friend void friendFunction();
};

// friend function definition
void friendFunction(){
    base b;
	cout << "Private Variable: " << b.private_variable<< endl;
	cout << "Protected Variable: " << b.protected_variable<<endl;
}

int main(){
	base b;
	friendFunction();

	return 0;
}
