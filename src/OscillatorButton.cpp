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
    this->x = x;
    this->y = y;
    this->type = type;
    xsize = 40;
    ysize = 25;
    freq = 440;
    active = false;
    
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

void OscillatorButton::draw(){
    ofNoFill();
    if(active){
        ofSetColor(200);
    }
    else{
        ofSetColor(80);
    }

    ofRect(x, y, xsize, ysize);
    img.draw(x, y, xsize, ysize);
}

bool OscillatorButton::isHovered(int x, int y){
    if(x > this->x && y > this->y && x < (this->x + xsize) && y < (this->y + ysize)){
        return true;
    }
    return false;
}

void OscillatorButton::setFreq(int freq){
    if(freq > 0 && freq < 22050){
        this->freq = freq;
    }
}

int OscillatorButton::getFreq(){
    return freq;
}

bool OscillatorButton::isActive(){
    return active;
}

void OscillatorButton::activate(){
    active = true;
}

void OscillatorButton::deactivate(){
    active = false;
}
