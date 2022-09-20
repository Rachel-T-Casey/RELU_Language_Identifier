#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "node.hpp"
#include <vector>
    class Network {
        
        public:
            Network(unsigned int inputs, unsigned int outputs);
            ~Network();
            // Sets the inital input values

            void addLayer();
            void deleteLayer();

            void connectLayers(unsigned int one, unsigned int two);
            unsigned int layers() const; 
            void addNodesToLayer(unsigned int layer, unsigned int nodes) ; 
            Node* node(unsigned int layer, unsigned int nodeNum) const;
            void connectNodes(Node* one, Node* two, double strength);
            void setBias(double bias);
        private:
            Node* m_bias;
            std::vector<std::vector<Node*>> m_nodes;
            std::vector<Node*> m_inputs;
            std::vector<Node*> m_outputs;
            const double DCS = 0.5;
    };

#endif 



