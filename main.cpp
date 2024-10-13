#include <iostream>
#include "Model.h"
#include "View.h"
#include "Controller.h"


int main()
{
    std::cout << "Hello MVC project!\n";        
    char ch;    
    do
    {   
        std::unique_ptr<View> view_ptr{ std::make_unique<View>() };
        std::unique_ptr<Doc> doc_ptr{ std::make_unique<Doc>() };
        GraphController myController(std::move(view_ptr), std::move(doc_ptr)); 
        
        std::cout << "Enter 'y' to continue or 'q' to exit" << std::endl;
        std::cin >> ch;
        if (ch == 'q')
            break;     
    } while (true);

    return 0;
}
