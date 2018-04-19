#include <iostream>
#include <string>
#include "Bucket.h"

using std::cin;
using std::cout;
using std::endl;

Bucket::Bucket(int v) {
    this->volume = v;
    this->water = 0;
    this->color = "Red";
}

void Bucket::fill(int w) {
    if(w <= 0) {
        cout << "No water is filled." << endl;
        return;
    }
    if(water + w > volume) {
        int f = volume - w; // actual fill
        cout << "Bucket is full, only" << f << "L water filled." << endl;
        water = volume;
    }
    else {
        cout << w << "L water filled." << endl;
        water += w;
    }
}

void Bucket::pour(int w) {
    if(w <= 0) {
        cout << "No water is poured." << endl;
        return;
    }
    if(water < w) {
        cout << "Not enough water, only" << water << "L water poured." << endl;
        water = volume;
    }
    else {
        cout << w << "L water poured." << endl;
        water -= w;
    }
}

void Bucket::replenish() {
    for(int w = water; w < volume; ++w) {
        cout << "Filling water..." << endl;
    }
    water = volume;
    cout << "Replenished." << endl;
}

void Bucket::empty() {
    for(int w = water; w > 0; --w) {
        cout << "Pouring water..." << endl;
    }
    water = 0;
    cout << "Empty." << endl;
}

void Bucket::manip() {
    char c;
    while(hint(), cin >> c) {
        switch(c) {
            case 'p':
            {
                cout << "input pour water:" << endl;
                int w;
                cin >> w;
                this->pour(w);
                break;
            }
            case 'f':
            {
                cout << "input fill water:" << endl;
                int w;
                cin >> w;
                this->fill(w);
                break;
            }
            case 'r':
            {
                this->replenish();
                break;
            }
            case 'q':
            {
                return;
            }
            default:
            {
                continue;
            }
        } // end of switch
        show();
    } // end of while
}

void Bucket::hint() {
    cout << "'f': fill, 'p': pour, 'r': replenish, 'e': empty, 'q': quit" << endl;
}

void Bucket::paint(std::string c) {
    this->color = c;
}

void Bucket::show() {
    cout << this->color << "bucket with " << this->water << "L water in it." << endl;
}
