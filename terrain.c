#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//🟥 🟦 🟩 🟨 🟧 🟪 ⬛ ⬜ 🟫
#define red "🟥"
#define blue "0 0 255 "
#define green "0 255 0 "
#define yellow "255 255 0 "
#define orange "🟧"
#define purple "🟪"
#define black "⬛"
#define white "⬜"
#define brown "🟫"



int main() {

    srand(time(NULL));
    int lx = 50, ly = 50;
    //char *map[lx][ly];

    char ***map = malloc(ly * sizeof(char **));

    for (int y = 0; y < ly; y++)
    {
        map[y] = malloc(lx * sizeof(char *));
    }

    //First run
    for (int y = 0; y<ly; y++) 
    {
        for (int x = 0; x<lx; x++) 
        {
            map[y][x] = blue;

            if (rand() % (lx+ly)/4  + 1 == 1) map[x][y] = green;
        }
        
    }

    for (int y = 0; y<ly; y++) 
    {
        for (int x = 0; x<lx; x++) 
        {
            if (x > 0 &&
                x < lx-1 && 
                y > 0 && 
                y < ly-1 &&
                (map[y][x-1] != blue ||
                map[y-1][x-1] != blue || 
                map[y-1][x] != blue || 
                map[y-1][x+1] != blue || 
                map[y][x+1] != blue || 
                map[y+1][x+1] != blue  || 
                map[y+1][x]  != blue ||
                map[y+1][x-1] != blue ) &&
                rand() % 2 + 1 == 1)
                map[y][x] = green;
        }
        
    }

    //third run (sand)
    for (int y = 0; y<ly; y++) 
    {
        for (int x = 0; x<lx; x++) 
        {
            
            if (x > 0 &&
                x < lx-1 && 
                y > 0 && 
                y < ly-1 &&
                (map[y][x-1] == blue ||
                map[y-1][x-1] == blue || 
                map[y-1][x] == blue || 
                map[y-1][x+1] == blue || 
                map[y][x+1] == blue || 
                map[y+1][x+1]== blue  || 
                map[y+1][x] == blue ||
                map[y+1][x-1]== blue ) && 
                map[y][x] != blue && 
                rand() % 4 + 1 == 1)
                map[y][x] = yellow;
        }
    }

    //write to the console
    FILE *fm = fopen("map.ppm", "w");
    fprintf(fm, "P3\n%d %d\n255\n", lx, ly);

    for (int y = 0; y<ly; y++) 
    {
        for (int x = 0; x<lx; x++) 
        {
            fprintf(fm, "%s", map[y][x]);
        }
        fprintf(fm,"\n");
    }
    fclose(fm);

    for (int y = 0; y < ly; y++)
    {
        free(map[y]);
    }

    free(map);
    
    return 0;
}
