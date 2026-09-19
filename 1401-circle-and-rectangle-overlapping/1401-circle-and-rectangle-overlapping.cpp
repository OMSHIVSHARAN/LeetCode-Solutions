class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearestX = max(x1, min(xCenter, x2));
        int nearestY = max(y1, min(yCenter, y2));
        
        int distX = nearestX - xCenter;
        int distY = nearestY - yCenter;
        
        return (distX * distX + distY * distY) <= radius * radius;
    }
};