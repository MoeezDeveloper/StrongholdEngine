#include "head.h"
#include <iostream>
#include <random>
#include <chrono>
#include <thread>


//people block
people::people() : total_population(100), happy_level(50) {}

void people::newpeopl() {
    if (happy_level > 50 && total_population > 0) {
        total_population += static_cast<int>(total_population * 0.05); // 5% growth
    }
    else
        cout << "\t\t\t\t\t\t\tLow happiness Level\n";
}



//soldiers block
Soldiers::Soldiers() : soldier_count(20), morale(50.0) {}

void Soldiers::addsoldr(int count, int total_population, Resources* resources) {

    if (count < 0 || total_population < count) throw runtime_error("Not enough folk ");
    if (resources->food->getQuantity() < count * 10) throw runtime_error("Not enough food!");
    soldier_count += count;
    resources->food->setQuantity(resources->food->getQuantity() - count * 10);

}

void Soldiers::train() {

    morale += 10.0;
    if (morale > 100.0) morale = 100.0;
}

void Soldiers::paySoldiers(double funds) {
    // Pay soldiers 
    if (funds < 0) throw runtime_error("Cannot pay negative coin!");
    morale += funds / soldier_count;
    if (morale > 100.0) morale = 100.0;
}

void Soldiers::craftWeapons(Resources* resources) {
    // Craft weapons 
    if (resources->building_count < 1) throw runtime_error("Need a building to craft weapons!");
    resources->weapon_count += 10 * resources->building_count;
}



//coin block
Coin::Coin() : kingdom_coin(1000.0), tax_rate(0.1), revenue(0.0), corruption_loss(0.0) {}

void Coin::collectTaxes(people* population) {
    // Collect taxes
    revenue = population->total_population * tax_rate * 10.0;
    kingdom_coin += revenue;
    population->happy_level -= static_cast<int>(tax_rate * 10);
    if (population->happy_level < 20)
        applyCorruption();
}

void Coin::checkRevolt(int happiness) {

    if (happiness < 20) throw runtime_error("people are revolting ");
}

void Coin::applyCorruption() {

    srand(time(0));
    int rnd_cmp = rand() % 50 + 1;
    if (rnd_cmp <= 5) {
        corruption_loss += revenue * 0.1 * rnd_cmp;
        kingdom_coin -= corruption_loss;
    }

}




//laws block
Laws::Laws() : ruler(make_unique<King>()) {}
Laws::~Laws() {}
void Laws::hold_election(Kingdom* kingdom) {
    // Hold election 
    if (kingdom->stability < 30) {
        kingdom->stability -= 10;
    }
    else if (kingdom->stability < 40) {
        kingdom->stability += 10;
    }
    if (kingdom->stability > 100) kingdom->stability = 100;
}


//king block
void King::applyPolicy(double* tax_rate, double* morale) {
    // Applyincrease tax rate
    *tax_rate += 0.08;
    if (*tax_rate > 0.5) *tax_rate = 0.5;
    *morale += 5.0;
    if (*morale > 100.0) *morale = 100.0;
}



//foof block
Food::Food() : quantity(500) {}
int Food::getQuantity() const { return quantity; }
void Food::setQuantity(int q) { quantity = q; }



//resources block
Resources::Resources() : food(make_unique<Resource<int>>()), weapon_count(50), building_count(0) {
    food->setQuantity(500);
}
Resources::~Resources() {}

void Resources::manageResources(Coin* economy) {

    food->setQuantity(food->getQuantity() + building_count * 50);
    economy->kingdom_coin -= building_count * 10;
    if (economy->kingdom_coin < 0) throw runtime_error("Not enough coin for upkeep!");
}

void Resources::checkFoodSupply(people* population) {

    if (food->getQuantity() < population->total_population * 2) {
        population->happy_level -= 10;
        throw runtime_error("Not enough food!");
    }
}

void Resources::buildStructure(const string& type) {

    if (type == "Farm" || type == "Forge" || type == "Castle") {
        building_count++;
    }
    else {
        throw runtime_error("Unknown structure type!");
    }
}


//trade block
void Trade::conductTrade(Resources* resources, Coin* economy) {

    resources->food->setQuantity(resources->food->getQuantity() + 100);
    economy->kingdom_coin -= 100;
    if (economy->kingdom_coin < 0) throw runtime_error("Not enough coin to trade!");
}



//friends block
friends::friends() : trust_level(make_unique<Resource<double>>()), at_war(false), war_opponent("") {
    trust_level->setQuantity(0.0);
}
friends::~friends() {}

void friends::mk_friend() {
    // Increase trust level 
    trust_level->setQuantity(trust_level->getQuantity() + 10.0);
    if (trust_level->getQuantity() > 100.0) trust_level->setQuantity(100.0);
}

void friends::trd_agree(const string& partner, int food_amount) {


    if (food_amount < 0) throw runtime_error("Cannot trade negative food!");
}

void friends::declareWar(const string& opponent) {

    at_war = true;
    war_opponent = opponent;
}

void friends::attemptBribery(Coin* economy) {

    int rnd_number = rand() % 100 + 1;
    if (economy->kingdom_coin < 100) throw runtime_error("Not enough coin!");
    economy->kingdom_coin -= 100;
    if (rnd_number <= 50) {
        trust_level->setQuantity(trust_level->getQuantity() + rnd_number);
        if (trust_level->getQuantity() > 100.0) trust_level->setQuantity(100.0);
    }
}



