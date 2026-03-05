#include <iostream>
#include <limits>
#include "gameplay.h"
#include "minimax.h"
using namespace std;

Game::Game() {
    currentMark = Mark::O; 
}

void Game::zmianaOsoby() {
    currentMark = (currentMark == Mark::O ? Mark::X : Mark::O);
}

bool Game::jakiWynik() {
    Mark wygrany = b.zwyciesca();
    if (wygrany != Mark::empty) {
        b.pokaz();
        cout << "\n>>> WYGRAL GRACZ: " << (wygrany == Mark::O ? "O" : "X") << " <<<\n";
        return true;
    }
    if (b.czyRemis()) {
        b.pokaz();
        cout << "\n>>> REMIS! <<<\n";
        return true;
    }
    return false;
}

void Game::gra() {
    bool grajDalej = true;
    
    while (grajDalej) {
        b = Board();
        currentMark = Mark::O; 
        bool koniecRundy = false;

        cout << "\n--- KOLKO I KRZYZYK ---\n";
        cout << "1. Gra 2 graczy (Lokalnie)\n";
        cout << "2. Gra z Komputerem\n";
        cout << "Wybierz tryb (1 lub 2): ";
        int tryb;
        
        while (!(cin >> tryb) || (tryb != 1 && tryb != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Blad! Wybierz 1 lub 2: ";
        }

        MM komputer(Mark::X); 

        while (!koniecRundy) {
            b.pokaz();
            cout << "\nRuch gracza: " << (currentMark == Mark::O ? "O" : "X") << endl;

            int row = -1, col = -1;

            if (tryb == 2 && currentMark == Mark::X) {
                cout << "Komputer mysli...\n";
                pair<int, int> najlepszyRuch = komputer.znajdzNajlepszyRuch(b);
                row = najlepszyRuch.first;
                col = najlepszyRuch.second;
            } 
            else {
                cout << "Wprowadz wiersz i kolumne z zakresu (0-2) [np. 1 2]: ";
                if (!(cin >> row >> col)) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Blad! Uzywaj tylko cyfr.\n";
                    continue; 
                }
            }

            if (b.ustawPole(row, col, currentMark)) {
                if (jakiWynik()) {
                    koniecRundy = true; 
                } else {
                    zmianaOsoby(); 
                }
            } else {
                if (currentMark == Mark::O || tryb == 1) { 
                    cout << "To pole jest zajete lub nieprawidlowe! Podaj inne.\n";
                }
            }
        }

        cout << "\nCzy chcesz zagrac jeszcze raz? (t/n): ";
        char wybor;
        cin >> wybor;
        if (wybor != 't' && wybor != 'T') {
            grajDalej = false;
        }
    }
    cout << "Dzieki za gre! Do zobaczenia.\n";
}