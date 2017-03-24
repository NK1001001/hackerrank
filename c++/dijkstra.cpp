//
//  main.cpp
//  algorithms
//
//  Created by Nathaniel Kohn on 24 F 2017.
//  Copyright © 2017 Nathaniel Kohn. All rights reserved.
//
#include <queue>
#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <memory>
#include <map>
#include <set>
#include <queue>
#define mp make_pair

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
const int max_int = 1 << 20; //numeric_limits<int>::max();


class Graph{
public:
    Graph(int nodes = 3000, int edges = 3000*3000/2):
        nodes_(nodes+1),
        edges_(edges),
        dist_(nodes+1, max_int),
        adjList_(nodes+1),
        visited_(nodes+1, 0),
        in_queue_(nodes+1, 0)
    {
        //cout << " graph created, nodes: " << nodes_ << "edges: "  << edges_ << endl;
        //cout << "max is: " << max_int <<  endl;
    }
    ~Graph() {}
    void addEdge(int from, int to, int w) {
        
        adjList_[from].emplace_back(mp(w, to));
        adjList_[to].emplace_back(mp(w, from));
    }
    vii getNeighbours(int n) {
        return adjList_[n];
    }
    void dijkstra(int src);
    
private:
    vi dist_;
    vector<vii> adjList_;
    int nodes_;
    int edges_;
    int src_;
//    std::priority_queue<ii, vii, greater<ii>> pq;
    //std::set<ii> pq;
    map<int, int> path_;
    void print(int node);
    vi visited_;
	vi in_queue_;
	queue<ii> q_;
};

void Graph::print(int node)
{
    if (node == src_) {
        return;
    }
    print(path_[node]);
    cout << dist_[node];
}
void Graph::dijkstra(int src)
{
    src_ = src;
    dist_[src] = 0;
//	pq.push(ii(0, src));
    //pq.emplace(ii(0, src));
	q_.push(ii(0, src)); in_queue_[src_] = 1;
//	while(!pq.empty()) {
	while(!q_.empty()) {
    //for (auto i = pq.begin(); i != pq.end(); ++i) {
//        auto front = pq.top();  pq.pop();
        auto front = q_.front();  q_.pop();
        //auto front = *i;
//        cout << front.first << " " << front.second << " " << endl;
//        visited_[front.second];
        int d = front.first, u = front.second;
		in_queue_[u] = 0;
//        if (d == dist_[u]) {
    		for(int i = 0 ; i < (int)adjList_[u].size(); ++i) {
    			auto v = adjList_[u][i];
                	if(visited_[v.second]) {
                  	 	continue;
                	}
    			if(dist_[v.second] > dist_[u] + v.first) {
                    //pq.erase(ii(dist_[v.second], v.second));
                    		dist_[v.second] = dist_[u] + v.first;
//                    pq.push(ii(dist_[v.second], v.second));
				if(!in_queue_[v.second]) {
                    			q_.push(mp(dist_[v.second], v.second));
					in_queue_[v.second] = 1;
				}
                    //pq.emplace(ii(dist_[v.second], v.second));
    			}
            }
    //    }
	}
    for(int i = 1; i < nodes_; ++i) {
        if(i == src_) {
            continue;
        }
        if(dist_[i] == max_int) {
            cout << "-1" << " ";
        }
        else{
            cout << dist_[i] << " ";
        }
    }
    cout << endl;
}


//
//int main(){
//    int t;
//    cin >> t;
//    for(int a0 = 0; a0 < t; a0++){
//        int n;
//        int m;
//        cin >> n >> m;
//        unique_ptr<Graph> g(new Graph(n,m));
//        for(int a1 = 0; a1 < m; a1++){
//            int x;
//            int y;
//            int r;
//            
//            cin >> x >> y >> r;
//            g->addEdge(x, y, r);
//        }
//        int s;
//        cin >> s;
//        g->dijkstra(s);
//    }
//    return 0;
//}
