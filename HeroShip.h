#include"SFML\Graphics.hpp"
#include"Bullets.h"

const int VEL=10;//Velocity with which ship will move i.e. 10 pixels
class HeroShip
{
public:
  sf::IntRect box; // a box to store the dimensions i.e.x,y,width and height of ship
  sf::RectangleShape rect; //rectangle shape that is displayed
  int xVel,yVel; // variables to store horizontal and vertical velocity
	
  Bullets *myBullets[20]; // array of bullet ptr objects; 20 Bullets to fire 
  int num_of_bullets;  // to keep track of how many bullets have been fired

  HeroShip(); // constructor
  void handleEvents();  // to get input from user
  void update();  // to update values
  void display(sf::RenderWindow *window);  //to display values
  void shoot();  //if user wants to shoot a bullet

};

HeroShip::HeroShip()
{
  box.left=200; // ship’s initial position is (200,500) on screen
  box.top=500;
  box.height=20; // height and weight of ship is 20x20
  box.width=20;
	
  rect.setSize(sf::Vector2f(box.width,box.height)); //dimension of rect to display
  rect.setFillColor(sf::Color::Red);  // color of the ship
	
  xVel=0; // initially x and y velocity are 0
  yVel=0;

  num_of_bullets=0; // initially bullets fired is 0
}
void HeroShip::handleEvents()
{
  //top or down
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    yVel=-VEL;
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    yVel=VEL;
  else
    yVel=0;
  //left or right
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    xVel=-VEL;
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    xVel=VEL;
  else
    xVel=0;
  // if Z key is pressed shoot func is called which fires a bullet
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    shoot();
	
}

void HeroShip::update()
{
  //update values
  box.left+=xVel;
  box.top+=yVel;
  //update the position of fired bullets
  for(int i=0;i<num_of_bullets;i++)
    myBullets[i]->update();
}

void HeroShip::display(sf::RenderWindow *window)
{
  //display the fired bullets
  for(int i=0;i<num_of_bullets;i++)
	  myBullets[i]->display(window);
	
  //set the x,y values of the rectangle i.e. ship to be displayed
  rect.setPosition(box.left,box.top);
  window->draw(rect); // draw on the window
}

void HeroShip::shoot()
{
  if(num_of_bullets<20)
  {
    // creates a new bullet
    myBullets[num_of_bullets]=new Bullets(box.left+box.width/2,box.top-10);
    num_of_bullets++; // increment the bullet counter
  }
}

