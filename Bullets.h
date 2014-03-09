#include"SFML\Graphics.hpp"

const int VELO=20; //velocity of bullet
class Bullets
{
public:
  sf::IntRect box; // to represent bullet’s dimension
  sf::RectangleShape rect; // to draw bullet as a rectangle
  int yVel; // bullet’s y velocity

  Bullets(int x,int y); // constructor to specify position of bullet w.r.t ship
	
  void update();  // update fired bullets
  void display(sf::RenderWindow *window); // draw the fired bullets

};

Bullets::Bullets(int x, int y)
{
  box.left=x;
  box.top=y;
  box.height=10; // height of bullet
  box.width=2; // width of bullet
	
  rect.setSize(sf::Vector2f(box.width,box.height)); //set the dim of drawable rect
  rect.setFillColor(sf::Color::Blue); // set blue color for the bullet rect
	
  yVel=-VELO; // bullets move upwards. So negative y velocity
}

void Bullets::update()
{
  box.top+=yVel; // bullet’s y values are updated; x values remain same
}

void Bullets::display(sf::RenderWindow *window)
{
  rect.setPosition(box.left,box.top); // set the position of rect to draw as bullet
  window->draw(rect); // display bullet
}

