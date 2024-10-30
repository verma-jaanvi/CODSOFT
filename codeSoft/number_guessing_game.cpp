#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>

int main(){
    int ans=0,tries=0, range=0, gess_num=-1;
    start:
    std::cout <<"------welcome to the number gusessing game-------"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<"HOW TO PLAY:"<<std::endl;
    std::cout<<"I will think of a number between 0 and till the range you give."<<std::endl;
    std::cout<<"You will have to guess the number."<<std::endl;
    std::cout<<"If you guess the number, you win."<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;

    menu:
    std::cout<<"menu:"<<std::endl;
    std::cout<<"1. start game"<<std::endl;
    std::cout<<"2. see the score of your last game."<<std::endl;
    std::cout<<"3. exit game"<<std::endl;
    std::cout<<"--------------------------------------------------"<<std::endl;
    std::cout<<"enter your choice"<<std::endl;
    std::cin>> ans;

    // starting the game
    if(ans==1){
        std::cout<<"the game begins........."<<std::endl;
        std::cout<<"enter the range your number guesses should lie in between...."<<std::endl;
        std::cin>>range;

        // std::srand(time(0));
        // num=std::rand()%(range+1);
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, range);
        int randomVal = distrib(gen);

        do{
            tries=1;
            std::cout<<"enter your guess"<<std::endl;
            std::cin>>gess_num;
            if(gess_num==randomVal){
                std::cout<<"you won, you guessed the number in "<<tries<<" tries!!"<<std::endl;
                goto start;
                break;
            }else if(gess_num>randomVal){
                std::cout<<"your guess is too high"<<std::endl;
            }else if(gess_num<randomVal){
                std::cout<<"your guess is too low"<<std::endl;
            }
            tries++;
        }while(gess_num!=randomVal);
    }
    else if(ans==2){
        if(tries==0){
            std::cout<< "you haven't played the game yet"<<std::endl;
        }else{
            std::cout<<"you guessed the number in "<<tries<<" tries"<<std::endl;
        }
        goto menu;
    }else if(ans==3){
        std::cout<<"thanks for playing"<<std::endl;
        exit(0);
    }
    else{
        std::cout<<"invalid choice...."<<std::endl;
        goto menu;
    }
    
    return 0;
}