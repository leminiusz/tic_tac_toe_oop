#include <bits/stdc++.h>
#include "board.h"
using namespace std;


//ustawiamy wszystkie pola na empty
void Board::reset(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=Mark::empty;
        }
    }
}

//konstruktor tworzy plansze i wywoluje reset
Board::Board(){
    reset();
}

//pokazuje obecny stan planszy
void Board::pokaz() const{
     cout << "   0   1   2"<<'\n';
    for(int i=0;i<3;i++){
        cout<<i<<"  ";
        for(int j=0;j<3;j++){
            if(board[i][j]==Mark::empty){
                cout<<' ';
            }else if(board[i][j]==Mark::O){
                cout<<'O';
            }else{
                cout<<'X';
            }
            if(j<2)
                cout<<" | ";
        }
        cout<<endl;
        if(i<2)
        cout<<"  ---+---+---"<<endl;
    }
}

//zwraca true i ustawia pole jesli sie da a inaczej zwraca false
bool Board::ustawPole(int row , int col, Mark x){
    if(row<=2 && col<=2){
        if(board[row][col]==Mark::empty){
            board[row][col]=x;
            return true;
        }else{
            return false;
        }
    }else{
        cout<<"Podany wiersz i kolumna nie są z poprawnego zakresu!"<<'\n';
        return false;
    }
}

//zwraca co znajduje sie w zadanym polu
Mark Board::wartoscPola(int row, int col) const{
    if(row<=2 && col<=2){
        return board[row][col];
    }else{
        cout<<"Podany wiersz i kolumna nie są z poprawnego zakresu!"<<'\n';
        return Mark::empty;
    }
}

//sprawdza czy stan na planszy jest zwycieski
Mark Board::zwyciesca() const{
    if( (board[0][0]==board[0][1] && board[0][1]==board[0][2] && board[0][0]!=Mark::empty) ||
        (board[0][0]==board[1][0] && board[1][0]==board[2][0] && board[0][0]!=Mark::empty) ||
        (board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=Mark::empty)){
            return board[0][0];
    }else if((board[0][2]==board[1][2] && board[1][2]==board[2][2] && board[0][2]!=Mark::empty) || 
            (board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=Mark::empty) ){
            return board[0][2];
    }else if((board[1][0]==board[1][1] && board[1][1]==board[1][2] && board[1][0]!=Mark::empty)){
            return board[1][0];
    }else if((board[2][0]==board[2][1] && board[2][1]==board[2][2] && board[2][0]!=Mark::empty)){
            return board[2][0];
    }else if((board[0][1]==board[1][1] && board[1][1]==board[2][1] && board[0][1]!=Mark::empty)){
        return board[0][1];
    }
    return Mark::empty;
}

//sprawdza czy wszystkie miejsca na planszy sa zajete czyli jest remis
bool Board::czyRemis() const{
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==Mark::empty){
                return false;
            }
        }
    }
    return true;
}
