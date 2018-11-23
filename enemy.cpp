#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;

int main()
{
    enum directions {u,ur,r,dr,ul,l,dl,d};
    bool shoot=false;
    int shootx,shooty;
    int enemyxcounter=0;
    sf::Vector2i source(0,u);
    sf::RenderWindow window(sf::VideoMode(1280,768),"first window",sf::Style::Default);
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(60);
    
    sf::Texture texture;
    sf::Texture background;
    background.loadFromFile("space.png");
    texture.loadFromFile("shipsprite.png");
    sf::Sprite sprite;
    sf::Sprite backsp;
    sf::Sprite enemy;
    backsp.setTexture(background);
    sprite.setTexture(texture);
    enemy.setTexture(texture);
    sf::CircleShape circle(5);
    circle.setOrigin(5,5);
    
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
         {
            switch(event.type)
            {
                case sf::Event::Closed:
                      window.close();
                      break;      
            }
         }
         
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                      {
                          source.y=u;
                          shootx=0;
                          shooty=-10;
                          sprite.move(0.0f,-5.0f);
                      }
                      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                      {
                          source.y=d;
                          shootx=0;
                          shooty=10;
                          sprite.move(0.0f,5.0f);
                      }
                      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                      {
                          source.y=l;
                          shootx=-10;
                          shooty=0;
                          sprite.move(-5.0f,0.0f);
                      }
                      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                      {
                          source.y=r;
                          shootx=10;
                          shooty=0;
                          sprite.move(5.0f,0.0f);
                      }
                      
                      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                      {
                          circle.setPosition(sf::Vector2f(sprite.getPosition().x+32,sprite.getPosition().y+32));
						  shoot=true;
					  }
         source.x++;
         if(source.x*64>=texture.getSize().x)
             source.x=0;
             
         enemyxcounter++;     
         if(enemyxcounter*64>=texture.getSize().x)
              enemyxcounter=0;
               
          enemy.move(-2.0f,0.0f);  
             
         sprite.setTextureRect(sf::IntRect(source.x*64,source.y*64,64,64));
         enemy.setTextureRect(sf::IntRect(enemyxcounter*64,5*64,64,64));
			
         if(enemy.getPosition().x<=0)
			enemy.setPosition(window.getSize().x-128,window.getSize().y-704);
			
         window.draw(backsp);
         window.draw(sprite);
         window.draw(enemy);
         if(shoot==true && circle.getPosition().x>0 && circle.getPosition().x<window.getSize().x && circle.getPosition().y>0 && circle.getPosition().y<window.getSize().y)
         {
             circle.move(shootx,shooty);
             window.draw(circle);
         }
         window.display();
         window.clear();
    }
    return 0;
}

