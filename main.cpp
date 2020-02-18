#include <iostream>

using namespace std;
// this method is from TA Zuyuan Zhang
/*double round(double var)
{
    double value = (int)(var * 100.0);
    return (double)value / 100.0;
}*/

double round(double num)
{    double rndnum;
    double num2 = num * 100;
    int num3 = (int)num2;
    double dec3 = num2 - num3;
    if ((dec3*10) >= 5) {
        rndnum = ((int)((num)*100))/100.00 + 0.01;
        
    }
    else {
        rndnum= ((int)((num)*100))/100.00;
        
    }    return rndnum;
    
}
template <class DT>
class Point; //class prototype
template <class DT>
ostream& operator <<(ostream& s, Point<DT>& otherOne);

template<class LT>
class LineSegment;
template <class LT>
ostream& operator <<(ostream& s, LineSegment<LT>& otherOne);

template<class IT>
class Segments;
template <class IT>
ostream& operator <<(ostream& s, Segments<IT>& otherOne);

//Start of Point class
template<class DT>
class Point{
    friend ostream& operator << <DT>(ostream& s, Point<DT>& otherOne);
    protected:
  
    DT x;
    DT y;
    public:
    Point();//default
    Point(DT xValue, DT yValue);
    void setLocation(DT xValue, DT yValue);//This sets x and y
    DT getXValue();//return x
    DT getYValue();//return y

    void display();//prints in this format (0.0,0.0)
};

template <class DT>
Point<DT>::Point(){
    x = NULL;
    y = NULL;
}
template<class DT>
Point<DT>::Point(DT a, DT b){
    x = a;
    y = b;
}

template<class DT>
void Point<DT>::setLocation(DT xValue, DT yValue){// question isnt this what the constructor does.
    x = xValue;
    y = yValue;
}

template<class DT>
DT Point<DT>::getXValue(){
    return  x;
}

template <class DT>
DT Point<DT>::getYValue(){
    return  y;
}

template<class DT>
void Point<DT>::display(){
    cout<< "("<< round(x) << ", " << round(y) <<")";
}
template <class DT>
ostream& operator <<  (ostream& s, Point<DT>& otherOne) {
    s << "(" << (*otherOne.x) << ", " << (*otherOne.y) << ")";
    return s;
}
// End of Point class

// Start of LineSegment class
template<class LT>
class LineSegment{
    friend ostream& operator << <LT>(ostream& s, LineSegment<LT>& otherOne);
    protected:
    //so in main when we decide which type of data its going to be
    //The LT will be converted to that LT
        Point<LT> p1;
        Point<LT> p2;
    public:
    LineSegment();
    LineSegment(Point<LT> one, Point<LT> owo);
    
    LT length();// return the length of the line segment - done
    Point<LT> midpoint();//returns a point object - done
    
    Point<LT> xIntercept();
    Point<LT> yIntercept();
    LT slope();
    bool itIntersects(LineSegment L);
    Point<LT> getPoint1();
    Point<LT> getPoint2();
    Point<LT> intersectionPoint(LineSegment L);
    bool isParrallel(LineSegment L);//checks if slopes are the same
    void displayEquation();// print y = m * x + c
    
};
template <class LT>
LineSegment<LT>::LineSegment(){//Default construtor
    p1.setLocation(0.0, 0.0);
    p2.setLocation(0.0, 0.0);
}
template<class LT>
LineSegment<LT>:: LineSegment(Point<LT> one, Point<LT> two){
    p1 = one;
    p2 = two;
}
template<class LT>
LT LineSegment<LT>::length(){
    LT l = 0.0;
    LT x1,x2,y1,y2;//These points are going to be populated with the object call.
    LT squareRt;//This will be used to find the root
    LT temp = 0.0;
    x1 = p1.getXValue();
    y1 = p1.getYValue();
    
    x2 = p2.getXValue();
    y2 = p2.getYValue();
    
    
    l = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1-y2);//I used this formate to make a power of two
   //I used this method for finding square root. //https://ourcodeworld.com/articles/read/884/how-to-get-the-square-root-of-a-number-without-using-the-sqrt-function-in-c
    squareRt = l / 2;
    while(squareRt != temp){
         temp = squareRt;
        
        squareRt = ( l/temp + temp) / 2;
      }
    LT length =  round(squareRt);
    return length;
}
template<class LT>
LT LineSegment<LT>::slope(){
   
    LT x1,x2,y1,y2;
    x1 = p1.getXValue();
    y1 = p1.getYValue();
       
    x2 = p2.getXValue();
    y2 = p2.getYValue();
    //slope is (y2 - y1) / (x2-x1)
    LT slope = (y2 - y1) / (x2-x1);
    return slope;
   
}
template<class LT>
Point<LT> LineSegment<LT>::midpoint(){
    
    //((x1 + x2)/2, (y1 + y2)/2)
    LT x1,x2,y1,y2;
    x1 = p1.getXValue();
    y1 = p1.getYValue();
    x2 = p2.getXValue();
    y2 = p2.getYValue();
    LT midPtX = (x1 + x2)/2;
    LT midPtY = (y1 + y2)/2;
    Point<LT> midPt( round(midPtX),  round(midPtY));
    return midPt;
}

