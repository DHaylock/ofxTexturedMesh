//
//  ofxTexturedMesh
//
//  Created by David Haylock on 14/01/2016.
//
//

#pragma once
#ifndef ofxTexturedMesh_h
#define ofxTexturedMesh_h

#include "ofMain.h"
class ofxTexturedMesh {
    
    public:
        ofxTexturedMesh();
        ofxTexturedMesh(vector<ofVec3f> _pts,int texWidth,int texHeight);
        ~ofxTexturedMesh();

        void setup(vector<ofVec3f> _pts,ofVec3f origin,bool orientation,int texWidth,int texHeight,int size);
        void update();
        void draw(bool showWireframe,bool showVertices,bool showOrigin,ofImage img);
    
        vector<ofVec3f> pts;
        ofVec3f origin;
        ofMesh mesh;
        ofPolyline originLine;
};
#endif