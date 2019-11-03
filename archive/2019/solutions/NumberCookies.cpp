#include <bits/stdc++.h>
using namespace std;

int apply(int x, int y, char op) {
    if (op == '+')
        return x + y;
    else if (op == '-')
        return x - y;
    else
        return x * y;
}

int main() {
    int n;
    char a[7];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    int ret = INT_MIN;
    sort(a, a + n);
    do {
        bool valid = true;
        for (int i=0; i<n; i++)
            if (!isdigit(a[i]) && (i == 0 || i == n - 1 || !isdigit(a[i-1])) || a[i] == '0' && (i == 0 || !isdigit(a[i-1])) && i < n - 1 && isdigit(a[i+1]))
                valid = false;

        if (valid) {
            stack<char> ops;
            stack<int> vals;
            int num = 0;
            for (int i=0; i<n; i++) {
                if (isdigit(a[i]))
                    num = 10 * num + a[i] - '0';
                else {
                    vals.push(num);
                    num = 0;
                    while (!ops.empty() && (ops.top() == '*' || a[i] != '*')) {
                        int y = vals.top();
                        vals.pop();
                        int x = vals.top();
                        vals.pop();
                        char op = ops.top();
                        ops.pop();
                        vals.push(apply(x, y, op));
                    }
                    ops.push(a[i]);
                }
            }
            vals.push(num);
            while (!ops.empty()) {
                int y = vals.top();
                vals.pop();
                int x = vals.top();
                vals.pop();
                char op = ops.top();
                ops.pop();
                vals.push(apply(x, y, op));
            }

            ret = max(ret, vals.top());
        }
    } while (next_permutation(a, a + n));

    cout << ret << endl;

    return 0;
}