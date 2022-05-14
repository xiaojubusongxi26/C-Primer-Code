bool oneEditAway(char* first, char* second){
    int len1 = strlen(first), len2 = strlen(second);
    if (abs(len1 - len2) > 1) {
        return false;
    } else if (fmax(len1, len2) == 1) {
        return true;
    }
    char *lang, *sort;
    if (len1 > len2) {
        lang = first;
        sort = second;
    } else {
        lang = second;
        sort = first;
    }
    int f = 0, rf = 0;
    for (int i = 0; i < fmin(len1, len2); i++) {
        if (lang[i + f] != sort[i + rf] && len1 != len2) {
            f++;
            i--;
        } else if (lang[i + f] != sort[i + rf] && len1 == len2) {
            f++;
            rf++;
            i--;
        }
        if (f > 1) {
            return false;
        }
    }
    return true;
}