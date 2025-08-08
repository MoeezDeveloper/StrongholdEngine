#include "head.h"
#pragma execution_character_set("utf-8")
#include <iostream>
#include <string>
#include <cstdlib>
#pragma comment(lib, "winmm.lib")
#include <ctime>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// Colors for console 
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string CYAN = "\033[36m";
const string MAGENTA = "\033[35m";
const string WHITE = "\033[37m";
const string BOLD = "\033[1m";
const string BG_MAGENTA = "\033[45m";


// Play sound effects
void playSound(const string& type) {
#ifdef _WIN32
    if (type == "menu") Beep(500, 200);
    else if (type == "success") Beep(800, 300);
    else if (type == "error") Beep(300, 400);
    else if (type == "event") Beep(1000, 500);
    else if(type=="end"){
        Beep(1500, 500); 
        Beep(2500, 400);
    }
#else
    cout << "\a";
#endif
}

// Clear input buffer 
void clearInputBuffer() {
    cin.clear();
    cin.ignore();
}

// Display help menu with game guidance
void displayHelp() {
    cout << CYAN << BOLD << "\t\t\t\t\t╔═══════════════════════ Guidance for Thy Realm ═══════════════════════╗" << endl;
    cout << "\t\t\t\t\t║ Tips for Ruling Your Kingdom:                                        ║" << endl;
    cout << "\t\t\t\t\t╠═════════════════════════════════════════════════════════════════════╣" << endl;
    cout << WHITE << "\t\t\t\t\t║ 1. Care for People: Keep your people happy and growing. 😊🌱👥       ║" << endl;
    cout << "\t\t\t\t\t║ 2. Build Forces: Grow your army with soldiers and weapons. ⚔️🛡️     ║" << endl;
    cout << "\t\t\t\t\t║ 3. Gain Coin: Collect taxes or trade for more gold. 💰📈            ║" << endl;
    cout << "\t\t\t\t\t║ 4. Build Things: Grow food or build farms and castles. 🏰🌾        ║" << endl;
    cout << "\t\t\t\t\t║ 5. Set Laws: Make rules to guide your kingdom. 📜⚖️                ║" << endl;
    cout << "\t\t\t\t\t║ 6. Deal with Others: Make friends or fight other lords. 🤝⚔️       ║" << endl;
    cout << "\t\t\t\t\t║ 7. Save or Load: Keep your kingdom safe or bring it back. 💾🔄     ║" << endl;
    cout << "\t\t\t\t\t║ 8. Send Message: Talk to other players. 💬📨                      ║" << endl;
    cout << "\t\t\t\t\t║ 9. Leave Game: Rest from your duties. 🛌⏸️                        ║" << endl;
    cout << "\t\t\t\t\t║ 10. Run Tests: Test kingdom mechanics. 🧪🛠️                       ║" << endl;
    cout << CYAN << "\t\t\t\t\t\t╚═════════════════════════════════════════════════════════════════════╝" << RESET << endl;
    cout << YELLOW << BOLD << "\t\t\t\t\t\tPress Enter to return to ruling: ⏎ " << RESET;

    cin.get();
}

