
import networkx as nx
import sys


class Graph:
    def __init__(self, n):
        g = nx.Graph()
        self.nodes = []
        self.adj = []
        self.vertex_num = n
        self.dist = []
        for i in range(self.vertex_num):
            row_dist = []
            for j in range(self.vertex_num):
                self.nodes.append([i, j])
                row_dist.append(sys.maxint)
            self.dist.append(row_dist)
        for i in range(self.vertex_num):
            for j in range(self.vertex_num):
                if i > 0:
                    print 'i is bigger than zero'

    def neighbours(self, node):
        dirs = [[-1, 0], [1, 0], [0, 1], [0, -1]]
        res = []
        for d in dirs:
            neighbour = [node[0] + d[0], node[1] + d[1]]
            if neighbour in self.nodes:
                res.append(neighbour)
        return res

    def bfs(self):
        print 'All nodes: \n'

        for n in self.nodes:
            print n
        for i in range(self.vertex_num):
            for j in range(self.vertex_num):
                print 'this is the value in for indexes: ', i, j, self.dist[i][j]
        print 'end'
