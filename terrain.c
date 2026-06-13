#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define blue "0 0 255 "
#define green "0 255 0 "
#define yellow "255 255 0 "

int main() {

    srand(time(NULL));
    int lx = 100, ly = 100;

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
        }
        
    }

    //random dots set
    int num_of_dots = 100;
    int randomy = rand() % ly;
    int randomx = rand() % lx;
    int spectr = 10;

    for (int z = 0; z < num_of_dots; z++) 
    {
        randomy += ((rand() % spectr*2 + 2)-spectr);
        randomx += ((rand() % spectr*2 + 2)-spectr); 
        if (randomx < lx && randomx > 0 && randomy < ly && randomy > 0) map[randomy][randomx] = green;
        else 
        {
            randomy = rand() % ly;
            randomx = rand() % lx;
        }
    }

    //sand
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

    //write to the file
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

    //free
    for (int y = 0; y < ly; y++)
    {
        free(map[y]);
    }
    free(map);
    
    return 0;
}
