#include <bits/stdc++.h>
using namespace std;
int predict(int page[], vector<int> &fr, int pn, int index) {
  // Store the index of pages which are going
  // to be used recently in future
  int res = -1, farthest = index;
  for (int i = 0; i < fr.size(); i++) {
    int j;
    for (j = index; j < pn; j++) {
      if (fr[i] == page[j]) {
        if (j > farthest) {
          farthest = j;
          res = i;
        }
        break;
      }
    }
    // Return the page which are
    // are never referenced in future,
    if (j == pn)
      return i;
  }
  // If all of the frames were not in future,
  // return any of them, we return 0. Otherwise
  // we return res.
  return (res == -1) ? 0 : res;
}
bool search(int key, vector<int> &fr) {
  for (int i = 0; i < fr.size(); i++)
    if (fr[i] == key)
      return true;
  return false;
}
void opr(int page[], int pn, int fn) {
  vector<int> fr;
  int hit = 0;
  for (int i = 0; i < pn; i++) {
    // Page found in a frame : HIT
    if (search(page[i], fr)) {
      hit++;
      continue;
    }
    // If a page not found in a frame : MISS
    // check if there is space available in frames.
    if (fr.size() < fn)
      fr.push_back(page[i]);
    // Find the page to be replaced.
    else {
      int j = predict(page, fr, pn, i + 1);
      fr[j] = page[i];
    }
  }
  cout << "Hits = " << hit << endl;
  cout << "Misses = " << pn - hit << endl;
}
// main Function
int main() {
  int page[] = {1, 7, 8, 3, 0, 2, 0, 3, 5, 4, 0, 6, 1};
  int pn = sizeof(page) / sizeof(page[0]);
  int fn = 3;
  opr(page, pn, fn);
  return 0;
}
