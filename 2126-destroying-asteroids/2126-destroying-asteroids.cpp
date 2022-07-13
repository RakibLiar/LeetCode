class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        for(int a: asteroids) {
            if(mass < a)
                return false;
            mass += a;
            if(mass >= asteroids[asteroids.size()-1])
                return true;
        }
        return true;
    }
};