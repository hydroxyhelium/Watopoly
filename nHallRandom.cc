#include "nHallRandom.h"

NH_Cases NHall_Card_Generator(float seed){
    if (NH_DECK.size() == 0){
        for(int i = 0; i < 2;++i){
            NH_DECK.emplace_back(NH_Cases::N100);
            NH_DECK.emplace_back(NH_Cases::P100);
        }
        for(int i = 0; i <  3;++i){
            NH_DECK.emplace_back(NH_Cases::N50);
            NH_DECK.emplace_back(NH_Cases::P50);
        }
        for(int i = 0; i <  6;++i){
            NH_DECK.emplace_back(NH_Cases::P25);
        }
        NH_DECK.emplace_back(NH_Cases::P200);
        NH_DECK.emplace_back(NH_Cases::N200);
    }
    std::default_random_engine rng{seed};
    std::shuffle( NH_DECK.begin(), NH_DECK.end(), rng );
    NH_Cases retval =  NH_DECK.back();
    NH_DECK.pop_back();
    return retval;
}