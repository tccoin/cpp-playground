#include <cmath>

// #1 naive solution
class Solution {
 public:
  string longestWord(vector<string>& words) {
    vector<vector<string>> dict;
    dict.resize(30);
    size_t maxSize = 0;
    for (string word : words) {
      dict[word.size() - 1].push_back(word);
      maxSize = max(word.size(), maxSize);
    }
    if (dict[0].size() == 0) return "";
    int largestSize = 1;
    for (int i = 1; i < maxSize; i++) {
      vector<string> next;
      for (int j = 0; j < dict[i].size(); j++) {
        string word = dict[i][j];
        for (string dictWord : dict[i - 1]) {
          if (word.substr(0, i) == dictWord) {
            next.push_back(word);
          }
        }
      }
      dict[i] = next;
      if (next.size() > 0) largestSize = i + 1;
    }
    sort(dict[largestSize - 1].begin(), dict[largestSize - 1].end());
    return dict[largestSize - 1][0];
  }
};

// #2 Brute Force, best solution in all 4 methods
class Solution {
 public:
  string longestWord(vector<string>& words) {
    auto cmp = [](auto& a, auto& b) {
      return a.size() == b.size() ? a < b : a.size() < b.size();
    };
    set<string, decltype(cmp)> dict(cmp);
    for (string word : words) dict.insert(word);
    string result = "";
    for (string word : words) {
      if (word.size() < result.size() ||
          word.size() == result.size() && word >= result)
        continue;
      bool valid = true;
      for (int i = 1; i < word.size(); i++) {
        if (!dict.count(word.substr(0, i))) {
          valid = false;
          break;
        }
      }
      if (valid) result = word;
    }
    return result;
  }
};

// #3 Trie with sorted input
class TrieNode {
 public:
  char val;
  unordered_map<char, TrieNode*> children;
  TrieNode(char val_) : val(val_) {}
};

class Solution {
 public:
  string longestWord(vector<string>& words) {
    auto cmp = [](auto a, auto b) { return a.size() < b.size(); };
    sort(words.begin(), words.end(), cmp);
    string result = "";
    TrieNode* root = createNode(' ');
    TrieNode* curr;
    for (auto word : words) {
      curr = root;
      bool success = true;
      for (int i = 0; i < word.size() - 1; i++) {
        if (curr->children.count(word[i])) {
          curr = curr->children[word[i]];
        } else {
          success = false;
          break;
        }
      }
      if (!success) continue;
      char lastChar = *(word.rbegin());
      curr->children[lastChar] = createNode(lastChar);
      if (word.size() > result.size() ||
          word.size() == result.size() && word < result) {
        result = word;
      }
    }
    deleteNodes();
    return result;
  }

  vector<TrieNode*> nodes;

  TrieNode* createNode(char val) {
    TrieNode* node = new TrieNode(val);
    nodes.push_back(node);
    return node;
  };

  void deleteNodes() {
    for (auto node : nodes) delete node;
  }
};

// #4 Trie with unsorted input, better than #3
class TrieNode {
 public:
  char val;
  int wordIndex = -1;
  unordered_map<char, TrieNode*> children;
  TrieNode(char val_) : val(val_) {}
};

class Trie {
 public:
  TrieNode* root;
  vector<string>& words;

  Trie(vector<string>& words_) : words(words_) {
    root = new TrieNode(' ');
    insertWords();
  }

  void insertWords() {
    TrieNode* curr;
    for (int i = 0; i < words.size(); i++) {
      string word = words[i];
      curr = root;
      for (char ch : word) {
        if (!curr->children.count(ch)) {
          curr->children[ch] = new TrieNode(ch);
        }
        curr = curr->children[ch];
      }
      curr->wordIndex = i;
    }
  }

  string search() {
    stack<TrieNode*> todo;
    todo.push(root);
    string result = "";
    TrieNode* curr;
    while (!todo.empty()) {
      curr = todo.top();
      todo.pop();
      if (curr->wordIndex != -1 || curr == root) {
        for (auto child : curr->children) {
          todo.push(child.second);
        }
      }
      if (curr->wordIndex != -1) {
        string word = words[curr->wordIndex];
        if (word.size() > result.size() ||
            word.size() == result.size() && word < result) {
          result = word;
        }
      }
    }
    return result;
  }
};

class Solution {
 public:
  string longestWord(vector<string>& words) {
    Trie tree(words);
    return tree.search();
  }
};