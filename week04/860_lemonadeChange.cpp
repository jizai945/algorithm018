// ---------------- leetcode 860 ---------------------

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int m_5 = 0, m_10 = 0;

        for (int i=0; i<bills.size(); i++) {
            if (bills[i] == 5) {
                m_5++;
            } else if (bills[i] == 10) {
                if (m_5 == 0) return false;

                m_5--;
                m_10++;
            } else if (bills[i] == 20) {
                if (m_10 != 0 && m_5 != 0) {
                    m_5--;
                    m_10--;
                } else if (m_5 >= 3) {
                    m_5-=3;
                } else {
                    return false;
                }

            }
        }

        return true;

    }
};