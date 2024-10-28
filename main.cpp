// COMSC-210 | Lab-24 | Jeremiah Ortiz
#include <iostream>
#include <cstdlib> 
#include <fstream>
#include <iomanip>
#include <set>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat> trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(set<Goat> trip);
int main_menu();

void add_goat(set<Goat> &trip, string name[], string color[]) {

    int names = rand() % SZ_NAMES;

    int colors = rand() % SZ_COLORS;

    int ages = rand() % MAX_AGE; 

    Goat goat(name[names], ages, color[colors]); 

    trip.push_back(goat); 

    cout << "Added goat\n"; 
}

void delete_goat(set<Goat> &trip) {

    int i = select_goat(trip); 

    auto a = trip.begin(); 

    advance(a, i -1); 

    trip.erase(a); 

     if (trip.empty()) {

         return;
    }
}

void display_trip(const set<Goat> trip) {

    int c = 1; 

    for (const auto &goat : trip) {

        cout << "[" << c++ << "]" << goat.get_name() << " (" << goat.get_age() << ", " << goat.get_color() << ")" << endl; 
    }

    if (trip.empty()) {

        return; 
    }
}

int select_goat(const set<Goat> trip) {

    display_trip(trip); 

    int c; 

    while (c < 1 || c > trip.size()) {

        cin >> c; 

        cin >> c; 
    }

    return c; 

}

int main_menu() {

    int select; 

    cout << "**GOAT MANAGER 3001** \n" << "[1] Add a goat \n" << "[2] Delete a goat \n" << "[3] List goats \n" << "[4] Quit \n" << "Choice ->"; 
    cin >> select; 

    while (select < 1 || select > 4) {

        cin >> select; 
    }

    return select; 
}

int main() {

    srand(time(0));
    set<Goat> trip; 
    string names[SZ_NAMES]; 
    string colors[SZ_COLORS]; 

    // read & populate arrays for names and colors
    fstream fin("names.txt");
    int i = 0;
    while (fin >> names[i++] && i < SZ_NAMES);
    fin.close();

    fstream fin1("colors.txt");
    i = 0;
    while (fin1 >> colors[i++] && i < SZ_COLORS); 
    fin1.close();

    bool run = true; 

    while (run) {

        switch (main_menu()) {

            case 1: 
                add_goat(trip, names, colors); 

                break; 

            case 2: 
                delete_goat(trip);

                break; 

            case 3: 
                display_trip(trip);

                break; 

            case 4:
                run = false; 

                break; 

        }
    }


    return 0;
}
