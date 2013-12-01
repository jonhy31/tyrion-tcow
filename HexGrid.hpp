#ifndef HEXGRID_HPP_
#define HEXGRID_HPP_

#include "includes.hpp"

class HexGrid {
public:

	HexGrid();
	HexGrid(int height, int width, float radius, sf::Color color);
	HexGrid(HexGrid &grid);
	void draw(sf::RenderWindow &App);
	void handleMouse(sf::RenderWindow &App, sf::Event &evt);
	void setHeight(int height);
	int getHeight();
	void setWidth(int width);
	int getWidth();
	void setRadius(float radius);
	float getRadius();
	void setColor(sf::Color color);
	sf::Color getColor();

private:

	sf::CircleShape hexagon;
	sf::Color defColor;
	int defHeight;
	int defWidth;
	int hexNumber;
	int yRow;
	float defRadius;
	float xPos;
	float yPos;
	float myPos;
	float mxPos;
	float hXPos;
	float hYPos;
	float y1;
	float y2;
	float y3;
	float y4;
	float x1;
	float x2;
	float x3;
	float m1;
	float m2;
	float m3;
	float m4;
	float b1;
	float b2;
	float b3;
	float b4;
	bool isHovering;

};

#endif
