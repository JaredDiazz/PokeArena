#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    string nombreEntrenador;
    int opcionMenu, opcionPokemon, equipoPokemon[2];
    //TipoPokemon: fuego == 0, agua == 1, electrico == 2, planta == 3
    string nombrePokemon[8] = {"Charizard", "Arcanine", "Blastoise", "Gyarados", "Electabuzz", "Jolteon", "Venusaur", "Victreebel"};
    int tipoPokemon[8] = {0, 0, 1, 1, 2, 2, 3, 3};
    int vidaPokemon[8] = {200, 200, 200, 200, 200, 200, 200, 200};
    int ataquePokemon[8] = {20, 20, 20, 20, 20, 20, 20, 20};
    int defensaPokemon[8] = {50, 50, 50, 50, 50, 50, 50, 50};

    cout << R"(
       ⠀⢢⣤⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⢀⣀⣠⣤⣶⣶⡟⠁⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣷⣶⣦⣤⣀⡀⠀⠀⠀⠀⢀⣀⣤⣴⣶⣶⣶⣶⣶⣶⣦⣤⣀⡀⢀⣀⣠⣤⣴⣶⣾⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⠁⠙⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠀⠸⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠐⢶⣶⣶⣶⣶⣶⣶⣾⣿⣿⣿⣿⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣶⣶⣶⣶⣾⠟⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠠⣶⡆⠈⠻⣿⣿⣿⣿⣿⠋⠠⣶⡆⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣤⣤⣤⣤⣤⣿⣿⣿⣿⣿⣦⣤⣤⣶⣶⣶⣾⡿⢿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⡛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢀⣾⣿⣿⣿⣿⣯⣤⡤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠶⣶⣶⣾⣿⣿⣿⣿⣧⠀⠛⠁⠀⠈⠿⠋⠉⠉⠉⠉⠻⠋⠀⠀⠈⠁⢠⣾⣿⣿⣿⣿⣿⣿⣿⣷⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢠⣤⣤⣤⣀⠀⠈⠻⢿⣿⣿⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⠟⣿⣿⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣷⣦⡀⠀⠙⠿⣿⣿⣿⣿⣿⣦⣀⣠⣀⣴⡀⣠⡀⣠⡀⣴⣄⣠⣾⣿⣿⣿⣿⣿⣿⡿⠋⠀⣼⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣋⣀⣠⣾⣿⣿⣿⣿⣿⣿⣷⣶⣶⣤⣄⠀
⠀⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷
⠀⢀⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠛⠻⣿⣿⣿⡿⠟⠙⠿⣿⣿⣿⣿⣿⣿⣿⣿
⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠟⠿⠿⠿⠛⠁⣿⣿⠃⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⠁⠀⠀⠀⠀⠀⠹⡇⠀⠀⠀⠈⠙⠛⠋⠁⣸⡿⠃
⠸⣿⣿⡟⠉⠉⠉⠉⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠛⠁⠀⠀⠀⠀ ⠙⣧⠙⣿⣿⣿⣿⣿⣿⣿⣿⠘⡏⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡿⠁⠀
⠀⢻⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠈⠣⠈⠻⣿⡿⢿⣿⣿⣿⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀   ⠙⢷⠈⢻⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⠀   ⠀⠻⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀   ⠙⠇
                     _                                   
         _ __   ___ | | _____  __ _ _ __ ___ _ __   __ _ 
        | '_ \ / _ \| |/ / _ \/ _` | '__/ _ \ '_ \ / _` |
        | |_) | (_) |   <  __/ (_| | | |  __/ | | | (_| |
        | .__/ \___/|_|\_\___|\__,_|_|  \___|_| |_|\__,_|
        |_|                                              
             (PRESIONA ENTER PARA COMENZAR EL JUEGO)
    )";
    cin.get();
    //Peticion nombre jugador
    cout << "Ingresa tu nombre de entrenador: ";
    cin >> nombreEntrenador;
    
    //Menu principal
    bool salir = false;
    while (!salir) {
        cout << "¡Bienvenido a PokeArena, " << nombreEntrenador << "!" << endl;
        cout << "==========MENU==========" << endl;
        cout << "||  1. Batalla 1v1    ||" << endl;
        cout << "||  2. Batalla 2v2    ||" << endl;
        cout << "||  3. Historial      ||" << endl;
        cout << "||  4. Salir          ||" << endl;
        cout << "========================" << endl;
        cout << "Ingresa una opcion: " << endl;
        cin >> opcionMenu;

        switch (opcionMenu)
        {
        case 1:
        {
            //Listado de pokemons
            cout << "Haz seleccionado Batalla 1 vs 1, observa los pokemons disponibles:" << endl;
            cout << "====================POKEMONS====================" << endl;
            for (int i = 0; i < 8; i++) {
                //Modificacion para mostrar en el for el nombre del tipo con un color acorde a este en lugar del numero
                string nombreTipo;
                string colorTipo;
                switch (tipoPokemon[i]){
                    case 0: nombreTipo =  "Fuego"; colorTipo = "\033[31m"; break;
                    case 1: nombreTipo =  "Agua"; colorTipo = "\033[36m"; break;
                    case 2: nombreTipo =  "Electrico"; colorTipo = "\033[33m"; break;
                    case 3: nombreTipo =  "Planta"; colorTipo = "\033[32m"; break;
                }
                cout << i << ". " << nombrePokemon[i] << " Tipo: " << colorTipo << nombreTipo << "\033[0m" << " HP: " << vidaPokemon[i] << " ATK: " << ataquePokemon[i] << " DEF: " << defensaPokemon[i] << endl;
                cout << "================================================" << endl;
            }
            //Eleccion de pokemon del jugador
            bool confirmacion = false;
            while (!confirmacion){
                cout << "Elije tu pokemon: ";
                cin >> opcionPokemon;
                //Validacion de la opcion
                if (opcionPokemon < 0 || opcionPokemon > 7)
                {
                    cout << "Ingresa una opcion valida." << endl;
                    continue;
                }
                cout << "Haz seleccionado a " << nombrePokemon[opcionPokemon] << endl;
                int eleccion;
                cout << "¿Estas seguro de tu eleccion? 1.Si 2.No" << endl;
                cin >> eleccion;
                if (eleccion == 1){
                    confirmacion = true;
                }          
            }
        }
        break;
        case 2:
        {
            //Listado de pokemons
            cout << "Haz seleccionado Batalla 2 vs 2, observa los pokemons disponibles:" << endl;
            cout << "====================POKEMONS====================" << endl;
            for (int i = 0; i < 8; i++) {
                //Modificacion para mostrar en el for el nombre del tipo con un color acorde a este en lugar del numero
                string nombreTipo;
                string colorTipo;
                switch (tipoPokemon[i]){
                    case 0: nombreTipo =  "Fuego"; colorTipo = "\033[31m"; break;
                    case 1: nombreTipo =  "Agua"; colorTipo = "\033[36m"; break;
                    case 2: nombreTipo =  "Electrico"; colorTipo = "\033[33m"; break;
                    case 3: nombreTipo =  "Planta"; colorTipo = "\033[32m"; break;
                }
                cout << i << ". " << nombrePokemon[i] << " Tipo: " << colorTipo << nombreTipo << "\033[0m" << " HP: " << vidaPokemon[i] << " ATK: " << ataquePokemon[i] << " DEF: " << defensaPokemon[i] << endl;
                cout << "================================================" << endl;
            }
        //Creacion de la eleccion de dos pokemons para el combate 2v2
            for (int i = 0; i < 2; i++)
            {
                bool confirmacion = false;
                while(!confirmacion){
                    cout << "Elije tu pokemon: Numero " << (i + 1) << endl;
                    cin >> opcionPokemon;
                    //Validacion
                    if  (opcionPokemon < 0 || opcionPokemon > 7)
                    {
                        cout << "Ingresa una opcion valida." << endl;
                        continue;
                    }
                    //Validacion para no repetir pokemons
                    if (i == 1 && opcionPokemon == equipoPokemon[0])
                    {
                        cout << "No puedes repetir pokemons en el equipo, elige otro" << endl;
                        continue;
                    }
                    //Confirmacion de equipo pokemon
                    cout << "Elegiste a " << nombrePokemon[opcionPokemon] << endl;
                    int eleccion;
                    cout << "¿Estas seguro de tu eleccion? 1.Si 2.No" << endl;
                    cin >> eleccion;
                    if (eleccion == 1)
                    {
                        equipoPokemon[i] = opcionPokemon;
                        confirmacion = true;
                    }
                }
            }
        }
        break;
        case 3:
        break;
        case 4:
        salir = true;
        cout << "¡Gracias por jugar a PokeArena!" << endl;
        break;
        default:
        cout << "Ingresa una opcion valida." << endl;
            break;
        }
    }

    return 0;  
}