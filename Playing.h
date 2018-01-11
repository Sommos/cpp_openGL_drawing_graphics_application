#ifndef PLAYING_H_INCLUDED
#define PLAYING_H_INCLUDED

#include "Game_State.h"

#include "../Model.h"

class Application;

namespace State
{
    class Playing : public Game_State
    {
        public:
            Playing(Application& application);

            void input()    override;
            void update()   override;
            void draw()     override;

        private:
            Model m_model;
    };
}

#endif // PLAYING_H_INCLUDED
