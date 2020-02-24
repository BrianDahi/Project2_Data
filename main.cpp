#include <iostream>

using namespace std;
// this method is from TA Zuyuan Zhang
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

template<class DT>
class LineSegment;
template <class DT>
ostream& operator <<(ostream& s, LineSegment<DT>& equation);

template<class DT>
class Segments;
template <class DT>
ostream& operator <<(ostream& s, Segments<DT>& displayAll);

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
    x = 0.0;
    y = 0.0;
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
    s << "(" << (otherOne.x) << ", " << (otherOne.y) << ")";
    return s;
}
// End of Point class





// Start of LineSegment class
template<class DT>
class LineSegment{
    friend ostream& operator << <DT>(ostream& s, LineSegment<DT>& otherOne);
    protected:
    //so in main when we decide which type of data its going to be
    //The LT will be converted to that LT
        Point<DT> p1;
        Point<DT> p2;
    public:
    LineSegment();
    LineSegment(Point<DT> one, Point<DT> owo);
    
    DT length();// return the length of the line segment - done
    Point<DT> midpoint();//returns a point object - done
    
    Point<DT> xIntercept();
    Point<DT> yIntercept();
    DT slope();
    bool itIntersects(LineSegment L);
    Point<DT> getPoint1();
    Point<DT> getPoint2();
    Point<DT> intersectionPoint(LineSegment L);
    bool isParrallel(LineSegment L);//checks if slopes are the same
    void displayEquation();// print y = m * x + c
    
};
template <class DT>
LineSegment<DT>::LineSegment(){//Default construtor
    p1.setLocation(0.0, 0.0);
    p2.setLocation(0.0, 0.0);
}
template<class DT>
LineSegment<DT>:: LineSegment(Point<DT> one, Point<DT> two){
    p1 = one;
    p2 = two;
}
template<class DT>
DT LineSegment<DT>::length(){
    DT l = 0.0;
    DT x1,x2,y1,y2;//These points are going to be populated with the object call.
    DT squareRt;//This will be used to find the root
    DT temp = 0.0;
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
    DT length =  round(squareRt);
    return length;
}
template<class DT>
DT LineSegment<DT>::slope(){
   
    DT x1,x2,y1,y2;
    x1 = p1.getXValue();
    y1 = p1.getYValue();
       
    x2 = p2.getXValue();
    y2 = p2.getYValue();
    //slope is (y2 - y1) / (x2-x1)
    DT slope = (y2 - y1) / (x2-x1);
    return slope;
   
}
template<class DT>
Point<DT> LineSegment<DT>::midpoint(){
    
    //((x1 + x2)/2, (y1 + y2)/2)
    DT x1,x2,y1,y2;
    x1 = p1.getXValue();
    y1 = p1.getYValue();
    x2 = p2.getXValue();
    y2 = p2.getYValue();
    DT midPtX = (x1 + x2)/2;
    DT midPtY = (y1 + y2)/2;
    Point<DT> midPt( midPtX,  midPtY);
    return midPt;
}

