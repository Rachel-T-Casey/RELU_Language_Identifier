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

}
void Network::deleteLayer() {

}

void Network::inputs(std::vector<double> inputValues) {

}            
void Network::expected(std::vector<double> expectedOutputs) {

}
