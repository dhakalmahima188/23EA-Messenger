#include "Visualizer.h"


void Visualizer::splitInt(std::string str)
{
        std::string num = "";
        datas.clear();
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] == ' ' && i == str.length())
                break;
            else if (str[i] == ' ') {
                int t = stoi(num);
                datas.push_back(t);
                num = "";
            }
            else
                num = num + str[i];
        }
        if (str[str.length() - 1] != ' ') {
            int y = stoi(num);
            datas.push_back(y);
        }

}

void Visualizer::printData(std::vector<int> datas)
{
    std::cout<<" The data we enterd is : ";
    for (const auto data : datas) {
        std::cout << data<<",";
    }
    std::cout << std::endl;
}

Visualizer::Visualizer() :window(sf::VideoMode(1000, 900), "Visualizer"),

setDataButton("Set", sf::Vector2f(120, 50), 20, sf::Color::Green, sf::Color::Black),
sortButton("Sort", sf::Vector2f(120, 50), 20, sf::Color::Green, sf::Color::Black),
pauseButton("Pause/Play", sf::Vector2f(200, 50), 20, sf::Color::Green, sf::Color::Black), textbox1(20, sf::Color::Red, false)
{
    isSorting = true;
    std::thread sortThread(&Visualizer::sort, this);
    sortThread.detach(); // it destroys sorting thread
    if (!font.loadFromFile("DejaVuSans.ttf"))
    {
    }
    setDataButton.setPosition(sf::Vector2f(55, 55));
    setDataButton.setFont(font);
    sortButton.setPosition(sf::Vector2f(825, 55));
    sortButton.setFont(font);
    pauseButton.setPosition(sf::Vector2f(450, 775));
    pauseButton.setFont(font);
    textbox1.setFont(font);
    textbox1.setPosition(sf::Vector2f(200, 80));
    textbox1.setLimit(true, 50);


}



void Visualizer::run()
{
    std::cout << "Running \n";
    while (window.isOpen()) {
        handleUserInput();
        render();
    }
}

void Visualizer::handleUserInput()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::TextEntered){
             textbox1.typedOn(event);
            break;
        }
        else if (event.type == sf::Event::EventType::MouseMoved)
        {
            if (setDataButton.isMouseOver(window))
            {
                setDataButton.setBackColor(sf::Color::Red);

            }
            else
            {
                setDataButton.setBackColor(sf::Color::Green);
            }
            if (pauseButton.isMouseOver(window))
            {
                pauseButton.setBackColor(sf::Color::Red);

            }
            else
            {
                pauseButton.setBackColor(sf::Color::Green);
            }

            if (sortButton.isMouseOver(window))
            {
                sortButton.setBackColor(sf::Color::Red);
            }
            else
            {
                sortButton.setBackColor(sf::Color::Green);
            }
        }
        else if (event.type == sf::Event::EventType::MouseButtonPressed)
        {
            if (setDataButton.isMouseOver(window))
            {
                if (textbox1.getInput() != "") {
                    splitInt(textbox1.getInput());
                }
                printData(datas);
                Q.setData(&datas[0],datas.size());
            }
            else if (sortButton.isMouseOver(window))
            {
                isSorting = false;
            }
            else if (pauseButton.isMouseOver(window)) {
                Q.isPaused = !Q.isPaused;
            }
            else if (textbox1.isMouseOver(window))
            {
               textbox1.setSelected(true);
            }
            else {
                textbox1.setSelected(false);
            }
        }
    }
}
void Visualizer::render()
{
    window.clear(sf::Color::White);
    setDataButton.drawTo(window);
    sortButton.drawTo(window);
    Q.draw(window);
    textbox1.drawTo(window);
    pauseButton.drawTo(window);
    window.display();
}
void Visualizer::sort()
{
    while (window.isOpen())
    {
        if (!isSorting) {
            this->isSorting = Q.sort(&datas[0], 0, datas.size()-1);
            std::cout << isSorting << std::endl;
        }
    }
}

