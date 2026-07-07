#include <iostream>
using namespace std;

int main() {
    // tipoPokemon: fuego == 0, agua == 1, electrico == 2, planta == 3
    string nombrePokemon[8] = {"Charizard", "Arcanine", "Blastoise", "Gyarados", "Electabuzz", "Jolteon", "Venusaur", "Victreebel"};
    int tipoPokemon[8] = {0, 0, 1, 1, 2, 2, 3, 3};
    int vidaPokemon[8] = {200, 200, 200, 200, 200, 200, 200, 200};
    int ataquePokemon[8] = {20, 20, 20, 20, 20, 20, 20, 20};
    int defensaPokemon[8] = {50, 50, 50, 50, 50, 50, 50, 50};

    for (int i = 0; i < 8; i++)
    {
        cout << nombrePokemon[i] << " tipo: " << tipoPokemon[i] << " vida: " << vidaPokemon[i] << " ataque: " << ataquePokemon[i] << " defensa: " << defensaPokemon[i] << endl;
    }
    
    return 0;
}