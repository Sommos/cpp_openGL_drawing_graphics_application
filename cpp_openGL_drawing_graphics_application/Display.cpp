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

    // initialize the display
    void init()
    {
        // configure the context settings for OpenGL
        sf::ContextSettings settings;
        settings.depthBits = 24;
        settings.majorVersion = 3;
        settings.minorVersion = 3; // OpenGL 3.3

        // create the SFML window with the specified width, height, title, style, and settings
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), "Window", sf::Style::Close, settings);

        // initialize GLEW
        glewInit();

        // set the viewport to cover the entire window
        glViewport(0, 0, WIDTH, HEIGHT);
    }

    // close the display window
    void close()
    {
        window->close();
    }

    // clear the display window with a specified color
    void clear()
    {
        // set the clear color to black
        glClearColor(0.0, 0.0, 0.0, 1.0); 
        // clear the depth and color buffers
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT); 
    }

    // update the display window
    void update()
    {
        window->display();
    }

    // check if the display window should be closed
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

    // check if the display window is open
    bool isOpen()
    {
        return window->isOpen();
    }
}
