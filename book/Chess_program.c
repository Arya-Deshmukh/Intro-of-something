#include <stdio.h>
#include <string.h>
void checkpos1(char (*a)[8][8][2], char p, char c1, int r1, char c2, int r2, int numero);
void knightcon(char c1, int r1, char c2, int r2, int* count);
void bpawncon(char a[8][8][2], char c1, int r1, char c2, int r2, int* count, int numero);
void wpawncon(char a[8][8][2], char c1, int r1, char c2, int r2, int* count, int numero);
void bishop(char a[8][8][2], char c1, int r1, char c2, int r2, int* count, int numero);
void display(char (*y)[8][8][2]) {
    printf("    A    B    C    D    E    F    G    H\n\n");
    for (int i = 0; i < 8; i++) {
        printf("%d  ", 8-(i));
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                printf(" %c", *y[i][j][0]);
                printf("%c  ", *y[i][j][1]);
            }
            else {
                printf("[%c", *y[i][j][0]);
                printf("%c] ", *y[i][j][1]);
            }
        }
        printf("\n");
        printf("\n");
    }
}
int equate(char r) {
    int rg = 8;
    if (r == 'A' || r == 'a')
        rg = 0;
    else if (r == 'B' || r == 'b')
        rg = 1;
    else if (r == 'C' || r == 'c')
        rg = 2;
    else if (r == 'D' || r == 'd')
        rg = 3;
    else if (r == 'E' || r == 'e')
        rg = 4;
    else if (r == 'F' || r == 'f')
        rg = 5;
    else if (r == 'G' || r == 'g')
        rg = 6;
    else if (r == 'H' || r == 'h')
        rg = 7;
    return rg;
}
void knightcon(char c1, int r1, char c2, int r2, int* count) {
    int x = equate(c1), y = equate(c2);
    if (((r2 == (r1 + 1)) && (y=x+2)) || ((r2 == (r1 - 1)) && (y=x+2)) || ((r2 == (r1 - 1)) && (y=x-2)) || ((r2 == (r1 + 1)) && (y = x - 2)) || ((r2 == (r1 + 2)) && (y=x+1)) || ((r2 == (r1 - 2)) && (y=x+1)) || ((r2 == (r1 - 2)) && (y = x - 1)) || ((r2 == (r1 + 2)) && (y = x - 1))) {
        *count = 3;
    }
    else {
        printf("wrong move for knight\n");
    }
}
void bpawncon(char a[8][8][2], char c1, int r1, char c2, int r2, int* count, int numero) {
    if (numero == 2) {
        if ((r2 == (r1 + 1) && c2 == c1) || (r2 == (r1 + 2) && c2 == c1)) {
            *count += 1;
        }
        else
            printf("Wrong move for pawn\n");
    }
    else {
        if ((r2 == (r1 + 1) && c2 == c1)) {
            *count += 1;
        }
        else if ((r2 == (r1 + 1) && (equate(c2) == (equate(c1) + 1))) || (r2 == (r1 + 1) && (equate(c2) == (equate(c1) - 1)))) {
            if (a[r2][equate(c2)][0] == 'W') {
                *count += 1;
            }
            else
                printf("Wrong move for pawn\n");
        }
        else
            printf("Wrong move for pawn\n");
    }

}
void wpawncon(char a[8][8][2], char c1, int r1, char c2, int r2, int* count, int numero) {
    if (numero == 1) {
        if ((r2 == (r1 - 1) && c2 == c1) || (r2 == (r1 - 2) && c2 == c1)) {
            *count =3;
        }
        else
            printf("Wrong move for pawn\n");
    }
    else {
        if ((r2 == (r1 - 1) && c2 == c1)) {
            *count =3;
        }
        else if ((r2 == (r1 - 1) && (equate(c2) == (equate(c1) + 1))) || (r2 == (r1 - 1) && (equate(c2) == (equate(c1) - 1)))) {
            printf("works");
            if (a[r2][equate(c2)][0] == 'W') {
                *count =3;
            }
            else
                printf("Wrong move for pawn\n");
        }
        else
            printf("Wrong move for pawn\n");
    }
}
void bishop(char a[8][8][2], char c1, int r1, char c2, int r2, int* count, int numero) {
    int g=0;
    int x = equate(c1);
    int y = equate(c2);
    if ((r2 - r1) == (equate(c2) - equate(c1)) || (r2 - r1) == (equate(c1) - equate(c2))) {
        if (1==1) {
            if (r2 - r1 > 0) {
                if (equate(c2) - equate(c1) > 0) {
                    while (r1 != r2 - 1) {
                        if ((a[r1][x][0] == 'B') || (a[r1][x][0] == 'W')) {
                            printf("Wrong move for bishop\n");
                            g = 0;
                            break;
                        }
                        else {
                            g = 1;
                            r1 += 1;
                            x += 1;
                        }
                           
                    }
                }
                else {
                    while (r1 != r2 - 1) {
                        if ((a[r1][x][0] == 'B') || (a[r1][x][0] == 'W')) {
                            printf("Wrong move for bishop\n");
                            g = 0;
                            break;
                        }
                        else {
                            g = 1;
                            r1 += 1;
                            x -= 1;
                        }
                            
                    }
                }
            }
            else {
                if (equate(c2) - equate(c1) > 0) {
                    while (r1 != r2 - 1) {
                        if ((a[r1][x][0] == 'B') || (a[r1][x][0] == 'W')) {
                            printf("Wrong move for bishop\n");
                            g = 0;
                            break;
                        }
                        else {
                            g = 1;
                            r1 -= 1;
                            x += 1;
                        }
                            
                    }
                }
                else {
                    while (r1 != r2 - 1) {
                        if ((a[r1][x][0] == 'B') || (a[r1][x][0] == 'W')) {
                            printf("Wrong move for bishop\n");
                            g = 0;
                            break;
                        }
                        else {
                            g = 1;
                            r1 -= 1;
                            x -= 1;
                        }
                       
                    }
                }
            }
        }
    }
    else
        printf("Wrong move for bishop\n");
    if (g == 1) {
        (*count) += 1;
    }
}
//numero is the count of moves like if move = 1 then even moves for black and odd for white//
/*
void checkpos1(char a[8][8][2],char p, char c1, int r1, char c2, int r2, int numero) {
    int count = 0;
    r1 -= 1;
    if (numero % 2 == 0) {
        if (a[r1][equate(c1)][0] == 'B') {
            if (a[r1][equate(c1)][1] == p) {
                count = 1;
            }
            else {
                printf("%c piece is not ther in the given position.\n ", p);
            }
        }
    }
    else {
        if (a[r1][equate(c1)][0] == 'W') {
            if (a[r1][equate(c1)][1] == p) {
                count = 1;
            }
            else {
                printf("%c piece is not ther in the given position.\n ", p);
            }
        }
    }
    if (count == 1) {
        if (numero % 2 == 0) {
            if (a[r2][equate(c2)][0] == 'B') {
                printf("You cant hit yout own piece");
            }
            else {
                count = 2;
            }
        }
        else {
            if (a[r2][equate(c2)][0] == 'W') {
                printf("You cant hit yout own piece");
            }
            else {
                count = 2;
            }
    }
}*/
void checkpos1(char (*a)[8][8][2], char p, char c1, int r1, char c2, int r2, int numero) {
    int count = 0;
    r1 = 8-r1;
    r2 = 8-r2;
    if (numero % 2 == 0) {
        if (*a[r1][equate(c1)][0] == 'B') {
            if (*a[r1][equate(c1)][1] == p) {
                count = 1;
            }
            else {
                printf("%c piece is not ther in the given position.\n ", p);
            }
        }
    }
    
    else {
        if (*a[r1][equate(c1)][0] == 'W') {
            if (*a[r1][equate(c1)][1] == p) {
                count = 1;
            }
            else {
                printf("%c piece is not ther in the given position.\n ", p);
            }
        }
    }
    
    if (count == 1) {
        if (numero % 2 == 0) {
            if (*a[r2][equate(c2)][0] == 'B') {
                printf("You cant hit your own piece\n");
            }
            else {
                count = 2;
            }
        }
        else {
            if (*a[r2][equate(c2)][0] == 'W') {
                printf("You cant hit your own piece\n");
            }
            else {
                count = 2;
            }
        }
    }
    if (count == 2) {
        if (p == 'N') {
            knightcon(c1, r1, c2, r2, &count);
            if (count == 3) {
                *a[r2][equate(c2)][0] = *a[r1][equate(c1)][0];
                *a[r2][equate(c2)][1] = *a[r1][equate(c1)][1];
                *a[r1][equate(c1)][1] = ' ';
                *a[r1][equate(c1)][0] = ' ';
            }
            else {
                printf("Not a valid move");
            }
        }
        else if (p == 'P') {
            if (numero % 2 == 0) {
                bpawncon(*a, c1, r1, c2, r2, &count, numero);
                if (count == 3) {
                    *a[r2][equate(c2)][0] = *a[r1][equate(c1)][0];
                    *a[r2][equate(c2)][1] = *a[r1][equate(c1)][1];
                    *a[r1][equate(c1)][1] = ' ';
                    *a[r1][equate(c1)][0] = ' ';

                }
                
            }
            else {
                wpawncon(*a, c1, r1, c2, r2, &count, numero);
                if (count == 3) {
                    *a[r2][equate(c2)][0] = *a[r1][equate(c1)][0];
                    *a[r2][equate(c2)][1] = *a[r1][equate(c1)][1];
                    *a[r1][equate(c1)][1] = ' ';
                    *a[r1][equate(c1)][0] = ' ';
                    
                }
                
            }

        }
        else if (p == 'B') {
            bishop(*a, c1, r1, c2, r2, &count, numero);
            if (count == 3) {
                *a[r2][equate(c2)][0] = *a[r1][equate(c1)][0];
                *a[r2][equate(c2)][1] = *a[r1][equate(c1)][1];
                *a[r1][equate(c1)][1] = ' ';
                *a[r1][equate(c1)][0] = ' ';
            }
        }
    }
}


