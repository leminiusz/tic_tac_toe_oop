#include <iostream>
#include "board.h"
using namespace std;

int main() {
    Board b;              
    Mark current = Mark::O;

    while(true){
        b.pokaz();
        cout<<"Ruch gracza: "<<(current==Mark::O ? "O" : "X")<<endl;

        int row=-1;
        int col=-1;

        cout<<"Wprowadz kolumne i wiersz z zakresu (0-2) : "<<endl;
        cin>>row>>col;

        if(b.ustawPole(row,col,current)){
            if(b.zwyciesca()!=Mark::empty){
                b.pokaz();
                cout<<"Wygral gracz: "<<(current==Mark::O ? "O" : "X")<<endl;
                break;
            }
            if(b.czyRemis()){
                b.pokaz();
                cout<<"Remis!"<<endl;
                break;
            }
            current = (current==Mark::O ? Mark::X : Mark::O);
        }else{
            cout<<"Podane pole jest zajęte, podaj inne!"<<endl;
        }
    }
}
