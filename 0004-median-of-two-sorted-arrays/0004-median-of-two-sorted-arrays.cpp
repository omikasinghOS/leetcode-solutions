class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size()) swap(a, b);
        int m = a.size(), n = b.size(), l = 0, r = m;
        while(true) {
            int i= (l + r) / 2;
            int j = (m + n + 1) / 2 - i;

            int al = (i ? a[i - 1] : INT_MIN);
            int ar = (i < m ? a[i] : INT_MAX);
            int bl = (j ? b[j - 1] : INT_MIN);
            int br = (j < n ? b[j] : INT_MAX);

            if (al <= br && bl <= ar)
                return (m + n) & 1
                    ? max(al, bl)
                    : (max(al, bl) + min(ar, br)) / 2.0;

            if (al > br) r = i - 1;
            else l = i + 1;
        }

        return 0;
    }
};