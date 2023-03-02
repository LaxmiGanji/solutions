char *convert(char *s, int numRows) {
    int len = strlen(s);
    if (numRows == 1 || numRows >= len)
        return s;

    char *result = (char *) malloc((len + 1) * sizeof(char));
    int step = 2 * numRows - 2;
    int count = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < len; j += step) {
            result[count++] = s[j];
            int tmp = j + step - 2 * i;
            if (i != 0 && i != numRows - 1 && tmp < len) {
                result[count++] = s[tmp];
            }
        }
    }
    result[count] = '\0';
    return result;
}
