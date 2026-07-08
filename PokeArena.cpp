#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleTitleA("PokeArena");
    SetConsoleOutputCP(CP_UTF8);
    string nombreEntrenador;
    //Variables de menus y elecciones
    int opcionMenu, opcionPokemon, enemigoElegido, equipoPokemon[2], equipoEnemigo[2];
    //TipoPokemon: fuego == 0, agua == 1, electrico == 2, planta == 3
    //Stats de los pokemon
    string nombrePokemon[8] = {"Charizard", "Arcanine", "Blastoise", "Gyarados", "Electabuzz", "Jolteon", "Venusaur", "Victreebel"};
    int tipoPokemon[8] = {0, 0, 1, 1, 2, 2, 3, 3};
    int vidaPokemon[8] = {150, 190, 220, 180, 130, 160, 210, 170};
    int ataquePokemon[8] = {90, 70, 55, 75, 100, 95, 60, 80};
    int defensaPokemon[8] = {60, 40, 25, 45, 70, 45, 30, 50};
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
    system("cls");
    //Peticion nombre jugador
    cout << "Ingresa tu nombre de entrenador: ";
    cin >> nombreEntrenador;
    
    //Menu principal
    bool salir = false;
    while (!salir) {
        system("cls");
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
            system("cls");
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
            //Eleccion de la cpu del pokemon enemigo y validacion para que no sea el mismo del jugador
            int enemigoElegido = rand() % 8;
            while (enemigoElegido == opcionPokemon){
                enemigoElegido = rand() % 8;
            }
            cout << "Lucharas contra " << nombrePokemon[enemigoElegido] << endl;
            //Variables de combate
            int hpJ = vidaPokemon[opcionPokemon];
            int hpE = vidaPokemon[enemigoElegido];
            int intentosProteccionJ = 0;
            int intentosProteccionE = 0;
            bool proteccionJ = false;
            bool proteccionE = false;
            //Inicio del combate 1v1
            while (hpJ > 0 && hpE > 0)
            {
                proteccionJ = false;
                cout << "====================COMBATE POKEMON====================" << endl;
                cout << "HP de " << nombrePokemon[opcionPokemon] << ": " << hpJ << "            HP de " << nombrePokemon[enemigoElegido] << ": " << hpE << endl;
                cout << "¿Que haras? \n 1. Ataque rapido \n 2. Ataque pesado \n 3. Proteccion" << endl;
                int accionJ;
                cin >> accionJ;
                //Calculos del combate
                switch(accionJ){
                    //Utilizacion de ataque rapido
                    case 1:
                    {
                        int dano = ataquePokemon[opcionPokemon] - (defensaPokemon[enemigoElegido] / 2);
                        if ((tipoPokemon[opcionPokemon] + 1) / 4 == tipoPokemon[enemigoElegido]){
                            dano = dano * 1.2;
                            cout << "¡El ataque es efectivo!" << endl;
                        }
                        hpE -= dano;
                        cout << nombreEntrenador << " utilizo ataque rapido." << endl;
                        cout << "Causo " << dano << " de daño a " << nombrePokemon[enemigoElegido] << endl;
                        intentosProteccionJ = 0;
                        break;
                    }
                    //Utilizacion de ataque pesado
                    case 2:
                    {
                        int precision = 50;
                        int probabilidad = rand() % 100;
                        if (probabilidad < precision) 
                        {
                            int dano = (ataquePokemon[opcionPokemon] - (defensaPokemon[enemigoElegido] / 2)) * 1.1;
                            if ((tipoPokemon[opcionPokemon] + 1) % 4 == tipoPokemon[enemigoElegido])
                            {
                                dano = dano * 1.2;
                                cout << "¡El ataque es efectivo!" << endl;
                            }
                            hpE -= dano;
                            cout << nombreEntrenador << " utilizo ataque pesado." << endl;
                            cout << "Causo " << dano << " de daño a " << nombrePokemon[enemigoElegido] << endl;
                        }
                        else 
                        {
                            cout << nombrePokemon[opcionPokemon] << " ha fallado el ataque." << endl;
                        }
                        intentosProteccionJ = 0;
                        break;
                    }
                    //Utilizacion de proteccion
                    case 3:
                    {
                        int precision;
                        if (intentosProteccionJ == 0)
                        {
                            precision = 100;
                        }
                        else if (intentosProteccionJ == 1)
                        {
                            precision = 30;
                        }
                        else
                        {
                            precision = 3;
                        }
                        break;
                    }
                }
            }
        break;
        }
        case 2:
        {
            system("cls");
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
                cout << i << ". " << nombrePokemon[i] << " TIPO: " << colorTipo << nombreTipo << "\033[0m" << " HP: " << vidaPokemon[i] << " ATK: " << ataquePokemon[i] << " DEF: " << defensaPokemon[i] << endl;
                cout << "================================================" << endl;
            }
        //Creacion de la eleccion de dos pokemons para el combate 2v2
            for (int i = 0; i < 2; i++)
            {
                bool confirmacion = false;
                while(!confirmacion){
                    cout << "Elije tu pokemon numero " << (i + 1) << endl;
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
            //Eleccion del equipo enemigo por la cpu junto con validacion para no repetir los pokemons del jugador
            equipoEnemigo[0] = rand() % 8;
            while (equipoEnemigo[0] == equipoPokemon[0] || equipoEnemigo[0] == equipoPokemon[1])   {
                equipoEnemigo[0] = rand() % 8;
            }        
            equipoEnemigo[1] = rand() % 8;
            while (equipoEnemigo[1] == equipoPokemon[0] || equipoEnemigo[1] == equipoPokemon[1])   {
                equipoEnemigo[1] = rand() % 8;
            }        
            cout << "Lucharas contra " << nombrePokemon[equipoEnemigo[0]] << " y " << nombrePokemon[equipoEnemigo[1]] << endl;     
        break;
        }
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