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
//    pts.clear();
//    pts = _pts;
//    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
//    
//    int interval = texWidth/pts.size();
//    for (int pt = 0; pt < pts.size(); pt++) {
//        if (pt == 0) {
//            
////            ofVec3f thisPoint = pts[pts.size()];
////            ofVec3f zero = pts[0];
////            
////            ofVec3f direction = (zero - thisPoint);
////            
////            float distance = direction.length();
////            
////            ofVec3f unitDirection = direction.getNormalized();
////            
////            //find both directions to the left and to the right
////            ofVec3f toTheLeft = unitDirection.getRotated(-90, ofVec3f(0,0,1));
////            ofVec3f toTheRight = unitDirection.getRotated(90, ofVec3f(0,0,1));
////            
////            //use the map function to determine the distance.
////            //the longer the distance, the narrower the line.
////            //this makes it look a bit like brush strokes
////            float thickness = 40;
////            
////            //calculate the points to the left and to the right
////            //by extending the current point in the direction of left/right by the length
////            ofVec3f leftPoint = thisPoint+toTheLeft*thickness;
////            ofVec3f rightPoint = thisPoint+toTheRight*thickness;
////            
////            //add these points to the triangle strip
////            mesh.addTexCoord(ofVec2f(0,0));
////            mesh.addVertex(ofVec3f(leftPoint.x, leftPoint.y, leftPoint.z));
////            mesh.addVertex(ofVec3f(rightPoint.x, rightPoint.y, rightPoint.z));
//        }
//        else {
//            ofVec3f thisPoint = pts[pt-1];
//            ofVec3f zero = pts[pt];
//            
//            ofVec3f direction = (zero - thisPoint);
//            
//            float distance = direction.length();
//            
//            ofVec3f unitDirection = direction.getNormalized();
//            
//            //find both directions to the left and to the right
//            ofVec3f toTheLeft = unitDirection.getRotated(-90, ofVec3f(0,0,1));
//            ofVec3f toTheRight = unitDirection.getRotated(90, ofVec3f(0,0,1));
//            
//            //use the map function to determine the distance.
//            //the longer the distance, the narrower the line.
//            //this makes it look a bit like brush strokes
//            float thickness = 40;
//            
//            //calculate the points to the left and to the right
//            //by extending the current point in the direction of left/right by the length
//            ofVec3f leftPoint = thisPoint+toTheLeft*thickness;
//            ofVec3f rightPoint = thisPoint+toTheRight*thickness;
//            
//            //add these points to the triangle strip
//            mesh.addTexCoord(ofVec2f(0,pt*interval));
//            mesh.addVertex(ofVec3f(leftPoint.x, leftPoint.y, leftPoint.z));
//            mesh.addVertex(ofVec3f(rightPoint.x, rightPoint.y, rightPoint.z));
//        }
//        mesh.smoothNormals(90);
//    }
}
//--------------------------------------------------------------
void ofxTexturedMesh::setup(vector<ofVec3f> _pts,int texWidth,int texHeight,int size)
{
    pts.clear();
    pts = _pts;
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    int interval = texWidth/pts.size();
    for (int pt = 0; pt < pts.size(); pt++) {
        if (pt == 0) {
            ofVec3f thisPoint = pts[pts.size()-1];
            ofVec3f zero = pts[0];
            
            ofVec3f direction = (zero - thisPoint);
            
            float distance = direction.length();
            
            ofVec3f unitDirection = direction.getNormalized();
            
            ofVec3f toTheLeft = unitDirection.getRotated(-90, ofVec3f(0,0,1));
            ofVec3f toTheRight = unitDirection.getRotated(90, ofVec3f(0,0,1));
            
            float thickness = size;
            
            ofVec3f leftPoint = thisPoint+toTheLeft*thickness;
            ofVec3f rightPoint = thisPoint+toTheRight*thickness;
            
            mesh.addTexCoord(ofVec2f(pt*interval,0));
            mesh.addVertex(ofVec3f(leftPoint.x, leftPoint.y, leftPoint.z));
            
            mesh.addTexCoord(ofVec2f(pt*interval,texHeight));
            mesh.addVertex(ofVec3f(rightPoint.x, rightPoint.y, rightPoint.z));
        }
        else if (pt == pts.size()) {
            ofVec3f thisPoint = pts[pts.size()-1];
            ofVec3f zero = pts[pts.size()];
            
            ofVec3f direction = (zero - thisPoint);
            
            float distance = direction.length();
            
            ofVec3f unitDirection = direction.getNormalized();
            
            //find both directions to the left and to the right
            ofVec3f toTheLeft = unitDirection.getRotated(-90, ofVec3f(0,0,1));
            ofVec3f toTheRight = unitDirection.getRotated(90, ofVec3f(0,0,1));
            
            float thickness = size;
            
            ofVec3f leftPoint = thisPoint+toTheLeft*thickness;
            ofVec3f rightPoint = thisPoint+toTheRight*thickness;
            
            mesh.addTexCoord(ofVec2f(0,pt*pts.size()));
            mesh.addVertex(ofVec3f(leftPoint.x, leftPoint.y, leftPoint.z));
            
            mesh.addTexCoord(ofVec2f(texWidth,pt*pts.size()));
            mesh.addVertex(ofVec3f(rightPoint.x, rightPoint.y, rightPoint.z));
        }
        else {
            ofVec3f thisPoint = pts[pt-1];
            ofVec3f nextPoint = pts[pt];
            
            ofVec3f direction = (nextPoint - thisPoint);
            
            float distance = direction.length();
            
            ofVec3f unitDirection = direction.getNormalized();
            
            ofVec3f toTheLeft = unitDirection.getRotated(-90, ofVec3f(0,0,1));
            ofVec3f toTheRight = unitDirection.getRotated(90, ofVec3f(0,0,1));
            
            float thickness = size;
            
            ofVec3f leftPoint = thisPoint+toTheLeft*thickness;
            ofVec3f rightPoint = thisPoint+toTheRight*thickness;
            
            mesh.addTexCoord(ofVec2f(pt*interval,0));
            mesh.addVertex(ofVec3f(leftPoint.x, leftPoint.y, leftPoint.z));
            
            mesh.addTexCoord(ofVec2f(pt*interval,texHeight));
            mesh.addVertex(ofVec3f(rightPoint.x, rightPoint.y, rightPoint.z));
        }
    }
}
//--------------------------------------------------------------
void ofxTexturedMesh::draw(bool showWireframe,ofImage img)
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
    ofSetColor(ofColor::black);
    mesh.drawVertices();
    ofPopStyle();
}