#include "Application.h"

Application::Application()
{
    // push an instance of the "Playing" state onto the stack of game states
    pushState(std::make_unique<State::Playing>(*this)); 
}

void Application::runMainGameLoop()
{
    while (Display::isOpen()) 
    {
        Display::clear(); 
        m_states.top()->input(); 
        m_states.top()->update(); 
        m_states.top()->draw(); 
        Display::update();
        Display::checkForClose(); 
    }
}

void Application::pushState(std::unique_ptr<State::Game_State> state)
{
    // move the ownership of the state object into the stack of game states
    m_states.push(std::move(state)); 
}

void Application::popState()
{
    // remove the top game state from the stack
    m_states.pop(); 
}
