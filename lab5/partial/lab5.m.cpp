#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <list>
#include <tuple>
#include <vector>

#include "reverse_find.hpp"

struct Player {
    std::string name;
    int wins;

    friend bool operator==(const Player& a, const Player& b) {
        return std::tie(a.name, a.wins) == std::tie(b.name, b.wins);
    }
    friend bool operator!=(const Player& a, const Player& b) { return !(a == b); }
};

void firstTest()
{
    auto removePlayersNamed = [](auto& c, const std::string& name) {
        // Would you say there is a bug in this helper function,
        // or in how it is used?
        auto it = std::remove_if(
            c.begin(), c.end(),
            [&](const Player& p) { return p.name == name; }
        );
        c.erase(it, c.end());
    };

    std::vector<Player> team = {
        Player{"alice", 0},
        Player{"bob", 0},
        Player{"charlie", 0},
        Player{"bob", 0},
        Player{"charlie", 0},
        Player{"dave", 0},
    };
    auto bob = team.begin() + 1;
    assert(bob->name == "bob");

    removePlayersNamed(team, bob->name);

    std::cout << "The players NOT named 'bob' are:\n";
    for (const auto& p : team) {
        std::cout << p.name << "\n";
    }
    std::cout << "(You should have seen alice, charlie, charlie, dave.)\n";
}

void secondTest()
{
    std::vector<Player> team = {
        Player{"alice", 2},
        Player{"bob", 0},
        Player{"charlie", 4},
        Player{"dave", 0},
        Player{"ernie", 3},
    };
    team.shrink_to_fit();

    std::vector<Player> new_arrivals = {
        Player{"ted", 0},
        Player{"bob", 0},
        Player{"carol", 0},
    };

    // Insert the new arrivals in sorted order, eliminating any who've already arrived.
    // Since all new arrivals will have "wins=0", we don't have to
    // search through the entire container -- let's limit our search
    // as much as possible.

    auto hasNoWins = [](const auto& p) { return p.wins == 0; };
    auto first = std::find_if(team.begin(), team.end(), hasNoWins);
    if (first == team.end()) {
        team.insert(team.end(), new_arrivals.begin(), new_arrivals.end());
    } else {
        auto last = lab5::reverse_find_if(team.begin(), team.end(), hasNoWins);

        for (const auto& player : new_arrivals) {
            if (std::count(first, last, player) == 0) {
                team.push_back(player);
            }
        }
    }

    std::cout << "The team after inserting new arrivals is:\n";
    for (const auto& p : team) {
        std::cout << p.name << "\n";
    }
    std::cout << "(You should have seen alice, bob, charlie, dave, ernie, ted, carol.)\n";
}

int main()
{
    firstTest();
    secondTest();
}