template<class LT>
Point<LT> LineSegment<LT>::xIntercept(){
    LT x1,x2,y1,y2;
    x1 = p1.getXValue();
    y1 = p1.getYValue();
    x2 = p2.getXValue();
    y2 = p2.getYValue();
    // y = mx + b; we need b
    
    // now we can find x intercept y becomes zero
     LT slope = (y2 - y1) / (x2-x1);
    LT b = y1 - (slope * x1);
    LT xInter = ( - b ) / slope;
    Point<LT> pointxIntercept( round(xInter), 0);
    return pointxIntercept;
}
template<class LT>
Point<LT> LineSegment<LT>::yIntercept(){
    LT x1,x2,y1,y2;
    x1 = p1.getXValue();
    y1 = p1.getYValue();
    x2 = p2.getXValue();
    y2 = p2.getYValue();
    // y = mx + b; we need b
    LT slope = (y2 - y1) / (x2-x1);
   //double b = y1 - (slope * x1);
   // now we can find x intercept
    LT yInter =  y1 - (slope * x1);
    Point<LT> pointyIntercept(0 ,  round(yInter));
    return pointyIntercept;
}
//I am using these two getPoint methods to access thepoint object from the
//parameter line seg
template<class LT>
Point<LT> LineSegment<LT>::getPoint1(){
    LT x = p1.getXValue();
    LT y = p1.getYValue();
    Point<LT> px(x,y);
    return px;
}
template<class LT>
Point<LT> LineSegment<LT>::getPoint2(){
    LT x = p2.getXValue();
    LT y = p2.getYValue();
    Point<LT> px2(x,y);
    return px2;
}
template<class LT>
bool LineSegment<LT>::isParrallel(LineSegment<LT> L){//Questi754!on about the object created.
   /* The this pointer is letting me access the points in the object that
    is calling the method
   */
       return this->slope() == L.slope();
}
template<class LT>
bool LineSegment<LT>::itIntersects(LineSegment<LT> L){
    /* if they have the same slope then they will never intersect
     however if they dont then sooner or later they will intersect*/
   // test more then just the slope
  
    //First test if they have the same slope
    if(this->slope() == L.slope()){
        return false;
    }
    LT x1 = this->p1.getXValue();
    LT y1 = this->p1.getYValue();
    LT x2 = this->p2.getXValue();
    LT y2 = this->p2.getYValue();
    
    
    LT x3 = L.getPoint1().getXValue();
    LT y3 = L.getPoint1().getYValue();
    LT x4 = L.getPoint2().getXValue();
    LT y4 = L.getPoint2().getYValue();
    // this equation was derived by http://www.cs.swan.ac.uk/~cssimon/line_intersection.html
    LT a = ((y3-y4)*(x1-x3) + ((x4 - x3)*(y1-y3))) / ((x4-x3)*(y1-y2) - ((x1-x2)*(y4-y3)));
    LT b = (((y1-y2) * (x1-x3)) + ((x2-x1) * (y1-y3))) / (((x4-x3) * (y1-y2)) - ((x1-x2) * (y4-y3)));
    if(a >= 0 && a <= 1 && b >= 0 && b <= 1)
        return true;
    else{
        return false;
    }
}
template<class LT>
Point<LT> LineSegment<LT>::intersectionPoint(LineSegment L){
    /*The idea is when they do intercet they will have the
     same y values so we will set them equal to each other
     and find the points. after we find x we will set the x in
     the line forumal and solve for y*/
    if(this->slope() != L.slope()){
    }
    
      LT m1 = slope();// slope of object calling method
      LT mX1 = this->p1.getXValue();
      LT mY1 = this->p1.getYValue();
    
      LT c1 = mY1 - (m1 * mX1);// This is my b for the first equation
      
      LT x1 = L.getPoint1().getXValue();
      LT y1 = L.getPoint1().getYValue();
    
      LT m2 = L.slope(); // slope of the parameter object
      LT c2 = y1 - (m2 * x1);// this is my b for second equation
    LT xPointIntercept = (c2 - c1)/ (m1 - m2);
    LT yPointIntercept = ((c1*m2) - (c2*m1))/(m2-m1);
    Point<LT> pt( round(xPointIntercept),  round(yPointIntercept));
    return pt;
}
template<class LT>
void LineSegment<LT>::displayEquation(){
   // print y=m*x+c y=1*x+0
    LT x1,y1;
    x1 = p1.getXValue();
    y1 = p1.getYValue();
     
   // double b = round(y1 - (slope() * x1));
   LT x2 = p2.getXValue();
   LT y2 = p2.getYValue();
    
    LT slope = round((y2 - y1) / (x2-x1));
   
    cout<< "y=" <<  slope << "*x+" <<  yIntercept().getYValue() << endl;
  
    
}

