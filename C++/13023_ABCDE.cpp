#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visited[2001];

void DFS(int pers, vector<vector<int>> &social,int cnt) {
	visited[pers] = true;

	if (cnt == 4) {
		cout << 1; 
		exit(0);
	}
	for (int i = 0; i < social[pers].size(); i++) {
		if (!visited[social[pers][i]]) {
			DFS(social[pers][i],social,cnt+1);
		}
	}
	visited[pers] = false;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	vector <vector <int>> social(n + 1);

	int x, y;
	for(int i=0 ; i <m; i++){
		cin >> x >> y;
		social[x].push_back(y);
		social[y].push_back(x);
	}
	
	for (int i = 0; i < n; i++) {
		DFS(i, social, 0);
	}
	cout << 0;
}