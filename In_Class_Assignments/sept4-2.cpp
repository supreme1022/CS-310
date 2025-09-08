#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    try
    {
        bool condition = true;
        int nums[] = {2,5,3,67,90};
        int i;
        cout << "Enter an index: ";
        cin >> i;

        if(i < 0 || i > 5){
            throw out_of_range("Index out of bound");
        }

        cout << "Num at index: " << i << ": " << nums[i] << endl;
        if(condition){
            throw runtime_error("Runtime Error occurred");
        } else {
            throw out_of_range("Index out of bound");
        }

    } catch(const runtime_error&e){

        std::cerr << "Runtime Error: " << e.what() << endl;
    } catch(const out_of_range& e){

        std::cerr << "Out of Range Error: " << e.what() << endl;
    }
    cout << "Execution continues..." << endl;
    return 0;
}