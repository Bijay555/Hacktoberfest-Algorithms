#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool isWordPresent(vector<string> &dict, string word)
{
    for (string str : dict)
    {
        if (word.compare(str) == 0)
        {
            return true;
        }
    }
    return false;
}
int wordBreak(vector<string> &dict, string statement, string ans)
{
    if (statement.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 1; i <= statement.length(); i++)
    {
        string str = statement.substr(0, i);
        if (isWordPresent(dict, str))
        {
            count += wordBreak(dict, statement.substr(i), ans + str + " ");
        }
    }
    return count;
}
void wordBreak_Crypto()
{
    vector<string> dict = {"samsung", "sam", "sung", "i", "like", "ilike", "sun", "go", "samsungo"};
    string str = "ilikelikesamsungo";
    cout << wordBreak(dict, str, "") << endl;
}
void solve()
{
    wordBreak_Crypto();
}
int main(int args, char **argv)
{
    solve();
    return 0;
}