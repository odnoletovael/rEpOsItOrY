#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;
class Node {
public:
int cnt;
char c;
Node* left;
Node* right;
Node(char ch, int ct) {
        c = ch;
        cnt = ct;
    }
 Node(Node* l, Node* r) {
        c = 0;
        left = l;
        right = r;
        cnt = l->cnt + r->cnt;
    }
};
 
void BuildF(Node* root, vector<bool>& cph, map<char, vector<bool>>& f) {
if (root->left) {
        cph.push_back(false);
        BuildF(root->left, cph, f);
    }
if (root->right) {
        cph.push_back(true);
        BuildF(root->right, cph, f);
    }
if (root->c) {
        f[root->c] = cph;
    }
if (!cph.empty()) {
        cph.pop_back();
    }
}
 
bool TreeSort(const Node* a, const Node* b) {
    return a->cnt < b->cnt;
}
 
string Decode(string& str, map<vector<bool>, char>& f) {
    string out;
    vector<bool> cph;
    for (int i = 0; i<str.length(); i++) {
        cph.push_back(str[i] == '0' ? false : true);
        if (f[cph])
        {
            out += f[cph];
            cph.clear();
        }
    }
    return out;
}
 
int main() {
    string str;
    cout << "Enter your string:\n";
    cin >> str;
   
    map<char, int> mp;
 
    for (char &i : str) {
        mp[i]++;
    }
 
    list<Node*> tree;
   
    for (auto &it : mp) {
        Node* p = new Node(it.first, it.second);
        tree.push_back(p);
    }
 
    while (tree.size() != 1) {
        tree.sort(TreeSort);
 
        const auto l = tree.front();
        tree.pop_front();
        const auto r = tree.front();
        tree.pop_front();
 
        auto pr = new Node(l, r);
        tree.push_back(pr);
    }
 
    const auto root = tree.front();
 
    vector<bool> cph;
    map<char, vector<bool> > f;
    BuildF(root, cph, f);
 
   
    for (auto &it : mp) {
        cout << it.first << " - ";
        for (auto&& j : f[it.first])
            cout << j;
        cout << endl;
    }
 
    string out;
    cout << "code: ";
    for (char i : str)
        for (auto&& j : f[i]) {
            out += j + '0';
            cout << j;
        }
 
    cout << "\ndecode: ";
    map<vector<bool>, char> origins;
    for (auto &i : f)
        origins[i.second] = i.first;
    cout << Decode(out, origins).c_str() << endl;
}
