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
    ob = *new OscillatorButton(100,350);
    
    sampleRate 			= 44100; /* Sampling Rate */
    initialBufferSize	= 512;	/* Buffer Size. you have to fill this buffer with sound*/
    buffer = new double[initialBufferSize];
    screenRatio = (double)ofGetWidth()/initialBufferSize;
    ofSoundStreamSetup(2,0,this, sampleRate, initialBufferSize, 4);/* Call this last ! */
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(30);
    ofFill();
    ofSetColor(220,220,220);
    for(int i=0; i < initialBufferSize-1; i++){
        ofLine(i*screenRatio, ofGetHeight()/2 + buffer[i]*100, (i+1)*screenRatio, ofGetHeight()/2 + buffer[i+1]*100);
    }
    ob.draw();
}

//--------------------------------------------------------------
void ofApp::audioRequested 	(float * output, int bufferSize, int nChannels){
    
    for (int i = 0; i < bufferSize; i++){

        wave=sine1.sinewave(440);
        buffer[i] = wave;
        
        mymix.stereo(wave, outputs, 0.5);
        
        output[i*nChannels] = outputs[0]; /* You may end up with lots of outputs. add them here */
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
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(ob.isHovered(x,y)){
        cout << "hello";
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