#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height);
int min(int x, int y);

int main() {
	vector<int> data = {1,8,6,2,5,4,8,3,7};
	cout << maxArea(data) << endl;
	return 0;
}

int maxArea(vector<int>& height) {
	int maxArea = 0;
	int lhsIndex = 0;
	int rhsIndex = height.size() - 1;
	while (lhsIndex != rhsIndex) {
		int currentArea = (rhsIndex - lhsIndex) * min(height[lhsIndex], height[rhsIndex]);
		if (currentArea > maxArea) {
			maxArea = currentArea;
		}
		if (height[lhsIndex] > height[rhsIndex]) {
			rhsIndex--;
		}
		else if (height[lhsIndex] < height[rhsIndex]) {
			lhsIndex++;
		}
		else {
			rhsIndex--;
		}
	}
	return maxArea;
}

int min(int x, int y) {
	if (x < y) return x;
	else return y;
}