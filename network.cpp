#include "Network.hpp"
#include <stdexcept>
#include <iostream>
Network::Network(unsigned int inputs, unsigned int outputs) {
    
    std::vector<Node*>* inputLayer = &m_nodes.inputs();
    this->m_nodes.addLayer();
    std::vector<Node*>* outputLayer = &m_nodes.outputs();
    for(unsigned int i = 0; i < inputs; i++) {
        Node* n = new Node;
        inputLayer->push_back(n);
        this->m_nodes[0].push_back(n);
    }
        // Code for bias node management 

    for(unsigned int i = 0; i < outputs; i++) {
        Node * n = new Node;
        outputLayer->push_back(n);
    }
}
Network::~Network() {
    for(unsigned int i = 0; i < this->m_nodes.size(); i++) {
        for(auto& node : this->m_nodes[i]) {
            delete node;
        }
    }
}
void Network::addLayer() {
    this->m_nodes.addLayer();
    return;
}
void Network::addNodes(unsigned int index, unsigned int count) {
    for(unsigned int i = 0; i < count; i ++) {
        this->m_nodes[index].push_back(new Node);
    }
}

std::vector<double> Network::layer(unsigned int index) {
    std::vector<double> r;
    for(auto& node : this->m_nodes[index]) {
        r.push_back(node->getVal());
    }
    return r;
}

void Network::connectNode(Node* input, Node* output, double strength) {
    input->addConnection(output, strength);
}

void Network::connectLayer(unsigned int send, unsigned int receive) {
    for(auto& sender : this->m_nodes[send]) {
        for(auto& receiver : this->m_nodes[receive]) {
            this->connectNode(sender, receiver, DCS);
        }
    }
}
void Network::process(std::vector<int> data) {
    if(data.size() != this->m_nodes.inputs().size())
        throw;
    for(unsigned int i = 0; i < data.size(); i++) {
        this->m_nodes.inputs()[i]->setValue(data[i]);
    }
    for(unsigned int i = 0; i < this->m_nodes.size()-1; i++) {
        for(auto& node : this->m_nodes[i]) {
            node->pushValue();
        }
    }
}