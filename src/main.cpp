#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "message.cpp"
#include "login.cpp"
using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ios;
using std::string;
extern char currentLoggedInUsername[20];
extern bool isLoggedIn, isUser;
extern User LoggedInUser;
extern char current_user_username[20];
extern void call_home();
extern void adduser();

int main()
{

menu:
    std::system("CLS");

    // system( "color 61" );
    std::cout << "\t\t" << char(201);
    for (int i = 0; i < 20; i++)
    {
        std::cout << char(205);
    }
    std::cout << char(187) << std::endl;
    std::cout << "\t\t" << char(186) << "  23-EA MESSENGER   " << char(186) << std::endl;
    std::cout << "\t\t" << char(200);
    for (int i = 0; i < 20; i++)
    {
        std::cout << char(205);
    }
    std::cout << char(188) << std::endl;
    std::cout << "\t\t" << char(218);
    for (int i = 0; i < 20; i++)
    {
        std::cout << char(196);
    }
    std::cout << char(191) << std::endl;
    std::cout << "\t\t" << char(179) << "   1.Register       " << char(179) << std::endl;

    std::cout << "\t\t" << char(195);
    for (int i = 0; i < 20; i++)
    {
        std::cout << char(196);
    }
    std::cout << char(180) << std::endl;
    std::cout << "\t\t" << char(179) << "   2.login          " << char(179) << std::endl;
    std::cout << "\t\t" << char(195);
    for (int i = 0; i < 20; i++)
    {
        std::cout << char(196);
    }
    std::cout << char(180) << std::endl;
    std::cout << "\t\t" << char(179) << "   3.Exit           " << char(179) << std::endl;

    std::cout << "\t\t" << char(192);
    for (int i = 0; i < 20; i++)
    {
        std::cout << char(196);
    }
    std::cout << char(217) << std::endl;
    std::cout << "Press the required option 1, 2, 3...." << std::endl;
    int i;
    std::cin >> i;
    switch (i)
    {
    case 1:
    {
        std::system("CLS");
        Register();
        goto menu;
        break;
    }
    case 2:
    {
        std::system("CLS");
        char usr[20];
        char pwd[20];
        std::cout << "\t\t" << char(218);
        for (int i = 0; i < 25; i++)
        {
            std::cout << char(196);
        }
        std::cout << char(191) << std::endl;
        std::cout << "\t\t" << char(179) << "  Enter your username :  " << char(179) << std::endl;
        std::cout << "\t\t" << char(192);
        for (int i = 0; i < 25; i++)
        {
            std::cout << char(196);
        }
        std::cout << char(217) << std::endl;
        std::cin >> usr;
        std::cout << "\t\t" << char(218);
        for (int i = 0; i < 25; i++)
        {
            std::cout << char(196);
        }
        std::cout << char(191) << std::endl;
        std::cout << "\t\t" << char(179) << "  Enter your password :  " << char(179) << std::endl;
        std::cout << "\t\t" << char(192);
        for (int i = 0; i < 25; i++)
        {
            std::cout << char(196);
        }
        std::cout << char(217) << std::endl;
        std::cin >> pwd;
        login(usr, pwd);
        if (isLoggedIn)
        {
            std::cout << "Successfully Logged In!!!!!!!!!" << std::endl;
        }
        goto home;
        break;
    }
    case 3:
        exit(0);
    }
home:
{
    {
        std::system("CLS");
        std::system("CLS");
        std::cout << "\t\t" << char(218);
        for (int i = 0; i < 20; i++)
        {
            std::cout << char(196);
        }
        std::cout << char(191) << std::endl;
     
        std::cout << "\t\t" << char(179) << "   1.Message        " << char(179) << std::endl;

        std::cout << "\t\t" << char(195);
        for (int i = 0; i < 20; i++)
        {
            std::cout << char(196);
        }
        std::cout << char(180) << std::endl;
        std::cout << "\t\t" << char(179) << "   2.Log Out        " << char(179) << std::endl;

        std::cout << "\t\t" << char(192);
        for (int i = 0; i < 20; i++)
        {
            std::cout << char(196);
        }
        std::cout << char(217) << std::endl;

        std::cout << "Select the required optiton";
        std::cin >> i;
    }
    switch (i)
    {
      
    case 1:
    message:
    {
        std::system("CLS");
        std::cout << "\t\t" << char(218);
        for (int i = 0; i < 20; i++)
        {
            std::cout << char(196);
        }
        std::cout << char(191) << std::endl;
        std::cout << "\t\t" << char(179) << "   1.Send Message   " << char(179) << std::endl;
        std::cout << "\t\t" << char(195);
        for (int i = 0; i < 20; i++)
        {
            std::cout << char(196);
        }
        std::cout << char(180) << std::endl;
        std::cout << "\t\t" << char(179) << "   2.View Inbox     " << char(179) << std::endl;
        std::cout << "\t\t" << char(195);
        for (int i = 0; i < 20; i++)
        {
            std::cout << char(196);
        }
        std::cout << char(180) << std::endl;
        std::cout << "\t\t" << char(179) << "   3.Exit           " << char(179) << std::endl;
        std::cout << "\t\t" << char(192);
        for (int i = 0; i < 20; i++)
        {
            std::cout << char(196);
        }
        std::cout << char(217) << std::endl;
        int z;
        cin >> z;
        {
            switch (z)
            {
            case 1:
            {
                std::system("CLS");
                std::cout << "Enter the username of receiver" << std::endl;
                char receiver[20];
                std::cin >> receiver;
                
                    char msgbody[250];
                  
                    std::cout << "Enter the msg body" << std::endl;
                    std::cin.ignore();
                   
                    // getline(cin, msgbody);
                    std::cin.getline(msgbody, 150);
                     compress((string)msgbody, receiver);
                //   strcpy(msgbody,ans);
                    message msg(receiver, msgbody);
                    msg.sendMessage();
                
                goto message;
                break;
            }
            case 2:
            {
                std::system("CLS");
                char sender[20];
                if (viewsenders())
                {
                    cin >> sender;
                    message m(sender);
                    std::system("CLS");
                    viewmessage(m);
                    cout << "Press c key to continue" << endl;
                    char n;
                    cin >> n;
                    goto message;
                }
                else
                {
                    cout << "Press c key to continue" << endl;
                    char n;
                    cin >> n;
                    goto message;
                }

                break;
            }
            case 3:
                goto home;
            }
        }
        break;
    case 2:
        goto menu;
    }
    }
}
    return 0;
};
