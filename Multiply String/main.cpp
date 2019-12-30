#include <iostream> 
#include <queue> 
#include <string>
using namespace std;

class Digits {
public:
	Digits(int value, int digit) : value(value), digit(digit) {}
	bool operator<(Digits& other) {
		return digit < other.digit;
	}
	int value;
	int digit;
};

string multiply(string num1, string num2);
bool operator<(const Digits& lhs, const Digits& rhs);
int CToI(char value);
char IToC(int value);
priority_queue<Digits, vector<Digits>> pq;

int main() {
	cout << multiply("3", "2") << endl;
	return 0;
}

string multiply(string num1, string num2) {
	string result;
	bool doCarry = false;
	int carryValue = 0;
	int resultLength = 0;
	for (int i = num1.length() - 1; i >= 0; i--) {
		int mulValue = 0;
		int digitIndex = num1.length()-i;
		for (int j = num2.length() - 1; j >= 0; j--) {
			mulValue = CToI(num2[j]) * CToI(num1[i]);
			if (doCarry) {
				mulValue += carryValue;
				doCarry = false;
				carryValue = 0;
			}
			if (mulValue >= 10) {
				doCarry = true;
				carryValue = (mulValue / 10);
				mulValue %= 10;
			}
			pq.push(Digits(mulValue,digitIndex));
			digitIndex++;
		}
		if (doCarry) {
			pq.push(Digits(carryValue, digitIndex));
			doCarry = false;
			carryValue = 0;
		}
		resultLength = digitIndex;
	}

	result.resize(resultLength,'0');
	int resultIndex = resultLength - 1;
	doCarry = false;
	carryValue = 0;
	while (!pq.empty()) {
		Digits top = pq.top();
		int digitSum = 0;
		if (doCarry) {
			digitSum += carryValue;
			doCarry = false;
			carryValue = 0;
		}
		while (!pq.empty()) {
			if (pq.top().digit != top.digit) break;
			Digits number = pq.top();
			digitSum += number.value;
			if (!pq.empty()) pq.pop();
			else break;
		}
		if (digitSum >= 10) {
			doCarry = true;
			carryValue = (digitSum / 10);
			digitSum %= 10;
		}
		result[resultIndex] = IToC(digitSum);
		resultIndex--;
	}
	if (doCarry) {
		result[resultIndex] = IToC(carryValue);
		return result;
	}
	int startIndex = result.find_first_not_of('0');
	if (startIndex < 0) return "0";
	return result.substr(startIndex);
}

bool operator<(const Digits& lhs, const Digits& rhs) {
	return lhs.digit > rhs.digit;
}

int CToI(char value) {
	return value - '0';
}

char IToC(int value) {
	return value + '0';
}