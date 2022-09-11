#ifndef NODE_HPP
#define NODE_HPP

#include <algorithm> 
#include <vector>
class Node {
    public:
        Node();
        void pushValue();
        void addConnection(Node* ptr, double weight);
        void suggestValue(double weightedValue);
        void setValue(double newValue);
        double getVal() const;
        std::vector<std::pair<Node*, double>> getConnetions() const;
    private:
        double relu(double value) const;
        double m_value;
        std::vector<std::pair<Node*, double>> m_connections;
    };
#endif
