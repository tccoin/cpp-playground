class Solution {
 public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    int width = image[0].size();
    int tmp;
    for (int i = 0; i < image.size(); i++) {
      for (int j = 0; j < width / 2; j++) {
        tmp = image[i][j];
        image[i][j] = !image[i][width - 1 - j];
        image[i][width - 1 - j] = !tmp;
      }
      if (width % 2 == 1) image[i][width / 2] = !image[i][width / 2];
    }
    return image;
  }
};