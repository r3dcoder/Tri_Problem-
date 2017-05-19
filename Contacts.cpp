#include <bits/stdc++.h>

using namespace std;
vector<string>s;

struct node
{
    bool endmark;
    int cnt = 0;
    node* next[26 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;

void insert(string str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
        curr->cnt++;
    }
    curr->endmark = true;
}

int search(string str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
        {
            return 0;
        }
        curr = curr->next[id];
    }
    return curr->cnt;
}


int main()
{
    int t;
    cin>>t;
    root = new node();
    while(t--)
    {
        bool flag = 0;
        string ss, s1;
        cin>>ss>>s1;
        if( ss == "add" )
        {
            // s.push_back(s1);
            insert(s1, s1.size());
        }

        else
        {
            cout<< search(s1, s1.size()) <<endl;

        }
    }

    return 0;
}

