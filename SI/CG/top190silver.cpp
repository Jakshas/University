#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

class Cell {
  public:
    Cell() {
        neighbors.resize(6);
    }

    void input() {
        cin >> cellIndex >> richness;
        for (auto &n : neighbors) {
            cin >> n;
        }
    }
    int cellIndex;
    int richness;
    vector<int> neighbors;
};

class Tree {
  public:
    Tree() = default;
    Tree(int cell_index, int size, bool is_mine, bool is_dormant) : cellIndex{cell_index}, size{size}, isMine{is_mine}, isDormant{is_dormant} {}
    void input() {
        cin >> cellIndex >> size >> isMine >> isDormant;
    }
    int cellIndex;
    int size;
    bool isMine;
    bool isDormant;
};

class Game {
  private:
    int day = 0;
    int nutrients = 0;
    vector<Cell> board;
    vector<Tree> trees;
    vector<tuple<string, int, int>> possible_actions;
    vector<tuple<int, int>> possibleSeeds;
    vector<int> possibleGrows;
    vector<int> possibleHarvests;
    int mySun;
    int oppSun;
    int score;
    int oppScore;
    int oppIsWaiting;
    int middleCuts = 0;
    int midRadCuts = 0;

  public:
    void inputInitData() {
        int numberOfCells;
        cin >> numberOfCells;
        for (int i = 0; i < numberOfCells; i++) {
            Cell cell;
            cell.input();
            board.push_back(cell);
        }
    }

    void inputInfo() {
        // input game info
        cin >> day;
        cin >> nutrients;
        cin >> mySun >> score;
        cin >> oppSun >> oppScore >> oppIsWaiting;

        // input trees info
        trees.clear();
        int numberOfTrees;
        cin >> numberOfTrees;
        for (int i = 0; i < numberOfTrees; i++) {
            Tree tree;
            tree.input();
            trees.push_back(tree);
        }

        // input possible actions
        possibleGrows.clear();
        possibleHarvests.clear();
        possibleSeeds.clear();
        int numberOfPossibleMoves;
        cin >> numberOfPossibleMoves;
        for (int i = 0; i < numberOfPossibleMoves; i++) {
            string type;
            int arg1 = 0;
            int arg2 = 0;
            cin >> type;

            if (type == "WAIT") {
                continue;
            } else if (type == "COMPLETE") {
                cin >> arg1;
                possibleHarvests.push_back(arg1);
            } else if (type == "GROW") {
                cin >> arg1;
                possibleGrows.push_back(arg1);
            } else if (type == "SEED") {
                cin >> arg1;
                cin >> arg2;
                possibleSeeds.push_back(make_tuple(arg1, arg2));
            }
        }
    }
    //poprawic rozstawianie drzew w gore i dol - inne wykrywanie
    //hardcode na pierwsze 5 dni
    //zająć środek w pierwszych dniach
    //dodac 'rzut' drzewem na odleglosc

