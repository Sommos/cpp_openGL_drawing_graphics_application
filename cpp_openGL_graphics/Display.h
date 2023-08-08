#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include <memory>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>

namespace Display
{
    void init(); // Set Display Settings and Make Window
    void close(); // Close Window On Call.
    void clear(); // Clear Contents of the Window, each Frame
    void update(); // Update Contents within the Window
    void checkForClose();
    bool isOpen(); // Check if Window Open

    // Window Display Properties
    constexpr static int WIDTH = 1280;
    constexpr static int HEIGHT = 720;
}
#endif