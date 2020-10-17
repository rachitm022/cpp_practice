#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
	SegmentTree(int count) {
		n = count;
		data = vector<int>(2 * n, 0);
	}

	SegmentTree(vector<int> const &values) {
		n = values.size();
		data = vector<int>(2 * n);
		copy(values.begin(), values.end(), &data[0] + n);
		for (int idx = n - 1; idx > 0; idx--)
			data[idx] = min(data[idx * 2], data[idx * 2 + 1]);
	}

	void update(int idx, int value) {
		idx += n;
		data[idx] = value;

		while (idx > 1) {
			idx /= 2;
			data[idx] = min(data[2 * idx], data[2 * idx + 1]);
		}
	}

	int minimum(int left, int right) { // interval [left, right)
		int ret = numeric_limits<int>::max();
		left += n;
		right += n;

		while (left < right) {
			if (left & 1) ret = min(ret, data[left++]);
			if (right & 1) ret = min(ret, data[--right]);
			left >>= 1;
			right >>= 1;
		}
		return ret;
	}

private:
	int n;
	vector<int> data;
};

int main() {
	SegmentTree st(5);
	st.update(0, 5);
	st.update(1, 2);
	st.update(2, 3);
	st.update(3, 1);
	st.update(4, 4);
	for (int i = 0; i < 5; i++) {
		cout << i << ": " << st.minimum(i, i+1) << endl;
	}

	cout << st.minimum(1, 4) << endl;
	st.update(3, 10);
	cout << st.minimum(1, 4) << endl;
	cout << st.minimum(0, 5) << endl;
	st.update(4, 0);
	cout << st.minimum(1, 4) << endl;
	cout << st.minimum(0, 5) << endl;

	SegmentTree st2({5, 2, 3, 1, 4});
}