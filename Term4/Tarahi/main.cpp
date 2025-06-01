
#include <iostream>
#include <vector>
#include <string>


int number_of_rows_in_grid;
int number_of_columns_in_grid;

std::vector<std::vector<char>> game_board_layout;
std::vector<std::vector<int>> previously_found_scores;

const int SCORE_FOR_BLOCKED_PATH = -2000000000;

int figure_out_max_score(int current_r, int current_c);

int main() {

    std::cin >> number_of_rows_in_grid;
    std::cin >> number_of_columns_in_grid;

    std::string temp_text_line;
    std::getline(std::cin, temp_text_line);

    game_board_layout.resize(number_of_rows_in_grid);

    int row_counter_for_setup_1;
    for (row_counter_for_setup_1 = 0; row_counter_for_setup_1 < number_of_rows_in_grid; row_counter_for_setup_1 = row_counter_for_setup_1 + 1) {
        game_board_layout[row_counter_for_setup_1].resize(number_of_columns_in_grid);
    }

    int row_counter_for_reading;
    for (row_counter_for_reading = 0; row_counter_for_reading < number_of_rows_in_grid; row_counter_for_reading = row_counter_for_reading + 1) {
        std::string line_of_chars_read;
        std::getline(std::cin, line_of_chars_read);

        int col_counter_for_reading;
        for (col_counter_for_reading = 0; col_counter_for_reading < number_of_columns_in_grid; col_counter_for_reading = col_counter_for_reading + 1) {

            game_board_layout[row_counter_for_reading][col_counter_for_reading] = line_of_chars_read[col_counter_for_reading];
        }
    }

    previously_found_scores.resize(number_of_rows_in_grid);
    int row_counter_for_setup_2;
    for (row_counter_for_setup_2 = 0; row_counter_for_setup_2 < number_of_rows_in_grid; row_counter_for_setup_2 = row_counter_for_setup_2 + 1) {
        previously_found_scores[row_counter_for_setup_2].resize(number_of_columns_in_grid);
    }

    int row_counter_for_init;
    for (row_counter_for_init = 0; row_counter_for_init < number_of_rows_in_grid; row_counter_for_init = row_counter_for_init + 1) {
        int col_counter_for_init;
        for (col_counter_for_init = 0; col_counter_for_init < number_of_columns_in_grid; col_counter_for_init = col_counter_for_init + 1) {
            previously_found_scores[row_counter_for_init][col_counter_for_init] = -1;
        }
    }


    int max_score_overall = 0;

    int starting_row_iterator;
    for (starting_row_iterator = 0; starting_row_iterator < number_of_rows_in_grid; starting_row_iterator = starting_row_iterator + 1) {

        int starting_col_iterator;
        for (starting_col_iterator = 0; starting_col_iterator < number_of_columns_in_grid; starting_col_iterator = starting_col_iterator + 1) {

            char current_char_on_board;
            current_char_on_board = game_board_layout[starting_row_iterator][starting_col_iterator];

            if (current_char_on_board == 'W') {

                int temp_score_for_a_path;

                int next_row_option1;
                int next_col_option1;
                next_row_option1 = starting_row_iterator - 1; // Move one row up
                next_col_option1 = starting_col_iterator - 1; // Move one col left

                bool is_option1_valid = true;

                if (next_row_option1 < 0) { is_option1_valid = false; }
                if (next_row_option1 >= number_of_rows_in_grid) { is_option1_valid = false; }

                if (next_col_option1 < 0) { is_option1_valid = false; }
                if (next_col_option1 >= number_of_columns_in_grid) { is_option1_valid = false; }

                if (is_option1_valid == true) {
                    char char_at_destination1;
                    char_at_destination1 = game_board_layout[next_row_option1][next_col_option1];

                    if (char_at_destination1 != 'W') {
                        temp_score_for_a_path = figure_out_max_score(next_row_option1, next_col_option1);

                        if (temp_score_for_a_path > max_score_overall) {
                            max_score_overall = temp_score_for_a_path;
                        }
                    }
                }

                int next_row_option2;
                int next_col_option2;
                next_row_option2 = starting_row_iterator - 1;
                next_col_option2 = starting_col_iterator;

                bool is_option2_valid = true;
                if (next_row_option2 < 0) { is_option2_valid = false; }
                if (next_row_option2 >= number_of_rows_in_grid) { is_option2_valid = false; }

                if (next_col_option2 < 0) { is_option2_valid = false; }
                if (next_col_option2 >= number_of_columns_in_grid) { is_option2_valid = false; }

                if (is_option2_valid == true) {
                    char char_at_destination2;
                    char_at_destination2 = game_board_layout[next_row_option2][next_col_option2];

                    if (char_at_destination2 != 'W') {
                        temp_score_for_a_path = figure_out_max_score(next_row_option2, next_col_option2);
                        if (temp_score_for_a_path > max_score_overall) {
                            max_score_overall = temp_score_for_a_path;
                        }
                    }
                }
                int next_row_option3;
                int next_col_option3;
                next_row_option3 = starting_row_iterator - 1;
                next_col_option3 = starting_col_iterator + 1;

                bool is_option3_valid = true;
                if (next_row_option3 < 0) { is_option3_valid = false; }
                if (next_row_option3 >= number_of_rows_in_grid) { is_option3_valid = false; }
                if (next_col_option3 < 0) { is_option3_valid = false; }
                if (next_col_option3 >= number_of_columns_in_grid) { is_option3_valid = false; }

                if (is_option3_valid == true) {
                    char char_at_destination3;
                    char_at_destination3 = game_board_layout[next_row_option3][next_col_option3];

                    if (char_at_destination3 != 'W') {
                        temp_score_for_a_path = figure_out_max_score(next_row_option3, next_col_option3);
                        if (temp_score_for_a_path > max_score_overall) {
                            max_score_overall = temp_score_for_a_path;
                        }
                    }
                }
            }
        }
    }

    std::cout << max_score_overall << std::endl;

    return 0;
}


