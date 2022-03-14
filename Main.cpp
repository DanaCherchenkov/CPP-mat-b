#include <iostream>
#include <stdlib.h>
#include <string>
#include "mat.hpp"
using namespace std;
using namespace ariel;

int main(){
    cout << "Please insert inputs to get the rug: " << endl;

    int width, length;
    char char1, char2;
    cin >> width;
    cin >> length;
    cin >> char1;
    cin >> char2;

    cout << mat(width, length, char1, char2)<< endl;
    return 0;
}