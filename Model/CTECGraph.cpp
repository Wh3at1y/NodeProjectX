//
//  CTECGraph.cpp
//  NodeProjectX
//
//  Created by Montoya, Samuel on 4/25/16.
//  Copyright © 2016 CTEC. All rights reserved.
//
namespace CTECData {
    template <class Type>
    class CTECGraph
    {
    private:
        static const int MAXIMUM = 20;
        bool adjacencyMatrix [MAXIMUM] [MAXIMUM];
        Type labels [MAXIMUM];
        int manyVertices;
        
    public:
        CTECGraph();
        ~CTECGraph();
        
        void addVertex(const Type& value);
        
    };
}
#include "CTECGraph.hpp"
