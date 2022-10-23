int getMEX(vector < int > & a) {
  bool found = false;
  for (int i = 1;; i++) {
    found = false;
    for (auto x: a) {
      if (x == i) {
        found = true;
        break;
      }
    }
    if (!found) {
      return i;
    }
  }
}