void displayMenu() {
    cout << BLUE << BOLD << "\t\t\t\t\t╔══════════════════════    Stronghold   ═══════════════════════╗" << endl;
    cout << "\t\t\t\t\t║🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰║" << endl;
    cout << "\t\t\t\t\t║🏰 🛡️ 🛡️ 🛡️ 🛡️ 🛡️ 🛡️ 🛡️ 🛡️ 🛡️ 🛡️ 🛡️ 🛡️ 🛡️ 🛡️ 🛡️ 🛡️ 🛡️ 🛡️ 🛡️ 🏰║" << endl;
    cout << "\t\t\t\t\t║🏰 🛡️ 🏹 🏹 🏹 🏹 🏹 🏹 🏹 🏹 🏹 🏹 🏹 🏹 🏹 🏹 🏹 🏹 🏹 🛡️ 🏰║" << endl;
    cout << "\t\t\t\t\t║🏰 🛡️ 🏹 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏹 🛡️ 🏰║" << endl;
    cout << "\t\t\t\t\t║🏰 🛡️ 🏹 🏰 🚪 🚪 🚪 🏰 🏰 🏰 🚪 🚪 🚪 🏰 🏰 🏰 🏹 🛡️ 🏹 🛡️ 🏰║" << endl;
    cout << "\t\t\t\t\t║🏰 🛡️ 🏹 🏰 🪟 🪟 🪟 🏰 🏰 🏰 🪟 🪟 🪟 🏰 🏰 🏰 🏹 🛡️ 🛡️ 🏰 🏰║" << endl;
    cout << "\t\t\t\t\t║🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰 🏰║" << endl;
    cout << "\t\t\t\t\t╚══════════════════════════════════════════════════════════════╝" << RESET << endl;
    cout << WHITE << "\t\t\t\t\t\t1. Care for People 😺👥    2. Build Forces ⚔️🛡️" << endl;
    cout << "\t\t\t\t\t\t3. Gain Coin 💰📈          4. Build Things 🏰🏗️" << endl;
    cout << "\t\t\t\t\t\t5. Set Laws 📜⚖️           6. Deal with Others 🤝⚔️" << endl;
    cout << "\t\t\t\t\t\t7. Save or Load 💾📀       8. Send Message 💬📜" << endl;
    cout << "\t\t\t\t\t\t9. Get Help 🆘🚨           " << endl;
    cout << YELLOW << BOLD << "\t\t\t\t\t\t\tPick a number (1-10): 🔢" << RESET;

}

