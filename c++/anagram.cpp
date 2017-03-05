#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

int number_needed(string a, string b) {
	vector<int> dict(256, 0);
	for (size_t i = 0; i < a.length(); ++i) {
		char c = a[i];
		++dict[c];
	}
	for (size_t i = 0; i < b.length(); ++i) {
		char c = b[i];
		--dict[c];
	}
	int cnt = 0; 
	for (int i = 0 ; i < 256; ++i) {
		cnt += abs(dict[i]);
	}
	return cnt;
}

int main(){
	string a;
	cin >> a;
	string b;
	cin >> b;
	cout << number_needed(a, b) << endl;
	return 0;
}

