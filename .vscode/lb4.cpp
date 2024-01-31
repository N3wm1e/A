#include <iostream>
using namespace std;
class Graphic_Object
{
    public:
    Graphic_Object(string name,string color)
    {
        this->name=name;
        this->color=color;
    }
    void Move(){cout<<name<<" moved!\n";}
    void Copy(){cout<<name<<" copied!\n";}
    string getName(){return this->name;}
    string getColor(){return this->color;}
    void setName(string name){this->name=name;}
    void setColor(string newColor)
    {
        this->color=newColor;
        cout<<name<<" Color set to "<<newColor<<endl;
    }
    private:
    string name;
    string color;
};
class Circle : public Graphic_Object
{
    public:
    Circle(string name,string color,int radius)
    :Graphic_Object(name,color),radius(radius){}
    int getRadius(){return radius;}
    void setRadius(int radius){this->radius=radius;}
    void showRadius(){cout<<"Radius = "<<radius<<endl;}
    private:
    int radius;
};
class Ellipse : public Circle{
    public:
    Ellipse(string name,string color,int radius,int focusDistance)
    :Circle(name,color,radius),focusDistance(focusDistance){}
    int getFocus(){return focusDistance;}
    void setFocus(int focusDist){this->focusDistance=focusDist;}
    void showFocus(){cout<<getName()<<" focus distance: "<<focusDistance<<endl;}
    private:
    int focusDistance;
};
class Rectangle : public Graphic_Object
{
    public:
    Rectangle(string name,string color,int length,int height):
    Graphic_Object(name,color),length(length),height(height){}
    virtual void calculatePerimeter()
    {
        cout<<"Perimeter = "<<length*2+height*2<<endl;
    }
    virtual void calculateSquare()
    {
        cout<<"Square = "<<length*height<<endl;
    }
    virtual void showLength(){cout<<getName()<<" length: "<<length<<endl;}
    int getLength(){return length;}
    virtual void showHeight(){cout<<getName()<<" height: "<<height<<endl;}
    int getHeight(){return height;}
    virtual void setLength(int length){this->length=length;}
    virtual void setHeight(int height){this->height=height;}
    protected:
    void setDimensions(int length,int height)
    {
        this->height=height;
        this->length=length;
    }
    private:
    int length;
    int height;
};
class Square : public Rectangle
{
    public:
    Square(string name,string color,int sideLength):
    Rectangle(name,color,sideLength,sideLength){}
    int getSideLength(){return sideLength;}
    void setSide(int sideLen){
        this->sideLength=sideLen;
        setDimensions(sideLen,sideLen);
    }
    void showSide(){cout<<"Side length: "<<sideLength<<endl;}
    virtual void setLength(int sideLen) override
    {
        setDimensions(sideLen,sideLen);
    }
    virtual void setHeight(int sideLen) override
    {
        setDimensions(sideLen,sideLen);
    }
    virtual void showLength() override
    {
        showSide();
    }
    virtual void showHeight() override
    {
        showSide();
    }
    private:
    int sideLength;
};
int main() {
    Graphic_Object gr("Graphic 1","Yellow");
    cout<<gr.getName()<<endl;
    gr.Move();
    gr.setColor("Light Pink");
    gr.setName("GrayLine");
   
    Circle cir("Circle 1","Green",5);
    cout<<cir.getName()<<endl;
    cir.showRadius();
    cir.Move();
    cir.setColor("Orange");
   
    Ellipse ell("Ellipse 1","Red",7,8);
    cout<<ell.getName()<<endl;
    ell.showFocus();
    ell.showRadius();
    ell.Move();
    ell.setName("ellipse 1");
    ell.setColor("Gray");
   
    Rectangle rec("recyangle 1","chili",3,9);
    cout<<rec.getName()<<endl;
    rec.showLength();
    rec.Move();
    rec.setHeight(8);
    rec.showHeight();
    rec.calculateSquare();
    rec.calculatePerimeter();
   
    Square sq("square 1","chill",5);
    cout<<sq.getName()<<endl;
    sq.setSide(7);
    sq.showLength();
    sq.calculatePerimeter();
    sq.calculateSquare();
    sq.Move();
    sq.setColor("RedBluish");
    return 0;
}
