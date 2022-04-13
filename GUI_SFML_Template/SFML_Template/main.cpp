#include<iostream>
#include <TGUI/TGUI.hpp>
#include "Btn.h"
#include "Input.h"
#include "fs.h"

//    __________________________________________
//   /                      _ ___         __    \
//  /     | /\ |\ | |_| /\ /_  |  | |\ | | _     \
// /     _| \/ | \| | | \/ _/  |  | | \| \__|     \
// -------------------------------------------------
// Login system - Anton
// Class and function mixing - Jonathan, Anton
// Class dependency - Jonathan 
// Receptsidan - Melker

sf::RenderWindow window{ {800, 600}, "JonHosting.com" };
//A Gui Object that works with Sfml window. 
tgui::GuiSFML gui{ window };
tgui::String languages[2][12] = { {"Back","Local","Cloud","Login","Username","Password","Create New","Edit"},{"Tillbaks","Lokal","Online","Logga in","Namn","Nyckel","Skapa Ny","Redigera"}};
tgui::String uname; // username identifier
std::string AppDir = "%appdata%/RecipeStacker/users/"; // more professional to save in appdata instead of local saving

Btn btnPage[9];// list of buttons to be used
Input inputPage[2]; // list of input areas to be allowed to be used
tgui::ScrollablePanel::Ptr ScrollList = tgui::ScrollablePanel::create(); // scrollable list for the list of 

int currentPage = -1; // Set to main page
int Lang = 0; // Set to default language
void pickLang(int L); void goMain(); void whatLogin(int p); void saver(); bool handleLogin(int which); void checkLogin(); // Define functions so there are no problems with references
bool RunGUI(int p = 0)
{
    try
    {
        if (currentPage != p) {
            for (int i = 1; i < 9; i++) {
                //gui.remove(btnPage[i].get());
                //btnPage[i].destroy();
                // Alternative method above ^
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
        case 5: // viewer / preview
            btnPage[8].get()->setVisible(true);


            break;
        case 4: {// list page to pick one to edit
            btnPage[7].get()->setVisible(true);



            window.setFramerateLimit(30); // högre bilduppdatering för en bättre upplevelse när man skriver
            break; }
        case 3: { // local login page
            btnPage[0].get()->setVisible(true);
            btnPage[5].get()->setVisible(true);
            
            
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
            window.setFramerateLimit(10); // låg bilduppdatering för att spara på GPUn när det ändå inte kommer märkas
            btnPage[0].get()->setVisible(false);
            for (int i = 1; i < 3; i++)btnPage[i].get()->setVisible(true);
            break;
        }
        currentPage = p;
        return true;
    }
    catch (const tgui::Exception& e)
    {
        std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
        return false;
    }
}


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

    btnPage[2].setColor(sf::Color::Red, sf::Color::Green); // Engelska / English
    btnPage[2].setText("English");
    btnPage[2].get()->setSize({ "50%", "16.67%" });
    btnPage[2].get()->setPosition({ "50%", "16.67%" });
    btnPage[2].get()->onClick(pickLang, 0);
    btnPage[2].setTextSize(21);

    btnPage[3].setColor(sf::Color::Red, sf::Color::Green); // local login button
    btnPage[3].setTextSize(21);
    btnPage[3].get()->setSize({ "50%", "16.67%" });
    btnPage[3].get()->setPosition({ "25%","16.67%" });
    btnPage[3].get()->onPress(whatLogin, 0);

    btnPage[4].setColor(sf::Color::Red, sf::Color::Green); // cloud login button
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
    btnPage[7].get()->onPress(RunGUI, 6);

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

    // add objects to the GUI
    for(int i=0;i<9;i++)gui.add(btnPage[i].get());
    gui.add(inputPage[0].get());//    _____________________________
    gui.add(inputPage[1].get());//   /                             \
    //                              /       | /\  |\ |    . . .     \
    // create directories for data /       _| \/  | \|     ,         \
    //                             -----------------------------------
    fs fi;
    bool ex = fi.exists("%appdata%/RecipeStacker");
    if(!ex) {
        fi.mkdir("%appdata%/RecipeStacker");
        fi.mkdir("%appdata%/RecipeStacker/users");
    }
    
    RunGUI();
    window.setFramerateLimit(10); // low framerate for less GPU usage
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
void pickLang(int L) { // Efter man väljer språk så ska knapparna och de andra objekten med text uppdateras till det språket.
    Lang = L; 
    btnPage[0].setText(languages[Lang][0]);
    btnPage[3].setText(languages[Lang][1]);
    btnPage[4].setText(languages[Lang][2]);
    btnPage[5].setText(languages[Lang][3]);
    btnPage[6].setText(languages[Lang][3]);
    btnPage[7].setText(languages[Lang][6]);
    inputPage[0].get()->setDefaultText(languages[Lang][4]);
    inputPage[1].get()->setDefaultText(languages[Lang][5]);
    RunGUI(1); // Gå vidare
}
void goMain() { RunGUI(0); } //Man går till första sidan
void whatLogin(int p) { // Lokalt eller Online?
    if (p == 0) { // Lokalt
        RunGUI(3);
    }
    else { // Annars är det Online / Cloud
        RunGUI(2);
    }
}
void saver(){ //Funktionen för att spara eller nåt sånt

} 
void checkLogin() { // Kolla om användaren finns och sätt färg på knappen baserat på det.
    uname = inputPage[0].get()->getText();
    std::string nam = uname.toStdString();
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
bool handleLogin(int which){ // sparar namnet i en global variabel, kollar vilken typ av inlogg det är, verifierar och skickar sedan sidare
    uname = inputPage[0].get()->getText();
    std::cout << "Logging in as: " << uname << ";" << which << "\n";
    if (uname != "") {
        if (which == 0) { // local/file action
            RunGUI(4);
            fs loginUser;
            std::string path = AppDir + uname.toStdString(); 
            bool ex = loginUser.exists(path.c_str());
            if (!ex) {
                loginUser.mkdir(path.c_str());
            }

            return true;
        }
        else { // online/cloud action
            tgui::String pass = inputPage[1].get()->getText(); // variable for the password


        }
    }
    return false;
}