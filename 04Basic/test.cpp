#include <SFML/Graphics.hpp>
using namespace sf;

void update(int &keytime, RectangleShape &square,RenderWindow &window);//a funtion which will update the possition of the square
void draw(RenderWindow &window, RectangleShape &square);// despaly the everthing

int main()
{
    int keytime = 8;
    RenderWindow window(VideoMode(600, 400), "SFML works!");
    window.setFramerateLimit(100);//speed of the objct

    RectangleShape square(Vector2f(100.f, 100.f));

    square.setFillColor(Color::Red);
    square.setPosition(Vector2f(window.getSize().x / 2, window.getSize().y / 2));
    square.setOutlineThickness(5.f);
    square.setOutlineColor(Color::Blue);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
        }

        window.clear(Color::White);// set the background color

        // Update the square
        update(keytime, square,window);

        // Draw the square
        draw(window, square);
    }

    return 0;
}

void update(int &keytime, RectangleShape &square,RenderWindow &window)
{
    // if (keytime < 8)//chake the key time
    //     keytime++;
    if (Keyboard::isKeyPressed(Keyboard::A) && square.getPosition().x > 0 )//getposition().x it will don't alow the object to move out side the perticular area
    {
        square.move(-5.f, 0.f);
        keytime = 0;
    }
    
    if (Keyboard::isKeyPressed(Keyboard::D) && square.getPosition().x +square.getPosition().x < window.getSize().x)
    {
        square.move(5.f, 0.f);
        keytime = 0;
    }
    if (Keyboard::isKeyPressed(Keyboard::S) && square.getPosition().y +square.getPosition().y < window.getSize().y )
    {
        square.move(0.f, 5.f);
        keytime = 0;
    }
    if (Keyboard::isKeyPressed(Keyboard::W) && square.getPosition().y > 0 )
    {
        square.move(0.f, -5.f);
        keytime = 0;
    }
    if (Mouse::isButtonPressed(Mouse::Left))// it will help us to by left cleack on the mouse we can change the color of the objct
    {
        square.setFillColor(Color::Blue);
        square.setOutlineColor(Color::Red);

        keytime = 0;
    }else { 
        square.setFillColor(Color::Red);
        square.setOutlineColor(Color::Blue);
    }
}

void draw(RenderWindow &window, RectangleShape &square)
{
    window.draw(square);

    // Display everything
    window.display();
}