    string compute_next_action() {
        if (day != 23) {
            vector<tuple<int, int>> plantFields; //(idx, richness)
            make_heap(plantFields.begin(), plantFields.end(), [](const auto &a, const auto &b) {
                return get<1>(a) < get<1>(b);
            });
            int treeSum = 0;
            int lvl3 = 0;
            int lvl2 = 0;
            int lvl1 = 0;
            vector<Tree> myTrees;
            for (const auto &tree : trees) {
                if (tree.isMine) {
                    myTrees.push_back(tree);
                    treeSum++;
                    if (tree.size == 3)
                        lvl3++;
                    if (tree.size == 2)
                        lvl2++;
                    if (tree.size == 1)
                        lvl1++;
                }
            }

            // if (nutrients < 13) { //last moment for escape
            //     return "COMPLETE " + to_string(possibleHarvests[0]);
            // }

            if (possibleGrows.size() != 0) {
                sort(possibleGrows.begin(), possibleGrows.end(), [&](const auto &a, const auto &b) { //sort by best richness
                    return board[a].richness > board[b].richness;
                });

                auto g = find_if(myTrees.begin(), myTrees.end(), [&](const auto &tree) {
                    return tree.cellIndex == possibleGrows[0];
                });
                if (g != myTrees.end()) {
                    if (day < 12) {
                        return "GROW " + to_string(possibleGrows[0]); //grow a tree whenever possible without day 12, 22 & 23
                    } else if (day == 15 || day == 13 || day == 17) {
                        return "GROW " + to_string(possibleGrows[0]);
                    } else {
                        if ((*g).size == 2) {
                            if (mySun - 7 - lvl3 >= 4)
                                return "GROW " + to_string(possibleGrows[0]);
                        }
                        if ((*g).size == 1) {
                            if (mySun - 3 - lvl2 >= 4)
                                return "GROW " + to_string(possibleGrows[0]);
                        }
                        if ((*g).size == 0) {
                            if (mySun - 1 - lvl1 >= 4)
                                return "GROW " + to_string(possibleGrows[0]);
                        }
                    }
                }
            }
            cerr << "MYSUN AFTER DEL - " << mySun - 7 - lvl3 << endl;
            int maxCuts = 1;
            if (day > 13) {
                maxCuts++;
            }
            if (day > 15) {
                maxCuts += 2;
            }
            if (day > 16) {
                maxCuts++;
            }
            if (day > 17) {
                maxCuts += 3;
            }
            if (day > 19) {
                maxCuts += 10;
            }
            cerr << "MIDDLE CUTS: " << middleCuts << endl;
            cerr << "MAX CUTS: " << maxCuts << endl;
            for (const auto &tree : myTrees) {
                cerr << tree.cellIndex << endl;
                if (tree.cellIndex < 7 && tree.size == 3 && day > 11) { //collect most valuable trees ealier
                    if (middleCuts < maxCuts) {

                        auto temp = find_if(possibleHarvests.begin(), possibleHarvests.end(), [&](const auto &a) {
                            return a == tree.cellIndex;
                        });
                        if (temp != possibleHarvests.end()) {
                            middleCuts++;
                            return "COMPLETE " + to_string(tree.cellIndex);
                        }
                    }
                }
                if (tree.cellIndex < 19 && tree.size == 3 && day > 11) { //collect most valuable trees ealier
                    if (middleCuts < maxCuts) {

                        auto temp = find_if(possibleHarvests.begin(), possibleHarvests.end(), [&](const auto &a) {
                            return a == tree.cellIndex;
                        });
                        if (temp != possibleHarvests.end()) {
                            middleCuts++;
                            return "COMPLETE " + to_string(tree.cellIndex);
                        }
                    }
                }
                if (tree.cellIndex < 39 && tree.size == 3 && day > 11) { //collect most valuable trees ealier
                    if (middleCuts < maxCuts) {

                        auto temp = find_if(possibleHarvests.begin(), possibleHarvests.end(), [&](const auto &a) {
                            return a == tree.cellIndex;
                        });
                        if (temp != possibleHarvests.end()) {
                            middleCuts++;
                            return "COMPLETE " + to_string(tree.cellIndex);
                        }
                    }
                }
            }

            for (const auto &tree : myTrees) { //check between trees
                if (!tree.isDormant && tree.size > 1) {
                    cerr << "Current tree: " << tree.cellIndex << endl;
                    for (int k = 0; k < 6; k++) {
                        int neighbor = board[tree.cellIndex].neighbors[k];
                        if (neighbor != -1) {
                            int field = board[neighbor].neighbors[(k + 1) % 6];
                            if (field != -1 && board[field].richness != 0) {
                                bool guard = true;
                                cerr << "FIELD: " << field << endl;
                                for (int i = 0; i < trees.size(); i++) {
                                    if (trees[i].cellIndex == field) { //check is field is empty
                                        guard = false;
                                        break;
                                    }

                                    for (int l = 0; l < 6; l++) {
                                        if (board[field].neighbors[l] == trees[i].cellIndex && trees[i].isMine) { //dont place seed next to my trees
                                            guard = false;
                                            break;
                                        }
                                    }
                                }
                                if (guard) {
                                    plantFields.push_back(make_tuple(field, board[field].richness));
                                    push_heap(plantFields.begin(), plantFields.end(), [](const auto &a, const auto &b) {
                                        return get<1>(a) < get<1>(b);
                                    });
                                }
                            }
                        }
                    }
                }
            }
            cerr << "TREESUM: " << treeSum << endl;
            if (day < 17 && treeSum < 8) {
                for (int i = 0; i < 37; i++) {
                    int sum = 0;
                    for (int j = 0; j < 6; j++) {
                        for (const auto &tree : trees) {
                            if (tree.cellIndex == board[i].neighbors[j] && !tree.isMine) { //sum = enemy trees around given field
                                sum++;
                            }
                        }
                    }
                    if (sum > 3) { //2 na 700
                        for (const auto &p : possibleSeeds) {
                            if (get<1>(p) == i) {
                                return "SEED " + to_string(get<0>(p)) + " " + to_string(get<1>(p));
                            }
                        }
                    }
                }

                if (plantFields.size() == 0) {
                    return "WAIT";
                }
                auto front = plantFields.front();
                cerr << "BEST SEED: " << get<0>(front) << endl;
                if (treeSum < 8) {
                    for (const auto &p : possibleSeeds) {
                        if (get<1>(p) == get<0>(front)) {
                            return "SEED " + to_string(get<0>(p)) + " " + to_string(get<1>(p));
                        }
                    }
                }
            }
        } else {
            for (const auto &tree : trees) {
                if (tree.isMine && tree.size == 3) {
                    return "COMPLETE " + to_string(tree.cellIndex);
                }
            }
        }
        return "WAIT";
    }
};

int main() {
    Game game;
    game.inputInitData();

    while (true) {
        game.inputInfo();

        cout << game.compute_next_action() << endl;
    }
}