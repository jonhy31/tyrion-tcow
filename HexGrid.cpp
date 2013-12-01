#include "HexGrid.hpp"

HexGrid::HexGrid() : defHeight(0),
defWidth(0),
defRadius(0),
defColor(0,0,0,0),
hexNumber(0),
yRow(1),
isHovering(false)
{}

HexGrid::HexGrid(int height, int width, float radius, sf::Color color){

	defHeight = height;
	defWidth = width;
	defRadius = radius;
	defColor = color;
	hexNumber = width * height;
	yRow = 1;
	isHovering = false;
}

HexGrid::HexGrid(HexGrid &grid){
	defHeight = grid.getHeight();
	defWidth = grid.getWidth();
	defRadius = grid.getRadius();
	defColor = grid.getColor();
	hexNumber = defWidth * defHeight;
	yRow = 1;
	isHovering = false;
}

void HexGrid::draw(sf::RenderWindow &App){

	hexagon.setRadius(defRadius);
	hexagon.setPointCount(6);
	hexagon.setFillColor(defColor);
	hexagon.setOutlineThickness(1);
	hexagon.setOutlineColor(sf::Color::Black);

	xPos = hexagon.getRadius();
	yPos = hexagon.getRadius();

	for(int i = 1; i <= hexNumber; ++i){
				
		hexagon.setPosition(xPos, yPos);

		mxPos = App.mapPixelToCoords(sf::Mouse::getPosition(App)).x;
		myPos = App.mapPixelToCoords(sf::Mouse::getPosition(App)).y;

		y1 = hexagon.getPosition().y + hexagon.getPoint(3).y;
		y2 = hexagon.getPosition().y + hexagon.getPoint(4).y;
		y3 = hexagon.getPosition().y + hexagon.getPoint(5).y;
		y4 = hexagon.getPosition().y + hexagon.getPoint(0).y;
		x1 = hexagon.getPosition().x + hexagon.getPoint(4).x;
		x2 = hexagon.getPosition().x + hexagon.getPoint(0).x;
		x3 = hexagon.getPosition().x + hexagon.getPoint(2).x;
		m1 = (y4 - y3) / (x2 - x1);
		m2 = (y4 - y3) / (x2 - x3);
		m3 = (y1 - y2) / (x2 - x1);
		m4 = (y1 - y2) / (x2 - x3);
		b1 = y4 - m1 * x2;
		b2 = y4 - m2 * x2;
		b3 = y1 - m3 * x2;
		b4 = y1 - m4 * x2;

		if(!(myPos < y4 && myPos > y1) && !(mxPos < x1 && mxPos > x3)){

			if(mxPos > x1 && mxPos < x3 && myPos > y2 && myPos < y3)
				isHovering = true;

			else if(mxPos > x1 && mxPos < x2 && myPos > (mxPos * m1 + b1) && myPos < (mxPos * m3 + b3))
				isHovering = true;

			else if(mxPos > x2 && mxPos < x3 && myPos > (mxPos * m2 + b2) && myPos < (mxPos * m4 + b4))
				isHovering = true;
			
			else
				isHovering = false;

		}

		if( i % defWidth == 0 && i != 0 ){
			if (yRow % 2 == 0){
				xPos = hexagon.getRadius();
				yPos += hexagon.getRadius() * 1.55;
			}
			else{
				xPos = sqrt(3) * hexagon.getRadius() + ((hexagon.getRadius() / 10) + 1.3 );
				yPos += hexagon.getRadius() * 1.55;
			}

			++yRow;
		}

		else
			xPos += sqrt(3) * hexagon.getRadius() + 0.5;

		if(isHovering == true){
			hexagon.setFillColor(sf::Color(0,255,0));
			App.draw(hexagon);
			hXPos = hexagon.getPosition().x;
			hYPos = hexagon.getPosition().y;
		}
		else{
			hexagon.setFillColor(defColor);
			App.draw(hexagon);
		}

	}

}

void HexGrid::handleMouse(sf::RenderWindow &App, sf::Event &evt){
	while(App.pollEvent(evt)){
		switch(evt.type){
		case sf::Event::Closed:
			App.close();
			break;

		case sf::Event::MouseButtonPressed:
			switch(evt.mouseButton.button){
			case sf::Mouse::Left:
				std::cout << "Left Pressed\n";
				break;
			}
			break;
		}
	}
}

void HexGrid::setHeight(int height){
	defHeight = height;
	hexNumber = defHeight * defWidth;
}

int HexGrid::getHeight(){
	return defHeight;
}

void HexGrid::setWidth(int width){
	defWidth = width;
	hexNumber = defHeight * defWidth;
}

int HexGrid::getWidth(){
	return defWidth;
}

void HexGrid::setRadius(float radius){
	defRadius = radius;
}

float HexGrid::getRadius(){
	return defRadius;
}

void HexGrid::setColor(sf::Color color){
	defColor = color;
}

sf::Color HexGrid::getColor(){
	return defColor;
}