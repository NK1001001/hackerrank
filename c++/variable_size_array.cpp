#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using vi = vector<int>;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
//	cout << "vector of vector\n" ;
	vector<vi> listOfVec;
	int arrNum, qNum;

	cin >> arrNum; cin >> qNum;
	listOfVec.resize(arrNum);
	for (int i = 0; i < arrNum; ++i) {
		int arrSize;
		cin >> arrSize;
		for (int j = 0; j < arrSize; ++j) {
			int arrObj;
			cin >> arrObj;
			listOfVec[i].emplace_back(arrObj);
		}
	}
	for (int i = 0; i < arrNum; ++i) {
		for ( auto j : listOfVec[i] ) {

			//cout << j << " ";
		}
	}
	for (int i = 0; i < qNum; ++i) {
		int idx1, idx2;
		cin >> idx1; cin >> idx2;
		cout << listOfVec[idx1][idx2] << endl;
	}
    return 0;

}

