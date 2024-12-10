// 2981. Find Longest Special Substring That Occurs Thrice I

 void update(int a[], int len) {
    if (len > a[0]) {
        a[2] = a[1];
        a[1] = a[0];
        a[0] = len;
    } else if (len > a[1]) {
        a[2] = a[1];
        a[1] = len;
    } else if (len > a[2]) {
        a[2] = len;
    }
 }
