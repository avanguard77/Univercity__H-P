#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

void find_cycles(int node, std::vector<bool>& visited, std::vector<bool>& in_stack, std::set<int>& result_set, const std::vector<int>& a) {
    vector<int> stack;
    unordered_map<int, int> index_map;

    int current = node;
    while (!visited[current]) {
        visited[current] = true;
        in_stack[current] = true;
        stack.push_back(current);
        index_map[current] = stack.size();

        int next_node = a[current];

        if (in_stack[next_node]) {
            if (index_map.find(next_node) != index_map.end()) {
                while (!stack.empty() && index_map[stack.back()] >= index_map[next_node]) {
                    result_set.insert(stack.back());
                    stack.pop_back();
                }
            }
            break;
        }

        current = next_node;
    }

    while (!stack.empty()) {
        in_stack[stack.back()] = false;
        stack.pop_back();
    }
}

std::pair<int, std::vector<int>> largest_subset(int n, const std::vector<int>& a) {
    std::vector<bool> visited(n + 1, false);
    std::vector<bool> in_stack(n + 1, false);
    std::set<int> result_set;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            find_cycles(i, visited, in_stack, result_set, a);
        }
    }

    std::vector<int> result_list(result_set.begin(), result_set.end());
    std::sort(result_list.begin(), result_list.end());
    return {result_list.size(), result_list};
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    auto [size, subset] = largest_subset(n, a);
    std::cout << size << std::endl;
    for (int i : subset) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
