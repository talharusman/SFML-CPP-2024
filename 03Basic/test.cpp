#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    window.setFramerateLimit(60);
    
    CircleShape triangle;
    triangle.setRadius(50.f);
    triangle.setFillColor(Color::Red);//it will set the color of the whole triangle
    triangle.setOutlineThickness(5.f);// it wil set the outer line and (5.f) is thickness of the outere line
    triangle.setOutlineColor(Color::Black); // it will set the color of outer line fo the triangle
    triangle.setPosition(Vector2f(10.f, 4.f));// it will set the possition of the tringle
    triangle.setPointCount(3);// it will conver the circle into triangle
    
    Vertex line[] = {Vertex(Vector2f(200.f, 400.f), Color::Black), Vertex(Vector2f(50.f, 100.f), Color::Black)};
    
    ConvexShape convex;
    
    convex.setFillColor(Color::Red);//it will set the color of the whole triangle
    convex.setOutlineThickness(5.f);// it wil set the outer line and (5.f) is thickness of the outere line
    convex.setOutlineColor(Color::Black);// it will set the color of outer line fo the triangle
    convex.setPosition(Vector2f(200.f, 4.f));// it will set the possition of the tringle
     convex.setPointCount(5);// it willdecit how much corner point has

    convex.setPoint(0, Vector2f(0, 0));// it will tell the possite of the points of convex
    convex.setPoint(1, Vector2f(50, 10));
    convex.setPoint(2, Vector2f(100, 50));
    convex.setPoint(3, Vector2f(40, 60));
    convex.setPoint(4, Vector2f(10, 50));

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);//set the color of the background
        
        window.draw(triangle);//will print the tringle on concole
        window.draw(line, 2, LinesStrip); // Changed 'Lines' to 'LinesStrip'
        window.draw(convex);//will print the convex on concole

        window.display();
    }

    return 0;
}
