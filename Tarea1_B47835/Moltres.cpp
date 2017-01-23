#include "Moltres.h"

Moltres::Moltres(){
    //std::cout<<"Constructor Moltres"<<std::endl;
    type = Fire::getType() + "/" + Flying::getType();
    strongVs = Fire::getStrongVs() + Flying::getStrongVs();
    weakVs= Fire::getWeakVs() + Flying::getWeakVs();
    char* tempName = new char[5];
    gen_random(tempName,4);
    name = tempName;
    delete[] tempName;
    species = "Moltres";
    cry = "FANANANANAG";
    HP=90;
    ATK=100;
    DEF=90;
    sATK=125;
    sDEF=85;
    SPD=90;
    EXP=10;
}

Moltres::~Moltres(){
    // std::cout<<"Destructor Moltres"<<std::endl;
}

void Moltres::gen_random(char *s, const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}


std::vector<std::string> Moltres::getTypes(){
    std::vector<std::string> types;
    types.push_back(Fire::getType());
    types.push_back(Flying::getType());
    return types;
}


void Moltres::atk1(Pokemon &other){
    std::cout <<name<<":"<<species<<" attack "<<other.name<<":"<<other.species<<std::endl;
    std::cout <<name<<":"<<species<<" used SKY ATTACK!"<<std::endl;
    int pwr=140   ;
    int acc=90;
    if(hasMissed(acc))
    {
        std::cout <<name<<":"<<species<< "'s attack missed!" << std::endl;
        std::cout<<"------------------------------------------"<<std::endl;
        std::cout<<""<< std::endl;
        std::cout<<""<< std::endl;
    }
    else
    {
        std::vector<std::string> oType = other.getTypes();
        double mult = 1;
        bool isElectric = false;
        int i = 0;
        while (!isElectric && i < 2)
        {
            if (oType[i].compare("Electric") == 0){
                std::cout<<"It's not very effective..."<<std::endl;
                mult=0.5;
                isElectric = true;
            }
            i++;
        }
        int damage = getDamage(pwr,ATK,DEF,1.5,mult);
        other.HP -= damage;
        std::cout<<"The damage caused by "<<name<<":"<<species<<" to"<<other.name<<":"<<other.species<<" is: "<<damage<<std::endl;  
        std::cout<<"------------------------------------------"<<std::endl;
        std::cout<<""<< std::endl;
        std::cout<<""<< std::endl;
    }
}

void Moltres::atk2(Pokemon &other){
    std::cout <<name<<":"<<species<<" attack "<<other.name<<":"<<other.species<<std::endl;
    std::cout <<name<<":"<<species<<" used FLAMETHROWER!"<<std::endl;
    int pwr=90;
    int acc=100;
    std::vector<std::string> oType = other.getTypes();
    double mult = 2;
    bool isWaterorFire = false;
    int i = 0;
    while (!isWaterorFire && i < 2)
    {
        if (oType[i].compare("Water") == 0 || oType[i].compare("Fire")==0 ){
            mult=0.5;
            isWaterorFire = true;
            std::cout << "It's not very effective!" << std::endl;
        }
        i++;
    }
    
    int damage = getDamage(pwr,sATK,sDEF,1.5,mult);
    other.HP -= damage;
    std::cout<<"The damage caused by "<<name<<":"<<species<<" to"<<other.name<<":"<<other.species<<" is: "<<damage<<std::endl;  
    std::cout<<"------------------------------------------"<<std::endl;
    std::cout<<""<< std::endl;
    std::cout<<""<< std::endl;
}


void Moltres::atk3(Pokemon &other){
    std::cout <<name<<":"<<species<<" attack "<<other.name<<":"<<other.species<<std::endl;
    std::cout <<name<<":"<<species<<" used HURRICANE!"<<std::endl;
    int pwr=110;
    int acc=70;
    if(hasMissed(acc))
    {
        std::cout <<name<<":"<<species<<"'s attack missed!" << std::endl;
        std::cout<<"------------------------------------------"<<std::endl;
        std::cout<<""<< std::endl;
        std::cout<<""<< std::endl;
    }
    else
    {
        std::vector<std::string> oType = other.getTypes();
        double mult = 2;
        bool isElectric = false;
        int i = 0;
        while (!isElectric && i < 2)
        {
            if (oType[i].compare("Electric") == 0){
                mult=0.5;
                isElectric = true;
                std::cout << "It's not very effective..." << std::endl;
            }
            i++;
        }

        int damage = getDamage(pwr,sATK,sDEF,1.5,mult);
        other.HP -= damage;
        std::cout<<"The damage caused by "<<name<<":"<<species<<" to"<<other.name<<":"<<other.species<<" is: "<<damage<<std::endl;  
        std::cout<<"------------------------------------------"<<std::endl;
        std::cout<<""<< std::endl;
        std::cout<<""<< std::endl;
    }
}

void Moltres::atk4(Pokemon &other){
    std::cout <<name<<":"<<species<<" attack "<<other.name<<":"<<other.species<<std::endl;
    std::cout <<name<<":"<<species<<" used BURNED UP!"<<std::endl;
    int pwr=130;
    int acc=100;
    double mult=1;
    std::vector<std::string> oType = other.getTypes();
    bool isWaterorFire = false;
    int i = 0;
    while (!isWaterorFire && i < 2)
    {
        if (oType[i].compare("Water") == 0 || oType[i].compare("Fire")==0 ){
            mult=0.5;
            isWaterorFire = true;
            std::cout << "It's not very effective!" << std::endl;
        }
        i++;
    }
    int damage = getDamage(pwr,sATK,sDEF,1.5,mult);
    other.HP -= damage;
    std::cout<<"The damage caused by "<<name<<":"<<species<<" to"<<other.name<<":"<<other.species<<" is: "<<damage<<std::endl;  
    std::cout<<"------------------------------------------"<<std::endl;
    std::cout<<""<< std::endl;
    std::cout<<""<< std::endl;
}


void Moltres::printInf(){
    std::cout<<"Name:  "<< name <<std::endl;
    std::cout<<"Species: "<< species <<std::endl;
    std::cout<<"HP:  "<< HP <<std::endl;
    std::cout<<"ATK:  "<< ATK <<std::endl;
    std::cout<<"DEF: "<< DEF <<std::endl;
    std::cout<<"sATK: "<< sATK <<std::endl;
    std::cout<<"sDEF: "<< sDEF <<std::endl;
    std::cout<<"SPD: "<< SPD <<std::endl;
    std::cout<<"EXP: "<< EXP <<std::endl;
    std::cout<<"cry: "<< cry <<std::endl;
    std::cout<<"------------------------------------------"<<std::endl;
    std::cout<<""<< std::endl;
    std::cout<<""<< std::endl;
}