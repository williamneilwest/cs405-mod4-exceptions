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
    } catch (std::exception& e){
        throw std::overflow_error("Overflow Error!");

    }



}

float divide(float num, float den)
{
    // Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception

    if (den == 0){
        throw std::runtime_error("Division by zero!");
    }


}

void do_division()
{
    //  create an exception handler to capture ONLY the exception thrown
    //  by divide.

     try {
         float numerator = 10.0f;
         float denominator = 0;
         auto result = divide(numerator, denominator);
         std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
     }catch (std::runtime_error& e){
         throw std::runtime_error("Division by 0 is undefined!");
         }

}

int main() {
    try {
        std::cout << "Exceptions Tests!" << std::endl;

        // Create exception handlers that catch (in this order):
        //  your custom exception
        //  std::exception
        //  uncaught exception
        //  that wraps the whole main function, and displays a message to the console.

        try {
            do_division();
        }
        catch (std::runtime_error &e) {
            std::cout << e.what() << std::endl;
        }
        try {
            do_custom_application_logic();
        }
        catch(std::overflow_error& e){
            std::cout<<e.what()<<std::endl;

        }


    }
    catch(std::exception& f){
        std::cout<<f.what()<<std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu