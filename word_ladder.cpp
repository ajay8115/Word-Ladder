#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &list)
{
    int n = list.size();
    int f = 0;
    set<string> s;
    for (int i = 0; i < list.size(); i++)
    {
        s.insert(list[i]);
        if (list[i] == endWord)
        {
            f = 1;
        }
    }
 
    if (f == 0)
    {
        return 0;
    }

    queue<string> q;

    q.push(beginWord);

    int depth = 0;
    while (!q.empty())
    {
        depth+=1;
        int lsize = q.size();
        while (lsize--)
        {
            string cur = q.front();
            q.pop();

            for (int i = 0; i < cur.length(); i++)
            {
                string temp = cur;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    temp[i] = c;
                    if (temp == cur)
                    {
                        continue;
                    }

                    if (temp == endWord)
                    {
                        return depth + 1;
                    }

                    if (s.find(temp) != s.end())
                    {
                        q.push(temp);
                        s.erase(temp);
                    }
                }
            }
        }
    }

    return 0;
}