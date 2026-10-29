#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include "queueuser.h" 

void mostrarPantallaJuego() {
    clear();
    printw("R B\nY G\nPresiona 'R', 'B', 'Y' o 'G' para cambiar el color.\n");
    refresh();
}

int main() {
    initscr(); 
    cbreak();
    noecho();
    keypad(stdscr, TRUE); 
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK); 
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);

    int continuar = 1;

    Cola* colaLetras = crearCola();
    while (continuar) {
        attron(COLOR_PAIR(0));
        printw("Jugar\nPresiona cualquier tecla para comenzar el juego.\n");
        refresh();

        getch(); // Esperar a que se presione una tecla para iniciar el juego

        mostrarPantallaJuego(); 

        int ch;
        int tiempoEspera = 0; 
        while ((ch = getch()) != 'q') { 
            switch (ch) {
                case 'R': case 'r':
                    encolar(colaLetras, 'R');
                    attron(COLOR_PAIR(1)); 
                    mvprintw(0, 0, "R");
                    refresh();
                    tiempoEspera = 1;
                    break;
                case 'B': case 'b':
                    encolar(colaLetras, 'B'); 
                    attron(COLOR_PAIR(2)); 
                    mvprintw(0, 2, "B"); 
                    refresh();
                    tiempoEspera = 1; 
                    break;
                case 'Y': case 'y':
                    encolar(colaLetras, 'Y'); 
                    attron(COLOR_PAIR(3)); 
                    mvprintw(1, 0, "Y"); 
                    refresh();
                    tiempoEspera = 1; 
                    break;
                case 'G': case 'g':
                    encolar(colaLetras, 'G'); 
                    attron(COLOR_PAIR(4)); 
                    mvprintw(1, 2, "G"); 
                    refresh();
                    tiempoEspera = 1; 
                    break;
                default:
                    
                    attron(COLOR_PAIR(0) | A_BOLD); 
                    mvprintw(3, 0, "Has perdido"); 
                    attroff(A_BOLD); 
                    mvprintw(4, 0, "Jugar de nuevo (J) o Salir (S)"); 
                    refresh();
                    int opcion = getch(); 
                    if (opcion == 'J' || opcion == 'j') {
                        mostrarPantallaJuego(); 
                        tiempoEspera = 0;
                    } else if (opcion == 'S' || opcion == 's') {
                        continuar = 0; 
                        liberarCola(colaLetras); 
                        break;
                    }
                    break;
            }

            if (tiempoEspera) {
                usleep(500000);
                attroff(COLOR_PAIR(1)); 
                attroff(COLOR_PAIR(2));
                attroff(COLOR_PAIR(3));
                attroff(COLOR_PAIR(4));
                mostrarPantallaJuego(); 
                tiempoEspera = 0;
            }
            refresh();
        }
    }

    endwin();
    return 0;
}