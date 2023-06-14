class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0];int y1 = rec1[1];int x2 = rec1[2];int y2 = rec1[3];
        int x3 = rec2[0];int y3 = rec2[1];int x4 = rec2[2];int y4 = rec2[3];

        if(x1 < x4 && x3 < x2 && y1 < y4 && y3 < y2) return true;
        return false;
        
    }
};
/*
this solution is only valid for points given like this:

x1 = bottom left of rectangle
x2 = top right of the rectangle

there are 4 cases of intersection btw r1 and r2.
draw each of them and we find this common in every intersection : if(x1 < x4 && x3 < x2 && y1 < y4 && y3 < y2) return true;
NOTE ALWAYS x1 with x4 and x3 with x2

*/
