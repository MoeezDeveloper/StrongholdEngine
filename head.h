#pragma once
#include <string>
#include <fstream>
#include <stdexcept>
#include <memory>

using namespace std;

// Base class 
class Leader {
public:
    virtual void applyPolicy(double* tax_rate, double* morale) = 0; 
    virtual ~Leader() = default; 
};


template <typename T>
class Resource {
public:
    T quantity;
    Resource() : quantity(0) {}
    void setQuantity(T q) { quantity = q; }
    T getQuantity() const { return quantity; }
};

class people {
public:
    int total_population;
    int happy_level;
    people();
    void newpeopl();
};

class Soldiers {
public:
    int soldier_count;
    double morale;
    Soldiers();
    void addsoldr(int count, int total_population, class Resources* resources); 
    void train(); 
    void paySoldiers(double funds); 
    void craftWeapons(class Resources* resources); 
};

class Coin {
public:
    double kingdom_coin;
    double tax_rate;
    double revenue;
    double corruption_loss; 
    Coin();
    void collectTaxes(people* population);
    void checkRevolt(int happiness); 
    void applyCorruption();
};

class Laws {
public:
    unique_ptr<Leader> ruler;
    Laws();
    ~Laws();
    void hold_election(class Kingdom* kingdom); 
};

class King : public Leader {
public:
    void applyPolicy(double* tax_rate, double* morale) override; 
};

class Resources {
public:
    unique_ptr<Resource<int>> food; 
    int weapon_count;
    int building_count;
    Resources();
    ~Resources();
    void manageResources(Coin* economy); 
    void checkFoodSupply(people* population);

    void buildStructure(const string& type);
};

class Food {
public:
    int quantity;
    Food();
    int getQuantity() const;
    void setQuantity(int q);
};

class Trade {
public:
    void conductTrade(Resources* resources, Coin* economy);
};
class friends {
public:
    unique_ptr<Resource<double>> trust_level;
    bool at_war;
    string war_opponent;
    friends();
    ~friends();
    void mk_friend();
    void trd_agree(const string& partner, int food_amount);
    void declareWar(const string& opponent);
    void attemptBribery(Coin* economy);
};

        class Bank {
        public:
            void takeLoan(double amount, Coin* economy);

            void repayLoan(double amount, Coin* economy);

        };



        class Kingdom {
        public:
            int stability;
            unique_ptr<people> population;
            unique_ptr<Soldiers> soldiers;
            unique_ptr<Coin> economy;
            unique_ptr<Laws> laws;
            unique_ptr<Resources> resources;
            unique_ptr<Trade> trade;
            unique_ptr<friends> diplomacy;
            unique_ptr<Bank> bank;
            Kingdom();
            ~Kingdom();
            void manage_people();
            void people_conflt();

            void happy_check();

            void tax_collect();
            void fight(Kingdom* target, class Player* attacker, class Player* defender); // Engage in combat
        };

        class Event {
        public:
            string randomEvent(Kingdom* kingdoms, people* population, Soldiers* soldiers, Coin* economy, Laws* laws, Resources* resources); // Trigger random events
        };

        class Player {
        public:
            string name;
            string msg;
            bool msgchk;
            shared_ptr<Kingdom> kingdom;
            Player(const string& n);
            Player();
            ~Player();
            void sendMessage(const string& message);


        };

        class Game {
        public:

            Player** players;

            int player_count;
            Game(int num_players, string* names);
            ~Game();
            void initializeKingdom();
            void save();

            void load();

            void slp_act(int seconds);
            Player* get_pl_nam(const string& name);
        };
