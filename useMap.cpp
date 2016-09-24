/*
Author: Akshay Joshi
*/

#include <iostream>
#include <map>
using namespace std;

union func_vtc{
  void (*drawCircle)(struct Circle *C);
  float (*areaCircle)(struct Circle*);
};

union func_vtt{
  void (*drawTriangle)(struct Triangle *T);
  float (*areaTriangle)(struct Triangle*);
};

struct Triangle {
    char TColor;
    char Tshade;
    short height;
    short base;
    func_vtt vtt[2];
};

struct  Circle {
    char color;
    char shade;
    short radius;
    func_vtc vtc[2];
};


void setCircle (struct Circle *C, char col, char shad, short rad);
void drawCircle (struct Circle *C) ;
float areaCircle(struct Circle*);

void setTriangle (struct Triangle *T, char col, char shad, short heigh, short bass);
void drawTriangle (struct Triangle *T);
float areaTriangle(struct Triangle*);

union shape_ptr {
   struct Circle* cir_ptr;
   struct Triangle* tri_ptr;
 };

void do_poly(union shape_ptr shape);

int main() {

  Triangle t1;//created triangle object
  Triangle t2;
  Circle c1;// created circle object
  Circle c2;
  setCircle (&c1,'R' , 'L', 3 );
  setCircle (&c2,'B' , 'D', 2 );
  setTriangle (&t1, 'G', 'D', 6, 2);
  setTriangle (&t2, 'B', 'L',10, 5);

std:: map<int,union shape_ptr> myData;
myData[0].tri_ptr=&t1;
myData[1].tri_ptr=&t2;
myData[2].cir_ptr=&c1;
myData[3].cir_ptr=&c2;

std::map<int, union shape_ptr> :: iterator it=myData.begin();
for(it=myData.begin();it!=myData.end();it++)
{
  do_poly(it->second);
}
  return 0;
}


void do_poly(union shape_ptr shape){
shape.tri_ptr->vtt[0].drawTriangle(shape.tri_ptr);
cout<<"Area: "<<shape.tri_ptr->vtt[1].areaTriangle(shape.tri_ptr)<<endl;
}

float areaCircle(struct Circle* ACirc)
{
  short rad;
  rad=  (*ACirc).radius;
  float area= ((rad)*(rad)*(3.14));
  return area;
}

void setCircle (struct Circle *C, char col, char shad, short rad)
{
 C->color=col;
 C->shade=shad;
 C->radius=rad;
 C->vtc[0].drawCircle=drawCircle;
 C->vtc[1].areaCircle=areaCircle;
}

void drawCircle (struct Circle* Cad)
{
  string Colour, Shadow;
  switch(Cad->color)
 {
   case 'R':
        Colour="Red";
        break;
  case 'G':
       Colour="Green";
       break;
  case 'B':
        Colour="Blue";
        break;
  default:
        Colour="Invalid Colour";
        break;
    }

    switch(Cad->shade)
    {
     case 'D':
          Shadow="Dark";
          break;
    case 'L':
         Shadow="Light";
         break;
    default:
          Shadow="Invalid Shade";
          break;
      }

  cout<<"\nThese are Circles's features \nColor:"<< Colour <<"\nShade: " <<Shadow <<"\nRadius: " <<(*Cad).radius<<endl;
}

float areaTriangle(struct Triangle* Atri)
{
  short H, bas;
  H=  (*Atri).height;
  bas=  (*Atri).base;
  float area= ((H)*(bas)*(0.5));
  return area;
}

void setTriangle (struct Triangle *T, char col, char shad, short heigh, short bass)
{

T->TColor=col;
T->Tshade=shad;
T->height=heigh;
T->base=bass;
T->vtt[0].drawTriangle=&drawTriangle;
T->vtt[1].areaTriangle=&areaTriangle;

}

void drawTriangle (struct Triangle* Tad)
{

  string Colour, Shadow;
  switch(Tad->TColor)
 {
   case 'R':
        Colour="Red";
        break;
  case 'G':
       Colour="Green";
       break;
  case 'B':
        Colour="Blue";
        break;
  default:
        Colour="Invalid Colour";
        break;
    }

    switch(Tad->Tshade)
    {
     case 'D':
          Shadow="Dark";
          break;
    case 'L':
         Shadow="Light";
         break;
    default:
          Shadow="Invalid Shade";
          break;
      }

  cout<<"\nThese are Triangle's features \nColor:"<< Colour <<"\nShade: " <<Shadow <<"\nHeight: " << (*Tad).height<<"\nBase: " << (*Tad).base<<endl;
}
