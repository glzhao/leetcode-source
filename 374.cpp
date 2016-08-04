/*
 * 374. Guess Number Higher or Lower
 *
 * We are playing the Guess Game. The game is as follows:
 *
 * I pick a number from 1 to n. You have to guess which number I picked.
 *
 * Every time you guess wrong, I'll tell you whether the number is higher or
 * lower.
 *
 * You call a pre-defined API guess(int num) which returns 3 possible results
 * (-1, 1, or 0):
 *
 * -1 : My number is lower
 *  1 : My number is higher
 *  0 : Congrats! You got it!
 * Example:
 * n = 10, I pick 6.
 * Return 6.
 */

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0

#include <iostream>

int guess(int num)
{
    int request = 100;

    if (request < num) {
       return -1;
    } else if (request > num) {
        return 1;
    } else {
        return 0;
    }
}

class Solution {
public:
    int guessNumber(int n) {
        int request = 0;
        int low = 1, high = n;
        long mid = 1 + (n - 1) / 2;

        while(low <= high) {
            mid = low + (high - low ) / 2;
            int ret = guess(mid);
            if (ret < 0) {
                high = mid - 1;  
            } else if (ret > 0) {
                low = mid + 1;
            } else {
                break;
            }
        }

        return mid;
    }
};

int main(int argc, char *argv[])
{
    Solution *s = new Solution;

    std::cout << s->guessNumber(100) << std::endl;
    return 0;
}