//bank block
void Bank::takeLoan(double amount, Coin* economy) {
    // Take a loan
    if (amount < 0) throw runtime_error("Cannot borrow negative coin!");
    economy->kingdom_coin += amount;
}

void Bank::repayLoan(double amount, Coin* economy) {
    // Repay a loan
    if (amount < 0) throw runtime_error("Cannot repay negative coin!");
    economy->kingdom_coin -= amount;
    if (economy->kingdom_coin < 0) throw runtime_error("Not enough coin to repay!");
}



//event block
string Event::randomEvent(Kingdom* kingdoms, people* population, Soldiers* soldiers, Coin* economy, Laws* laws, Resources* resources) {

    srand(time(0));
    int event_type = rand() % 4 + 1;
    if (event_type == 1) {
        population->total_population -= population->total_population / 10;
        population->happy_level -= 10;
		return "Disease spread!";
        //diesease
    }
    else if (event_type == 2) {
        soldiers->soldier_count -= soldiers->soldier_count / 10;
        soldiers->morale -= 5.0;
		return "War broke out!";
        //war
    }
    else if (event_type == 3) {
        economy->kingdom_coin -= economy->kingdom_coin / 5;
        economy->applyCorruption();
        laws->hold_election(kingdoms);
		return "Economic crisis!";
        //economic crisis
    }

    else {
        resources->food->setQuantity(resources->food->getQuantity() - 100);
        if (resources->food->getQuantity() < 0) resources->food->setQuantity(0);
        population->happy_level -= 5;
        laws->hold_election(kingdoms);
		return "Food shortage!";
        //low food+election
    }
}




//kingdom block
Kingdom::Kingdom() : stability(50), population(make_unique<people>()), soldiers(make_unique<Soldiers>()),
economy(make_unique<Coin>()), laws(make_unique<Laws>()), resources(make_unique<Resources>()),
trade(make_unique<Trade>()), diplomacy(make_unique<friends>()), bank(make_unique<Bank>()) {
}
Kingdom::~Kingdom() {}
//increase happy
void Kingdom::manage_people() {

    population->happy_level += 10;
    if (population->happy_level > 100) population->happy_level = 100;
}
//if happy is low decrease population
void Kingdom::people_conflt() {

    if (population->happy_level < 30) {
        population->total_population -= population->total_population / 20;
    }
}

void Kingdom::happy_check() {

    population->newpeopl();
}

void Kingdom::tax_collect() {

    economy->collectTaxes(population.get());
}

void Kingdom::fight(Kingdom* target, Player* attacker, Player* defender) {
    // Simulate combat:
    if (soldiers->soldier_count > target->soldiers->soldier_count) {
        target->stability -= 10;
        target->soldiers->soldier_count -= soldiers->soldier_count / 10;
      //  cout << attacker->name << " wins the battle!\n";
    }
    else {
        stability -= 10;
        soldiers->soldier_count -= target->soldiers->soldier_count / 10;
        //cout << defender->name << " wins the battle!\n";
    }
}




//player block
Player::Player(const string& n) : name(n), msgchk(false), kingdom(make_shared<Kingdom>()) {}
Player::~Player() {}
Player::Player() : name("Default"), msgchk(false), kingdom(make_unique<Kingdom>()) {}
void Player::sendMessage(const string& message) {

    cout << "Message from " << name << ": " << message << "\n";
}




//game block
Game::Game(int num_players, string* names) : player_count(num_players) {

    if (num_players < 1 || num_players > 4) throw runtime_error("Need 1 to 4 players!");
    players = new Player * [num_players];
    for (int i = 0; i < num_players; ++i) {

        string name = names[i];
        players[i] = new Player(name);
    }

}

Game::~Game() {

    for (int i = 0; i < player_count; ++i) {
        delete players[i];
    }
    delete[] players;
}


void Game::initializeKingdom() {
    for (int i = 0; i < player_count; ++i) {
        players[i]->kingdom->stability = 50;
    }
}

void Game::save() {
    // Save game 
    ofstream file("fill.txt");
    if (!file) throw runtime_error("Cannot save kingdom!");
    for (int i = 0; i < player_count; ++i) {
        file << players[i]->name << " "
            << players[i]->kingdom->stability << " "
            << players[i]->kingdom->population->total_population << " "
            << players[i]->kingdom->economy->kingdom_coin << " "
            << players[i]->kingdom->soldiers->soldier_count << "\n";
    }
    file.close();
}

void Game::load() {
    // Load game 
    ifstream file("fill.txt");
    if (!file) throw runtime_error("Cannot load kingdom!");
    for (int i = 0; i < player_count; ++i) {
        string name;
        int stability, population;
        double coin;
        int soldiers;
        file >> name >> stability >> population >> coin >> soldiers;
        players[i]->kingdom->stability = stability;
        players[i]->kingdom->population->total_population = population;
        players[i]->kingdom->economy->kingdom_coin = coin;
        players[i]->kingdom->soldiers->soldier_count = soldiers;
    }
    file.close();
}

void Game::slp_act(int seconds) {

    this_thread::sleep_for(chrono::seconds(seconds));
}

Player* Game::get_pl_nam(const string& name) {

    for (int i = 0; i < player_count; ++i) {
        if (players[i]->name == name) return players[i];
    }
    return nullptr;
}

