#include <iostream>
#include <stdexcept>

using namespace std;

void divide(int a, int b){
    if(b == 0){
        throw invalid_argument("Division by zero is invalid");
    }
    cout << "Result: " << a/b << endl;
}

int main(){

    string user_input = "y";
    int a, b;

    while(user_input == "y"){

        try 
        {
            /* code */
            cout << "Enter two numbers: ";
            cin >> a >> b;

            divide(a, b);
        }
        catch(const invalid_argument& e)
        {
            std::cerr << "Caught: " << e.what() << endl;
        }
        catch(const exception& e)
        {
            std::cerr << "General Error: " << e.what() << endl;
        }

        cout << "Do you want to try again?[y/n] ";
        cin >> user_input;

    }

}