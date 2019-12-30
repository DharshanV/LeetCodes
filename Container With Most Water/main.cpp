#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height);
int min(int x, int y);

int main() {
	vector<int> data = {7,7,7,7};
	cout << maxArea(data) << endl;
	return 0;
}

int maxArea(vector<int>& height) {
	int maxArea = 0;
	for (int i = 0; i < height.size(); i++) {
		for (int j = i+1; j < height.size(); j++) {
			int currentArea = (j - i) * min(height[i], height[j]);
			if (currentArea > maxArea) {
				maxArea = currentArea;
			}
		}
	}
	return maxArea;
}

int min(int x, int y) {
	if (x < y) return x;
	else return y;
}