#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//🟥 🟦 🟩 🟨 🟧 🟪 ⬛ ⬜ 🟫
#define red "🟥"
#define blue "🟦"
#define green "🟩"
#define yellow "🟨"
#define orange "🟧"
#define purple "🟪"
#define black "⬛"
#define white "⬜"
#define brown "🟫"



int main() {

    srand(time(NULL));
    int lx = 30, ly = 20;
    char *map[lx][ly];

    for (int y = 0; y<ly; y++) {

    for (int x = 0; x<lx; x++) {
        

        map[y][x] = blue;

        if (rand() % 10 + 1 == 1) map[x][y] = green;

        if (x,y != 0 && (map[y][x-1] == green || map[y-1][x] == green) && rand() % 2 + 1 == 1)
            map[y][x] = green;


        
        printf("%s", map[y][x]);

    }
    printf("\n");
    }

    
    
    return 0;
}
