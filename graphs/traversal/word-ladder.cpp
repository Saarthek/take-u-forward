/*
This code is a solution of the problem Word Ladder from LeetCode at the link
https://leetcode.com/problems/word-ladder/description/
The solution uses Breadth First Search (BFS) to find the shortest transformation sequence.
Input:
    beginWord -> Starting word
    endWord -> Target word
    n -> Number of words in the dictionary
    wordList[0] wordList[1] ... wordList[n-1] -> Dictionary words
Output:
    Length of the shortest transformation sequence from beginWord to endWord,
    or 0 if no such transformation exists.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
//Breadth First Search (BFS)
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool poss = false;
        for(string word : wordList){
            if(word == endWord){
                poss = true;
                break;
            }
        }

        int n = wordList.size();
        int lenw = beginWord.size();

        if(!poss){
            return 0;
        }

        queue<string> q;
        int ans = 0;
        q.push(beginWord);

        unordered_set<string> st;
        for(string word : wordList){
            st.insert(word);
        }

        while(!q.empty()){
            ans++;
            int qsz = q.size();

            //Level wise BFS traversal
            for(int i = 0; i < qsz; i++){
                string tp = q.front();
                q.pop();

                //Replace letters at every position
                for(int j = 0; j < lenw; j++){
                    char ch = tp[j];

                    //Try every possible replacement
                    for(char ch2 = 'a'; ch2 <= 'z'; ch2++){
                        if(ch2 != ch){
                            tp[j] = ch2;

                            if(st.find(tp) != st.end()){
                                q.push(tp);

                                if(tp == endWord){
                                    return ans + 1;
                                }

                                st.erase(tp);
                            }
                        }
                    }

                    tp[j] = ch;
                }
            }
        }

        return 0;
    }

//Time Complexity -> O(n * L * 26) = O(n * L)
//Space Complexity -> O(n)
};

int main(){
    Solution sol;

    string beginWord, endWord;
    cin >> beginWord >> endWord;

    int n;
    cin >> n;

    vector<string> wordList(n);
    for(int i = 0; i < n; i++){
        cin >> wordList[i];
    }

    int ans = sol.ladderLength(beginWord, endWord, wordList);
    cout << ans << "\n";

    return 0;
}