int main() {
    PlaySound(TEXT("back1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    system("chcp 65001 > nul");
    cout << CYAN << BOLD << "\t\t\t\t\t╔═══════════════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t║           WELCOME TO STRONGHOLD 🏰👑        🏰║" << endl;
    cout << "\t\t\t\t\t║   03:45 AM PKT, Saturday, May 31, 2025 ⏰🗓️   ║" << endl;
    cout << "\t\t\t\t\t║           Rule Your Kingdom! 👑🏰           🏰║" << endl;
    cout << "\t\t\t\t\t╚═══════════════════════════════════════════════╝" << RESET << endl;
    cout << YELLOW << BOLD << "\t\t\t\t\t\tHow many lords will play (1-4)? 🎲👑 " << RESET;


    int num_players = 0;
    cin >> num_players;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
    }
    while (num_players < 1 || num_players > 4) {
        cout << RED << BOLD << "\t\t\t\t\t\t❌ Please choose 1 to 4 lords: " << RESET;
        playSound("error");

        cin >> num_players;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    clearInputBuffer();
    playSound("success");

    string n[4];
    for (int j = 0; j < num_players; j++) {
        cout << RED << BOLD << "\t\t\t\t\t\t👑 Player " << j + 1 << " Name: ✍️" << RESET;
        cin >> n[j];
        playSound("success");
    }

    // Initialize  game
    Game* game = nullptr;
    try {
        game = new Game(num_players, n);
        game->initializeKingdom();
        cout << GREEN << BOLD << "\t\t\t\t\t✅ Your kingdom is ready for " + to_string(num_players) + " lords! 🏰" << endl << RESET;
        playSound("success");
    }
    catch (const runtime_error& e) {
        cout << RED << BOLD << "\t\t\t\t\t❌ Trouble starting your kingdom: " + string(e.what()) << endl << RESET;
        playSound("error");
        return 1;
    }

    bool running = true;
    int turn_count = 0;
    while (running) 
    {
        //loop for both player
        for (int i = 0; i < num_players; ++i)
        {

            Player* player = game->players[i];
            int j = num_players - 1 - i;
            Player* opnd = game->players[j];
            Kingdom* kingdom = player->kingdom.get();
            system("CLS");
            int ln = player->name.length();
            // kingdom status
            cout << CYAN << BOLD << "\n\t\t\t\t\t\t  ╔";
            for (int k = 0; k < (30 - ln) / 2; k++)
                cout << "═";
            cout << "👑Turn for " << player->name;
            for (int k = 0; k <= (29 - ln) / 2; k++)
                cout << "═";
            cout << "╗" << endl << RESET;
            cout << WHITE << "\t\t\t\t\t\t  ║ 📊 Stability: " << setw(4) << to_string(kingdom->stability) << right << setw(25) << "║" << endl;
            cout << "\t\t\t\t\t\t  ║ 👥 People: " << left << setw(4) << to_string(kingdom->population->total_population) << right << setw(28) << "║" << endl;
            cout << "\t\t\t\t\t\t  ║ 💰 Coin: " << left << setw(12) << to_string(kingdom->economy->kingdom_coin) << " gold" << right << setw(17) << "║" << endl;
            cout << "\t\t\t\t\t\t  ║ ⚔️ Soldiers: " << left << setw(4) << to_string(kingdom->soldiers->soldier_count) << right << setw(26) << "║" << endl;
            cout << "\t\t\t\t\t\t  ║ 🌾 Food: " << left << setw(4) << to_string(kingdom->resources->food->getQuantity()) + " units" << right << setw(25) << "║" << endl;
            cout << "\t\t\t\t\t\t  ║ 🏰 Buildings: " << left << setw(4) << to_string(kingdom->resources->building_count) << right << setw(25) << "║" << endl;
            cout << "\t\t\t\t\t\t  ║ 😊 Happiness: " << left << setw(4) << to_string(kingdom->population->happy_level) << right << setw(25) << "║" << endl;
            
            if (kingdom->diplomacy->at_war) {
                int ln = opnd->name.length();
                cout << RED << "\t\t\t\t\t\t  ║ ⚔️ Fighting: " + kingdom->diplomacy->war_opponent << right << setw(30 - ln) << "║" << endl << RESET;
            }
            if (player->msgchk) {
                int ln = opnd->name.length() + player->msg.length();
                cout << YELLOW << "\t\t\t\t\t\t  ║ 📜 Message from " << opnd->name << ": " << player->msg << right << setw(25 - ln) << "║" << endl << RESET;
                player->msgchk = false; 
            }
            else {
                int ln = opnd->name.length();
                cout << "\t\t\t\t\t\t  ║ 📭 No new messages from " << opnd->name << right << setw(19 - ln) << "║" << endl;
            }
            cout << CYAN << "\t\t\t\t\t\t  ╚";
            for (int k = 0; k < 41; k++)
                cout << "═";
            cout << "╝" << RESET << endl;

            //  random events every 3 
            if (turn_count % 3 == 0 && turn_count != 0) {
                try {
                    Event event;
                    cout << MAGENTA << BOLD << "\t\t\t\t\t\t ⚠️ Something different happened "   << RESET;
                    					cout << YELLOW << BOLD <<" ⚠️ " << event.randomEvent(kingdom, kingdom->population.get(), kingdom->soldiers.get(), kingdom->economy.get(), kingdom->laws.get(), kingdom->resources.get()) << endl << RESET;
                  
                   
                    playSound("event");
                    game->slp_act(3);
                }
                catch (const exception& e) {
                    cout << RED << BOLD << "\t\t\t\t\t\t❌ Error in the realm: " + string(e.what()) << endl << RESET;
                    playSound("error");
                }
            }

            displayMenu();
            int choice;
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
            }
            while (choice < 1 || choice > 10) {
                cout << RED << BOLD << "\t\t\t\t\t\t\t❌ Please pick 1 to 10: " << RESET;
                playSound("error");
                cin >> choice;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
            clearInputBuffer();
            playSound("menu");

            try {
                if (choice == 1) {
                    // Care for people
                    kingdom->manage_people();
                    kingdom->people_conflt();
                    kingdom->economy->checkRevolt(kingdom->population->happy_level);
                    kingdom->happy_check();
                    cout << GREEN << BOLD << "\t\t\t\t\t✅ Your people are happy! Total: " + to_string(kingdom->population->total_population) + ". 😊" << endl << RESET;
                    playSound("success");
                    game->slp_act(2);
                }
                else if (choice == 2) {
                    // Build Forces
                    cout << YELLOW << BOLD << "\t\t\t\t\t\t1. Grow Soldiers ⚔️" << endl;
                    cout << "\t\t\t\t\t\t2. Train Soldiers 🏋️" << endl;
                    cout << "\t\t\t\t\t\t3. Pay Soldiers 💰" << endl;
                    cout << "\t\t\t\t\t\t4. Craft Weapons 🔨" << endl;
                    cout << "\t\t\t\t\t\t\tPick action (1-4): 🔢" << RESET;
                    int army_choice;
                    cin >> army_choice;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    while (army_choice < 1 || army_choice > 4 || kingdom->economy->kingdom_coin < static_cast<double>(army_choice * 5)) {
                        cout << RED << BOLD << "\t\t\t\t\t\t\t❌ Pick 1 to 4: " << RESET;
                        playSound("error");
                        cin >> army_choice;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                    }

                    playSound("menu");
                    if (army_choice == 1) {
                        cout << YELLOW << BOLD << "\t\t\t\t\t\tHow many soldiers to grow? ⚔️" << RESET;
                        int recruit_count;
                        cin >> recruit_count;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                        while (recruit_count < 0) {
                            cout << RED << BOLD << "\t\t\t\t\t\t❌ Enter 0 or more: " << RESET;
                            playSound("error");
                            cin >> recruit_count;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                            }
                        }
                        clearInputBuffer();
                        kingdom->soldiers->addsoldr(recruit_count, kingdom->population->total_population, kingdom->resources.get());
                        cout << GREEN << BOLD << "\t\t\t\t\t\t✅ Your army grows stronger! ⚔️" << endl << RESET;
                        if (kingdom->soldiers->soldier_count > 500) {
                            cout << YELLOW << BOLD << "\t\t\t\t\t\tYour army is now large 🛡️" << endl << RESET;
                        }
                        kingdom->economy->kingdom_coin -= recruit_count * 5;
                        playSound("success");
                        game->slp_act(3);
                    }
                    else if (army_choice == 2) {
                        kingdom->soldiers->train();
                        cout << GREEN << BOLD << "\t\t\t\t\t\t✅ Soldiers now sharper and ready! ⚔️" << endl << RESET;
                        playSound("success");
                        game->slp_act(5);
                    }
                    else if (army_choice == 3) {
                        cout << YELLOW << BOLD << "\t\t\t\t\t\t\tCoin to pay soldiers: 💰" << RESET;
                        double funds;
                        cin >> funds;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                        while (funds < 0) {
                            cout << RED << BOLD << "\t\t\t\t\t\t❌ Enter 0 or more: " << RESET;
                            playSound("error");
                            cin >> funds;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                            }
                        }

                        kingdom->soldiers->paySoldiers(funds);
                        kingdom->economy->kingdom_coin -= funds;
                        if (kingdom->economy->kingdom_coin < 0) throw runtime_error("No coin left in kingdom_coin!");
                        cout << GREEN << BOLD << "\t\t\t\t\t\t✅ Soldiers are pleased with their pay! 💰" << endl << RESET;
                        playSound("success");
                        game->slp_act(2);
                    }
                    else if (army_choice == 4) {
                        kingdom->soldiers->craftWeapons(kingdom->resources.get());
                        cout << GREEN << BOLD << "\t\t\t\t\t\t✅ New weapons forged for battle! 🔨" << endl << RESET;
                        playSound("success");
                        game->slp_act(3);
                    }
                }
                else if (choice == 3) {
                    // Gain Coin
                    cout << YELLOW << BOLD << "\t\t\t\t\t\t1. Collect Taxes 💰" << endl;
                    cout << "\t\t\t\t\t\t2. Borrow Coin 🏦" << endl;
                    cout << "\t\t\t\t\t\t3. Pay Back Coin 💸" << endl;
                    cout << "\t\t\t\t\t\t4. Trade Goods 📦" << endl;
                    cout << "\t\t\t\t\t\t\tPick action (1-4): 🔢" << RESET;
                    int money_choice;
                    cin >> money_choice;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    while (money_choice < 1 || money_choice > 4) {
                        cout << RED << BOLD << "\t\t\t\t\t\t\t❌ Pick 1 to 4: " << RESET;
                        playSound("error");
                        cin >> money_choice;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                    }
                    clearInputBuffer();
                    playSound("menu");
                    if (money_choice == 1) {
                        kingdom->tax_collect();
                        cout << GREEN << BOLD << "\t\t\t\t\t\t✅ Taxes bring " + to_string(kingdom->economy->revenue) + " coin to the treasury! 💰" << endl << RESET;
                        playSound("success");
                        game->slp_act(2);
                    }
                    else if (money_choice == 2) {
                        cout << YELLOW << BOLD << "\t\t\t\t\t\t\tHow much coin to borrow? 🏦" << RESET;
                        double loan_amount;
                        cin >> loan_amount;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                        while (loan_amount < 0) {
                            cout << RED << BOLD << "\t\t\t\t\t\t❌ Enter 0 or more: " << RESET;
                            playSound("error");
                            cin >> loan_amount;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                            }
                        }
                        clearInputBuffer();
                        kingdom->bank->takeLoan(loan_amount, kingdom->economy.get());
                        cout << GREEN << BOLD << "\t\t\t\t\t\t✅ Borrowed " + to_string(loan_amount) + " coin for the realm! 💰" << endl << RESET;
                        playSound("success");
                        game->slp_act(2);
                    }
                    else if (money_choice == 3) {
                        cout << YELLOW << BOLD << "\t\t\t\t\t\t\tHow much coin to pay back? 💸" << RESET;
                        double repay_amount;
                        cin >> repay_amount;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                        while (repay_amount < 0) {
                            cout << RED << BOLD << "\t\t\t\t\t\t❌ Enter 0 or more: " << RESET;
                            playSound("error");
                            cin >> repay_amount;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                            }
                        }

                        kingdom->bank->repayLoan(repay_amount, kingdom->economy.get());
                        cout << GREEN << BOLD << "\t\t\t\t\t\t✅ Paid back " + to_string(repay_amount) + " coin to the bank! 💸" << endl << RESET;
                        playSound("success");
                        game->slp_act(2);
                    }
                    else if (money_choice == 4) {
                        kingdom->trade->conductTrade(kingdom->resources.get(), kingdom->economy.get());
                        cout << GREEN << BOLD << "\t\t\t\t\t\t✅ Trade fills your stores with goods! 📦" << endl << RESET;
                        playSound("success");
                        game->slp_act(2);
                    }
                }
                else if (choice == 4) {
                    // Build Things
                    cout << YELLOW << BOLD << "\t\t\t\t\t\t1. Check Resources 📊" << endl;
                    cout << "\t\t\t\t\t\t2. Build Something 🏰" << endl;
                    cout << "\t\t\t\t\t\t\tPick action (1-2): 🔢" << RESET;
                    int build_choice;
                    cin >> build_choice;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    while (build_choice < 1 || build_choice > 2) {
                        cout << RED << BOLD << "\t\t\t\t\t\t❌ Pick 1 to 2: " << RESET;
                        playSound("error");
                        cin >> build_choice;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                    }
                    clearInputBuffer();
                    playSound("menu");
                    if (build_choice == 1) {
                        kingdom->resources->manageResources(kingdom->economy.get());
                        kingdom->resources->checkFoodSupply(kingdom->population.get());
                        cout << GREEN << BOLD << "\t\t\t\t\t\t✅ Your resources are in order! 📊" << endl << RESET;
                        playSound("success");
                        game->slp_act(2);
                    }
                    else if (build_choice == 2) {
                        cout << YELLOW << BOLD << "\t\t\t\t\t\tWhat to build (Farm, Forge, Castle)? 🏰" << RESET;
                        string building_type;
                        getline(cin, building_type);

                        if (building_type != "Farm" && building_type != "Forge" && building_type != "Castle") {
                            throw runtime_error("That’s not a valid building!");
                        }
                        kingdom->resources->buildStructure(building_type);
                        cout << GREEN << BOLD << "\t\t\t\t\t\t✅ A new " + building_type + " graces your kingdom! 🏰" << endl << RESET;
                        playSound("success");
                        game->slp_act(3);
                    }
                }
                else if (choice == 5) {
                    // Set Laws
                    kingdom->laws->hold_election(kingdom);
                    kingdom->laws->ruler->applyPolicy(&kingdom->economy->tax_rate, &kingdom->soldiers->morale);
                    cout << GREEN << BOLD << "\t\t\t\t\t\t\t\t✅ New laws set! Taxes: " + to_string(kingdom->economy->tax_rate) << " 📜" << endl << RESET;
                    playSound("success");
                    game->slp_act(3);
                }
                else if (choice == 6) {
                    // Deal with Others
                    cout << YELLOW << BOLD << "\t\t\t\t\t\t1. Make Ally 🤝" << endl;
                    cout << "\t\t\t\t\t\t2. Trade Food 🌾" << endl;
                    cout << "\t\t\t\t\t\t3. Start War ⚔️" << endl;
                    cout << "\t\t\t\t\t\t4. Attack Foe 🗡️" << endl;
                    cout << "\t\t\t\t\t\t5. To Trust 💰" << endl;
                    cout << "\t\t\t\t\t\t\tPick action (1-5): 🔢" << RESET;

                    int diplo_choice;
                    cin >> diplo_choice;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    while (diplo_choice < 1 || diplo_choice > 5) {
                        cout << RED << BOLD << "\t\t\t\t\t\t❌ Pick 1 to 5: " << RESET;
                        playSound("error");
                        cin >> diplo_choice;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                    }
                    clearInputBuffer();
                    playSound("menu");
                    if (diplo_choice == 1) {
                        kingdom->diplomacy->mk_friend();
                        cout << GREEN << BOLD << "\t\t\t\t\t✅ A new ally joins your cause! Trust: " + to_string(kingdom->diplomacy->trust_level->getQuantity()) << " 🤝" << endl << RESET;
                        playSound("success");
                        game->slp_act(2);
                    }
                    else if (diplo_choice == 2) {
                        cout << YELLOW << BOLD << "\t\t\t\t\t\tEnter name of player you want to trade: 👤" << RESET;
                        string partner;
                        getline(cin, partner);
                        cout << YELLOW << BOLD << "\t\t\t\t\t\t\tHow much food to trade? 🌾" << RESET;
                        int amount;
                        cin >> amount;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                        while (amount < 0) {
                            cout << RED << BOLD << "\t\t\t\t\t❌ Enter 0 or more: " << RESET;
                            playSound("error");
                            cin >> amount;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                            }
                        }
                        clearInputBuffer();
                        kingdom->diplomacy->trd_agree(partner, amount);
                        Player* partner_player = game->get_pl_nam(partner);
                        if (partner_player) {
                            partner_player->kingdom->resources->food->setQuantity(
                                partner_player->kingdom->resources->food->getQuantity() + amount);
                            kingdom->resources->food->setQuantity(
                                kingdom->resources->food->getQuantity() - amount);
                            cout << GREEN << BOLD << "\t\t\t\t\t\t\t✅ Traded " + to_string(amount) + " food to " + partner + "! 🌾" << endl << RESET;
                        }
                        else {
                            cout << GREEN << BOLD << "\t\t\t\t\t\t✅ Lord not found, but trade is noted! 📝" << endl << RESET;
                        }
                        playSound("success");
                        game->slp_act(2);
                    }
                    else if (diplo_choice == 3) {
                        cout << YELLOW << BOLD << "\t\t\t\t\t\t\tWho to declare war on? ⚔️" << RESET;
                        string opponent;
                        getline(cin, opponent);
                        if (opponent == player->name) throw runtime_error("Cannot declare war on yourself!");
                        kingdom->diplomacy->declareWar(opponent);
                        cout << RED << BOLD << "\t\t\t\t\t\t\t⚔️ War declared on " + opponent + "! 🛡️" << endl << RESET;
                        playSound("success");
                        game->slp_act(2);
                    }
                    else if (diplo_choice == 4) {
                        cout << YELLOW << BOLD << "\t\t\t\t\t\t\tWho to attack? 🗡️" << RESET;
                        string target_name;
                        getline(cin, target_name);
                        Player* target_player = game->get_pl_nam(target_name);
                        if (!target_player) {
                            throw runtime_error("That player cannot be found!");
                        }
                        if (player->name == target_name) {
                            throw runtime_error("You cannot attack your own kingdom!");
                        }
                        kingdom->fight(target_player->kingdom.get(), player, target_player);
                        cout << GREEN << BOLD << "\t\t\t\t\t\t\t\t✅ Your forces strike " + target_name + "! ⚔️" << endl << RESET;
                        playSound("success");
                        game->slp_act(3);
                    }
                    else if (diplo_choice == 5) {
                        kingdom->diplomacy->attemptBribery(kingdom->economy.get());
                        cout << GREEN << BOLD << "\t\t\t\t\t\t✅ Trust level increase: " + to_string(kingdom->diplomacy->trust_level->getQuantity()) << " 💰" << endl << RESET;
                        playSound("success");
                        game->slp_act(2);
                    }
                }
                else if (choice == 7) {
                    
                    // Save or Load
                    cout << YELLOW << BOLD << "\t\t\t\t\t\t1. Save Kingdom 💾" << endl;
                    cout << "\t\t\t\t\t\t2. Load Kingdom 📀" << endl;
                    cout << "\t\t\t\t\t\t3. To Give up  😞" << endl;
              
                    cout << "\t\t\t\t\t\t\tPick action (1-2): 🔢" << RESET;
                    int file_choice;
                    cin >> file_choice;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    while (file_choice < 1 || file_choice > 3) {
                        cout << RED << BOLD << "\t\t\t\t\t\t❌ Pick 1 to 2: " << RESET;
                        playSound("error");
                        cin >> file_choice;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                    }
                    clearInputBuffer();
                    playSound("menu");
                    if (file_choice == 1) {
                        game->save();
                        cout << GREEN << BOLD << "\t\t\t\t\t\t✅ Your kingdom is saved! 💾" << endl << RESET;
                        playSound("success");
                        game->slp_act(1);
                    }
                    else if (file_choice == 2) {
                        game->load();
                        cout << GREEN << BOLD << "\t\t\t\t\t\t✅ Your kingdom is restored! 📀" << endl << RESET;
                        playSound("success");
                        game->slp_act(1);
                    }
					else if (file_choice == 3) {
						cout << RED << BOLD << "\t\t\t\t\t\t❌ You have chosen to give up your kingdom! 😞" << RESET << endl;
						playSound("error");
						running = false; 
						int win_ck[4] = { 0, 0, 0, 0 };
                        // anounce winner on base of greater population ,resources and etc
						int max_win = 0;
						for (int k = 1; k < num_players; k++) {
							if (game->players[k]->kingdom->population->total_population > game->players[max_win]->kingdom->population->total_population) {
								win_ck[k]++;
							}
							else if (game->players[k]->kingdom->population->total_population < game->players[max_win]->kingdom->population->total_population) {
								win_ck[max_win]++;
							}
							if (game->players[k]->kingdom->resources->food->getQuantity() > game->players[max_win]->kingdom->resources->food->getQuantity()) {
								win_ck[k]++;
							}
							else if (game->players[k]->kingdom->resources->food->getQuantity() < game->players[max_win]->kingdom->resources->food->getQuantity()) {
								win_ck[max_win]++;
							}
							if (game->players[k]->kingdom->economy->kingdom_coin > game->players[max_win]->kingdom->economy->kingdom_coin) {
								win_ck[k]++;
							}
							else if (game->players[k]->kingdom->economy->kingdom_coin < game->players[max_win]->kingdom->economy->kingdom_coin) {
								win_ck[max_win]++;
							}
							if (game->players[k]->kingdom->soldiers->soldier_count > game->players[max_win]->kingdom->soldiers->soldier_count) {
								win_ck[k]++;
							}
							else if (game->players[k]->kingdom->soldiers->soldier_count < game->players[max_win]->kingdom->soldiers->soldier_count) {
								win_ck[max_win]++;
							}
							if (game->players[k]->kingdom->resources->building_count > game->players[max_win]->kingdom->resources->building_count) {
								win_ck[k]++;
							}
							else if (game->players[k]->kingdom->resources->building_count < game->players[max_win]->kingdom->resources->building_count) {
								win_ck[max_win]++;
							}
							if (game->players[k]->kingdom->population->happy_level > game->players[max_win]->kingdom->population->happy_level) {
								win_ck[k]++;
							}
							else if (game->players[k]->kingdom->population->happy_level < game->players[max_win]->kingdom->population->happy_level) {
								win_ck[max_win]++;
							}
							if (game->players[k]->kingdom->diplomacy->trust_level->getQuantity() > game->players[max_win]->kingdom->diplomacy->trust_level->getQuantity()) {
								win_ck[k]++;
							}
							else if (game->players[k]->kingdom->diplomacy->trust_level->getQuantity() < game->players[max_win]->kingdom->diplomacy->trust_level->getQuantity()) {
								win_ck[max_win]++;
							}
							if (win_ck[k] > win_ck[max_win]) {
								max_win = k;
							}
							
						}
						system("CLS");
                        // game end display
                        cout << endl << endl << endl;
						cout << CYAN << BOLD << "\t\t\t\t\t\t╔═══════════════════════════════════════════════╗" << endl;
						cout << "\t\t\t\t\t\t║           STRONGHOLD GAME OVER 🏰👑         🏰║" << endl;
						cout << "\t\t\t\t\t\t║   03:45 AM PKT, Saturday, May 31, 2025 ⏰🗓️   ║" << endl;
						cout << "\t\t\t\t\t\t║           Rule Your Kingdom! 👑🏰           🏰║" << endl;
						cout << "\t\t\t\t\t\t╚═══════════════════════════════════════════════╝" << RESET << endl;
                        cout << endl;
						
						cout << GREEN << BOLD << "\t\t\t\t\t\t🏆 The winner is " << game->players[max_win]->name << " with the strongest kingdom! 🏰" << RESET << endl;
						cout << GREEN << BOLD << "\t\t\t\t\t\t🏰 Population: " << game->players[max_win]->kingdom->population->total_population << endl;
						cout << "\t\t\t\t\t\t🏰 Coin: " << game->players[max_win]->kingdom->economy->kingdom_coin << " gold" << endl;
						cout << "\t\t\t\t\t\t🏰 Soldiers: " << game->players[max_win]->kingdom->soldiers->soldier_count << endl;
						cout << "\t\t\t\t\t\t🏰 Buildings: " << game->players[max_win]->kingdom->resources->building_count << endl;
						cout << "\t\t\t\t\t\t🏰 Happiness: " << game->players[max_win]->kingdom->population->happy_level << endl;
						cout << "\t\t\t\t\t\t🏰 Trust Level: " << game->players[max_win]->kingdom->diplomacy->trust_level->getQuantity() << endl;
						cout << "\t\t\t\t\t\t🏰 Resources: " << game->players[max_win]->kingdom->resources->food->getQuantity() << " food units" << endl;
						for (int i = 0; i < 100; i++) {
							//sound for success
							playSound("end");
							Sleep(200); 
						}

						break;
					}
                }
                else if (choice == 8) {
                    // Send Message
                    cout << YELLOW << BOLD << "\t\t\t\t\t\t\tWhat message to send? 💬" << RESET;
                    string message;
                    getline(cin, message);
                    opnd->msg = message;
                    opnd->msgchk = true;
                    cout << GREEN << BOLD << "\t\t\t\t\t\t✅ Your message has been sent! 📜" << endl << RESET;
                    playSound("success");
                    game->slp_act(1);
                }
                else if (choice == 9) {
                    // Get Help
                    displayHelp();
                    playSound("menu");
                }

            }
            catch (const exception& e) {
                cout << RED << BOLD << "\t\t\t\t\t\t\t\t❌ Trouble in the realm: " + string(e.what()) << endl << RESET;
                playSound("error");
                game->slp_act(1);
            }
           
        }
        turn_count++;
    }

    // End the game
    delete game;
    cout << CYAN << BOLD << "\t\t\t\t\t\t\t\tYour kingdom rests in peace. 🕊️" << endl << RESET;
    playSound("success");
    PlaySound(NULL, 0, 0);
    return 0;

}
