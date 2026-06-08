#pragma once

#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Graph {
   private:
    std::unordered_map<int, std::unordered_set<int>> edges;
    std::unordered_set<int> verticies;

   public:
    Graph(const std::vector<int>& starts, const std::vector<int>& ends) {
        if (starts.size() != ends.size())
            throw std::invalid_argument("Size of starts != Size of ends");

        for (size_t i{0}; i < starts.size(); ++i) {
            verticies.insert(starts[i]);
            edges[starts[i]].insert(ends[i]);
        }
    }

    int numOutgoing(const int nodeID) const {
        if (!(verticies.contains(nodeID)))
            throw std::invalid_argument("No nodeID Found");
        return edges.at(nodeID).size();
    }

    const std::vector<int> adjacent(const int nodeID) const {
        if (!(verticies.contains(nodeID)))
            throw std::invalid_argument("No nodeID Found");

        std::vector<int> adjacency_list;
        std::for_each(edges.at(nodeID).cbegin(), edges.at(nodeID).cend(),
                      [&](const int& node) { adjacency_list.push_back(node); });
        return adjacency_list;
    }
};
