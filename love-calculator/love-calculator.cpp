// Dabananda Mitra
// imdmitra@outlook.com
// CSE, ISTT (2019-2020), Dhaka, Bangladesh

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class LoveCalculator {
	string name_1, name_2;
 public:
	LoveCalculator() {
		cout << "Your name: ";
		cin >> name_1;
		cout << "Your love name: ";
		cin >> name_2;
	}
	float Result() {
		return (rand() % (100 - 80 + 1)) + 80;
	}
};

int main() {
	srand ( time(NULL) );
	LoveCalculator obj;
	cout << "Your love depth is: " << obj.Result() << "%\n";

	return 0;
}
