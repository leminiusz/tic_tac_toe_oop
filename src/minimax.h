#ifndef MINIMAX_H
#define MINIMAX_H

#include "board.h"
#include <utility>

class MM {
    private:
        Mark aiMark;     
        Mark humanMark;  
        
        int minimax(Board& b, int depth, bool isMax); 
        
    public:
        MM(Mark ai);
        std::pair<int, int> znajdzNajlepszyRuch(Board& b); 
};

#endif // MINIMAX_H