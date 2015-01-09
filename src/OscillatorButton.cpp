//
//  OscillatorButton.cpp
//  oscillatorVis
//
//  Created by Nevo Segal on 01/01/2015.
//
//

#include "OscillatorButton.h"


OscillatorButton::OscillatorButton(){

}

OscillatorButton::OscillatorButton(int x, int y, string type){
    
    //initial stuff
    this->x = x;
    this->y = y;
    this->type = type;
    xsize = 40;
    ysize = 25;
    freq = 440;
    active = false;
    
    
    //choosing the image according to the type
    if(type == "tri"){
        img.loadImage("tri.png");
    }
    else if(type == "saw"){
        img.loadImage("saw.png");
    }
    else if(type == "square"){
        img.loadImage("square.png");
    }
    else{
        img.loadImage("sine.png");
    }
}

//play function, returns the sample according to the selected oscillator
double OscillatorButton::play(){
    if(type == "tri"){
        wave = osc.triangle(freq);
    }
    else if(type == "saw"){
        wave = osc.saw(freq);
    }
    else if(type == "square"){
        wave = osc.square(freq);
    }
    else{
        wave = osc.sinewave(freq);
    }
    return wave;
}

//draw function of the button
void OscillatorButton::draw(){
    ofNoFill();
    
    //if active - change color.
    if(active){
        ofSetColor(200);
    }
    else{
        ofSetColor(80);
    }

    ofRect(x, y, xsize, ysize);
    img.draw(x, y, xsize, ysize);
}

//checking if the button is hovered.
bool OscillatorButton::isHovered(int x, int y){
    if(x > this->x && y > this->y && x < (this->x + xsize) && y < (this->y + ysize)){
        return true;
    }
    return false;
}

//setting the frequency (if in range)
void OscillatorButton::setFreq(int freq){
    if(freq > 0 && freq < 22050){
        this->freq = freq;
    }
}

//getting the frequency
int OscillatorButton::getFreq(){
    return freq;
}

//checking if oscillator is active
bool OscillatorButton::isActive(){
    return active;
}

//activating the oscillator
void OscillatorButton::activate(){
    active = true;
}

//deactivating the oscillator
void OscillatorButton::deactivate(){
    active = false;
}
