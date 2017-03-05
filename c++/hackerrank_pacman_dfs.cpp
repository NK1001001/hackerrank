/*
* hackerrank pacman dfs
* My C++ solution to hackerrank pacman dfs challenge - won all games !!! :) 
*/


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <sstream>

using namespace std;
using ii = std::pair<int, int>;
using vi = std::vector<int>;
using vii = std::vector<ii>;
using mii = std::map<ii, ii>;
using stackii = std::stack<ii>;
static const int gridMaxColumnSize = 40;
static const int gridMaxRowSize = 40;

bool isValidStep(int r, int c, int pr, int pc, int fr, int fc, bool visited[][gridMaxColumnSize], vector<string> &g)
{
	if (g[pr][pc] == '%' || pr >= r || pc >= c || pr < 1 || pc < 1 || visited[pr][pc]) {
		return false;
	}
	return true;
}

void printRoute(mii &m, ii coor, int cnt)
{
	if (m[coor] == coor) {
		cout << cnt << endl;
		cout << coor.first << " " << coor.second << endl;
		return;
	}
	printRoute(m, m[coor], cnt+1);
	cout << coor.first << " " << coor.second << endl;
}

void markStep(int pacman_r, int pacman_c, bool visited[][gridMaxColumnSize], ii i, mii &route, stackii &stk)
{
	visited[pacman_r][pacman_c] = true;
	route.emplace(ii(pacman_r, pacman_c), i);
	stk.push(ii(pacman_r, pacman_c));

}
void dfs(int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> &grid) {
	//your logic here
	stackii stk;
	mii route;
	stk.push(make_pair(pacman_r, pacman_c));
	//vii visited;
	bool visited[gridMaxRowSize][gridMaxColumnSize] = { false };
	
	visited[pacman_r][pacman_c] = true;
	route.emplace(make_pair(ii(pacman_r, pacman_c), ii(pacman_r, pacman_c)));
	vii explored;
	
	while (!stk.empty()) {
		auto i = stk.top();
		explored.emplace_back(i);
		stk.pop();
		if (i == ii(food_r, food_c)) {
			break;
		}
		if (isValidStep(r, c, i.first - 1, i.second, food_r, food_c, visited, grid)) {
			markStep(i.first-1, i.second, visited, i, route, stk);
		}
		if (isValidStep(r, c, i.first, i.second - 1, food_r, food_c, visited, grid )) {
			markStep(i.first, i.second - 1, visited, i, route, stk);
		}
		if (isValidStep(r, c, i.first, i.second+1, food_r, food_c, visited, grid )) {
			markStep(i.first, i.second + 1, visited, i, route, stk);
		}
		if (isValidStep(r, c, i.first + 1, i.second, food_r, food_c, visited, grid )) {
			markStep(i.first + 1, i.second, visited, i, route, stk);
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
	std::stringstream strmPacman("3 9\n5 1\n7 20");
	/*std::stringstream strmFood("5 1");
	std::stringstream strmRc("7 20");*/
	/*cin >> pacman_r >> pacman_c;
	cin >> food_r >> food_c;
	cin >> r >> c;
*/
	strmPacman >> pacman_r >> pacman_c;
	strmPacman >> food_r >> food_c;
	strmPacman >> r >> c;

	vector <string> grid{
		"%%%%%%%%%%%%%%%%%%%%",
		"%--------------%---%",
		"%-%%-%%-%%-%%-%%-%-%",
		"%--------P-------%-%",
		"%%%%%%%%%%%%%%%%%%-%",
		"%.-----------------%",
		"%%%%%%%%%%%%%%%%%%%%"
	};
	/*for (int i = 0; i<r; i++) {
		string s; cin >> s;
		grid.push_back(s);
	}*/
	dfs(r, c, pacman_r, pacman_c, food_r, food_c, grid);
	cin.get();
	return 0;
}
