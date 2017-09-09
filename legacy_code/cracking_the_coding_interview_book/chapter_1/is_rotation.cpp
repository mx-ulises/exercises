bool is_rotation(string s_1, string s_2) {
    if (s_1.size() != s_2.size())
        return false;
    string s_3 = s_1 + s_1;
    return is_substring(s_3, s_2);
}