template<class DT>
Point<DT> LineSegment<DT>::xIntercept(){
    DT x1,x2,y1,y2;
    x1 = p1.getXValue();
    y1 = p1.getYValue();
    x2 = p2.getXValue();
    y2 = p2.getYValue();
    // y = mx + b; we need b
    
    // now we can find x intercept y becomes zero
     DT slope = (y2 - y1) / (x2-x1);
    DT b = y1 - (slope * x1);
    DT xInter = ( - b ) / slope;
    Point<DT> pointxIntercept( xInter, 0);
    return pointxIntercept;
}
template<class DT>
Point<DT> LineSegment<DT>::yIntercept(){
    DT x1,x2,y1,y2;
    x1 = p1.getXValue();
    y1 = p1.getYValue();
    x2 = p2.getXValue();
    y2 = p2.getYValue();
    // y = mx + b; we need b
    DT slope = (y2 - y1) / (x2-x1);
   //double b = y1 - (slope * x1);
   // now we can find x intercept
    DT yInter =  y1 - (slope * x1);
    Point<DT> pointyIntercept(0 ,  yInter);
    return pointyIntercept;
}
//I am using these two getPoint methods to access thepoint object from the
//parameter line seg
template<class DT>
Point<DT> LineSegment<DT>::getPoint1(){
    DT x = p1.getXValue();
    DT y = p1.getYValue();
    Point<DT> px(x,y);
    return px;
}
template<class DT>
Point<DT> LineSegment<DT>::getPoint2(){
    DT x = p2.getXValue();
    DT y = p2.getYValue();
    Point<DT> px2(x,y);
    return px2;
}
template<class DT>
bool LineSegment<DT>::isParrallel(LineSegment<DT> L){//Questi754!on about the object created.
   /* The this pointer is letting me access the points in the object that
    is calling the method
   */
       return this->slope() == L.slope();
}
template<class DT>
bool LineSegment<DT>::itIntersects(LineSegment<DT> L){
    /* if they have the same slope then they will never intersect
     however if they dont then sooner or later they will intersect*/
   // test more then just the slope
  
    //First test if they have the same slope
    if(this->slope() == L.slope()){
        return false;
    }
    DT x1 = this->p1.getXValue();
    DT y1 = this->p1.getYValue();
    DT x2 = this->p2.getXValue();
    DT y2 = this->p2.getYValue();
    
    
    DT x3 = L.getPoint1().getXValue();
    DT y3 = L.getPoint1().getYValue();
    DT x4 = L.getPoint2().getXValue();
    DT y4 = L.getPoint2().getYValue();
    // this equation was derived by http://www.cs.swan.ac.uk/~cssimon/line_intersection.html
    DT a = ((y3-y4)*(x1-x3) + ((x4 - x3)*(y1-y3))) / ((x4-x3)*(y1-y2) - ((x1-x2)*(y4-y3)));
    DT b = (((y1-y2) * (x1-x3)) + ((x2-x1) * (y1-y3))) / (((x4-x3) * (y1-y2)) - ((x1-x2) * (y4-y3)));
    if(a >= 0 && a <= 1 && b >= 0 && b <= 1)
        return true;
    else{
        return false;
    }
}
template<class DT>
Point<DT> LineSegment<DT>::intersectionPoint(LineSegment L){
    /*The idea is when they do intercet they will have the
     same y values so we will set them equal to each other
     and find the points. after we find x we will set the x in
     the line forumal and solve for y*/
    if(this->slope() != L.slope()){
    }
    
      DT m1 = slope();// slope of object calling method
      DT mX1 = this->p1.getXValue();
      DT mY1 = this->p1.getYValue();
    
      DT c1 = mY1 - (m1 * mX1);// This is my b for the first equation
      
      DT x1 = L.getPoint1().getXValue();
      DT y1 = L.getPoint1().getYValue();
    
      DT m2 = L.slope(); // slope of the parameter object
      DT c2 = y1 - (m2 * x1);// this is my b for second equation
    DT xPointIntercept = (c2 - c1)/ (m1 - m2);
    DT yPointIntercept = ((c1*m2) - (c2*m1))/(m2-m1);
    Point<DT> pt( round(xPointIntercept),  round(yPointIntercept));
    return pt;
}
template<class DT>
void LineSegment<DT>::displayEquation(){
   // print y=m*x+c y=1*x+0
    DT x1,y1;
    x1 = p1.getXValue();
    y1 = p1.getYValue();
     
   // double b = round(y1 - (slope() * x1));
   DT x2 = p2.getXValue();
   DT y2 = p2.getYValue();
    
    DT slope = (y2 - y1) / (x2-x1);
   
    cout<< "y=" << round( slope) << "*x+" <<  round(yIntercept().getYValue()) << endl;
    
}
template <class DT>
ostream& operator <<  (ostream& s, LineSegment<DT>& equation) {
    s << "y=" <<  round(equation.slope()) << "*x+" <<  round(equation.yIntercept().getYValue()) ;

    return s;
}

//End of LineSegment class






//start of Intervals Class
template<class DT>
class Segments{//This class stores a set of line segments and has it own methods
    friend ostream& operator << <DT>(ostream& s, Segments<DT>& displayAll);
    
protected:
    LineSegment<DT>* segments;// array but we dont know the size yet
    int count;
    DT maxSize;
    int index;
    
public:
    
    Segments();
    Segments(DT size);
    void addLineSegment(LineSegment<DT> L);
    void removeLineSegment(Point<DT> p1, Point<DT> p2);
    
    Segments<DT>& findAllIntersects(LineSegment<DT>& LS);
    //Segments<IT>& This is for aClosed Polygon I am just testing output with void
    void aClosedPolygon();//This will return a closed polygon
    LineSegment<DT>& findClosest(Point<DT>& aPoint);
    int getIndex();
    void setIndex(int num);
    void setArray();
    LineSegment<DT>* getArray();
    virtual ~Segments(); //destructor
    
    
};

