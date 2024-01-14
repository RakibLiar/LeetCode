class Solution {
public:
  bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) {
      return false;
    }

    set<char> charSet1(word1.begin(), word1.end());
    set<char> charSet2(word2.begin(), word2.end());

    if (charSet1 != charSet2) {
      return false;
    }

    unordered_map<char, int> freq1;
    unordered_map<char, int> freq2;

    for (char c : word1) {
      freq1[c]++;
    }
    for (char c : word2) {
      freq2[c]++;
    }

    multiset<int> freqSet1;
    multiset<int> freqSet2;

    for (auto f : freq1) {
      freqSet1.insert(f.second);
    }
    for (auto f : freq2) {
      freqSet2.insert(f.second);
    }

    return freqSet1 == freqSet2;
  }
};