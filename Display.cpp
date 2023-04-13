#include "Display.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>

namespace Display
{
    // width and height variables for the current window
    constexpr static int WIDTH = 1280;
    constexpr static int HEIGHT = 720;
    // pointer for RenderWindow object
    std::unique_ptr<sf::RenderWindow> window;

    void init()
    {
        // bit depth setting and version of OpenGL in use
        sf::ContextSettings settings;
        settings.depthBits = 24;
        settings.majorVersion = 3;
        settings.minorVersion = 3; //OpenGL 3.3
        // render the window at the size variables above
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), "Window", sf::Style::Close, settings);
        glewInit();
        glViewport(0, 0, WIDTH, HEIGHT);
    }
    
    // method that allows the user to close the current display window
    void close()
    {
        window->close();
    }

    // method to clear the current display window and set to a colour
    void clear()
    {
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    }

    // method to update the current display window
    void update()
    {
        window->display();
    }

    // method to check if the current window is closed
    void checkForClose()
    {
        sf::Event e;
        while (window->pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                close();
            }
        }
    }

    // method to check if the current window is open
    bool isOpen()
    {
        return window->isOpen();
    }
}
