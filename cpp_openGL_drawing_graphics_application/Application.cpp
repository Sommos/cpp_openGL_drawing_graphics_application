#include "Application.h"
#include "Display.h"
#include "States/Playing.h"

Application::Application()
{
    // push an instance of the "Playing" state onto the stack of game states
    pushState(std::make_unique<State::Playing>(*this)); 
}

// the main game loop
void Application::runMainGameLoop()
{
    // loop until the display is closed
    while (Display::isOpen()) 
    {
        // clear the display
        Display::clear(); 

        // handle input for the current state
        m_states.top()->input(); 
        // update the current state
        m_states.top()->update(); 
        // draw the current state
        m_states.top()->draw(); 

        // update the display
        Display::update();
        // check if the display should be closed
        Display::checkForClose(); 
    }
}

// push a new game state onto the stack
void Application::pushState(std::unique_ptr<State::Game_State> state)
{
    // move the ownership of the state object into the stack of game states
    m_states.push(std::move(state)); 
}

// pop the top game state from the stack
void Application::popState()
{
    // remove the top game state from the stack
    m_states.pop(); 
}
