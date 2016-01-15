#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    gradientImage.allocate(ofGetWidth()/2,50,OF_IMAGE_GRAYSCALE);
    for(int x = 0; x < gradientImage.getWidth(); x++) {
        for(int y = 0; y < gradientImage.getHeight(); y++) {
//            int value = 255*ofNoise(x/100.0,y/100.0,ofGetElapsedTimef()*0.1);
            int value = 255*((float)x/gradientImage.getWidth());
            gradientImage.setColor(x, y, value);
        }
    }
    gradientImage.update();
    
    mappedGradientImage.allocate(ofGetWidth()/2,50,OF_IMAGE_COLOR);
    int columnwidth = 0;
    for(map<string,ofxColorMap::ColorMap>::const_iterator it = colormap.namedMaps.begin();
        it != colormap.namedMaps.end(); it++) {
        const string& name = it->first;
        if(name.length() > columnwidth) {
            columnwidth = name.length();
        }
    }
    string defaultmap = "gray";
    int column = 0;
    int textheight = 16;
    int rowheight = textheight*1.2;
    columnwidth *= 7*1.2;
    
    // Make clickable boxes to select color map
    int row = 0;
    for(map<string,ofxColorMap::ColorMap>::const_iterator it = colormap.namedMaps.begin();
        it != colormap.namedMaps.end(); it++) {
        const string& name = it->first;
        ClickBox b;
        ofRectangle r;
        r.x = 2+column*columnwidth;
        r.y = 2+row*rowheight;
        if(r.y+rowheight+14 > ofGetHeight()) {
            column += 1;
            row = 0;
        } else {
            row += 1;
        }
        r.width = columnwidth-2;
        r.height = rowheight-2;
        b.text = name;
        b.active = false;
        if(name == defaultmap) {
            b.active = true;
            cout << name << endl;
        }
        b.box = r;
        boxes.push_back(b);
    }
    currentmap = defaultmap;
    colormap.setMapFromName(defaultmap);
    
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
    hide = true;
    showWires = false;
    showVertices = false;
    showOrigins = false;
    meshy.setup(points,origin,mappedGradientImage.getWidth(), mappedGradientImage.getHeight(),100);
}
//--------------------------------------------------------------
void ofApp::update()
{
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    for(int x = 0; x < gradientImage.getWidth(); x++) {
        for(int y = 0; y < gradientImage.getHeight(); y++) {
            int value = 255*ofNoise(x/100.0,y/100.0,ofGetElapsedTimef()*0.1);
            gradientImage.setColor(x, y, value);
        }
    }
    gradientImage.update();
    colormap.apply(gradientImage, mappedGradientImage);
}
//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(255);
    ofSetColor(ofColor::white);
    gradientImage.draw(0, 0);
    mappedGradientImage.draw(0, 50);
    
    
    if (!hide) {
        ofColor active(0,255*0.4,0);
        ofColor notactive(0,0,0);
        for(int i = 0; i < boxes.size(); i++) {
            ofDrawBitmapStringHighlight(boxes[i].text, boxes[i].box.x, boxes[i].box.y+14, boxes[i].active?active:notactive);
        }
    }
    
    meshy.draw(showWires,showVertices,showOrigins,mappedGradientImage);
    
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
    else if(key == 'h') {
        hide = !hide;
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
    if (!hide) {
        bool clicked = false;
        for(int i = 0; i < boxes.size(); i++) {
            if(boxes[i].box.inside(x,y)) {
                clicked = true;
                currentmap = boxes[i].text;
            }
        }
        
        if(clicked) {
            for(int i = 0; i < boxes.size(); i++) {
                boxes[i].active = (boxes[i].text == currentmap);
            }
            
            colormap.setMapFromName(currentmap);
        }
    }
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