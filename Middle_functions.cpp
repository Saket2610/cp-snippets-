auto dfs = [&](auto self, int x, int y, int z){
    // for recurrsive function 
    return self(self , p[x] , p[y] , p[z]);
};

function<i64(int, int)> f = [&](int x, int y) {
    // also for recurrsive function
}
