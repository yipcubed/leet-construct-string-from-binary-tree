#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

// https://leetcode.com/problems/construct-string-from-binary-tree/

// #include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    void tree2strR(TreeNode *t, stringstream &ss) {
        if (!t) return;
        ss << t->val;
        if (!t->left && !t->right) return;
        ss << "(";
        tree2strR(t->left, ss);
        ss << ")";
        if (t->right) {
            ss << "(";
            tree2strR(t->right, ss);
            ss << ")";
        }

    }

    string tree2str(TreeNode *t) {
        stringstream ss;
        tree2strR(t, ss);
        string s = ss.str();
        return s;
    }
};

void test1() {
    vector<int> v1{1, 2, 3, 4};
    auto t1 = new TreeNode(v1);

    cout << "1(2(4))(3) ? " << Solution().tree2str(t1) << endl;

    vector<int> v2{1, 2, 3, -1, 4};
    auto t2 = new TreeNode(v2, -1);
    cout << t2 << endl;
    cout << "1(2()(4))(3) ? " << Solution().tree2str(t2) << endl;

}

void test2() {

}

void test3() {

}