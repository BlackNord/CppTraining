#include "ex_12_18.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
#include <chrono>

namespace Vamp {
    int rand_dip(int up, int down) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(up, down);
        int d_ist = dist(mt);

        return d_ist;
    }

    class Room {
    public:
        Room() : bat{ false }, pit{ false }, vamp{ false }, number{ 0 }, num_of_neighbours{ 3 }{
            neighbours.reserve(3);
            for (int i{ 0 }; i < num_of_neighbours; ++i) {
                neighbours.push_back(nullptr);
            }
        }

        Room* ptr() {
            return this;
        }

        void set_ptr(Room* first, Room* second, Room* third) {
            neighbours[0] = first;
            neighbours[1] = second;
            neighbours[2] = third;
        }

        vector<Room*> get_neighbour() {
            return neighbours;
        }

        int get_number() {
            return number;
        }

        void set_number(int _number) {
            number = _number;
        }

        bool get_bat() {
            return bat;
        }

        bool get_pit() {
            return pit;
        }

        bool get_vamp() {
            return vamp;
        }

        void set_bat(bool condition) {
            bat = condition;
        }

        void set_vamp(bool condition) {
            vamp = condition;
        }

        void set_pit(bool condition) {
            pit = condition;
        }

    private:
        bool bat;
        bool pit;
        bool vamp;

        int num_of_neighbours;

        int number;
        vector<Room*> neighbours;
    };

    class Player {
    public:
        Player() : alive{ true }, arrows{ 5 } {}

        Room get_room() {
            return room;
        }

        void shot() {
            if (arrows > 0) {
                arrows--;
            }
        }

        void kill() {
            alive = false;
            //cout << "You are DEAD\n";
        }

        void set_room(Room _room) {
            room = _room;
        }

        void move_to(int pos) {
            for (int i{ 0 }; i < 3; ++i) {
                auto temp = room.get_neighbour();
                if (pos == (*temp[i]).get_number()) {
                    room = *temp[i];
                    do_from();
                }
            }
        }

        void do_from() {
            if (room.get_bat()) {
                int d_ist = rand_dip(1, 20);
                move_to(d_ist);
            }
            if (room.get_pit()) {
                kill();
            }
            if (room.get_vamp()) {
                kill();
            }
        }

    private:
        bool alive;
        int arrows;
        Room room;
    };

    class Cave {
    public:
        Cave() : num_of_rooms{ 20 }, num_of_bats{ 5 }, num_of_pits{ 5 } {
            cave.reserve(num_of_rooms);

            for (int i{ 0 }; i < cave.capacity(); ++i) {
                cave.push_back(Room());
            }

            generate_neighbours();

            num_generate();

            mobs_generate();

            vamp_generate();
        }

        Room get_room(int pos) {
            return cave[pos];
        }

    private:
        vector<Room> cave;
        int num_of_bats;
        int num_of_pits;
        int num_of_rooms;

        void vamp_generate() {
            for (int i{ 1 }; i < cave.size(); ++i) {
                if (!cave[i].get_bat() and !cave[i].get_pit()) {
                    cave[i].set_vamp(true);
                    return;
                }
            }
        }

        void num_generate() {
            vector<int> numbers;

            for (int i{ 1 }; i < 21; ++i) {
                numbers.push_back(i);
            }

            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            srand(time(0));
            shuffle(numbers.begin(), numbers.end(), default_random_engine(seed));

            for (int i{ 0 }; i < cave.size(); ++i) {
                cave[i].set_number(numbers[i]);
            }
        }

        bool check_room_b(int room) {
            int counter{ 0 };

            for (int i{ 0 }; i < cave[room].get_neighbour().size(); ++i) {
                if (cave[room].get_neighbour()[i]->get_bat()) {
                    ++counter;
                }
            }

            if (counter > 2) return false;
            else return true;
        }

        bool check_room_p(int room) {
            int counter{ 0 };

            for (int i{ 0 }; i < cave[room].get_neighbour().size(); ++i) {
                if (cave[room].get_neighbour()[i]->get_pit()) {
                    ++counter;
                }
            }

            if (counter > 2) return false;
            else return true;
        }

        void mobs_generate() {
            for (int i{ 0 }; i < num_of_bats; ++i) {
                while (true) {
                    int room = rand_dip(1, 19);
                    if (check_room_b(room)) {
                        cave[room].set_bat(true);
                        break;
                    }
                }
            }

            for (int i{ 0 }; i < num_of_pits; ++i) {
                while (true) {
                    int room = rand_dip(1, 19);
                    if (check_room_p(room)) {
                        cave[room].set_pit(true);
                        break;
                    }
                }
            }
        }

        void generate_neighbours() {
            cave[0].set_ptr(cave[1].ptr(), cave[4].ptr(), cave[7].ptr());
            cave[1].set_ptr(cave[0].ptr(), cave[2].ptr(), cave[9].ptr());
            cave[2].set_ptr(cave[1].ptr(), cave[3].ptr(), cave[11].ptr());
            cave[3].set_ptr(cave[2].ptr(), cave[4].ptr(), cave[13].ptr());
            cave[4].set_ptr(cave[0].ptr(), cave[3].ptr(), cave[5].ptr());
            cave[5].set_ptr(cave[4].ptr(), cave[6].ptr(), cave[14].ptr());
            cave[6].set_ptr(cave[5].ptr(), cave[7].ptr(), cave[16].ptr());
            cave[7].set_ptr(cave[0].ptr(), cave[6].ptr(), cave[8].ptr());
            cave[8].set_ptr(cave[7].ptr(), cave[9].ptr(), cave[17].ptr());
            cave[9].set_ptr(cave[1].ptr(), cave[8].ptr(), cave[10].ptr());
            cave[10].set_ptr(cave[9].ptr(), cave[11].ptr(), cave[18].ptr());
            cave[11].set_ptr(cave[2].ptr(), cave[10].ptr(), cave[12].ptr());
            cave[12].set_ptr(cave[11].ptr(), cave[13].ptr(), cave[19].ptr());
            cave[13].set_ptr(cave[3].ptr(), cave[12].ptr(), cave[14].ptr());
            cave[14].set_ptr(cave[5].ptr(), cave[13].ptr(), cave[15].ptr());
            cave[15].set_ptr(cave[14].ptr(), cave[16].ptr(), cave[19].ptr());
            cave[16].set_ptr(cave[6].ptr(), cave[15].ptr(), cave[17].ptr());
            cave[17].set_ptr(cave[8].ptr(), cave[16].ptr(), cave[18].ptr());
            cave[18].set_ptr(cave[10].ptr(), cave[17].ptr(), cave[19].ptr());
            cave[19].set_ptr(cave[12].ptr(), cave[15].ptr(), cave[18].ptr());
        }
    };

    class Game {
    public:
        Game() {
            player.set_room(cave.get_room(0));
        }

        void playing() {
            while (true) {
                vector<int> nums{};
                string action{};

                cout << "Room #" << player.get_room().get_number() << endl;
                cout << "Neighbours are: ";

                for (int i{ 0 }; i < player.get_room().get_neighbour().size(); ++i) {
                    int k = player.get_room().get_neighbour()[i]->get_number();
                    cout << k << " ";
                    nums.push_back(k);
                }
                cout << "\n>";

                cin >> action;

                if (action[0] == 'm') {
                    string temp;
                    for (int i{ 1 }; i < action.size(); ++i) {
                        temp.push_back(action[i]);
                    }
                    int num = atoi(temp.c_str());

                    bool marker{ false };
                    for (auto k : nums) {
                        if (num == k) marker = true;
                    }

                    if(!marker) cout << "Wrong way, my friend!\n";
                    else player.move_to(num);
                }
            }
        }

    private:
        Player player;
        Cave cave;
    };

}

void ex_12_18() {
    Vamp::Game g;
    g.playing();

    cout << "Test" << endl;
}