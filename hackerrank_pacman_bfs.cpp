
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <sstream>
#include <queue>

using namespace std;
using ii = std::pair<int, int>;
using vi = std::vector<int>;
using vii = std::vector<ii>;
using mii = std::map<ii, ii>;
using qii = std::queue<ii>;
static const int gridMaxColumnSize = 40;
static const int gridMaxRowSize = 40;

bool isValidStep(int r, int c, int pr, int pc, int fr, int fc, bool visited[][gridMaxColumnSize], vector<string> &g)
{
	if (g[pr][pc] == '%' || pr >= r || pc >= c || pr < 1 || pc < 1 || visited[pr][pc]) {
		return false;
	}
	return true;
}

static
void printRoute(mii &m, ii coor, int cnt)
{
	if (m[coor] == coor) {
		cout << cnt << endl;
		cout << coor.first << " " << coor.second << endl;
		return;
	}
	printRoute(m, m[coor], cnt + 1);
	cout << coor.first << " " << coor.second << endl;
}

void markStep(int pacman_r, int pacman_c, bool visited[][gridMaxColumnSize], ii i, mii &route, qii &stk)
{
	visited[pacman_r][pacman_c] = true;
	route.emplace(ii(pacman_r, pacman_c), i);
	stk.push(ii(pacman_r, pacman_c));

}

void nextMove(int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> &grid) {
	//your logic here
	qii q;
	mii route;
	q.push(make_pair(pacman_r, pacman_c));
	//vii visited;
	bool visited[gridMaxRowSize][gridMaxColumnSize] = { false };

	visited[pacman_r][pacman_c] = true;
	route.emplace(make_pair(ii(pacman_r, pacman_c), ii(pacman_r, pacman_c)));
	vii explored;

	while (!q.empty()) {
		auto i = q.front();
		explored.emplace_back(i);
		q.pop();
		if (i == ii(food_r, food_c)) {
			break;
		}
		if (isValidStep(r, c, i.first - 1, i.second, food_r, food_c, visited, grid)) {
			markStep(i.first - 1, i.second, visited, i, route, q);
		}
		if (isValidStep(r, c, i.first, i.second - 1, food_r, food_c, visited, grid)) {
			markStep(i.first, i.second - 1, visited, i, route, q);
		}
		if (isValidStep(r, c, i.first, i.second + 1, food_r, food_c, visited, grid)) {
			markStep(i.first, i.second + 1, visited, i, route, q);
		}
		if (isValidStep(r, c, i.first + 1, i.second, food_r, food_c, visited, grid)) {
			markStep(i.first + 1, i.second, visited, i, route, q);
		}
	}
	cout << explored.size() << endl;
	for (auto &i : explored) {
		cout << i.first << " " << i.second << endl;
	}
	printRoute(route, ii(food_r, food_c), 0);
}

int main(void) {

	int r, c, pacman_r, pacman_c, food_r, food_c;

	cin >> pacman_r >> pacman_c;
	cin >> food_r >> food_c;
	cin >> r >> c;
	vector <string> grid;

	for (int i = 0; i<r; i++) {
		string s; cin >> s;
		grid.push_back(s);
	}

	nextMove(r, c, pacman_r, pacman_c, food_r, food_c, grid);

	return 0;
}