int figure_out_max_score(int current_r, int current_c) {

    bool is_row_off_board;
    is_row_off_board = (current_r < 0) || (current_r >= number_of_rows_in_grid);

    bool is_col_off_board;
    is_col_off_board = (current_c < 0) || (current_c >= number_of_columns_in_grid);

    if (is_row_off_board == true || is_col_off_board == true) {
        return 0;
    }

    char char_here;
    char_here = game_board_layout[current_r][current_c];

    if (char_here == 'W') {
        return SCORE_FOR_BLOCKED_PATH;
    }

    int saved_score_value;
    saved_score_value = previously_found_scores[current_r][current_c];
    if (saved_score_value != -1) {
        return saved_score_value;
    }

    int points_for_this_cell = 0;
    if (char_here == 'B') {
        points_for_this_cell = 1;
    }

    int best_score_from_future_moves = 0;
    int score_from_one_recursive_call;

    int next_r_val_try1;
    int next_c_val_try1;
    next_r_val_try1 = current_r - 1;
    next_c_val_try1 = current_c - 1;

    score_from_one_recursive_call = figure_out_max_score(next_r_val_try1, next_c_val_try1);

    if (score_from_one_recursive_call != SCORE_FOR_BLOCKED_PATH) {

        if (score_from_one_recursive_call > best_score_from_future_moves) {
            best_score_from_future_moves = score_from_one_recursive_call;
        }
    }

    int next_r_val_try2;
    next_r_val_try2 = current_r - 1;

    score_from_one_recursive_call = figure_out_max_score(next_r_val_try2, current_c);
    if (score_from_one_recursive_call != SCORE_FOR_BLOCKED_PATH) {
        if (score_from_one_recursive_call > best_score_from_future_moves) {
            best_score_from_future_moves = score_from_one_recursive_call;
        }
    }

    int next_r_val_try3;
    int next_c_val_try3;
    next_r_val_try3 = current_r - 1;
    next_c_val_try3 = current_c + 1;

    score_from_one_recursive_call = figure_out_max_score(next_r_val_try3, next_c_val_try3);
    if (score_from_one_recursive_call != SCORE_FOR_BLOCKED_PATH) {
        if (score_from_one_recursive_call > best_score_from_future_moves) {
            best_score_from_future_moves = score_from_one_recursive_call;
        }
    }

    int final_score_for_this_cell;
    final_score_for_this_cell = points_for_this_cell + best_score_from_future_moves;

    previously_found_scores[current_r][current_c] = final_score_for_this_cell;

    return final_score_for_this_cell;
}