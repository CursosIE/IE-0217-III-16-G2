#include "Zapdos.h"

Zapdos::Zapdos(){
    //std::cout<<"Constructor Zapdos"<<std::endl;
    type = Electric::getType() + "/" + Flying::getType();
    strongVs = Electric::getStrongVs() + Flying::getStrongVs();
    weakVs= Electric::getWeakVs() + Flying::getWeakVs();
    char* tempName = new char[5];
    gen_random(tempName,4);
    name = tempName;
    delete[] tempName;
    species = "Zapdos";
    cry = "TUNUNUNUN";
    HP=90;
    ATK=90;
    DEF=85;
    sATK=125;
    sDEF=90;
    SPD=100;
    EXP=10;
}

Zapdos::~Zapdos(){
    // std::cout<<"Destructor Zapdos"<<std::endl;
}

void Zapdos::gen_random(char *s, const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}


std::vector<std::string> Zapdos::getTypes(){
    std::vector<std::string> types;
    types.push_back(Electric::getType());
    types.push_back(Flying::getType());
    return types;
}


void Zapdos::atk1(Pokemon &other){
    std::cout <<name<<":"<<species<<" attack "<<other.name<<":"<<other.species<<std::endl;
    std::cout <<name<<":"<<species<<" used DRILL PECK!"<<std::endl;
    int pwr=80;
    int acc=100;
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

    other.HP = other.HP - damage;
    std::cout<<"The damage caused by "<<name<<":"<<species<<" to"<<other.name<<":"<<other.species<<" is: "<<damage<<std::endl;  
    std::cout<<"------------------------------------------"<<std::endl;
    std::cout<<""<< std::endl;
    std::cout<<""<< std::endl;
}


void Zapdos::atk2(Pokemon &other){
    std::cout <<name<<":"<<species<<" attack "<<other.name<<":"<<other.species<<std::endl;
    std::cout <<name<<":"<<species<<" used THUNDER SHOCK!"<<std::endl;
    int pwr=40;
    int acc=100;
    std::vector<std::string> oType = other.getTypes();
    double mult = 2;
    bool isWater = false;
    int i = 0;
    while (!isWater && i < 2)
    {
        if (oType[i].compare("Water") == 0){
            mult=4;
            isWater = true;
        }
        i++;
    }
    std::cout << "It's super effective!" << std::endl;

    int damage = getDamage(pwr,sATK,sDEF,1.5,mult);
    other.HP = other.HP - damage;
    std::cout<<"The damage caused by "<<name<<":"<<species<<" to"<<other.name<<":"<<other.species<<" is: "<<damage<<std::endl;  
    std::cout<<"------------------------------------------"<<std::endl;
    std::cout<<""<< std::endl;
    std::cout<<""<< std::endl;
}

void Zapdos::atk3(Pokemon &other){
    std::cout <<name<<":"<<species<<" attack "<<other.name<<":"<<other.species<<std::endl;
    std::cout <<name<<":"<<species<<" used ZAP CANNON!"<<std::endl;
    int pwr=120;
    int acc=50;
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
        double mult = 2;
        bool isWater = false;
        int i = 0;
        while (!isWater && i < 2)
        {
            if (oType[i].compare("Water") == 0){
                mult=4;
                isWater = true;
            }
            i++;
        }
        std::cout << "It's super effective!" << std::endl;
        int damage = getDamage(pwr,sATK,sDEF,1.5,mult);
        other.HP -= damage;
        std::cout<<"The damage caused by "<<name<<":"<<species<<" to"<<other.name<<":"<<other.species<<" is: "<<damage<<std::endl;  
        std::cout<<"------------------------------------------"<<std::endl;
        std::cout<<""<< std::endl;
        std::cout<<""<< std::endl;
    }  
}

void Zapdos::atk4(Pokemon &other){
    std::cout <<name<<":"<<species<<" attack "<<other.name<<":"<<other.species<<std::endl;
    std::cout <<name<<":"<<species<<" used THUNDER!"<<std::endl;
    int pwr=110;
    int acc=70;
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
        double mult = 2;
        bool isWater = false;
        int i = 0;
        while (!isWater && i < 2)
        {
            if (oType[i].compare("Water") == 0){
                mult=4;
                isWater = true;
            }
            i++;
        }
        std::cout << "It's super effective!" << std::endl;
        int damage = getDamage(pwr,sATK,sDEF,1.5,mult);
        other.HP -= damage;
        std::cout<<"The damage caused by "<<name<<":"<<species<<" to"<<other.name<<":"<<other.species<<" is: "<<damage<<std::endl;  
        std::cout<<"------------------------------------------"<<std::endl;
        std::cout<<""<< std::endl;
        std::cout<<""<< std::endl;
    }
}

void Zapdos::printInf(){
    std::cout<<"Name:  "<< name <<std::endl;
    std::cout<<"Species: "<< species <<std::endl;
    std::cout<<"HP:  "<< HP <<std::endl;
    std::cout<<"ATK:  "<< ATK <<std::endl;
    std::cout<<"DEF: "<< DEF <<std::endl;
    std::cout<<"sATK: "<< sATK <<std::endl;
    std::cout<<"sDEF: "<< sDEF <<std::endl;
    std::cout<<"SPD: "<< SPD <<std::endl;
    std::cout<<"EXP: "<< EXP <<std::endl;
    std::cout<<"cry: "<< cry <<std::endl;  std::cout<<"------------------------------------------"<<std::endl;
    std::cout<<""<< std::endl;
    std::cout<<""<< std::endl;
}


