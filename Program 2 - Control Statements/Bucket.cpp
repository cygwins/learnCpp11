#include <iostream>
#include <string>
#include <cctype>
#include "Bucket.h"

using std::cin;
using std::cout;
using std::endl;

Bucket::Bucket(const int v) : volume(v) {
    water = 0;
    color = "Red";
}

void Bucket::fill(const int w) {
    if(w <= 0) {
        cout << "No water is filled." << endl;
        return;
    }
    if(water + w > volume) {
        int f = volume - water; // actual fill
        cout << "Bucket is full, only " << f << "L water filled." << endl;
        water = volume;
    }
    else {
        cout << w << "L water filled." << endl;
        water += w;
    }
}

void Bucket::pour(const int w) {
    if(w <= 0) {
        cout << "No water is poured." << endl;
        return;
    }
    if(water < w) {
        cout << "Not enough water, only " << water << "L water poured." << endl;
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
    while(static_cast<void>(hint()), cin >> c) { // prompt command guide, wait for input
        switch(c) {
            case 'p': // pour
            {
                cout << "input pour water:" << endl;
                int w;
                cin >> w;
                pour(w);
                break;
            }
            case 'f': // fill
            {
                cout << "input fill water:" << endl;
                int w;
                cin >> w;
                fill(w);
                break;
            }
            case 'r': // replenish
            {
                replenish();
                break;
            }
            case 'e': // empty
            {
                empty();
                break;
            }
            case 'c': // change color
            {
                std::string newColor;
                cout << "input color:" << endl;
                if(cin >> newColor) { paint(newColor); }
                break;
            }
            case 'q': // quit
            {
                return;
            }
            default: // invalid input
            {
                continue;
            }
        } // end of switch
        show();
    } // end of while
}

void Bucket::hint() {
    cout << "'f': fill       'p': pour     'c': change color" << endl
         << "'r': replenish  'e': empty    'q': quit" << endl;
}

void Bucket::paint(const std::string c) {
    color = c;
    color[0] = std::toupper(color[0]);
}

void Bucket::show() {
    cout << color << " bucket with " << water << "L water in it." << endl;
}
