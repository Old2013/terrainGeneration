#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define blue "0 0 255 "
#define green "0 255 0 "
#define yellow "255 255 0 "

int main() {

    srand(time(NULL));
    int lx = 1000, ly = 1000;
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
        }
        
    }

    //random dots set

    ///to expirement////
    int num_of_dots = rand() % 100;
    int num_of_islands = 5; 
    int spectr = 50;
    int clean = 25;
    ////////////////////

    for (int a = 0; a<num_of_islands ; a++)
    {
        int randomy = rand() % ly;
        int randomx = rand() % lx;

        for (int z = 0; z < num_of_dots; z++) 
        {
            randomy += ((rand() % spectr*2 + 2)-spectr);
            randomx += ((rand() % spectr*2 + 2)-spectr); 
            if (randomx < lx && randomx > 0 && randomy < ly && randomy > 0)
            { 
                map[randomy][randomx] = green;
                for (int y = spectr*-1; y<spectr ; y++)
                {
                    for (int x = spectr*-1; x<spectr ; x++)
                    {
                        if (randomx+x < lx && randomx+x > 0 && randomy+y < ly && randomy+y > 0) map[randomy+y][randomx+x] = green;
                    }
                }

            }else 
            {
                randomy = rand() % ly;
                randomx = rand() % lx;
            }
        }
    }

    //post product
    
    for (int c = 0; c<clean-1 ; c++)
    {
        for (int y = 0; y<ly ; y++)
        {
            for (int x = 0; x<lx ; x++)
            {
                if (x > 0 &&
                    x < lx-1 && 
                    y > 0 && 
                    y < ly-1 &&
                    map[y][x] != blue &&
                    (map[y][x-1] == blue ||
                    map[y-1][x] == blue ||
                    map[y][x+1] == blue ||
                    map[y+1][x] == blue) &&
                    rand() % 2 + 1 == 1) 
                    map[y][x] = blue;
            }
        }
    }

    int prob = 0;
    
    
    for (int y = 0; y<ly ; y++) 
    {
        for (int x = 0; x<lx ; x++)
        {
            if (x > 0 &&
                x < lx-1 && 
                y > 0 && 
                y < ly-1)
            {
                prob = 0;
                if (map[y][x-1] == blue) prob++;
                if (map[y-1][x] == blue) prob++;
                if (map[y][x+1] == blue) prob++;
                if (map[y+1][x] == blue) prob++;

                if (prob >= 3) map[y][x] = blue;
                    
            }
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
