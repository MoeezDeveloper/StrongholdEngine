# StrongholdEngine 🏰

Welcome to **StrongholdEngine**, the backbone of *Stronghold: A Strategic Kingdom Management Game*, a C++ project developed for our Object-Oriented Programming Lab at FAST National University, CFD Campus, Faisalabad. 🌟 Crafted by Abdul Moeez, Abdullah Tahir, and Reyan Naveed under the guidance of Dr. Anwar Shah, this turn-based strategy game challenges players to rule kingdoms through resource management, military strategy, economic policies, and diplomacy.

As Abdul Moeez, I architected the game engine and core logic, bringing *Stronghold*’s dynamic gameplay to life. 🚀 "This project showcases exceptional technical skill and teamwork," noted Dr. Anwar Shah, motivating us to deliver an engaging experience.

## Project Overview 📜

*Stronghold* immerses 1–4 players in kingdom governance, balancing resources (food, coins, morale), military strength, and diplomatic relations while tackling random events like economic crises. Built with C++17, leveraging OOP principles—inheritance, polymorphism, encapsulation, and templates—the game features a vibrant console interface with ANSI color-coded menus, ASCII art, and Windows API sound effects. 🎮

## Key Features ⚙️

- **Strategic Gameplay**: Manage resources, recruit armies, set taxes, and forge alliances, with random events every three turns. 🗳️
- **Technical Excellence**: Modular design with smart pointers (`std::unique_ptr`, `std::shared_ptr`) and exception handling for stability. 🛠️
- **User Interface**: Colorful console UI with ASCII art (e.g., castle visuals) for immersion. 🎨
- **Persistence**: Save/load functionality to preserve progress. 💾

## Getting Started 🏁

### Prerequisites

- **C++ Compiler**: g++ 11.2.0 or later (MinGW recommended for Windows). 🖥️
- **Operating System**: Windows (required for Beep sound effects). 🪟

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/[YourGitHubUsername]/StrongholdEngine.git
   ```
2. Navigate to the project directory:

   ```bash
   cd StrongholdEngine
   ```
3. Compile the source files:

   ```bash
   g++ -std=c++17 Source.cpp Impl.cpp -o Stronghold
   ```
4. Run the game:

   ```bash
   ./Stronghold
   ```

### Gameplay Instructions

- Launch and select 1–4 players. 👥
- Navigate menus to manage resources, train soldiers, or engage in diplomacy. ⚔️
- Save progress and adapt to random events. 🔄

## Project Structure 📁

- `Header.h`: Class declarations.
- `Source.cpp`: Game loop and UI logic.
- `Impl.cpp`: Engine and core logic implementations.

## Future Enhancements 🔮

We plan to enhance *Stronghold* with:

- Graphical UI using SDL or SFML. 🖼️
- Online multiplayer for global play. 🌐
- Cross-platform support to replace Windows APIs. 🧩
- Advanced mechanics like espionage. 🕵️

## Contributing 🤝

Contributions are welcome! Fork the repo, create a feature branch, and submit a pull request. See CONTRIBUTING.md for details. Report issues or suggest features via the Issues tab.

## Acknowledgments 🙏

Deepest thanks to Dr. Anwar Shah for his insightful mentorship and \[TA Name\] for their support. As Abdul Moeez, I found developing the game engine and logic immensely rewarding, complemented by Abdullah Tahir’s creative UI design and Reyan Naveed’s rigorous testing. Our teamwork brought *Stronghold* to life, fueling our passion for game development. ❤️

## License 📄

Licensed under the MIT License.

---

*Help shape Stronghold’s future! Star the repo or share feedback to join our journey.* ⭐