#include <iostream>
using namespace std;

main() {
    // tipoPokemon: fuego == 0, agua == 1, electrico == 2, planta == 3
    string nombrePokemon[8] = {"Charizard", "Arcanine", "Blastoise", "Gyarados", "Electabuzz", "Jolteon", "Venusaur", "Victreebel"};
    for (int i = 0; i < 8; i++) {
        cout << nombrePokemon[i] << endl;
    }
    return 0;
}