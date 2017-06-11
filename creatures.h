#ifndef CREATURES_H
#define	CREATURES_H
#include <string>
#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class creatures {
public:
    creatures(int L, string temp,int i);
    ~creatures(){ cout << "destroying a creature" << endl;};
    void creatures_attitude(int L);
    int is_a_zombie();
    virtual int is_a_good();
    virtual creatures * clone();
    void creature_beat(int bad_thrsh);
    void creature_bless(int good_thrsh,int bad_thrsh);
    void get_info();
private:
    string name;
    int lifetime;
};


class good_creature:public creatures{
public:
    good_creature(int L, string temp,int i):creatures(L, temp, i){};
    ~good_creature(){ cout << "destroying an good creature" << endl;};
    int is_a_good() {return true;};
    virtual good_creature * clone();    
};

class bad_creature:public creatures{
public:
    bad_creature(int L, string temp,int i):creatures(L, temp, i){};
    ~bad_creature(){ cout << "destroying a bad creature" << endl;};
    int is_a_good(){return false;};
    virtual bad_creature * clone();  
};

class creature_society{
public:
    creature_society(int N, int L);
    ~creature_society();
    void beat(int i, int bad_thrsh);
    void bless(int i,int good_thrsh,int bad_thrsh);
    void get_info();
    int no_of_good(int N);
    int no_of_bad();
    int no_of_zombies(int N);
private:
    int number_of_positions ;
    int initial_position;
    string name;
    class creatures **creatures_society;
};

#endif	/* CREATURES_H */

