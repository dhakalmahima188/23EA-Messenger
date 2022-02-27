#include "QuickSort.h"

QuickSort::QuickSort():currentPointer(13,3),loopPointer(13,3)
{
	outlineBox1.setSize(sf::Vector2f(900, 700));
	outlineBox1.setPosition(sf::Vector2f(50, 50));
	outlineBox1.setOutlineColor(sf::Color::Black);
	outlineBox1.setOutlineThickness(10);
	outlineBox1.setFillColor(sf::Color::Transparent);
	outlineBox2.setSize(sf::Vector2f(900, 100));
	outlineBox2.setPosition(sf::Vector2f(50, 50));
	outlineBox2.setOutlineColor(sf::Color::Black);
	outlineBox2.setOutlineThickness(10);
	outlineBox2.setFillColor(sf::Color::Transparent);
	currentPointer.setFillColor(sf::Color::Blue);
	currentPointer.setPosition(sf::Vector2f(50, currentPointerHeight));
	loopPointer.setFillColor(sf::Color::Red);
	loopPointer.setPosition(sf::Vector2f(50, loopPointerHeight));
	text1.setFont(font);
	text2.setFont(font);
	if(!font.loadFromFile("DejaVuSans.ttf"))
    {

    }
    text1.setCharacterSize(20);
    text1.setPosition(sf::Vector2f(60,800));
    text1.setString("Red = Index");
    text1.setFillColor(sf::Color::Red);
    text2.setCharacterSize(20);
    text2.setPosition(sf::Vector2f(60,830));
    text2.setString("Blue = Current");
    text2.setFillColor(sf::Color::Blue);
    text2.setCharacterSize(20);



}

void QuickSort::setData(int height[],int size)
{
	std::cout << " \n Setting Data ... ";
	int width = 30;
	int totWidth = 30 + width;
	double space = 0.3 * totWidth;
	highest = greatest(height, size);
	recn.clear();
	for (int i = 0; i < size; i++)
	{
		sf::RectangleShape rec;
		float z = (350 / (float)highest) * height[i];
		rec.setFillColor(sf::Color::Yellow);
		rec.setOutlineColor(sf::Color::Black);
		rec.setOutlineThickness(-3);
		rec.setSize(sf::Vector2f(40, -((int)z)));
		rec.setPosition(sf::Vector2f(i * 80 + 100, 690));
		recn.push_back(rec);
		totWidth = totWidth + space + width;
		std::cout << comma << height[i];
		comma = ",";
	}
}

bool QuickSort::sort(int data[], int low, int high)
{
	std::cout << "\n Sorting Data ";
	quicksort(data, low, high);
	std::cout << " \n Finally the sorted heights are : ";
	printdata(data,high-low+1);
	resetBarFillColor();
	currentPointer.setPosition(sf::Vector2f(50, currentPointerHeight));
	loopPointer.setPosition(sf::Vector2f(50, loopPointerHeight));
	return true;

}
bool QuickSort::quicksort(int height[], int low, int high)
{

	if (low < high)
	{
		int notation = partition(height, low, high);
		quicksort(height, low, notation - 1);
		quicksort(height, notation, high);

	}
	return true;
}

int QuickSort::partition(int height[], int low, int high)
{
	std::cout << " \n Finding the pivot and arranging the heights: ";
	int current = low, pivot = height[high];
	resetBarFillColor();
	recn[high].setFillColor(sf::Color::Green);
	currentPointer.setPosition(recn[current].getPosition().x, currentPointerHeight);
	for (int index = low; index < high; index++)
	{
		while (isPaused);
		loopPointer.setPosition(recn[index].getPosition().x, loopPointerHeight);
		std::this_thread::sleep_for(std::chrono::milliseconds(delayTime));
		if (height[index] <= pivot)
		{
			int temp = height[current];
			height[current] = height[index];
			height[index] = temp;
			rescaleBars(height);
			//printdata(height,high-low+1);
			std::this_thread::sleep_for(std::chrono::milliseconds(delayTime));
			current++;
			currentPointer.setPosition(recn[current].getPosition().x, currentPointerHeight);
			std::this_thread::sleep_for(std::chrono::milliseconds(delayTime));

		}
	}
	int tem = height[current];
	height[current] = height[high];
	height[high] = tem;
	rescaleBars(height);
	std::this_thread::sleep_for(std::chrono::milliseconds(delayTime));
	return current;
}

int QuickSort::greatest(int height[],int size)
{
	int maxx = height[0];
	for (int i = 0; i < size; i++)
	{
		if (height[i] > maxx)
			maxx = height[i];
	}
	return maxx;

}

void QuickSort::draw(sf::RenderWindow& window)
{
	window.draw(outlineBox1);
	window.draw(outlineBox2);
	for (int i = 0; i < recn.size(); i++) {
		window.draw(recn[i]);
	}
	window.draw(currentPointer);
	window.draw(loopPointer);
	window.draw(text1);
	window.draw(text2);
}

void QuickSort::resetBarFillColor()
{
	for (int i = 0; i < recn.size(); i++) {
		recn[i].setFillColor(sf::Color::Yellow);
	}
}

void QuickSort::rescaleBars(int height[])
{
	for (int i = 0; i < recn.size(); i++) {
		float z = (350 / (float)highest) * height[i];
		recn[i].setSize(sf::Vector2f(40, -((int)z)));
	}
}
void QuickSort::printdata(int height[],int size)
{
    for(int i=0;i<size;i++)
    {
        std::cout<<height[i]<<comma;
        comma=",";
    }
    std::cout<<std::endl;
}
