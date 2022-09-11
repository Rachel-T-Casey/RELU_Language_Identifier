#include "Network.hpp"

Network::Network(int inputs, int outputs) {
    for(int i = 0; i < inputs; i++) {
        this->m_inputNodes.push_back(new Node);
    }
    for(int i = 0; i < outputs; i++) {
        this->m_outputNodes.push_back(new Node);
    }
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
            layer.push_back(ptr);
        }
        m_hiddenNodes.push_back(layer);
    }

}
void Network::deleteLayer() {

}

void Network::inputs(std::vector<double> inputValues) {

}            
void Network::expected(std::vector<double> expectedOutputs) {

}
