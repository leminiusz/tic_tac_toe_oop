#include "minimax.h"
#include <algorithm> 

MM::MM(Mark ai) {
    aiMark = ai;
   
    humanMark = (aiMark == Mark::O) ? Mark::X : Mark::O; 
}


int MM::minimax(Board& b, int depth, bool isMax) {
    Mark wygrany = b.zwyciesca();
    
   
    if (wygrany == aiMark) return 10 - depth; 
    if (wygrany == humanMark) return -10 + depth; 
    if (b.czyRemis()) return 0;

    if (isMax) {
        int best = -1000; 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b.wartoscPola(i, j) == Mark::empty) {
                    b.ustawPole(i, j, aiMark);                       
                    best = std::max(best, minimax(b, depth + 1, !isMax)); 
                    b.cofnijruch(i, j);                              
                }
            }
        }
        return best;
    } else {
        int best = 1000; 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b.wartoscPola(i, j) == Mark::empty) {
                    b.ustawPole(i, j, humanMark);
                    best = std::min(best, minimax(b, depth + 1, !isMax));
                    b.cofnijruch(i, j);
                }
            }
        }
        return best;
    }
}


std::pair<int, int> MM::znajdzNajlepszyRuch(Board& b) {
    int bestVal = -1000;
    std::pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b.wartoscPola(i, j) == Mark::empty) {
                b.ustawPole(i, j, aiMark);
                int moveVal = minimax(b, 0, false); 
                b.cofnijruch(i, j);
                if (moveVal > bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove; 
}