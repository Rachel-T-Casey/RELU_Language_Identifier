#include "Network.hpp"
#include <stdexcept>
#include <iostream>
Network::Network(int inputs, int outputs) {
    for(int i = 0; i < inputs; i++) {
        this->m_inputNodes.push_back(new Node);
    }
    for(int i = 0; i < outputs; i++) {
        this->m_outputNodes.push_back(new Node);
    }
    this->m_bias = new Node;
    this->m_bias->setValue(0);
}
Network::~Network() {
    for(auto& i : this->m_inputNodes) {
        delete i;
    }
    for(auto& i : this->m_outputNodes) {
        delete i;
    }
}
void Network::addLayer(int nodes) {
    std::vector<Node*> layer;
    if(this->m_hiddenNodes.size() == 0) { 
        for(int i = 0; i < nodes; i++) {
            Node* ptr = new Node;
            for(auto& inputNode : this->m_inputNodes) {
                inputNode->addConnection(ptr, DCS);
            }
            for(auto& outputNode : this->m_outputNodes) {
                ptr->addConnection(outputNode, DCS);
            }
            this->m_bias->addConnection(ptr, DCS);
            layer.push_back(ptr);
        }
        m_hiddenNodes.push_back(layer);
    } else {
        for(int i = 0; i < nodes; i++) {
            Node* ptr = new Node;
            for(auto& hiddenNode : this->m_hiddenNodes[m_hiddenNodes.size()-1]) {
                hiddenNode->deleteConnections();
                hiddenNode->addConnection(ptr, DCS);
            }
            for(auto& outputNode : this->m_outputNodes) {
                ptr->addConnection(outputNode, DCS);
            }
            layer.push_back(ptr);
        }
    }
    this->m_hiddenNodes.push_back(layer);

}
void Network::deleteLayer() {

}

void Network::inputs(std::vector<double> inputValues) {
    if(inputValues.size() != inputValues.size()) {
        throw std::invalid_argument("Number of input values must equal number of input nodes");
    }
    for(unsigned int i = 0; i < inputValues.size(); i++) {
        this->m_inputNodes[i]->setValue(inputValues[i]);
    }
}            
void Network::expected(std::vector<double> expectedOutputs) {
    if(expectedOutputs.size() != this->m_outputNodes.size()) {
        throw std::invalid_argument("Number of expected outputs must equal number of output nodes");
    }
    for(auto& expectedValue : expectedOutputs) {
        this->m_expected.push_back(expectedValue);
    }
}

void Network::processData() {
    for(auto& inputNode : this->m_inputNodes) {
        inputNode->pushValue();
    }
    
    this->m_bias->pushValue();

    for(unsigned int i = 0; i < this->m_hiddenNodes.size(); i++) {
        for(auto& hiddenNode : this->m_hiddenNodes[i]) {
            hiddenNode->pushValue();
        }
    }
    for(auto& outputNode : this->m_outputNodes) {
        if(outputNode->getVal() > 1) {
            m_actual.push_back(1);
            return;
        }
        if(outputNode->getVal() < 0) {
            m_actual.push_back(0);
            return;
        }
        m_actual.push_back(outputNode->getVal());
    }
}

void Network::printActual() {
    for(auto& output : m_actual) {
        std::cout << output << std::endl;
    }
}

Node* Network::bias() const { 
    return this->m_bias;
 }
void Network::setBias(double bias) {
    this->m_bias->setValue(bias);
}