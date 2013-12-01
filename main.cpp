#include "HexGrid.hpp"

int main(){

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow app(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel),"Tyrion: TCoW");

	sf::View player1;
	sf::View deck;
	sf::View hexgrid;
	sf::View player2;

	player1.setViewport(sf::FloatRect(0.f, 0.f, 0.25f, 1.f));
	deck.setViewport(sf::FloatRect(0.25f,0.75f, 0.5f, 0.25f));
	hexgrid.setViewport(sf::FloatRect(0.25f,0.f,0.5f,0.75f));
	player2.setViewport(sf::FloatRect(0.75f,0.f,0.25f,1.f));

	HexGrid hex(8,8,60.f,sf::Color(250,0,0));

	while(app.isOpen()){
		sf::Event evt;
		while(app.pollEvent(evt)){
			if(evt.type == sf::Event::Closed)
				app.close();
		}
		app.clear(sf::Color::Black);

		app.setView(hexgrid);

		hex.draw(app);
		hex.handleMouse(app,evt);

		app.getDefaultView();

		app.display();
	}
	return 0;
}
