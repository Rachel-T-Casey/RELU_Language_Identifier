#include "node.hpp"


Node::Node() {}
void Node::addConnection(Node* ptr, double weight) {

}
void Node::suggestValue(double weightedValue) {

}

void Node::pushValue() {
    this->m_value = relu(this->m_value);
    for(auto& i : this->m_connections) {

    }
}
double Node::relu(double value) const {
    return std::max(value, 0.0);
}