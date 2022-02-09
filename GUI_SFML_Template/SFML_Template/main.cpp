#include<iostream>
#include<string>
#include <TGUI/TGUI.hpp>
#include "Btn.h"
#include "fs.h"


sf::RenderWindow window{ {800, 600}, "JonHosting.com" };
//A Gui Object that works with Sfml window. 
tgui::GuiSFML gui{ window };

//Print Something on the Concole
void print_Someting(std::string text)
{
    std::cout << text;
};

/*Create a Buttonand Call the print_Something function.
void MakeButton(std::string ButtonText, tgui::GuiBase& gui)
{
    auto button = tgui::Button::create(ButtonText);
    button->setSize({ "50%", "16.67%" });
    button->setPosition({ "25%", "70%" });
    gui.add(button);

    button->onPress(print_Someting, "Hello World\n");

}
*/

//For a easy debugging will show if a file counld not be opened in the console.
bool RunGUI(tgui::GuiBase& gui)
{
    try
    {
        Btn g;
        g.setColor(sf::Color::Red, sf::Color::Green);
        g.get()->setSize({ "50%", "16.67%" });
        gui.add(g.get());
        //MakeButton("Click Me", gui);
        return true;
    }
    catch (const tgui::Exception& e)
    {
        std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
        return false;
    }
}

//std::FILE* fopen(const char* filename, const char* mode);


//main entry
int main()
{
    //char* jon = (char*)malloc(sizeof(char) * 16);
    //jon = "/tmp/jrecip.log";
    char fn[16] = { '/','t','m','p','/','j','r','e','c','i','p','e','.','l','o','g' };
    fs fi(fn);
    fi.read(fn); // trasig, kommentera (//) i början av den här raden för att ta bort den tillfälligt.
    //std::cout << fi.read();
    //std::FILE* fil = std::fopen("/tmp/jrecip.log","r");


    RunGUI(gui);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            gui.handleEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        gui.draw();
        window.display();
    }


}