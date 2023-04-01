// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool do_even_more_custom_application_logic()
{
    // Throw any standard exception
    int x = INT_MAX;
    int y = 1;
    int z = x + y;
    if (z >0){
        std::cout<<"Addition successful!";
    }
    else {
        throw std::exception();
    }
    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}
void do_custom_application_logic()
{
    // Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;
    try{
        if(do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
        std::cout << "Leaving Custom Application Logic." << std::endl;
    } catch (std::exception& f){
        std::cout<<"Overflow Error! "<<f.what()<<std::endl;

    }



}

float divide(float num, float den)
{
    // Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception

    if (den == 0){
        throw std::exception();
    }
    return num/den;


}

void do_division()
{
    //  create an exception handler to capture ONLY the exception thrown
    //  by divide.

     try {
         float num;
         float den;
         std::cout<<"Numerator: ";
         std::cin>>num;
         std::cout<<"Denominator: ";
         std::cin>>den;
         auto result = divide(num, den);
         std::cout << "divide(" << num << ", " << den << ") = " << result << std::endl;
     }catch (const std::exception& e){
         std::cout<<"Division by 0 is undefined!"<<std::endl;
         }

}

int main() {
    std::cout << "Exceptions Tests!" << std::endl;

    try {
        // Create exception handlers that catch (in this order):
        //  your custom exception
        //  std::exception
        //  uncaught exception
        //  that wraps the whole main function, and displays a message to the console.
        do_division();
        do_custom_application_logic();
    }
    catch (std::runtime_error& f) {
        std::cout << f.what() << std::endl;
    }
    catch(std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
    catch(...){
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu