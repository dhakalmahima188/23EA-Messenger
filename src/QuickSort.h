#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
class QuickSort
{
public:
    QuickSort();
    void setData(int data[], int);
    int partition(int[], int, int);
    bool quicksort(int[], int, int);
    int greatest(int arr[],int);
    bool sort(int data[], int, int);
    void draw(sf::RenderWindow&);
    void printdata(int data[],int size);
    bool isPaused = false;
private:
    std::vector<sf::RectangleShape> recn;
    sf::CircleShape currentPointer,loopPointer;
    int currentPointerHeight = 700;
    int loopPointerHeight = 720;
    int delayTime = 800;
    int highest;
    float scalingFactor;
    sf::Font font;
    sf::RectangleShape outlineBox1;
    sf::RectangleShape outlineBox2;
    std::string comma = "";
    void resetBarFillColor();
    void rescaleBars(int []);
    sf::Text text1;
    sf::Text text2;
};

