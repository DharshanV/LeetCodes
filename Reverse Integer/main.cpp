#include <iostream>
#include <list>
using namespace std;

int reverse(int x);

//123 321
//-123 -321
//120 21
int main() {
	cout << reverse(1563847412) << endl;
	return 0;
}

int reverse(int x) {
	bool negative = (x < 0) ? 1 : 0;
	if (x == INT_MAX || x == INT_MIN) return 0;
	if (negative) x *= -1;
	int reversedInt = 0;
	int place = 0;

	list<int> digits;
	list<int>::iterator it;
	while (x/10 != 0) {
		digits.insert(digits.end(), x % 10);
		x /= 10;
	}
	digits.insert(digits.end(), x % 10);
	place = digits.size()-1;

	for (it = digits.begin(); it != digits.end(); ++it) {
		int a = (*it);
		int b = pow(10, place);
		if ((*it) > INT_MAX / b)
			return 0;
		int result = (a * b);
		if ((result > 0) && (reversedInt > INT_MAX - result)) return 0;
		reversedInt += result;
		place--;
	}

	return (negative) ? -reversedInt : reversedInt;
}