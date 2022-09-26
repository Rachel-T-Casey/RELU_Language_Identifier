#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "node.hpp"
#include <vector>
    class Network {
        
        public:
            Network(unsigned int inputs, unsigned int outputs);
            ~Network();
            void addLayer();
            void addNodes(unsigned int index, unsigned int nodeCount);
            void process(std::vector<double> inputs);
            std::vector<double> layer(unsigned int index);
            // Sets the inital input values

        private:
            class nodeVectors {    
                public: 
                    std::vector<Node*>& inputs()  { return this->m_inputs; }
                    std::vector<Node*>& outputs()  { return this->m_outputs; }
                    unsigned int size() const { return m_nodes.size();}
                    void addLayer() {
                        std::vector<Node*> layer;
                        this->m_nodes.push_back(layer);
                    }
                    void deleteLayer(unsigned int index) {
                        if(index == 0)
                            throw;
                        if(index >= m_nodes.size())
                            throw;
                        this->m_nodes.erase(m_nodes.begin() + index);
                    }
                    std::vector<Node*>& operator[](unsigned int index) {
                        if(index > m_nodes.size()) 
                            throw;
                        if(index == m_nodes.size())
                            return m_outputs;
                        return m_nodes[index];
                    }
                    const std::vector<Node*>& operator[](unsigned int index) const {
                        if(index > m_nodes.size()) 
                            throw;
                        if(index == m_nodes.size())
                            return m_outputs;
                        return m_nodes[index];
                    }
                private:
                    std::vector<std::vector<Node*>> m_nodes;
                    std::vector<Node*> m_inputs;
                    std::vector<Node*> m_outputs;
            };

            nodeVectors m_nodes;
            const double DCS = 0.5;
    };

#endif 



