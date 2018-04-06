/*
 * Author : Zimo Liu
 * HW4b - Postscript Printing
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Postscript {
private:
    ofstream file;
public:
    Postscript(string name){
        file.open (name);    //equals ofstream file(name)
        file<<"%%BoundingBox: 0 0 800 800\n"<<endl;
    }

    void line(int x1, int y1, int x2, int y2){
        file << x1<<' '<<y1<<" moveto\n"<<x2<<' '<<y2<<" lineto\n"<<"stroke\n"<<endl;
    }

    void setColor(int r, int g, int b){
        file << r <<' '<<g <<' '<<b<<' '<< "setrgbcolor "<<"\n"<<endl;

    }

    void drawRect(int x, int y, int w, int h){
        file <<x<<' '<<y<< " moveto\n"<<x+w<<' '<< y<<" lineto\n"<<x+w
             <<' '<<y+h << " lineto\n"<<x<<' '<< y+h <<" lineto\n"
             <<"closepath\n"<<"stroke\n"<<endl;
    }

    void fillRect(int x, int y, int w, int h) {
        file << x << ' ' << y << " moveto\n" << x + w << ' ' << y << " lineto\n" << x + w
             << ' ' << y + h << " lineto\n" << x << ' ' << y + h << " lineto\n"
             << "closepath\n" << "fill\n" << endl;
    }

    void setFillColor(int r, int g, int b){
        file << r/255.0 <<' '<<g/255.0 <<' '<<b/255.0 <<' '<< "setrgbcolor "<<"\n"<<endl;

    }

    void setStrokeColor(int r, int g, int b){
        file << r/255.0 <<' '<<g/255.0 <<' '<<b/255.0 <<' '<< "setrgbcolor "<<"\n"<<endl;

    }

    void drawTriangle(int x1,int y1, int x2,int y2, int x3,int y3){
        file <<x1<<' '<<y1<< " moveto\n"<<x2<<' '<< y2<<" lineto\n"<<x3
             <<' '<<y3 << " lineto\n" <<x1<<' '<< y1<<" lineto\n"<<"closepath\n"<<"stroke\n"<<endl;
    }

    void fillTriangle(int x1,int y1, int x2,int y2, int x3,int y3){
        file <<x1<<' '<<y1<< " moveto\n"<<x2<<' '<< y2<<" lineto\n"<<x3
             <<' '<<y3 << " lineto\n" <<x1<<' '<< y1<<" lineto\n"<<"closepath\n"<<"fill\n"<<endl;

    }

    void drawCircle(int x,int y,int r){
        file<<"newpath\n"<<x<<" "<<y<<" "<<r<<" "<<"0 360 arc\n"<<"fill\n"<<endl;

    }

    void text(int x, int y, string content) {
        file << "/Courier\n" << "20 selectfont\n" << x << " " << y << " " << "moveto\n" << "(" << content << ")" << " "
             << "show\n" << endl;
    }

    void close(){
        file<<"showpage\n"<<"%%EOF"<<endl;
        file.close();
    }

};

int main() {
    Postscript p("test.ps");
    p.line(0,0, 300,400);  // 0 0 moveto 300 400 lineto stroke
    int r = 255, g = 0, b = 0, x = 100, y = 100, w = 100, h = 100, x1 = 200,y1 = 200, x2 = 400 ,y2 = 200 , x3 = 300 , y3 = 300, X = 500, Y = 500 , R = 100 ;
    p.setColor(r, g, b);
    p.drawRect(x, y, w, h);   // x y moveto x+w y lineto x+w y+h lineto ... closepath stroke
    p.fillRect(x, y, w, h);   // x y moveto x+w y lineto x+w y+h lineto ... closepath fill
    p.setFillColor(r, g, b); // 1.0 0.5 0 setrgbcolor
    // optional, figure out how you want to manage color
    p.setStrokeColor(r, g, b);
    p.drawTriangle(x1,y1, x2,y2, x3,y3);
    p.fillTriangle(x1,y1, x2,y2, x3,y3);
    p.drawCircle(X,Y,R); // x y 0 360 r arc stroke
    p.text(x,y, "testing testing 123"); // look it up  setfont  (ABC) show
    p.close();
//    p.grid(300, 50, 500, 400, 50, 700);



}