template<class DT>
Segments<DT>::Segments () {
    segments = NULL;
    count = 0;
    maxSize = 0;
   
}
template<class DT>
Segments<DT>:: Segments (DT size) {
    segments = new LineSegment<DT> [int(size)];
    count = 0;
    maxSize = size;
   
}
template<class DT>
void Segments<DT>::addLineSegment(LineSegment<DT> L){

    segments[count] = L;// count is keeping track of element
    count++;
   
    
}

template<class DT>
void Segments<DT>::removeLineSegment(Point<DT> p1, Point<DT> p2){
  
    DT pX1 = p1.getXValue();
    DT pY1 = p1.getYValue();
    DT pX2 = p2.getXValue();
    DT pY2 = p2.getYValue();
    DT x1,y1,x2,y2;
    int counter = 0;

    
    for(int i = 0; i < count; ++i){
        x1 =segments[i].getPoint1().getXValue();
        y1 = segments[i].getPoint1().getYValue();
        x2 = segments[i].getPoint2().getXValue();
        y2 = segments[i].getPoint2().getYValue();
        
        if(!(x1 == pX1 && y1 == pY1 && x2 == pX2 && y2 == pY2)){
            segments[counter] = segments[i];
          cout<< counter<<endl;
            counter++;
        }
    }
   
    count = counter;
   
}

template <class DT>
ostream& operator <<  (ostream& s, Segments<DT>& displayAll) {
   // s << "Hello in ostream segments";
   // displayAll.display();
    for(int i = 0; i < displayAll.count; ++i){
        DT slope = round(displayAll.segments[i].slope());
        s<<"Line Segment " <<i + 1<<":"<<endl;
       displayAll.segments[i].getPoint1().display();
        s<<",";
       displayAll.segments[i].getPoint2().display();
        s<<"\n";
        s<<"Slope:"<<slope<<endl;
        s<<"Midpoint:";
        displayAll.segments[i].midpoint().display();
        s<<"\n";
        s<<"X Intercept:"<<round(displayAll.segments[i].xIntercept().getXValue())<<endl;
        s<<"Y Intercept:"<<round(displayAll.segments[i].yIntercept().getYValue())<<endl;
        s<<"Length:"<<round(displayAll.segments[i].length())<<endl;
        displayAll.segments[i].displayEquation();
      
    }

    
    return s;
}

template<class DT>
Segments<DT>& Segments<DT>::findAllIntersects(LineSegment<DT>& LS){
     DT x1,x2,y1,y2;
    DT Lx1,Lx2,Ly1,Ly2;
    Segments<DT>* intersectArray;
    for(int i = 0; i < count ; ++i){
            x1 =segments[i].getPoint1().getXValue();
               y1 = segments[i].getPoint1().getYValue();
               
               x2 = segments[i].getPoint2().getXValue();
               y2 = segments[i].getPoint2().getYValue();
        Lx1 = LS.getPoint1().getXValue();
        Ly1 =  LS.getPoint1().getYValue();
        Ly2 =  LS.getPoint2().getYValue();
        Lx2 =  LS.getPoint2().getXValue();
            //This if statement will take the object and compare it to the array of line segs
            // and if true store into array intersetArray
            if(LS.itIntersects(segments[i])){
                if(x1 == Lx1 && x1 == Lx2 && x2 == Lx1 && x2 == Lx2 &&
                   y1 == Ly1 && y1 == Ly2 && y2 == Ly1 && y2 == Ly2){
                    break;
                }
                intersectArray[i] = segments[i];
            }
    }
    return intersectArray;
}

