#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // Allocate the gradient Image
    // Fill with black to white pixels
    gradientImage.allocate(ofGetWidth()/2,50,OF_IMAGE_GRAYSCALE);
    for (int x = 0; x < gradientImage.getWidth(); x++) {
        for (int y = 0; y < gradientImage.getHeight(); y++) {
            int value = 255*((float)x/gradientImage.getWidth());
            gradientImage.setColor(x, y, value);
        }
    }
    gradientImage.update();
    
    // Make a circle
    ofVec3f origin = ofVec3f(ofGetWidth()/2, ofGetHeight()/2,0);
    vector <ofVec3f> points;
    for (int out = 0; out < 50; out++)
    {
        float angle = (1.0 * out) * (2.0 * M_PI)/(1.0 * 50);
        float rx = origin.x + (200 * cos(angle));
        float ry = origin.y + (200 * sin(angle));
        points.push_back(ofVec3f(rx,ry,0));
    }
    
    // Setup ofxTexturedMesh
    meshy.setup(points,origin, gradientImage.getWidth(), gradientImage.getHeight(),50);

    showWires = false;
    showVertices = false;
    showOrigins = false;
}
//--------------------------------------------------------------
void ofApp::update()
{
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}
//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(255);
    ofSetColor(ofColor::white);
    gradientImage.draw(0, 0);
    
    // Draw the Mesh
    meshy.draw(showWires,showVertices,showOrigins,gradientImage);
    
    ofPushStyle();
    ofFill();
    ofSetColor(ofColor::black);
    ofDrawRectangle(0, ofGetHeight()-20, ofGetWidth(), 20);
    stringstream stra;
    string w = (showWires) ? "True" : "False";
    string v = (showVertices) ? "True" : "False";
    string o = (showOrigins) ? "True" : "False";
    stra << "Showing Wireframe: " << w << " Showing Vertices: " << v << " Showing Origins: " << o << endl;
    ofSetColor(ofColor::white);
    ofDrawBitmapString(stra.str(),5, ofGetHeight()-7);
    ofPopStyle();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if(key == 'w') {
        showWires = !showWires;
    }
    else if(key == 'v') {
        showVertices = !showVertices;
    }
    else if(key == 'o') {
        showOrigins = !showOrigins;
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}
//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}