//End of LineSegment class

//start of Intervals Class
template<class IT>
class Segments{//This class stores a set of line segments and has it own methods
    friend ostream& operator << <IT>(ostream& s, Segments<IT>& otherOne);
    
protected:
    LineSegment<IT>* segments;// array but we dont know the size yet
    int count;
    IT maxSize;
    
public:
    Segments();
    Segments(IT size);
    void addLineSegment(LineSegment<IT> L);
    void display();
    void displaySub();
    Segments aClosedPolygon();//This will return a closed polygon
    
};
template<class IT>
Segments<IT>::Segments () {
    segments = NULL;
    count = 0;
    maxSize = 0;
   
}
template<class IT>
Segments<IT>:: Segments (IT size) {
    segments = new LineSegment<IT> [size];
    count = 0;
    maxSize = size;
   
}
template<class IT>
void Segments<IT>::addLineSegment(LineSegment<IT> L){

    segments[count] = L;// count is keeping track of element
    count++;
}
template<class IT>
void Segments<IT>::display(){
    //This for loop will go through all line segments and display
    // the many outputs .
    for(int i = 0; i < maxSize; ++i){
        IT slope = round(segments[i].slope());
        cout<<"Line Segment " <<i + 1<<":"<<endl;
        segments[i].getPoint1().display();
        cout<<",";
        segments[i].getPoint2().display();
        cout<<"\n";
        cout<<"Slope:"<<slope<<endl;
        cout<<"Midpoint:";
        segments[i].midpoint().display();
        cout<<"\n";
        cout<<"X Intercept:"<<segments[i].xIntercept().getXValue()<<endl;
        cout<<"Y Intercept:"<<segments[i].yIntercept().getYValue()<<endl;
        cout<<"Length:"<<segments[i].length()<<endl;
        segments[i].displayEquation();
      
    }
    for(int i = 0; i < count - 1; ++i){
       
       for(int j = i + 1; j < count ;++j ){//The j will set the offset
           //So when compareing the first element it wont be redundent and compare the first with the first
           if(segments[i].isParrallel(segments[j])){
               cout<<"The line segments compared are segments["<<i<<"] and segments["<<j
               << "]: Lines are Parallel"<<endl;
           }
           if( segments[i].itIntersects(segments[j])){
               cout<<"The line segments compared are segments["<<i<<"] and segments["<<
               j<<"]: Intersection Point :";
               segments[i].intersectionPoint(segments[j]).display();
               cout<<"\n";
           }
           if(segments[i].isParrallel(segments[j]) == false && segments[i].itIntersects(segments[j]) == false){
               
               cout<<"The line segments compared are segments["<<i<<"] and segments["<<j<<
               "]: Not Parallel and not Intersecting"<< endl;
           }
       }
    }
}

class Exception{
    
};

class LineSegmentsException : Exception{
  
};

class SegmentsException : Exception{
    
};

int main() {

    double x1,x2,y1,y2;
    int numberLines ;
    cin >> numberLines;
  
    Segments<double> intervals(numberLines);
    
    for(int i = 0; i <= numberLines; ++i){
        cin >> x1 >> y1 >> x2 >> y2;
        Point<double> point1(x1,y1);
        Point<double> point2(x2, y2);
        LineSegment<double> newLine(point1, point2);
        
        intervals.addLineSegment(newLine);
        if(cin.eof()){
            break;
        }
    }
   
    intervals.display();

    return 0;
}


/*
#include <iostream>
using namespace std;

class Brian{
public:
    int num;
    Brian();
    Brian(int num2);
    //operator is redefineing operations such as + * / <<
    Brian operator+ (Brian abo);
};
Brian::Brian(){}
Brian::Brian(int num2){
    num = num2;
}
Brian Brian::operator+ (Brian abo){
    Brian brandNew;
    brandNew.num = num + abo.num;
    return(brandNew);
}
class Second{
public:
    Second();
    ~Second();// destructor
    
};
Second::Second(){
    cout<<"I am the constructor"<<endl;
}
Second::~Second(){
    cout<<" I am the deleter"<< endl;
}
int main() {
    Second con;
    cout<<"something"<<endl;
    
    Brian a(34);
    Brian b(21);
    Brian c;
    c = a + b;
    cout << c.num << endl;
    cout<<"Hello"<< endl;
    
    return 0;
}
*/
