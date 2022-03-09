#include<iostream>
#include<string>
#include <TGUI/TGUI.hpp>
#include "Btn.h"
#include "Input.h"
#include "fs.h"


sf::RenderWindow window{ {800, 600}, "JonHosting.com" };
//A Gui Object that works with Sfml window. 
tgui::GuiSFML gui{ window };
tgui::String languages[2][12] = { {"Back","Local","Cloud","Login","Username","Password","Create New","Edit"},{"Tillbaks","Lokal","Online","Logga in","Namn","Nyckel","Skapa Ny","Redigera"}};
tgui::String uname; // username identifier

Btn btnPage[9];// list of buttons to be used
Input inputPage[2]; // list of input areas to be allowed to be used
int currentPage = -1; int Lang = 0;
void pickLang(int L); void goMain(); void whatLogin(int p); void saver(); bool handleLogin(int which); void checkLogin();
//For easy debugging, show if a file could not be opened in the console.
bool RunGUI(tgui::GuiBase& gui, int p = 0)
{
    try
    {
        if (currentPage != p) {
            for (int i = 1; i < 9; i++) {
                //gui.remove(btnPage[i].get());
                //btnPage[i].destroy();
                btnPage[i].get()->setVisible(false);
            }
            for (int i = 0; i < 2; i++) {
                inputPage[i].get()->setVisible(false);
            }
            std::cout << "P: " << p << "\n";
        }
        switch (p) {
        case 6: // editor


            break;
        case 5: // viewer
            btnPage[8].get()->setVisible(true);

            break;
        case 4: {// list page to pick one to edit
            btnPage[7].get()->setVisible(true);
            window.setFramerateLimit(30);
            break; }
        case 3: { // local login page
            btnPage[0].get()->setVisible(true);
            btnPage[5].get()->setVisible(true);
            

            //std::ifstream psinput("password.txt");
            
            inputPage[0].get()->setVisible(true);
            break; }
        case 2: // cloud login page
            btnPage[0].get()->setVisible(true);
            btnPage[6].get()->setVisible(true);
            

            for (int i = 0; i < 2; i++) inputPage[i].get()->setVisible(true);
            break;
        case 1: // pick login page
            btnPage[0].get()->setVisible(true);
            window.setFramerateLimit(20);
            for (int i = 3; i < 5; i++)btnPage[i].get()->setVisible(true);
            break;
        default: // language page
            //Btn g;
            window.setFramerateLimit(10);
            btnPage[0].get()->setVisible(false);
            for (int i = 1; i < 3; i++)btnPage[i].get()->setVisible(true);
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
    // initialize buttons and input boxes
    btnPage[0].setColor(sf::Color::Blue, sf::Color::Green); // go-back button
    btnPage[0].setTextColor(sf::Color::White);
    btnPage[0].setTextSize(21);
    btnPage[0].get()->setSize({ "15%", "10%" });
    btnPage[0].get()->setPosition({ "0%","0%" });
    btnPage[0].get()->onClick(goMain);

    btnPage[1].setColor(sf::Color::Red, sf::Color::Green); // Svenska
    btnPage[1].setText("Svenska");
    btnPage[1].get()->setSize({ "50%", "16.67%" });
    btnPage[1].get()->setPosition({ "0%", "16.67%" });
    btnPage[1].get()->onClick(pickLang, 1);
    btnPage[1].setTextSize(21);

    btnPage[2].setColor(sf::Color::Red, sf::Color::Green); // Engelska
    btnPage[2].setText("English");
    btnPage[2].get()->setSize({ "50%", "16.67%" });
    btnPage[2].get()->setPosition({ "50%", "16.67%" });
    btnPage[2].get()->onClick(pickLang, 0);
    btnPage[2].setTextSize(21);

    btnPage[3].setColor(sf::Color::Red, sf::Color::Green); // local login
    btnPage[3].setTextSize(21);
    btnPage[3].get()->setSize({ "50%", "16.67%" });
    btnPage[3].get()->setPosition({ "25%","16.67%" });
    btnPage[3].get()->onPress(whatLogin, 0);

    btnPage[4].setColor(sf::Color::Red, sf::Color::Green); // cloud login
    btnPage[4].setTextSize(21);
    btnPage[4].get()->setSize({ "50%", "16.67%" });
    btnPage[4].get()->setPosition({ "25%","60%" });
    btnPage[4].get()->onPress(whatLogin, 1);

    btnPage[5].get()->setSize({ "50%", "16.67%" }); // Login action button
    btnPage[5].setTextSize(21);
    btnPage[5].get()->setPosition({ "25%", "70%" });
    btnPage[5].get()->onMouseEnter(checkLogin);
    btnPage[5].get()->onPress(handleLogin, 0);

    btnPage[6].get()->setSize({ "50%", "16.67%" }); // Second Login action button
    btnPage[6].setTextSize(21);
    btnPage[6].get()->setPosition({ "25%", "70%" });
    btnPage[6].get()->onPress(handleLogin, 1);

    btnPage[7].get()->setSize({ "15%", "10%" }); // Create New -button
    btnPage[7].get()->setPosition({ "85%", "0%" });
    btnPage[7].setColor(sf::Color::Blue, sf::Color::Green);
    btnPage[7].setTextColor(sf::Color::White);
    btnPage[7].setTextSize(21);

    btnPage[8].get()->setSize({ "15%", "10%" }); // Edit -button
    btnPage[8].get()->setPosition({ "70%", "0%" });
    btnPage[8].setColor(sf::Color::Blue, sf::Color::Green);
    btnPage[8].setTextColor(sf::Color::White);
    btnPage[8].setTextSize(21);

    inputPage[0].get()->setSize("50%", "10%"); // uname
    inputPage[0].setTextSize(18);
    inputPage[0].get()->setPosition({ "25%", "25%" });

    inputPage[1].get()->setSize("50%", "10%"); // password
    inputPage[1].setTextSize(18);
    inputPage[1].get()->setPosition({ "25%", "40%" });
    for(int i=0;i<9;i++)gui.add(btnPage[i].get());
    gui.add(inputPage[0].get());
    gui.add(inputPage[1].get());
    //char* jon = (char*)malloc(sizeof(char) * 16);
    //jon = "/tmp/jrecip.log";
    //char fn[16] = { '/','t','m','p','/','j','r','e','c','i','p','e','.','l','o','g' };
    //fs fi(fn);
    //fi.read(fn); // trasig, kommentera (//) i början av den här raden för att ta bort den tillfälligt.
    //std::cout << fi.read();
    //std::FILE* fil = std::fopen("/tmp/jrecip.log","r");

    RunGUI(gui);
    window.setFramerateLimit(10);
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
void pickLang(int L) {
    Lang = L; 
    btnPage[0].setText(languages[Lang][0]);
    btnPage[3].setText(languages[Lang][1]);
    btnPage[4].setText(languages[Lang][2]);
    btnPage[5].setText(languages[Lang][3]);
    btnPage[6].setText(languages[Lang][3]);
    btnPage[7].setText(languages[Lang][6]);
    inputPage[0].get()->setDefaultText(languages[Lang][4]);
    inputPage[1].get()->setDefaultText(languages[Lang][5]);
    RunGUI(gui, 1);
}
void goMain() { RunGUI(gui,0); }
void whatLogin(int p) { if (p == 0) { RunGUI(gui, 3); } else { RunGUI(gui, 2); } }
void saver(){}
void checkLogin() {
    uname = inputPage[0].get()->getText();
    std::string nam = uname.toStdString() + ".txt";
    const char* name = nam.c_str();
    fs logfil;
    bool psinput = logfil.exists(name);
    if (psinput) {
        btnPage[5].get()->getRenderer()->setBackgroundColorHover({ 0, 0, 255, 175 });
    }
    else {
        btnPage[5].get()->getRenderer()->setBackgroundColorHover({ 255, 0, 0, 175 });
    }
}
bool handleLogin(int which){
    uname = inputPage[0].get()->getText();
    std::cout << "Logging in as: " << uname << ";" << which << "\n";
    if (uname != "") {
        if (which == 0) { // local/file
            RunGUI(gui, 4);
            char fn[16] = { '/','t','m','p','/','j','r','e','c','i','p','e','.','l','o','g' };
            fs logfil(fn);

            return true;
        }
        else { // online/cloud
            tgui::String pass = inputPage[1].get()->getText();


        }
    }
    return false;
}