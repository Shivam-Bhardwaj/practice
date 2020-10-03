//
// Created by shivam on 10/3/20.
//

#include "iostream"
#include "any"
#include "vector"
#include "cassert"
#include "algorithm"
#include "map"

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
  // Write your code here.
  vector<vector<string >> result;
  unordered_map<string, vector<string>> hash_table;
  for (auto &i: words) {
    auto current_word = i;
    sort(current_word.begin(), current_word.end());
    if (hash_table.find(current_word) == hash_table.end()) {
      hash_table[current_word] = vector<string>{i};
    } else {
      hash_table[current_word].push_back(i);
    }
  }
  result.reserve(hash_table.size());
  for (const auto &i: hash_table) {
    result.push_back(i.second);
  }
  return result;
}

bool compare(vector<vector<string>> expected, vector<vector<string>> output) {
  if (expected.size() != output.size()) {
    return false;
  }

  for (auto group : expected) {
    sort(group.begin(), group.end());
    if (find(output.begin(), output.end(), group) == output.end()) {
      return false;
    }
  }
  return true;
}

int main() {
  {
    vector<string> words = {"yo", "act", "flop", "tac",
                            "foo", "cat", "oy", "olfp"};
    vector<vector<string>> expected = {
      {"yo",   "oy"},
      {"flop", "olfp"},
      {"act",  "tac", "cat"},
      {"foo"}};
    vector<vector<string>> output = groupAnagrams(words);
    for (auto &el : output) {
      sort(el.begin(), el.end());
    }
    assert(compare(expected, output));
    cout << "TEST 0 PASS";
  }

}

