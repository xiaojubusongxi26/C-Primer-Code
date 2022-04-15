/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Initializes an empty nested list and return a reference to the nested integer.
 * struct NestedInteger *NestedIntegerInit();
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Set this NestedInteger to hold a single integer.
 * void NestedIntegerSetInteger(struct NestedInteger *ni, int value);
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 * void NestedIntegerAdd(struct NestedInteger *ni, struct NestedInteger *elem);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */

struct NestedInteger* helper (const char *s, int * index) {
    if (s[*index] == '[') {
        (*index)++;
        struct NestedInteger* ni = NestedIntegerInit();
        while (s[*index] != ']') {
            NestedIntegerAdd(ni, helper(s, index));
            if (s[*index] == ',') {
                (*index)++;
            }
        }
        (*index)++;
        return ni;
    } else {
        bool negative = false;
        if (s[*index] == '-') {
            negative = true;
            (*index)++;
        }
        int num = 0;
        while (s[*index] && isdigit(s[*index])) {
            num = num * 10 + s[*index] - '0';
            (*index)++;
        }
        if (negative) {
            num *= -1;
        }
        struct NestedInteger * ni = NestedIntegerInit();
        NestedIntegerSetInteger(ni, num);
        return ni;
    }
}

struct NestedInteger* deserialize(char * s){
    int index = 0;
    return helper(s, &index);
}