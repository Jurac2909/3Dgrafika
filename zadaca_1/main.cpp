#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

void tb(float poly, int z, float r, ofstream& mf){
    float ang, x, y;
    for (int i = 0; i <poly; i++) {
        ang = (360/poly)*i;
        x = cos(ang/360*2*M_PI)*r;
        y = sin(ang/360*2*M_PI)*r;
        mf<<"v " + to_string(x) + " " + to_string(y) + " " + to_string(z) +"\n"<<"v " + to_string(x) + " " + to_string(y) + " " + to_string(z) +"\n";


    }


}
void faces(float poly, ofstream& mf){
    int i1 = 1, i3 = poly * 2 + 1, i2 = 3, i4 = 3, i5 = poly*2 + 3, i6 = poly*2 + 1,vn;
    for (int i = 0; i < poly-1; ++i) {
        vn = i + 1;
        mf<<"f " + to_string(i1) + "//" + to_string(vn) + " " + to_string(i2) + "//" + to_string(vn) + " " + to_string(i3) + "//" + to_string(vn) + "\n";
        mf<<"f " + to_string(i4) + "//" + to_string(vn) + " " + to_string(i5) + "//" + to_string(vn) + " " + to_string(i6) + "//" + to_string(vn) + "\n";
        i1 = i1+2;
        i2 = i2+2;
        i3 = i3+2;
        i4 = i4+2;
        i5 = i5+2;
        i6 = i6+2;
    }
    vn = poly;
    i1 = 1;
    i4 = poly*4 - 1;
    i5 = poly*2 - 1;
    i6 = 1;
    mf<<"f " + to_string(i1) + "//" + to_string(vn) + " " + to_string(i2) + "//" + to_string(vn) + " " + to_string(i3) + "//" + to_string(vn) + "\n";
    mf<<"f " + to_string(i4) + "//" + to_string(vn) + " " + to_string(i5) + "//" + to_string(vn) + " " + to_string(i6) + "//" + to_string(vn) + "\n";


}
void bases(float poly, ofstream& mf){
    int b1 = 2 + poly*2, b2 = 2, b, c, vn = poly+1;
    for (int i = 0; i < poly-1; ++i) {
        b = b2 + 2*i;
        c = b2 + 2*i + 2;
        mf<<"f " + to_string(b2) + "//" + to_string(vn) + " " + to_string(b) + "//" + to_string(vn) + " " + to_string(c) + "//" + to_string(vn) + "\n";
    }
    for (int i = 0; i < poly-1; ++i) {
        b = b1 + 2*i;
        c = b1 + 2*i + 2;
        mf<<"f " + to_string(b1) + "//" + to_string(vn) + " " + to_string(b) + "//" + to_string(vn) + " " + to_string(c) + "//" + to_string(vn) + "\n";
    }
}
void norm(float poly, ofstream& mf){
    float ang, x, y;
    for (int i = 0; i <= poly; i++) {
        ang = (360/poly)*i;
        x = cos(ang/360*2*M_PI);
        y = sin(ang/360*2*M_PI);
        mf<<"vn " + to_string(x) + " " + to_string(y) + " 0" +"\n";

    }
    mf<<"vn 0 0 1\n";
}

int main() {
    float poly, r;
    cin>>poly>>r;
    ofstream myFile;
    myFile.open("trimeshcyl.obj");

    tb(poly,-1,r,myFile);
    tb(poly,1,r,myFile);
    norm(poly, myFile);
    faces(poly, myFile);
    bases(poly,myFile);
}
