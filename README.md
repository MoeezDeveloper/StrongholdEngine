StrongholdEngine

Welcome to StrongholdEngine, the core of Stronghold: A Strategic Kingdom Management Game, a C++ project developed for our Object-Oriented Programming Lab at FAST National University, CFD Campus, Faisalabad.  Abdul Moeez  Developed thisunder the guidance of Dr. Anwar Shah, this turn-based strategy game challenges players to govern kingdoms through resource management, military strategy, economic policies, and diplomacy.

As the engine developer, I designed the robust architecture that powers Stronghold’s dynamic gameplay. "This project exemplifies innovative application of OOP principles," noted Dr. Anwar Shah, inspiring us to create a seamless and engaging experience.

Project Overview

Stronghold immerses 1–4 players in the role of kingdom rulers, balancing food, coins, public morale, and military strength while navigating alliances, wars, and random events like economic crises. Built with C++ and leveraging OOP principles—inheritance, polymorphism, encapsulation, and templates—the game features a vibrant console interface with ANSI color-coded menus, ASCII art, and Windows API sound effects.

Key Features





Strategic Gameplay: Manage resources, recruit armies, set tax policies, and forge diplomatic ties, with random events adding unpredictability every three turns.



Technical Excellence: Modular design with smart pointers (std::unique_ptr, std::shared_ptr) for memory safety and exception handling for robust input validation.



User Interface: Engaging console-based UI with colorful menus and ASCII art (e.g., castle visuals) for an immersive experience.



Persistence: Save/load functionality to preserve game progress.

Getting Started

Prerequisites





C++ compiler (e.g., g++ 11.2.0 or later, MinGW recommended for Windows).



Windows OS (required for Windows API Beep sound effects).

Installation





Clone the repository:

git clone https://github.com/MoeezDeveloper/StrongholdEngine.git



Navigate to the project directory:

cd StrongholdEngine



Compile the source files:

g++ -std=c++17 Source.cpp Impl.cpp -o Stronghold



Run the game:

./Stronghold

Gameplay Instructions





Start the game and select the number of players (1–4).



Navigate the menu to manage resources, train soldiers, or engage in diplomacy.



Save your progress to resume later and adapt to random events.

Project Structure





Header.h: Defines all classes and methods.



Source.cpp: Implements the game loop, user interface, and input handling.



Impl.cpp: Contains core engine logic and class implementations.

Future Enhancements

We envision expanding Stronghold with:





A graphical interface using libraries like SDL or SFML.



Online multiplayer for global competition.



Cross-platform compatibility to replace Windows-specific APIs.



Advanced mechanics, such as espionage or expanded diplomacy.

Contributing

Contributions are welcome! Please fork the repository, create a feature branch, and submit a pull request. See CONTRIBUTING.md for guidelines. Report issues or suggest features via the Issues tab.

Acknowledgments

We express our deepest gratitude to Dr. Anwar Shah for his insightful mentorship and [TA Name] for their invaluable support. My role in developing the game engine was both challenging and rewarding, complemented by Abdul Moeez’s work on game logic and Abdullah Tahir’s innovative UI design. Together, we built a project that reflects our passion for programming and strategic game design.

License

This project is licensed under the MIT License.

Join us in shaping the future of Stronghold! Star the repository or share your feedback to help us grow this project.
