#include <iostream> 
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> network(101);
bool visited[101];
int cnt;
queue<int> q;

void BFS() {
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int com = q.front();
		q.pop();

		for (int i = 0; i < network[com].size(); i++) {
			if (!visited[network[com][i]]) {
				q.push(network[com][i]);
				visited[network[com][i]] = true;
				cnt++;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num, pair;
	cin >> num >> pair;

	int x, y;
	for (int i = 0; i < pair; i++) {
		cin >> x >> y;
		network[x].push_back(y);
		network[y].push_back(x);
	}
	BFS();
	cout << cnt << "\n";

}