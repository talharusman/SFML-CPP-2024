#include <SFML/Graphics.hpp>
using namespace sf;

void Draw(RenderWindow &window, CircleShape &hoop,CircleShape &ball) {
    window.clear(Color::White);
    window.draw(ball);
    window.draw(hoop);
    window.display();
}

void update(CircleShape &hoop,CircleShape &ball, RenderWindow &window, int &der, bool &isShoot) {
    // this condition will decide the positon of the ball 
    if(Mouse::isButtonPressed(Mouse::Left) )
    {
        isShoot = true;
    }
    if(!isShoot){
    ball.setPosition(Mouse::getPosition(window).x,Mouse::getPosition().y);
    }
    else
    {
        ball.move(0,-5.f);
    }
   
    // this conditons will deside the position of the hoop
    if (hoop.getPosition().x <= 0)
        der = 1;
    else if (hoop.getPosition().x + hoop.getRadius() * 2 >= window.getSize().x)
        der = 0;
    if (der == 0) {
        hoop.move(-5.f, 0.f);
    } else {
        hoop.move(5.f, 0.f);
    }
                                  
    //Collstion ball                   //it will chack the all couner of the boll it is interset with hoop or not
    if(ball.getPosition().y <= 0 || ball.getGlobalBounds().intersects(hoop.getGlobalBounds()))
    {
        //Retset the boll any time it will hapend 
        isShoot = false;
        ball.setPosition(ball.getPosition().x,window.getSize().y - ball.getRadius() * 3);
    }
}

int main() {
    RenderWindow window(sf::VideoMode(700, 500), "Simple game");
    window.setFramerateLimit(60);
    CircleShape hoop;
    int der = 0;
    hoop.setRadius(50.f);
    hoop.setFillColor(Color::Red);
    hoop.setOutlineThickness(5.f);
    hoop.setOutlineColor(Color::Black);
    hoop.setPosition(Vector2f(0.f, 30.f));

    CircleShape ball;
    bool isShoot = false;
    ball.setRadius(20.f);
    ball.setFillColor(Color::Blue);
    ball.setOutlineThickness(5.f);
    ball.setOutlineColor(Color::Black);
    ball.setPosition(Vector2f(0.f, window.getSize().y - ball.getRadius()*3));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if(event.type == Event::KeyPressed && event.key.code == Keyboard ::Escape )
                window.close();
        }
        update(hoop,ball, window, der,isShoot);
        Draw(window, hoop,ball);
    }

    return 0;
}
