#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <cassert>

/**
 * Battleship field validator
 *
 * Write a method that takes a field for well-known board game "Battleship" as an argument and
 * returns true if it has a valid disposition of ships, false otherwise.
 * Argument is guaranteed to be 10*10 two-dimension array.
 * Elements in the array are numbers, 0 if the cell is free and 1 if occupied by ship.
 *
 * Sheeps:
 * 4 cell - 1
 * 3 cell - 2
 * 2 cell - 3
 * 1 cell - 4
 */

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> &p) const {
        return p.first * 1337 + p.second;
    }
};

bool validate_battlefield(std::vector<std::vector<int>> field)
{
    int counter_sheep_4_cell {0}; // expected 1
    int counter_sheep_3_cell {0}; // expected 2
    int counter_sheep_2_cell {0}; // expected 3
    int counter_sheep_1_cell {0}; // expected 4

    using Coord_t = std::pair<int, int>;
    std::unordered_set<Coord_t, pair_hash> checked_fields;

    enum class SheepState {
        IsSheep,
        IsNotSheep,
        SheepCorrupted
    };

    auto is_corrupted = [&field](Coord_t coord) -> bool { return field[coord.first][coord.second]; };

    auto check_is_sheep_4_cell = [&is_corrupted, &checked_fields, &field](Coord_t coord) -> SheepState {
        // Валидация размеров вправо и вниз
        if (static_cast<size_t>(coord.first + 3) < field.size() &&
            static_cast<size_t>(coord.second + 3) < field[coord.first].size()) {
            return SheepState::IsNotSheep;
        }

        // check row
        const std::map<Coord_t, bool> row_fields{{std::make_pair(coord.first,     coord.second), field[coord.first]    [coord.second]},
                                                 {std::make_pair(coord.first + 1, coord.second), field[coord.first + 1][coord.second]},
                                                 {std::make_pair(coord.first + 2, coord.second), field[coord.first + 2][coord.second]},
                                                 {std::make_pair(coord.first + 3, coord.second), field[coord.first + 3][coord.second]}};

        if (std::all_of(row_fields.begin(), row_fields.end(), [](std::pair<std::pair<int, int>, bool> el) { return el.second; })) {
            for (auto [coord, cell_is_occupied]: row_fields) {
                checked_fields.insert(coord);

                const bool has_right_cell = static_cast<size_t>(coord.first + 1) < field.size();
                if (has_right_cell) {
                    Coord_t right_coord = coord;
                    ++right_coord.first;
                    if (is_corrupted(right_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(right_coord);
                }

                const bool has_down_cell = static_cast<size_t>(coord.second + 1) < field[coord.first].size();
                if (has_down_cell) {
                    Coord_t down_coord = coord;
                    ++down_coord.second;
                    if (is_corrupted(down_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(down_coord);
                }

                if (has_right_cell && has_down_cell) {
                    Coord_t right_down_coord = coord;
                    ++right_down_coord.second;
                    if (is_corrupted(right_down_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(right_down_coord);
                }
            }
            return SheepState::IsSheep;
        }

        // check column
        const std::map<Coord_t, bool> column_fields{{std::make_pair(coord.first, coord.second),     field[coord.first][coord.second]},
                                                    {std::make_pair(coord.first, coord.second + 1), field[coord.first][coord.second + 1]},
                                                    {std::make_pair(coord.first, coord.second + 2), field[coord.first][coord.second + 2]},
                                                    {std::make_pair(coord.first, coord.second + 3), field[coord.first][coord.second + 3]}};

        if (std::all_of(column_fields.begin(), column_fields.end(), [](std::pair<std::pair<int, int>, bool> el) { return el.second; })) {
            for (auto [coord, cell_is_occupied]: column_fields) {
                checked_fields.insert(coord);

                const bool has_right_cell = static_cast<size_t>(coord.first + 1) < field.size();
                if (has_right_cell) {
                    Coord_t right_coord = coord;
                    ++right_coord.first;
                    if (is_corrupted(right_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(right_coord);
                }

                const bool has_down_cell = static_cast<size_t>(coord.second + 1) < field[coord.first].size();
                if (has_down_cell) {
                    Coord_t down_coord = coord;
                    ++down_coord.second;
                    if (is_corrupted(down_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(down_coord);
                }

                if (has_right_cell && has_down_cell) {
                    Coord_t right_down_coord = coord;
                    ++right_down_coord.second;
                    if (is_corrupted(right_down_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(right_down_coord);
                }
            }
            return SheepState::IsSheep;
        }

        return SheepState::IsNotSheep;
    };
    auto check_is_sheep_3_cell = [&is_corrupted, &checked_fields, &field](Coord_t coord) -> SheepState {
        // Валидация размеров вправо и вниз
        if (static_cast<size_t>(coord.first + 2) < field.size() &&
            static_cast<size_t>(coord.second + 2) < field[coord.first].size()) {
            return SheepState::IsNotSheep;
        }

        // check row
        const std::map<Coord_t, bool> row_fields{{std::make_pair(coord.first,     coord.second), field[coord.first]    [coord.second]},
                                                 {std::make_pair(coord.first + 1, coord.second), field[coord.first + 1][coord.second]},
                                                 {std::make_pair(coord.first + 2, coord.second), field[coord.first + 2][coord.second]}};

        if (std::all_of(row_fields.begin(), row_fields.end(), [](std::pair<std::pair<int, int>, bool> el) { return el.second; })) {
            for (auto [coord, cell_is_occupied]: row_fields) {
                checked_fields.insert(coord);

                const bool has_right_cell = static_cast<size_t>(coord.first + 1) < field.size();
                if (has_right_cell) {
                    Coord_t right_coord = coord;
                    ++right_coord.first;
                    if (is_corrupted(right_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(right_coord);
                }

                const bool has_down_cell = static_cast<size_t>(coord.second + 1) < field[coord.first].size();
                if (has_down_cell) {
                    Coord_t down_coord = coord;
                    ++down_coord.second;
                    if (is_corrupted(down_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(down_coord);
                }

                if (has_right_cell && has_down_cell) {
                    Coord_t right_down_coord = coord;
                    ++right_down_coord.second;
                    if (is_corrupted(right_down_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(right_down_coord);
                }
            }
            return SheepState::IsSheep;
        }

        // check column
        const std::map<Coord_t, bool> column_fields{{std::make_pair(coord.first, coord.second),     field[coord.first][coord.second]},
                                                    {std::make_pair(coord.first, coord.second + 1), field[coord.first][coord.second + 1]},
                                                    {std::make_pair(coord.first, coord.second + 2), field[coord.first][coord.second + 2]}};

        if (std::all_of(column_fields.begin(), column_fields.end(), [](std::pair<std::pair<int, int>, bool> el) { return el.second; })) {
            for (auto [coord, cell_is_occupied]: column_fields) {
                checked_fields.insert(coord);

                const bool has_right_cell = static_cast<size_t>(coord.first + 1) < field.size();
                if (has_right_cell) {
                    Coord_t right_coord = coord;
                    ++right_coord.first;
                    if (is_corrupted(right_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(right_coord);
                }

                const bool has_down_cell = static_cast<size_t>(coord.second + 1) < field[coord.first].size();
                if (has_down_cell) {
                    Coord_t down_coord = coord;
                    ++down_coord.second;
                    if (is_corrupted(down_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(down_coord);
                }

                if (has_right_cell && has_down_cell) {
                    Coord_t right_down_coord = coord;
                    ++right_down_coord.second;
                    if (is_corrupted(right_down_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(right_down_coord);
                }
            }
            return SheepState::IsSheep;
        }

        return SheepState::IsNotSheep;
    };
    auto check_is_sheep_2_cell = [&is_corrupted, &checked_fields, &field](Coord_t coord) -> SheepState {
        // Валидация размеров вправо и вниз
        if (static_cast<size_t>(coord.first + 1) < field.size() &&
            static_cast<size_t>(coord.second + 1) < field[coord.first].size()) {
            return SheepState::IsNotSheep;
        }

        // check row
        const std::map<Coord_t, bool> row_fields{{std::make_pair(coord.first,     coord.second), field[coord.first]    [coord.second]},
                                                 {std::make_pair(coord.first + 1, coord.second), field[coord.first + 1][coord.second]}};

        if (std::all_of(row_fields.begin(), row_fields.end(), [](std::pair<std::pair<int, int>, bool> el) { return el.second; })) {
            for (auto [coord, cell_is_occupied]: row_fields) {
                checked_fields.insert(coord);

                const bool has_right_cell = static_cast<size_t>(coord.first + 1) < field.size();
                if (has_right_cell) {
                    Coord_t right_coord = coord;
                    ++right_coord.first;
                    if (is_corrupted(right_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(right_coord);
                }

                const bool has_down_cell = static_cast<size_t>(coord.second + 1) < field[coord.first].size();
                if (has_down_cell) {
                    Coord_t down_coord = coord;
                    ++down_coord.second;
                    if (is_corrupted(down_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(down_coord);
                }

                if (has_right_cell && has_down_cell) {
                    Coord_t right_down_coord = coord;
                    ++right_down_coord.second;
                    if (is_corrupted(right_down_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(right_down_coord);
                }
            }
            return SheepState::IsSheep;
        }

        // check column
        const std::map<Coord_t, bool> column_fields{{std::make_pair(coord.first, coord.second),     field[coord.first][coord.second]},
                                                    {std::make_pair(coord.first, coord.second + 1), field[coord.first][coord.second + 1]}};

        if (std::all_of(column_fields.begin(), column_fields.end(), [](std::pair<std::pair<int, int>, bool> el) { return el.second; })) {
            for (auto [coord, cell_is_occupied]: column_fields) {
                checked_fields.insert(coord);

                const bool has_right_cell = static_cast<size_t>(coord.first + 1) < field.size();
                if (has_right_cell) {
                    Coord_t right_coord = coord;
                    ++right_coord.first;
                    if (is_corrupted(right_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(right_coord);
                }

                const bool has_down_cell = static_cast<size_t>(coord.second + 1) < field[coord.first].size();
                if (has_down_cell) {
                    Coord_t down_coord = coord;
                    ++down_coord.second;
                    if (is_corrupted(down_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(down_coord);
                }

                if (has_right_cell && has_down_cell) {
                    Coord_t right_down_coord = coord;
                    ++right_down_coord.second;
                    if (is_corrupted(right_down_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(right_down_coord);
                }
            }
            return SheepState::IsSheep;
        }

        return SheepState::IsNotSheep;
    };
    auto check_is_sheep_1_cell = [&is_corrupted, &checked_fields, &field](Coord_t coord) -> SheepState {
        // Валидация размеров вправо и вниз
//        if (coord.first + 1 < field.size() &&
//            coord.second + 1 < field[coord.first].size()) {
//            return SheepState::IsNotSheep;
//        }

        // check row
        const std::map<Coord_t, bool> row_fields{{std::make_pair(coord.first,coord.second),
                                                  field[coord.first][coord.second]}};

        if (std::all_of(row_fields.begin(), row_fields.end(), [](std::pair<std::pair<int, int>, bool> el) { return el.second; })) {
            for (auto [coord, cell_is_occupied]: row_fields) {
                checked_fields.insert(coord);

                const bool has_right_cell = static_cast<size_t>(coord.first + 1) < field.size();
                if (has_right_cell) {
                    Coord_t right_coord = coord;
                    ++right_coord.first;
                    if (is_corrupted(right_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(right_coord);
                }

                const bool has_down_cell = static_cast<size_t>(coord.second + 1) < field[coord.first].size();
                if (has_down_cell) {
                    Coord_t down_coord = coord;
                    ++down_coord.second;
                    if (is_corrupted(down_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(down_coord);
                }

                if (has_right_cell && has_down_cell) {
                    Coord_t right_down_coord = coord;
                    ++right_down_coord.second;
                    if (is_corrupted(right_down_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(right_down_coord);
                }
            }
            return SheepState::IsSheep;
        }

        // check column
        const std::map<Coord_t, bool> column_fields{{std::make_pair(coord.first, coord.second),     field[coord.first][coord.second]},
                                                    {std::make_pair(coord.first, coord.second + 1), field[coord.first][coord.second + 1]}};

        if (std::all_of(column_fields.begin(), column_fields.end(), [](std::pair<std::pair<int, int>, bool> el) { return el.second; })) {
            for (auto [coord, cell_is_occupied]: column_fields) {
                checked_fields.insert(coord);

                const bool has_right_cell = static_cast<size_t>(coord.first + 1) < field.size();
                if (has_right_cell) {
                    Coord_t right_coord = coord;
                    ++right_coord.first;
                    if (is_corrupted(right_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(right_coord);
                }

                const bool has_down_cell = static_cast<size_t>(coord.second + 1) < field[coord.first].size();
                if (has_down_cell) {
                    Coord_t down_coord = coord;
                    ++down_coord.second;
                    if (is_corrupted(down_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(down_coord);
                }

                if (has_right_cell && has_down_cell) {
                    Coord_t right_down_coord = coord;
                    ++right_down_coord.second;
                    if (is_corrupted(right_down_coord)) {
                        return SheepState::SheepCorrupted;
                    }
                    checked_fields.insert(right_down_coord);
                }
            }
            return SheepState::IsSheep;
        }

        return SheepState::IsNotSheep;
    };

    for (size_t x = 0; x < field.size(); ++x) {
        for (size_t y = 0; y < field[x].size(); ++y) {
            const auto coord = std::make_pair(x, y);
            if (checked_fields.find(coord) != checked_fields.end()) {
                continue;
            }

            const bool cell_is_occupied = static_cast<bool>(field[x][y]);
            if (!cell_is_occupied) {
                checked_fields.insert(coord);
                continue;
            }

            const SheepState is_sheep_4_cell = check_is_sheep_4_cell(coord);
            if (is_sheep_4_cell == SheepState::SheepCorrupted) {
                return false;
            }
            else if (is_sheep_4_cell == SheepState::IsSheep) {
                ++counter_sheep_4_cell;
                continue;
            }

            const SheepState is_sheep_3_cell = check_is_sheep_3_cell(coord);
            if (is_sheep_3_cell == SheepState::SheepCorrupted) {
                return false;
            }
            else if (is_sheep_3_cell == SheepState::IsSheep) {
                ++counter_sheep_3_cell;
                continue;
            }

            const SheepState is_sheep_2_cell = check_is_sheep_2_cell(coord);
            if (is_sheep_2_cell == SheepState::SheepCorrupted) {
                return false;
            }
            else if (is_sheep_2_cell == SheepState::IsSheep) {
                ++counter_sheep_2_cell;
                continue;
            }

            const SheepState is_sheep_1_cell = check_is_sheep_1_cell(coord);
            if (is_sheep_1_cell == SheepState::SheepCorrupted) {
                return false;
            }
            else if (is_sheep_1_cell == SheepState::IsSheep) {
                ++counter_sheep_1_cell;
                continue;
            }


            checked_fields.insert(coord);
        }
    }

    return counter_sheep_4_cell == 1 &&
           counter_sheep_3_cell == 2 &&
           counter_sheep_2_cell == 3 &&
           counter_sheep_1_cell == 4;
}

int main()
{
    // that is valid
    const std::vector battle_field_1 {std::vector{1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                                      std::vector{1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
                                      std::vector{1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
                                      std::vector{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                      std::vector{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                                      std::vector{0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                      std::vector{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                                      std::vector{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                                      std::vector{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                      std::vector{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    if (validate_battlefield(battle_field_1) == true) {
        int a;
    }

    return 0;
}
