/*A company of dwarfs is travelling across the New Zealand. On reaching the Clutha River the dwarfs need to get across, but recent storms have washed away the bridge. Luckily, a small ferry, in the form of a square raft, is operating.

The raft is square and has N rows of seats, numbered from 1 to N. Each row contains N seats, labeled with consecutive letters (A, B, C, etc.). Each seat is identified by a string composed of its row number followed by its column number; for example, "9C" denotes the third seat in the 9th row.

The raft has already been loaded with barrels in some seat positions, and other seats are already occupied by dwarfs. Our company of dwarfs may only take the remaining unoccupied seats. The ferryman wants to accommodate as many dwarfs as possible, but the raft needs to be stable when making the crossing. That is, the following conditions must be satisfied:

the front and back halves of the raft (in terms of the rows of seats) must each contain the same number of dwarfs;
similarly, the left and right sides of the raft (in terms of the columns of seats) must each contain the same number of dwarfs.
You do not have to worry about balancing the barrels; you can assume that their weights are negligible.

For example, a raft of size N = 4 is shown in the following illustration:*/

#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;

int solution(int N, string &S, string &T) {
    unordered_set<string> barrels_set;
    unordered_set<string> dwarfs_set;

    istringstream ss_s(S);
    string seat;
    while (ss_s >> seat)
        barrels_set.insert(seat);

    istringstream ss_t(T);
    while (ss_t >> seat)
        dwarfs_set.insert(seat);

    int existing[2][2] = {};
    int free_space[2][2] = {};

    for (int row = 1; row <= N; ++row) {
        for (int col = 0; col < N; ++col) {
            char col_char = 'A' + col;
            string pos = to_string(row) + col_char;

            if (barrels_set.count(pos)) continue;

            int r = (row <= N / 2) ? 0 : 1; // 0=front, 1=back
            int c = (col < N / 2) ? 0 : 1;  // 0=left, 1=right

            if (dwarfs_set.count(pos))
                existing[r][c]++;
            else
                free_space[r][c]++;
        }
    }

    int max_dwarfs = -1;

    for (int f_l = 0; f_l <= free_space[0][0]; ++f_l) {
        for (int f_r = 0; f_r <= free_space[0][1]; ++f_r) {
            for (int b_l = 0; b_l <= free_space[1][0]; ++b_l) {
                for (int b_r = 0; b_r <= free_space[1][1]; ++b_r) {
                    int total_front = existing[0][0] + existing[0][1] + f_l + f_r;
                    int total_back  = existing[1][0] + existing[1][1] + b_l + b_r;
                    int total_left  = existing[0][0] + existing[1][0] + f_l + b_l;
                    int total_right = existing[0][1] + existing[1][1] + f_r + b_r;

                    if (total_front == total_back && total_left == total_right) {
                        int added = f_l + f_r + b_l + b_r;
                        if (added > max_dwarfs)
                            max_dwarfs = added;
                    }
                }
            }
        }
    }

    return max_dwarfs;
}
