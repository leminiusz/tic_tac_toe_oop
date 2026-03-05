#ifndef BOARD_H 
#define BOARD_H
#include <bits/stdc++.h>
using namespace std;

//empty -> puste miejsce na plnaszy
//X -> X w danym miejscu na planszy
//O -> O w danym miejscu na planszy
enum class Mark {empty , X , O};

class Board{
    private:
        Mark board[3][3];
        void reset();
    public:
        Board();
        void pokaz() const;
        bool ustawPole(int r, int c, Mark m);
        void cofnijruch(int r,int c);
        Mark wartoscPola(int r, int c) const;
        Mark zwyciesca() const;
        bool czyRemis() const;
};

#endif //BOARD_H