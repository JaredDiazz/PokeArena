#include <iostream>
#include <windows.h>
#include <cstdlib> 
#include <ctime>
#include <fstream>
using namespace std;

int main() {
    srand(time(0));
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

        switch (opcionMenu) {
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
            system("pause");
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
                system("cls");
                proteccionJ = false;
                cout << "====================COMBATE POKEMON====================" << endl;
                cout << "HP de " << nombrePokemon[opcionPokemon] << ": " << hpJ << "            HP de " << nombrePokemon[enemigoElegido] << ": " << hpE << endl;
                cout << "¿Que haras? \n 1. Ataque rapido \n 2. Ataque pesado \n 3. Proteccion" << endl;
                cout << "=======================================================" << endl;
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
                        int probabilidad = rand() % 100;
                        if (probabilidad < precision)
                        {
                            proteccionJ = true;
                            cout << nombrePokemon[opcionPokemon] << " se protegio." << endl;
                        }
                        else
                        {
                            proteccionJ = false;
                            cout << nombrePokemon[opcionPokemon] << " intento protegerse pero fallo." << endl;
                        }
                        intentosProteccionJ++;
                        break;
                    }
                    default:
                    cout << "No ingresaste una opcion valida, perdiste tu turno." << endl;
                    break;
                }
                //Turno de la cpu donde va seleccion un ataque al azar
                if (hpE > 0)
                {
                    proteccionE = false;
                    int accionE = rand() % 2 + 1;
                    switch (accionE) {
                    case 1:
                    {
                        if (proteccionJ)
                        {
                            cout << nombrePokemon[enemigoElegido] << " ataco, pero " << nombrePokemon[opcionPokemon] << " se protegio." << endl;
                        }
                        else 
                        {
                            int dano = ataquePokemon[enemigoElegido] - (defensaPokemon[opcionPokemon] / 2);
                            if((tipoPokemon[enemigoElegido] + 1) % 4 == tipoPokemon[opcionPokemon])
                            {
                                dano = dano * 1.2;
                                cout << "¡El ataque enemigo es efectivo!" << endl;
                            }
                            hpJ -= dano;
                            cout << "Giovanni utilizo ataque rapido." << endl;
                            cout << "Causo " << dano << " de daño a " << nombrePokemon[opcionPokemon] << endl;
                        }
                        intentosProteccionE = 0;
                        break;
                    }
                    case 2:
                    {
                        int precision = 50;
                        int probabilidad = rand() %100;
                        if (probabilidad < precision)
                        {
                            if (proteccionJ)
                            {
                                cout << nombrePokemon[enemigoElegido] << " ataco, pero " << nombrePokemon[opcionPokemon] << " se protegio." << endl;
                            }
                            else
                            {
                                int dano = (ataquePokemon[enemigoElegido] - (defensaPokemon[opcionPokemon] / 2)) * 1.1;
                                if ((tipoPokemon[enemigoElegido] + 1) % 4 == tipoPokemon[opcionPokemon])
                                {
                                    dano = dano * 1.2;
                                    cout << "¡El ataque enemigo es efectivo!" << endl;
                                }
                                hpJ -= dano;
                                cout << "Giovanni utilizo ataque pesado." << endl;
                                cout << "Causo " << dano << " de daño a " << nombrePokemon[opcionPokemon] << endl;
                            }
                        }    
                        else {
                            cout << nombrePokemon[enemigoElegido] << " ha fallado el ataque." << endl;
                        }   
                        break;
                    }
                    }
                    system("pause");
                }
            }
            //Resultado de la partida
            bool jugadorGanador;
            cout << "===============RESULTADO DE LA PARTIDA================" << endl;
            if (hpJ <= 0)
            {
                cout << "Tu " << nombrePokemon[opcionPokemon] << " se debilito. Has perdido." << endl;
                jugadorGanador = false;
            }
            else
            {
                cout << "El " << nombrePokemon[enemigoElegido] << " se debilito. Has ganado." << endl;
                jugadorGanador = true;
            }
            //Guardar historial de la partida 1v1
            ofstream historial("historial.txt", ios::app);
            if (historial.is_open())
            {
                historial << "Entrenador: " << nombreEntrenador << " Modo: 1v1" << " Pokemon: " << nombrePokemon[opcionPokemon] << " Resultado: " << (jugadorGanador ? "Gano" : "Perdio") << endl;
                historial.close();
            }
            system("pause");
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
            while (equipoEnemigo[1] == equipoPokemon[0] || equipoEnemigo[1] == equipoPokemon[1] || equipoEnemigo[1] == equipoEnemigo[0])   {
                equipoEnemigo[1] = rand() % 8;
            }        
            cout << "Lucharas contra " << nombrePokemon[equipoEnemigo[0]] << " y " << nombrePokemon[equipoEnemigo[1]] << endl;    
            system("pause");
            //Declaracion de variables para el combate 
            int hpJ[2] = { vidaPokemon[equipoPokemon[0]], vidaPokemon[equipoPokemon[1]] };
            int hpE[2] = { vidaPokemon[equipoEnemigo[0]], vidaPokemon[equipoEnemigo[1]] };
            int pokemonActivoJ = 0;
            int pokemonActivoE = 0;
            int intentosProteccionJ = 0;
            bool proteccionJ = false;
            //Calculo del combate 2v2
            while ((hpJ[0] > 0 || hpJ[1] > 0) && (hpE[0] > 0 || hpE[1] > 0)){
                system("cls");
                //Cambio pokemon pero este es el que no es manual, por si debilitan al pokemon que va delante
                if (hpJ[pokemonActivoJ] <= 0)
                {
                    if (pokemonActivoJ == 0)
                    {
                        pokemonActivoJ = 1;
                    }
                    else 
                    {
                        pokemonActivoJ = 0;
                    }
                    cout << nombrePokemon[equipoPokemon[pokemonActivoJ]] << " yo te elijo." << endl;
                }
                if (hpE[pokemonActivoE] <= 0)
                {
                    if (pokemonActivoE == 0)
                    {
                        pokemonActivoE = 1;
                    }
                    else
                    {
                        pokemonActivoE = 0;
                    }
                    cout << "El " << nombrePokemon[equipoEnemigo[pokemonActivoE]] << " enemigo entra al combate." << endl;
                }
                proteccionJ = false;
                cout << "====================COMBATE POKEMON====================" << endl;
                cout << "HP de " << nombrePokemon[equipoPokemon[pokemonActivoJ]] << ": " << hpJ[pokemonActivoJ] << "            HP de " << nombrePokemon[equipoEnemigo[pokemonActivoE]] << ": " << hpE[pokemonActivoE] << endl;
                cout << "¿Que haras? \n 1. Ataque rapido \n 2. Ataque pesado \n 3. Proteccion \n 4. Cambiar pokemon" << endl;
                cout << "=======================================================" << endl;
                int accionJ;
                cin >> accionJ;
                switch (accionJ)
                {
                case 1:
                {
                    int dano = ataquePokemon[equipoPokemon[pokemonActivoJ]] - (defensaPokemon[equipoEnemigo[pokemonActivoE]] / 2);
                    if ((tipoPokemon[equipoPokemon[pokemonActivoJ]] + 1) % 4 == tipoPokemon[equipoEnemigo[pokemonActivoE]])
                    {
                        dano = dano * 1.2;
                        cout << "¡El ataque es efectivo!" << endl;
                    }
                    hpE[pokemonActivoE] -= dano;
                    cout << nombreEntrenador << " utilizo ataque rapido." << endl;
                    cout << "Causo " << dano << " de daño a " << nombrePokemon[equipoEnemigo[pokemonActivoE]] << endl;
                    intentosProteccionJ = 0;
                    break;
                }
                case 2:
                {
                    int precision = 50;
                    int probabilidad = rand() % 100;
                    if (probabilidad < precision) 
                    {
                    int dano = (ataquePokemon[equipoPokemon[pokemonActivoJ]] - (defensaPokemon[equipoEnemigo[pokemonActivoE]] / 2)) * 1.1;
                    if ((tipoPokemon[equipoPokemon[pokemonActivoJ]] + 1) % 4 == tipoPokemon[equipoEnemigo[pokemonActivoE]])
                    {
                    dano = dano * 1.2;
                    cout << "¡El ataque es efectivo!" << endl;
                    }
                    hpE[pokemonActivoE] -= dano;
                    cout << nombreEntrenador << " utilizo ataque pesado." << endl;
                    cout << "Causo " << dano << " de daño a " << nombrePokemon[equipoEnemigo[pokemonActivoE]] << endl;
                    }
                    else 
                    {
                    cout << nombrePokemon[equipoPokemon[pokemonActivoJ]] << " ha fallado el ataque." << endl;
                    }
                    intentosProteccionJ = 0;
                    break;
                }
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
                    int probabilidad = rand() % 100;
                    if (probabilidad < precision)
                    {
                    proteccionJ = true;
                    cout << nombrePokemon[equipoPokemon[pokemonActivoJ]] << " se protegio." << endl;
                    }
                    else
                    {
                    proteccionJ = false;
                    cout << nombrePokemon[equipoPokemon[pokemonActivoJ]] << " intento protegerse pero fallo." << endl;
                    }
                    intentosProteccionJ++;
                    break;
                }
                case 4:
                {
                    int pokemonBanca;
                    if (pokemonActivoJ == 0)
                    {
                        pokemonBanca = 1;
                    }
                    else
                    {
                         pokemonBanca = 0;
                    }
                    if (hpJ[pokemonBanca] <= 0)
                    {
                        cout << nombrePokemon[equipoPokemon[pokemonActivoJ]] << " ya esta debilitado, no puede entrar al combate" << endl;
                    }
                    else
                    {
                        pokemonActivoJ = pokemonBanca;
                        cout << nombrePokemon[equipoPokemon[pokemonActivoJ]] << " yo te elijo." << endl;
                    }
                    intentosProteccionJ = 0;
                    break;
                }
                default:
                cout << "No ingresaste una opcion valida, perdiste tu turno." << endl;
                break;
                }
                //Turno de la cpu donde va seleccion un ataque al azar
                if (hpE[equipoEnemigo[pokemonActivoE]] > 0)
                {
                int accionE = rand() % 2 + 1;
                switch (accionE) {
                case 1:
                {
                    if (proteccionJ)
                    {
                    cout << nombrePokemon[equipoEnemigo[pokemonActivoE]] << " ataco, pero " << nombrePokemon[equipoPokemon[pokemonActivoJ]] << " se protegio." << endl;
                    }
                    else 
                    {
                    int dano = ataquePokemon[equipoEnemigo[pokemonActivoE]] - (defensaPokemon[equipoPokemon[pokemonActivoJ]] / 2);
                    if((tipoPokemon[equipoEnemigo[pokemonActivoE]] + 1) % 4 == tipoPokemon[equipoPokemon[pokemonActivoJ]])
                    {
                    dano = dano * 1.2;
                    cout << "¡El ataque enemigo es efectivo!" << endl;
                    }
                    hpJ[pokemonActivoJ] -= dano;
                    cout << "Giovanni utilizo ataque rapido." << endl;
                    cout << "Causo " << dano << " de daño a " << nombrePokemon[equipoPokemon[pokemonActivoJ]] << endl;
                    }
                    break;
                }
                case 2:
                {
                    int precision = 50;
                    int probabilidad = rand() %100;
                    if (probabilidad < precision)
                    {
                    if (proteccionJ)
                    {
                    cout << nombrePokemon[equipoEnemigo[pokemonActivoE]] << " ataco, pero " << nombrePokemon[equipoPokemon[pokemonActivoJ]] << " se protegio." << endl;
                    }
                    else
                    {
                    int dano = (ataquePokemon[equipoEnemigo[pokemonActivoE]] - (defensaPokemon[equipoPokemon[pokemonActivoJ]] / 2)) * 1.1;
                    if ((tipoPokemon[equipoEnemigo[pokemonActivoE]] + 1) % 4 == tipoPokemon[equipoPokemon[pokemonActivoJ]])
                    {
                    dano = dano * 1.2;
                    cout << "¡El ataque enemigo es efectivo!" << endl;
                    }
                    hpJ[pokemonActivoJ] -= dano;
                    cout << "Giovanni utilizo ataque pesado." << endl;
                    cout << "Causo " << dano << " de daño a " << nombrePokemon[equipoPokemon[pokemonActivoJ]] << endl;
                    }
                    }    
                    else 
                    {
                    cout << nombrePokemon[equipoEnemigo[pokemonActivoE]] << " ha fallado el ataque." << endl;
                    }   
                    break;
                }
                }
                system("pause");
                }
            }
            //Resultado de la partida
            bool jugadorGanador;
            cout << "===============RESULTADO DE LA PARTIDA================" << endl;
            if (hpJ[0] <= 0 && hpJ[1] <= 0)
            {
                cout << "Tu " << nombrePokemon[equipoPokemon[pokemonActivoJ]] << " se debilito. Has perdido." << endl;
                jugadorGanador = false;
            }
            else
            {
                cout << "Has debilita a los pokemons enemigos. Has ganado." << endl;
                jugadorGanador = true;
            }
            //Guardar partida 2v2
            ofstream historial("historial.txt", ios::app);
            if (historial.is_open())
            {
            historial << "Entrenador: " << nombreEntrenador << " Modo: 2v2" << " Pokemon: " << nombrePokemon[equipoPokemon[0]] << " y " << nombrePokemon[equipoPokemon[1]] << " Resultado: " << (jugadorGanador ? "Gano" : "Perdio") << endl;
            historial.close();
            }
            system("pause");
        break;
        }
        case 3:
        {
            //ver historial de partidas
            system("cls");
            cout << "===============HISTORIAL DE PARTIDAS===============" << endl;
            ifstream historial("historial.txt");
            if (historial.is_open())
            {
                string info;
                bool hayInfo = false;
                while (getline(historial, info))
                {
                    cout << info << endl;
                    hayInfo = true;
                }
                historial.close();
                if (!hayInfo)
                {
                    cout << "No hay partidas registradas." << endl;
                }
            }
            else
            {
                cout << "No hay partidas registradas." << endl;
            }
            cout << "==================================================" << endl;
            system("pause");
            break;
        }
        case 4:
        {
            salir = true;
            cout << "¡Gracias por jugar a PokeArena!" << endl;
            break;
        }
        default:
        cout << "Ingresa una opcion valida." << endl;
            break;
        }
    }

    return 0;  
}