#include <SFML/Graphics.hpp>
using namespace sf;

int main()
 {
                                //  VideoMode(width,hight)
    RenderWindow window(VideoMode(1244, 1000), "Example 02", Style::Default);
    window.setFramerateLimit(1000);//framerate independandt the game (int will control the speed of shape you make)
    
    CircleShape shape(150.f);//(5.f)-->radious of the circle
    
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close(); // it will close the window for us
            // if(event.type== Event::KeyPressed)  // it is use for key bord handtle to close the window  
        }

        // Update
        shape.move(0.1f,0.1f);//(x-axis,y-axis)-->it has a ability to move any varialbe in the (x,y) direction
        // Draw
        window.clear(Color::Red);//(backGround Colour)

        // drow everything
        window.draw(shape);
        window.display();
    }

    return 0;
}
