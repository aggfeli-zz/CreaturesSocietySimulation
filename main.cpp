#include <cstdlib>
#include "creatures.h"



int main(int argc, char** argv) 
{
    int N, M, L, good_thrsh, bad_thrsh, i, num;
    
    if (argv[1] != NULL && argv[2] != NULL && argv[3] != NULL && argv[4] != NULL && argv[5] != NULL)
    {
        N = atoi(argv[1]);
        M = atoi(argv[2]);
        L = atoi(argv[3]);
        good_thrsh = atoi(argv[4]);
        bad_thrsh = atoi(argv[5]);
    }
    else
    {
        N = 20;
        M = 30;
        L = 2;
        good_thrsh = 4;
        bad_thrsh = 5;
    }
    
 
    creature_society society(N, L);         //Construct creatures society
    
    for (i = 0; i < M; i++)
    {
        if (i < N) num = i;             //Choose position-it must be < N
        else if (i == N) num = 0;
        else num++;
        
        if ((num % 2) != 0) society.bless(num, good_thrsh, bad_thrsh);      //Bless or
        else society.beat(num,bad_thrsh);                                   //Beat

    }
    
    cout << "No of good creatures " << society.no_of_good(N) << endl;       //Return no of good creatures
    
    cout << "No of bad creatures " << society.no_of_bad() << endl;          //Return no of bad creatures
    
    cout << "No of zombies " << society.no_of_zombies(N) << endl;           //Return no of zombies
    
    return 0;
}