void initial(char (*a)[8][8][2]) {
	*a[0][0][0] = 'B';
    *a[0][0][1] = 'R';
    *a[0][1][0] = 'B';
    *a[0][1][1] = 'N';
    *a[0][2][0] = 'B';
    *a[0][2][1] = 'B';
    *a[0][3][0] = 'B';
    *a[0][3][1] = 'Q';
    *a[0][4][0] = 'B';
    *a[0][4][1] = 'K';
    *a[0][5][1] = 'B';
    *a[0][5][0] = 'B';
    *a[0][6][0] = 'B';
    *a[0][6][1] = 'N';
    *a[0][7][0] = 'B';
    *a[0][7][1] = 'R';
    *a[1][0][0] = 'B';
    *a[1][0][1] = 'P';
    *a[1][1][0] = 'B';
    *a[1][1][1] = 'P';
    *a[1][2][0] = 'B';
    *a[1][2][1] = 'P';
    *a[1][3][0] = 'B';
    *a[1][3][1] = 'P';
    *a[1][4][0] = 'B';
    *a[1][4][1] = 'P';
    *a[1][5][0] = 'B';
    *a[1][5][1] = 'P';
    *a[1][6][0] = 'B';
    *a[1][6][1] = 'P';
    *a[1][7][0] = 'B';
    *a[1][7][1] = 'P';
    *a[2][0][0] = ' ';
    *a[2][0][1] = ' ';
    *a[2][1][0] = ' ';
    *a[2][1][1] = ' ';
    *a[2][2][0] = ' ';
    *a[2][2][1] = ' ';
    *a[2][3][0] = ' ';
    *a[2][3][1] = ' ';
    *a[2][4][0] = ' ';
    *a[2][4][1] = ' ';
    *a[2][5][0] = ' ';
    *a[2][5][1] = ' ';
    *a[2][6][0] = ' ';
    *a[2][6][1] = ' ';
    *a[2][7][0] = ' ';
    *a[2][7][1] = ' ';
    *a[3][0][0] = ' ';
    *a[3][0][1] = ' ';
    *a[3][1][0] = ' ';
    *a[3][1][1] = ' ';
    *a[3][2][0] = ' ';
    *a[3][2][1] = ' ';
    *a[3][3][0] = ' ';
    *a[3][3][1] = ' ';
    *a[3][4][0] = ' ';
    *a[3][4][1] = ' ';
    *a[3][5][0] = ' ';
    *a[3][5][1] = ' ';
    *a[3][6][0] = ' ';
    *a[3][6][1] = ' ';
    *a[3][7][0] = ' ';
    *a[3][7][1] = ' ';
    *a[4][0][0] = ' ';
    *a[4][0][1] = ' ';
    *a[4][1][0] = ' ';
    *a[4][1][1] = ' ';
    *a[4][2][0] = ' ';
    *a[4][2][1] = ' ';
    *a[4][3][0] = ' ';
    *a[4][3][1] = ' ';
    *a[4][4][0] = ' ';
    *a[4][4][1] = ' ';
    *a[4][5][0] = ' ';
    *a[4][5][1] = ' ';
    *a[4][6][0] = ' ';
    *a[4][6][1] = ' ';
    *a[4][7][0] = ' ';
    *a[4][7][1] = ' ';
    *a[5][0][0] = ' ';
    *a[5][0][1] = ' ';
    *a[5][1][0] = ' ';
    *a[5][1][1] = ' ';
    *a[5][2][0] = ' ';
    *a[5][2][1] = ' ';
    *a[5][3][0] = ' ';
    *a[5][3][1] = ' ';
    *a[5][4][0] = ' ';
    *a[5][4][1] = ' ';
    *a[5][5][0] = ' ';
    *a[5][5][1] = ' ';
    *a[5][6][0] = ' ';
    *a[5][6][1] = ' ';
    *a[5][7][0] = ' ';
    *a[5][7][1] = ' ';
    *a[6][0][0] = 'W';
    *a[6][0][1] = 'P';
    *a[6][1][0] = 'W';
    *a[6][1][1] = 'P';
    *a[6][2][0] = 'W';
    *a[6][2][1] = 'P';
    *a[6][3][0] = 'W';
    *a[6][3][1] = 'P';
    *a[6][4][0] = 'W';
    *a[6][4][1] = 'P';
    *a[6][5][0] = 'W';
    *a[6][5][1] = 'P';
    *a[6][6][0] = 'W';
    *a[6][6][1] = 'P';
    *a[6][7][0] = 'W';
    *a[6][7][1] = 'P';
    *a[7][0][0] = 'W';
    *a[7][0][1] = 'R';
    *a[7][1][0] = 'W';
    *a[7][1][1] = 'N';
    *a[7][2][0] = 'W';
    *a[7][2][1] = 'B';
    *a[7][3][0] = 'W';
    *a[7][3][1] = 'Q';
    *a[7][4][0] = 'W';
    *a[7][4][1] = 'K';
    *a[7][5][0] = 'W';
    *a[7][5][1] = 'B';
    *a[7][6][0] = 'W';
    *a[7][6][1] = 'N';
    *a[7][7][0] = 'W';
    *a[7][7][1] = 'R';

}
void main() {
	char a[8][8][2];
    char c1, c2;
    int r1, r2,numero=1;
    char p;
    initial(&a);
	display(&a);
    while (1 == 1) {
        printf("Pls enter the chess piece you want to move: ");
        scanf_s(" %c", &p, 1);
        printf("Pls enter location of your piece:\nRow: ");
        scanf_s("%d", &r1);
        printf("Column: ");
        scanf_s(" %c", &c1, 1);
        printf("Pls enter final location of your piece:\nRow: ");
        scanf_s("%d", &r2);
        printf("Column: ");
        scanf_s(" %c", &c2, 1);
        checkpos1(&a, p, c1, r1, c2, r2, numero);
        display(&a);
        numero += 1;
    }

}