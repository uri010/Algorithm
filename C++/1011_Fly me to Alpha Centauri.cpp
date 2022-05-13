#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t; 
	
	for(int k=0; k <t; k++) {
		double x, y, result;
		cin >> x >> y;

		double distance = y - x;
		double i = 1;
		for (;; i++) {
			if (distance< i * i) {
				break;
			}
		}
		
		if (distance == (i- 1) * (i - 1)) 
			result = 2 * (i - 1) - 1;
		else if(distance < ((i - 1)* (i - 1) + i*i) / 2) 
			result = 2 * (i - 1);
		else 
			result = 2 * i- 1;
		
		cout << result << "\n";
	}
}
