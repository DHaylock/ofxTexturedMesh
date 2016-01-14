#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    gradientImage.allocate(ofGetWidth()/2,50,OF_IMAGE_GRAYSCALE);
    for (int x = 0; x < gradientImage.getWidth(); x++) {
        for (int y = 0; y < gradientImage.getHeight(); y++) {
            int value = 255*((float)y/gradientImage.getHeight());
            gradientImage.setColor(x, y, value);
        }
    }
    gradientImage.update();
    vector <ofVec3f> ptss;
    for (int out = 0; out < 50; out++)
    {
        float angle = (1.0 * out) * (2.0 * M_PI)/(1.0 * 50);
        float rx = ofGetWidth()/2 + (200 * cos(angle));
        float ry = ofGetHeight()/2 + (200 * sin(angle));
        ptss.push_back(ofVec3f(rx,ry,0));
    }
    
    meshy.setup(ptss, gradientImage.getWidth(), gradientImage.getHeight(),50);
    wires = false;
}
//--------------------------------------------------------------
void ofApp::update()
{
    for(int x = 0; x < gradientImage.getWidth(); x++) {
        for(int y = 0; y < gradientImage.getHeight(); y++) {
            int value = 255*ofNoise(x/100.0,y/100.0,ofGetElapsedTimef()*0.1);
            gradientImage.setColor(x, y, value);
        }
    }
    gradientImage.update();
}
//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(255);
    ofSetColor(ofColor::white);
    gradientImage.draw(0, 0);
    
    meshy.draw(wires,gradientImage);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    wires = !wires;
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