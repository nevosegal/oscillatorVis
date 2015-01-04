/* This is an example of how to integrate maximilain into openFrameworks,
 including using audio received for input and audio requested for output.
 
 
 You can copy and paste this and use it as a starting example.
 
 */


#include "ofApp.h"



//-------------------------------------------------------------
ofApp::~ofApp() {
    
    //    delete beat.myData; /*you should probably delete myData for any sample object
    //that you've created in ofApp.h*/
    
}


//--------------------------------------------------------------
void ofApp::setup(){
    /* some standard setup stuff*/
    
    ofEnableAlphaBlending();
    ofSetupScreen();
//    ofBackground(0, 0, 0);
    ofSetVerticalSync(true);
    numOsc = 4;
    osc_btns = new OscillatorButton[numOsc];
    osc_btns[0] = *new OscillatorButton(150,350,"sine");
    osc_btns[1] = *new OscillatorButton(250,350,"saw");
    osc_btns[2] = *new OscillatorButton(350,350,"square");
    osc_btns[3] = *new OscillatorButton(450,350,"tri");
    osc_btns[0].activate();
    
    ttf.loadFont("UbuntuMono-Bold.ttf", 16);
    sampleRate 			= 44100;
    initialBufferSize	= 512;
    buffer = new double[initialBufferSize];
    screenRatio = (double)ofGetWidth()/initialBufferSize;
    ofSoundStreamSetup(2,0,this, sampleRate, initialBufferSize, 4);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(30);
    ofFill();
    ofSetColor(220);
    for(int i=0; i < initialBufferSize-1; i++){
        ofLine(i*screenRatio, ofGetHeight()/2 + buffer[i]*100, (i+1)*screenRatio, ofGetHeight()/2 + buffer[i+1]*100);
    }
    for(int i = 0; i < numOsc; i++){
        osc_btns[i].draw();
    }
    ofSetColor(220);
    ttf.drawString(ofToString(osc_btns[currOsc].getFreq()),20, 20);
}

//--------------------------------------------------------------
void ofApp::audioRequested 	(float * output, int bufferSize, int nChannels){
    
    for (int i = 0; i < bufferSize; i++){
        
        buffer[i] = osc_btns[currOsc].play();
        
        mymix.stereo(buffer[i], outputs, 0.5);
        
        output[i*nChannels] = outputs[0];
        output[i*nChannels+1] = outputs[1];
    }
    
}

//--------------------------------------------------------------
void ofApp::audioReceived 	(float * input, int bufferSize, int nChannels){
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    int deltay = ypos-y;
    int currFreq = osc_btns[currOsc].getFreq();
    osc_btns[currOsc].setFreq(currFreq + deltay);
    ypos = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for (int i = 0; i < numOsc; i++) {
        if(osc_btns[i].isHovered(x,y)){
            currOsc = i;
            osc_btns[currOsc].activate();
            for(int j = 0; j < numOsc; j++){
                if(j != currOsc){
                    osc_btns[j].deactivate();
                }
            }
        }
        else{
            ypos = y;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}



//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}