#ifndef GAMEPLAY_H 
#define GAMEPLAY_H

#include "board.h" 

class Game {
    private:
        Board b;           
        Mark currentMark; 
        
        void zmianaOsoby();
        bool jakiWynik(); 
        
    public:
        Game();            
        void gra();        
};

#endif //GAMEPLAY_H