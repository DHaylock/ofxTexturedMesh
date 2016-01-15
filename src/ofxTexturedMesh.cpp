//
//  ofxTexturedMesh
//
//  Created by David Haylock on 14/01/2016.
//
//
#include "ofxTexturedMesh.h"
//--------------------------------------------------------------
ofxTexturedMesh::ofxTexturedMesh() {}
//--------------------------------------------------------------
ofxTexturedMesh::~ofxTexturedMesh() {}
//--------------------------------------------------------------
ofxTexturedMesh::ofxTexturedMesh(vector<ofVec3f> _pts,int texWidth,int texHeight)
{
}
//--------------------------------------------------------------
void ofxTexturedMesh::setup(vector<ofVec3f> _pts,ofVec2f origin,int texWidth,int texHeight,int size)
{
    mesh.clear();
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    
    originLine.addVertices(_pts);
    
    int interval = texHeight/_pts.size();
    for (int pt = 0; pt < _pts.size(); pt++) {
        
        if (pt == pts.size()-1) {
            mesh.addTexCoord(ofVec2f(0,0));
            mesh.addVertex(origin);
            
            mesh.addTexCoord(ofVec2f(texWidth,pt*interval));
            mesh.addVertex(_pts[pt]);
            
            mesh.addTexCoord(ofVec2f(texWidth,pt*interval));
            mesh.addVertex(_pts[0]);
        }
        else {
            mesh.addTexCoord(ofVec2f(0,0));
            mesh.addVertex(origin);
        
            mesh.addTexCoord(ofVec2f(texWidth,pt*interval));
            mesh.addVertex(_pts[pt+1]);
            
            mesh.addTexCoord(ofVec2f(texWidth,pt*interval));
            mesh.addVertex(_pts[pt]);
        }
    }
}
//--------------------------------------------------------------
void ofxTexturedMesh::draw(bool showWireframe,bool showVertices,bool showOrigin,ofImage img)
{
    ofPushStyle();
    ofSetColor(ofColor::white);
    img.getTexture().bind();
    mesh.draw();
    img.getTexture().unbind();
    
    if (showWireframe) {
        ofSetColor(ofColor::black);
        mesh.drawWireframe();
    }
    if (showVertices) {
        ofSetColor(ofColor::black);
        mesh.drawVertices();
    }

    if (showOrigin) {
        ofSetColor(ofColor::gold);
        originLine.draw();
    }
    ofPopStyle();
}