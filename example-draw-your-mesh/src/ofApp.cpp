#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    gradientImage.allocate(ofGetWidth()/2,50,OF_IMAGE_COLOR);
    for (int x = 0; x < gradientImage.getWidth(); x++) {
        for (int y = 0; y < gradientImage.getHeight(); y++) {
            int value = 255*((float)x/gradientImage.getWidth());
            gradientImage.setColor(x, y, value);
        }
    }
    gradientImage.update();

    showWires = false;
    showVertices = false;
    showOrigins = false;
}
//--------------------------------------------------------------
void ofApp::update()
{
    
}
//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(255);
    ofSetColor(ofColor::white);
    gradientImage.draw(0, 0);
    meshy.draw(showWires,showVertices,showOrigins,gradientImage);
    
    ofSetColor(ofColor::green);
    markerLine.draw();
    
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
    else if (key == 'l')
    {
        meshy.setup(pts,markerLine.getCentroid2D(),false, gradientImage.getWidth(), gradientImage.getHeight(), 25);
        pts.clear();
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
    markerLine.addVertex(x, y);
    pts.push_back(ofVec3f(x,y,0));
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    markerLine.clear();
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