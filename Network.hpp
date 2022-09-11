#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "node.hpp"
#include <vector>
    class Network {
        
        public:
            Network(int inputs, int outputs);
            ~Network();
            // Sets the inital input values

            void addLayer(int nodes);
            void deleteLayer();

            // Number of inputed values must equal number of inputers
            void inputs(std::vector<double> inputValues);
            void expected(std::vector<double> expectedOutputs);

            void processData();
            void printActual();
            Node* bias() const;
            void setBias(double bias);
        private:
            std::vector<Node*> m_inputNodes;
            std::vector<std::vector<Node*>> m_hiddenNodes;
            std::vector<Node*> m_outputNodes;
            Node* m_bias;
            
            std::vector<double> m_expected;
            std::vector<double> m_actual; 
            const double DCS = 0.5;
    };

#endif 