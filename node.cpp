#include "node.hpp"


Node::Node() { this->m_value = 0; }

void Node::addConnection(Node* ptr, double weight) {
    std::pair<Node*, double> p(ptr, weight);
    this->m_connections.push_back(p);
}

void Node::deleteConnection(Node* ptr) {
    for (auto it = this->m_connections.begin(); it != this->m_connections.end(); ++it) {
        std::pair<Node*, double> p = *it;
        if(p.first == ptr) {
            this->m_connections.erase(it);
        }   
    }
}
void Node::deleteConnections() {
    this->m_connections.clear();
}
void Node::suggestValue(double weightedValue) {
    this->m_value += weightedValue;
}
void Node::setValue(double newValue) {
    this->m_value = newValue;
}
void Node::pushValue() {
    this->m_value = relu(this->m_value);
    if(this->m_value == 0) {
        return;
    }
    for(auto& i : this->m_connections) {
        i.first->suggestValue(i.second * this->m_value);
    }
}
double Node::relu(double value) const {
    return std::max(value, 0.0);
}

double Node::getVal() const {
    return this->relu(this->m_value);
}

 std::vector<std::pair<Node*, double>> Node::getConnections() const {
    return this->m_connections;
 }