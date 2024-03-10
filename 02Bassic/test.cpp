#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    window.setFramerateLimit(40);
    CircleShape shape(100.f);//circlesShape is data type of the circle
    // Vector2f vec(10.f,12.f);// (float x,float y)
    // vec.x;
    shape.setFillColor(sf::Color::Green);//set the color of the shape
    shape.setPosition(Vector2f(0.f,0.f));//it will set the intial possition shape the shape
    
    RectangleShape rec(Vector2f(50.f,100.f));
    rec.setFillColor(Color(255,255,255));//Color(red,green,blue)-->RGB values
    rec.setPosition(Vector2f(400.f,200.f));//set the possition of the rectangle

    while (window.isOpen())
    {
        Event event;
        //it is a game loop which is creatiog a window 
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // shape.move(1.0f,2.0f);
        shape.rotate(2.f);//it will rotating around the origen which is set on the top left  

        // rec.move(-1.0f,0.0f);//it will move the rctangal shape 
        rec.rotate(9.f);//rotate(speed of rotation)

        window.clear(Color::Blue);//set the background color

        window.draw(shape);// it will draw the shap which you selacted
        window.draw(rec);//will print the rectangl on the concole
        window.display();
    }

    return 0;
}