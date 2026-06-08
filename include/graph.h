#pragma once

#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Graph {
   private:
    std::unordered_map<int, std::vector<int>> edges;
    std::unordered_set<int> vertices;

   public:
    Graph(const std::vector<int>& starts, const std::vector<int>& ends) {
        if (starts.size() != ends.size())
            throw std::invalid_argument("Size of starts != Size of ends");

        for (size_t i{0}; i < starts.size(); ++i) {
            vertices.insert(starts[i]);
            edges[starts[i]].push_back(ends[i]);
        }
    }

    int numOutgoing(const int nodeID) const {
        if (!(vertices.contains(nodeID)))
            throw std::invalid_argument("No nodeID Found");
        return edges.at(nodeID).size();
    }

    const std::vector<int>& adjacent(const int nodeID) const {
        if (!(vertices.contains(nodeID)))
            throw std::invalid_argument("No nodeID Found");
        return edges.at(nodeID);
    }

    std::unordered_set<int>::const_iterator const begin() {
        return vertices.begin();
    }

    std::unordered_set<int>::const_iterator const end() {
        return vertices.end();
    }
};
