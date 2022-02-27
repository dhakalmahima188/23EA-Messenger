#pragma once
#include<thread>
#include "QuickSort.h"
#include "Button.h"
#include "TextBox.h"
#include <string>


class Visualizer
{
private:
	Textbox textbox1;
	sf::RenderWindow window;
	bool isSorting;
	Button setDataButton, sortButton,pauseButton;
	std::vector<int> datas = { 20,200 };
	void splitInt(std::string str);
	sf::Font font;
	QuickSort Q;
	void printData(std::vector<int>);
public:
	Visualizer();
	void run();
	void handleUserInput();
	void update();
	void render();
	void sort();
};