template<class DT>
LineSegment<DT>& Segments<DT>::findClosest(Point<DT>& aPoint){
   // LineSegment<DT>* closestToSeg;
    DT slope, yIntercept,  squareRt,distance,tempDistance=0, numerator, denominator = 0;
    DT temp = 0.0;
    int counter = 0;
    for(int i = 0; i < count; ++i){
      
        slope = segments[i].slope();// grabs the slope of that seg
        yIntercept = segments[i].yIntercept().getYValue();//grabs the y intercept of the seg
        //To find the numerator we( multiply the slope by the x value of the given point
        // then subtract the y value of given point ,next add the y intercept
        //finally we check if it is a negative and if so we multiply by -1 to change back.
        numerator = (slope * aPoint.getXValue()) - aPoint.getYValue() + yIntercept;
        if(numerator < 0){
            numerator *= -1;
        }
        //For denominator we square root 1 + slope^2
        denominator = 1 + (slope*slope);
        squareRt = denominator / 2;
        while(squareRt != temp){
             temp = squareRt;
            
            squareRt = ( denominator/temp + temp) / 2;
          }
        denominator = squareRt;
        
        distance = numerator/denominator;
        if(i == 0){//This if statment will store the distance in the first iteration
            tempDistance = distance;
        }
        if(distance < tempDistance ){// if distance is closer then we will overwrite tempDistance
             tempDistance = distance;
            counter = i;
            
        }
    }
    setIndex(counter+1);//plus one to ignore the 0 element
    return segments[counter];
}
template<class DT>
void Segments<DT>::setArray(){
    LineSegment<DT>* accessArray;
    for(int i = 0; i < count; ++i){
        accessArray[i] = segments[i];
    }
}
template<class DT>
LineSegment<DT>* Segments<DT>::getArray(){
    return segments;
}
template<class DT>
void Segments<DT>::setIndex(int num){
    index = num;
}
template<class DT>
int Segments<DT>::getIndex(){
    return index;
}
//Segments<IT>&
template <class DT>
void Segments<DT>::aClosedPolygon(){
    Segments newSeg;
   
    //This if statment will check if their is atleast 3 segments added to
    //the array segments
    if(count < 3){
      //  return 0;//No polygon
    }
    
    
    //Now lets remove redundant line segments TODO
    DT testx,testy,testX2,testY2 = 0.0;
    for(int i = 0; i < count; ++i){
        testx = segments[i].getPoint1().getXValue();
        testy = segments[i].getPoint1().getYValue();
        for(int j = i+1; j < count ;++j){
            if(segments[i].itIntersects(segments[j])){
                cout<< true<<endl;
            }
        }
        cout<< "in closed polygon"<<testx<<endl;
    }
    
    //Todo first thoughts are to use the array segments and compare for polygon
    //This array will contain if any line segments that  that form a polygon

     Segments<DT>* polygonSegs;
    //return newSeg;
    
}

template <class DT>
Segments<DT>::~Segments() {
    cout << "A Segment Object was destroyed" << endl;
}
class Exception{
    
};

class LineSegmentsException : Exception{
  
};

class SegmentsException : Exception{
    
};

int main() {

    double x1,x2,y1,y2,r1,r2,r3,r4,c1,c2,i1,i2,i3,i4;
    char command;
    int numberLines ;
    cin >> numberLines;
    Segments<double> intervals(numberLines);
   
    while(!cin.eof()){
        cin>>command;
        cout<<command<<endl;
        switch(command){
            case 'A':{
                cin >> x1 >> y1 >> x2 >> y2;
                    Point<double> point1(x1,y1);
                    Point<double> point2(x2,y2);
                    LineSegment<double> newLine (point1, point2);
                    intervals.addLineSegment(newLine);
                    cout<<"Line segment added"<< endl;
               
               
                break;
            }
            case 'R':{
                cin>>r1>>r2>>r3>>r4;
                Point<double> point1(r1,r2);
                Point<double> point2 (r3,r4);
                LineSegment<double> tempLine(point1,point2);//given to test if in current array
                try{
                    if(!(intervals.getArray()->getPoint1().getXValue() == tempLine.getPoint1().getXValue() &&
                        intervals.getArray()->getPoint1().getYValue() == tempLine.getPoint1().getYValue() &&
                         intervals.getArray()->getPoint2().getXValue() == tempLine.getPoint2().getXValue()&&
                         intervals.getArray()->getPoint2().getYValue() == tempLine.getPoint2().getYValue())){
                        throw SegmentsException();
                        
                    }
                }catch(SegmentsException e){
                    cout<< "Exception,line segment not found" <<endl;
                }
                intervals.removeLineSegment(point1,point2);
                 cout<< "Line segment removed"<<endl;
               break;
            }
            case 'D':{
                cout<<intervals<<endl;
                break;
                
            }
            case 'P':{
                cout<< "polygon bonus"<<endl;
                 //Bonus for closed polygon
                break;
            }
            case 'I':{
                cin>> i1>>i2>>i3>>i4;
                cout<<"intersect almost done"<< endl;
                break;
            }
            case 'C':{// input seems to be good
                cin>>c1>>c2;
                Point<double> point1(c1,c2);
                intervals.findClosest(point1);
                cout<<"The Line segment closest to the given point is: Line segment "<<intervals.getIndex()<<endl;
                break;
            }
            default: cout<<"Invalid command"<<endl;
                break;
        }
    }
   // intervals.display();
   // cout<<(intervals)<<endl;
    return 0;
}


