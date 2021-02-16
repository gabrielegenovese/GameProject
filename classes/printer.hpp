#ifndef PRINTER_H_INCLUDED
#define PRINTER_H_INCLUDED

void startDraw();
void endDraw();
void setPlayerRoom(const char *name, int n, int time);
void my_print(int x, int y, char ch);
void drawRect(int startX, int startY, int mlength, int mheigth);
void printUI(const char *name, int room, int time, int points, int life, int strength, const char *weapon, const char *r_name[], int r_points[], int x_offset, int y_offset);
void print_room(char ** cont, int x, int y, int heigth, int width);
void print_string(int x, int y, const char* s);
void print_number(int x, int y, int n);
//da implementare
//void printRoom(char **room);  -> stampa la stanza di gioco


#endif