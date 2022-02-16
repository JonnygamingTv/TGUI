#include<iostream>
#include<string>
#include <TGUI/TGUI.hpp>
#include "Btn.h"
#include "fs.h"


sf::RenderWindow window{ {800, 600}, "JonHosting.com" };
//A Gui Object that works with Sfml window. 
tgui::GuiSFML gui{ window };
tgui::String languages[2][12] = { {"Back","Local","Cloud"},{"Tillbaks","Lokal","M\x86lnet"}};

/*Print Something on the Concole
void print_Someting(std::string text)
{
    std::cout << text;
};*/

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
Btn btnPage[6];// list of buttons to be used
int currentPage = -1; int Lang = 0;
void pickLang(int L); void goMain();
//For a easy debugging will show if a file counld not be opened in the console.
bool RunGUI(tgui::GuiBase& gui, int p = 0)
{
    try
    {
        if (currentPage != p) {
            for (int i = 0; i < 6; i++) {
                gui.remove(btnPage[i].get());
                btnPage[i].destroy();
            }
            std::cout << "P: " << p << "\n" << "\x86";
        }
        switch (p) {
        case 2:

            break;
        case 1:
            btnPage[0].setColor(sf::Color::Blue, sf::Color::Green);
            btnPage[0].setText(languages[Lang][0]);
            btnPage[0].setTextColor(sf::Color::White);
            btnPage[0].get()->setSize({ "15%", "10%" });
            btnPage[0].get()->setPosition({ "0%","0%" });
            btnPage[0].get()->onClick(goMain);
            btnPage[1].setColor(sf::Color::Red, sf::Color::Green);
            btnPage[1].setText(languages[Lang][1]);
            btnPage[1].get()->setSize({ "50%", "16.67%" });
            btnPage[1].get()->setPosition({ "25%","16.67%" });
            btnPage[2].setColor(sf::Color::Red, sf::Color::Green);
            btnPage[2].setText(languages[Lang][2]);
            btnPage[2].get()->setSize({ "50%", "16.67%" });
            btnPage[2].get()->setPosition({ "25%","60%" });
            for (int i = 0; i < 3; i++)gui.add(btnPage[i].get());
            break;
        default:
            //Btn g;
            btnPage[0].setColor(sf::Color::Red, sf::Color::Green);
            btnPage[0].setText("Svenska");
            btnPage[0].get()->setSize({ "50%", "16.67%" });
            btnPage[0].get()->setPosition({ "0%", "16.67%" });
            btnPage[0].get()->onClick(pickLang, 1);
            btnPage[1].setColor(sf::Color::Red, sf::Color::Green);
            btnPage[1].setText("English");
            btnPage[1].get()->setSize({ "50%", "16.67%" });
            btnPage[1].get()->setPosition({ "50%", "16.67%" });
            btnPage[1].get()->onClick(pickLang, 0);
            for (int i = 0; i < 2; i++)gui.add(btnPage[i].get());
            break;
        }
        currentPage = p;
        //window.clear();
        //gui.draw();
        //window.display();
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
void pickLang(int L) { std::cout << L << "\n"; Lang = L; RunGUI(gui, 1); }
void goMain() { RunGUI(gui,0); }