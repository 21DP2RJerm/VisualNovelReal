#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <string>
#include <windows.h>
#include <fstream>

int main() {
	bool izvele = FALSE, sakums = TRUE;
	int summa = 0;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Bin Chi Ling Window", sf::Style::Fullscreen);
	sf::RectangleShape fons(sf::Vector2f(1920.0f, 1080.0f));
	sf::RectangleShape mazais(sf::Vector2f(1920.0f, 1080.0f));
	
	sf::Vector2i pele = sf::Mouse::getPosition(window);


	int state = 1;
	fons.setPosition(0, 0);

	sf::Texture fonsTexture;
	fonsTexture.loadFromFile("hall.png");
	fons.setTexture(&fonsTexture);

	sf::Texture mazinais;
	mazinais.loadFromFile("mazins.png");
	mazais.setTexture(&mazinais);

	

	sf::Music music;
	music.openFromFile("fons.wav");
	music.setVolume(10);

	sf::Music bediga;
	bediga.openFromFile("bedigs.wav");
	bediga.setVolume(10);

	
	std::string tekstins;
	std::ifstream failins("SPELE.txt");

	
	sf::Font font;
	font.loadFromFile("minecraft.ttf");


	sf::Text teksts;
	teksts.setFont(font);
	teksts.setString("It was a regular monday evening. Math had just finished and I was on my way to the cafeteria");
	teksts.setCharacterSize(22);
	teksts.setFillColor(sf::Color::White);
	teksts.setPosition(100, 840);
	
	sf::Text A;
	A.setFont(font);
	A.setCharacterSize(20);
	A.setFillColor(sf::Color::White);
	A.setPosition(100, 950);

	sf::Text B;
	B.setFont(font);
	B.setCharacterSize(20);
	B.setFillColor(sf::Color::White);
	B.setPosition(1000, 950);

	window.clear();
	window.draw(fons);
	window.draw(teksts);
	window.draw(mazais);
	window.display();

	

	while (window.isOpen()) {
		if (music.getStatus() != sf::Music::Status::Playing) {
			music.play();

		}
		A.setString("");
		B.setString("");
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

				std::getline(failins, tekstins);

				if (tekstins == "1") {


					std::getline(failins, tekstins);
					teksts.setString(tekstins);
					std::getline(failins, tekstins);
					mazinais.loadFromFile(tekstins);
					mazais.setTexture(&mazinais);
					window.clear();
					window.draw(fons);
					window.draw(teksts);
					window.draw(mazais);
					window.draw(A);
					window.draw(B);
					window.display();

					Sleep(300);

				}
				else if (tekstins == "2") {

					std::getline(failins, tekstins);
					A.setString(tekstins);
					std::getline(failins, tekstins);
					B.setString(tekstins);


					window.clear();
					window.draw(fons);
					window.draw(teksts);
					window.draw(mazais);
					window.draw(A);
					window.draw(B);
					window.display();



					while(izvele == FALSE)
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
							if (sakums == TRUE) {
								music.pause();
								bediga.play();
								teksts.setString("You hit him on the head with your book. His head slams down on the floor. A loud bang echoes through the hallway. Everybody goes quit");
								window.clear();
								window.draw(fons);
								window.draw(teksts);
								window.display();
								Sleep(7000);
								teksts.setString("He doesn't get up. A pool of blood slowly starts expanding from where his head impacted the ground");
								window.clear();
								window.draw(fons);
								window.draw(teksts);
								window.display();
								Sleep(7000);
								teksts.setString("You try to get him to stand up, wake up atleast, but nothing happens.");
								window.clear();
								window.draw(fons);
								window.draw(teksts);
								window.display();
								Sleep(7000);
								teksts.setString("He's dead. And you just killed him");
								window.clear();
								window.draw(fons);
								window.draw(teksts);
								window.display();
								Sleep(5000);
								teksts.setString("Local police arrest you and charge for murder. You spend the rest of your life behind bars until dying from old age");
								window.clear();
								window.draw(fons);
								window.draw(teksts);
								window.display();
								Sleep(7000);
								teksts.setString("The End");
								window.clear();
								window.draw(fons);
								window.draw(teksts);
								window.display();
								Sleep(5000);
								window.close();
								break;
							}
							else {
								std::getline(failins, tekstins);
								teksts.setString(tekstins);
								std::getline(failins, tekstins);
								mazinais.loadFromFile(tekstins);
								mazais.setTexture(&mazinais);
								std::getline(failins, tekstins);
								std::getline(failins, tekstins);
								std::getline(failins, tekstins);
								if (tekstins == "-") {
									summa = summa - 1;
								}
								else if(tekstins == "+") {
									summa = summa + 1;
								}
								std::cout << summa;
								std::getline(failins, tekstins);
							}
								
							
							
							izvele = TRUE;
						}	
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
							std::getline(failins, tekstins);
							std::getline(failins, tekstins);
							std::getline(failins, tekstins);
							teksts.setString(tekstins);
							std::getline(failins, tekstins);
							mazinais.loadFromFile(tekstins);
							mazais.setTexture(&mazinais);
							std::getline(failins, tekstins);
							std::getline(failins, tekstins);
							if (tekstins == "-") {
								summa = summa - 1;
							}
							else if(tekstins == "+") {
								summa = summa + 1;
							}
							std::cout << summa;
							izvele = TRUE;
							sakums = FALSE;
						}
						
					window.clear();
					window.draw(fons);
					window.draw(teksts);
					window.display();
					izvele = FALSE;
				}
				else if(tekstins == "3"){
					fonsTexture.loadFromFile("cafe.png");
				}
				else if (tekstins == "4") {
					if (summa >= 3) {
						std::getline(failins, tekstins);
						std::getline(failins, tekstins);
						teksts.setString(tekstins);
					}
					else {
						std::getline(failins, tekstins);
						teksts.setString(tekstins);
					}
				}
			}
			
			switch (evnt.type) {

				//aizver programmu kad uzpiez x
			case sf::Event::Closed:
				window.close();
				break;

			
			}

		}
		
		
			
		window.clear();
		window.draw(fons);
		window.draw(teksts);
		window.draw(mazais);
		window.draw(A);
		window.draw(B);
		window.display();
		
		
		
		

	}
	return 0;
}