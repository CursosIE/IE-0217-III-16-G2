
#include "Articuno.h"

Articuno::Articuno(){
    //std::cout<"Constructor Articuno"<<std::endl;
    type = Water::getType() + "/" + Flying::getType();
    strongVs = Water::getStrongVs() + Flying::getStrongVs();
    weakVs= Water::getWeakVs() + Flying::getWeakVs();
    char* tempName = new char[5];  
    gen_random(tempName,4);
    name = tempName;
    delete[] tempName;
    species = "Articuno";
    cry = "PRUNUNFFG";
    HP=90;
    ATK=85;
    DEF=100;
    sATK=95;
    sDEF=125;
    SPD=85;
    EXP=10;
}

Articuno::~Articuno(){
    // std::cout<<"Destructor Articuno"<<std::endl;
}

void Articuno::gen_random(char *s, const int len) {
    static const char alphanum[] =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for (int i= 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    s[len] = 0;
}

std::vector<std::string> Articuno::getTypes(){
    std::vector<std::string> types;
    types.push_back(Water::getType());
    types.push_back(Flying::getType());
    return types;
}


void Articuno::atk1(Pokemon &other){
    std::cout <<name<<":"<<species<<" attack "<<other.name<<":"<<other.species<<std::endl;
    std::cout <<name<<":"<<species<<" used GUST!"<<std::endl;
    int pwr=40;
    int acc=100;
    std::vector<std::string> oType = other.getTypes();
    double mult = 1;
    bool isElectric = false;
    int i = 0;    while (!isElectric && i < 2)
    {      
        if (oType[i].compare("Electricr") == 0){
            std::cout<<"It's not vey effective..."<<std::endl;
            mult=0.5;
            isElectric = true;
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


void Articuno::atk2(Pokemon &other){
    std::cout <<name<<":"<<species<<" attack "<<other.name<<":"<<other.species<<std::endl;
    std::cout <<name<<":"<<species<<" used FREEZE DRY!"<<std::endl;
    int pwr=70;
    int acc=100;
    std::vector<std::string> oType = other.getTypes();
    double mult = 1;
    bool isWater = false;
    bool isFire = false;
    int i = 0;
    while (isWater != isFire && i < 2 )
    {
        if (oType[i].compare("Water") == 0){
            mult=0.5;
            isWater = true;
            std::cout << "It's not very effective..." << std::endl;
        }
        
        if (oType[i].compare("Fire") == 0){
            mult=2;
            isFire = true;
            std::cout << "It's super effective!" << std::endl;
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


void Articuno::atk3(Pokemon &other){
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

void Articuno::atk4(Pokemon &other){
    std::cout <<name<<":"<<species<<" attack "<<other.name<<":"<<other.species<<std::endl;
    std::cout <<name<<":"<<species<<" used BLIZZARD!"<<std::endl;
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
        double mult = 1;
        bool isWater = false;
        bool isFire = false;
        int i = 0;
        //   
        while (isWater != isFire && i < 2 )
        {
            if (oType[i].compare("Water") == 0){
                mult=0.5;
                isWater = true;
                std::cout << "It's not very effective..." << std::endl;
            }
            
            if (oType[i].compare("Fire") == 0){
                mult=2;
                isFire = true;
                std::cout << "It's super effective!" << std::endl;
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

void Articuno::printInf(){
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


