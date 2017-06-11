#include "creatures.h"

creatures::creatures(int L, string temp,int i) 
{
    char temp1[10];
    sprintf(temp1, "%d", i);        //Position in society
    this->lifetime = L;
    this->name = temp + temp1;      //Name + position in society
    cout << "Creature has just been created! " << name << endl;
}

int creatures::is_a_zombie()
{
    if (lifetime == 0) return 1;    
    else return 0;
}

int creatures::is_a_good()
{
    cout << "name of good" << name << endl;
}

creatures * creatures::clone()
{
    creatures *temp = NULL;
    temp->name = this->name;
    temp->lifetime = this->lifetime;
    delete this;
}

good_creature * good_creature::clone()
{
    cout << "Clone good creature " << endl;
    get_info();
    return new good_creature(*this);
}

bad_creature * bad_creature::clone()
{
    cout << "clone bad creature " << endl;
    get_info();
    return new bad_creature(*this);
}

void creatures::creature_beat(int bad_thrsh)
{
    cout << "Beat creature " << name <<  endl;
    if (is_a_zombie() == 0)                     //If it isn't a zombie
        lifetime--;                             //Decrease lifetime
}

void creatures::creature_bless(int good_thrsh,int bad_thrsh)
{
    cout << "Bless creature " << name << endl;
    if (is_a_zombie() == 0)                     //Check if creature is a zombie
        lifetime++;
    if (is_a_good() != 0)                       //Check if it's good
        if (lifetime > good_thrsh) creatures *temp = clone();          
    else
        if (lifetime > bad_thrsh) creatures *temp = clone();

}

creature_society::creature_society(int N, int L)        //Construct creature society
{
    int i, num = -1;
    string good[] = {"Ariel","Cherub","Ananchel","Daniel","Gabriel","Elijah","Angel","Forfax"};
    string bad[] = {"Lucifer","Michael","Raphael","Lilith","Succubus ","Cain","Incubus","Kali"};
    name = "Society 1";
    number_of_positions = N;
    creatures_society = new creatures*[number_of_positions];
    for (i = 0; i < N; i++)                                     //Create N creatures
    {
        if (num >= 7) num = 0;
        else num++;
        
        if (i < (N / 2))   creatures_society[i] = new good_creature(L, good[num], i );
        else creatures_society[i] = new bad_creature(L, bad[num], i);
    }   
}

void creatures::get_info()
{
    cout << " " << name << " " << lifetime << endl;
}

void creature_society::beat(int i, int bad_thrsh)   //Beat creature in i position
{
    creatures_society[i]->creature_beat(bad_thrsh);
}

void creature_society::bless(int i, int good_thrsh, int bad_thrsh)      //Bless creature in i position
{
    creatures_society[i]->creature_bless(good_thrsh, bad_thrsh);
}

int creature_society::no_of_good(int N)             //Find the number of good creatures
{
    int i, sum = 0;
    for (i = 0; i < number_of_positions; i++)
        if (creatures_society[i]->is_a_good() == 1) sum++;    //If it's good increase sum
    
    if (sum == N) cout << "Good Dominates in the World!" << endl;       //Only good creatures
    if (sum > 0 && sum < N) cout << "Try again to improve the world" << endl;   //Good and bad creatures exist
    return sum;
}

int creature_society::no_of_zombies(int N)              //Find the number of zombies
{
    int i, sum = 0;
    for (i = 0; i < number_of_positions; i++)
        if (creatures_society[i]->is_a_zombie() == 1) sum++; //If it's a zombie increase sum
    
    if (sum == N) cout << "This is a dead society" << endl;   //Only zombies exist
    return sum;
}

creature_society::~creature_society()           //Destruct society
{
    int i;
    cout << "Destroy society" << endl;
    for (i = 0; i < number_of_positions; i++)
        delete creatures_society[i];
    delete [] creatures_society;
}

int creature_society::no_of_bad()               //Find the number of bad creatures
{
    int i, sum = 0;
    for (i = 0; i < number_of_positions; i++)
        if (creatures_society[i]->is_a_good() == 0) sum++;

    return sum;
}