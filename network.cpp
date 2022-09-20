#include "Network.hpp"
#include <stdexcept>
#include <iostream>
Network::Network(unsigned int inputs, unsigned int outputs) {
    std::vector<Node*> inputLayer;
    for(unsigned int i = 0; i < inputs; i++) {
        Node* ptr = new Node;
        inputLayer.push_back(ptr);
        this->m_inputs.push_back(ptr);
    }
    this->m_bias = new Node;
    this->m_bias->setValue(0);
    inputLayer.push_back(m_bias);
    this->m_nodes.push_back(inputLayer);
    for(unsigned int i = 0; i < inputs; i++) {
        Node* ptr = new Node;
        this->m_outputs.push_back(ptr);
    }
}
Network::~Network() {
    for(unsigned int layer = 0; layer < this->m_nodes.size(); layer++) { 
        for(auto& node : this->m_nodes[layer]) {
            delete node;
        }
    }
    for(auto& outputNode : this->m_outputs) {
        delete outputNode;
    }
}

void Network::addLayer() {
    std::vector<Node*> layer;
    this->m_nodes.push_back(layer);
}

void Network::addNodesToLayer(unsigned int layer, unsigned int nodes) {
    for(unsigned int i = 0; i < nodes; i++) {
        Node* ptr = new Node;
        if(this->m_nodes.size() == layer) {
            this->m_outputs.push_back(ptr);
        } else {
            this->m_nodes[layer].push_back(ptr);
        }
    }
}

Node* Network::node(unsigned int layer, unsigned int nodeNum) const {
    if(nodeNum == this->m_nodes.size()) {
        return this->m_outputs[nodeNum];
    }
    return this->m_nodes[layer][nodeNum];
}

void Network::connectNodes(Node* one, Node* two, double strength) {
    one->addConnection(two, strength);
}
unsigned int Network::layers() const {
    return this->m_nodes.size() + 1;
}