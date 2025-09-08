#include <iostream>
using namespace std;

class Integer 
{
    private:
        /* data */
        int value;
    public:
        Integer(int v): value(v){};
        int getValue() const { return value;}

};

class Counter 
{
    private:
        int count;

    public:
        Counter(){
            count = 0;
        }
        void inc(){count++;}
        void dec(){
            (count == 0)? 0:count--;}
        int getCount() const{return count;}
};

class Library
{
    private:
        bool available;

    public:
        Library():available(true){}
        void checkOut(){
            if(available){
                available = false;
            }
        }

        void checkIn(){
            available = true;
        }

        bool isAvailable() const{
            return available;
        }
};

struct Point
{
    /* data */
    int x,y;
};

int main(){

    //Example1
    Integer n(40);
    n = 102;
    cout << "Value: " << n.getValue() << endl;

    //Example2
    Counter c;
    c.inc();
    cout << "Count: " << c.getCount() << endl;

    //Example3
    Library book;
    book.checkOut();
    cout << "Book Availablity: " << (book.isAvailable() ? "Yes":"No") << endl;

    //Example4
    Point points[2] = {{0,0}, {2,2}};
    for(int i = 0; i < 2; i++){
        /* code */
        cout << "Point " << (i+1) << ": [" << points[i].x << ", " << points[i].y << "]" << endl;
    }
    return 0;
}