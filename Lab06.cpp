//included libraries
#include <iostream>
#include <SFML/Graphics.hpp>

//namespaces
using namespace sf;
using namespace std;

//main
int main() {
	//image delcarations
	string background = "images1/backgrounds/winter.png"; //background picture
	string foreground = "images1/characters/yoda.png"; //character on top of picture
	Texture backgroundTex;
	Texture foregroundTex;


	//image loading check 1
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}

	//image loading check 2
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}

	//Image Texture rendering
	Image backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage = foregroundTex.copyToImage();

	//Size of front image
	Vector2u size = foregroundImage.getSize();

	//Pixel detection loop
	for (int y = 0; y < size.y; y++) {
		for (int x = 0; x < size.x; x++) {
			// These two loops will run the code inside for each pixel in
				// You can access the current pixel at x,y like so:

				Color currentPixel = foregroundImage.getPixel(x, y);//Acquires color of current pixel
				//If the green component of the pixel is the specific shade of green that is the background, 
				if (currentPixel.g == 214) {
					foregroundImage.setPixel(x, y, Color(255, 0, 0, 0)); //Makes the current pixel transparent to reveal the background image's pixel at the same coordinate
					//I used a color picker website to determine the specific g value of the greenscreen
				}

		}
	}

	// Rendering of the window
	RenderWindow window(VideoMode(1024, 768), "Green Removal");

	//sprites and textures
	Sprite sprite1;
	Sprite sprite2;
	Texture texture1;
	Texture texture2;
	texture2.loadFromImage(backgroundImage);
	texture1.loadFromImage(foregroundImage);
	sprite2.setTexture(texture2);
	sprite1.setTexture(texture1);

	//window loading
	window.clear();
	window.draw(sprite2);
	window.draw(sprite1);
	window.display();
	while (true);
}