#include <SFML/System.hpp>
#include "EditDistance.hpp"


int main() {
    sf::Clock clock;
    sf::Time t;

    std::string s1;
    std::string s2;

    std::cin >> s1;
    std::cin >> s2;
    EditDistance e1(s1, s2);
    int distance = e1.optDistance();
    std::cout << "Edit distance = " << distance << std::endl;
    std::string align = e1.alignment();
    std::cout << align << std::endl;
    t = clock.getElapsedTime();
    std::cout << "Execution time is " << t.asSeconds() << " seconds" << std::endl;
    return 0;
}
